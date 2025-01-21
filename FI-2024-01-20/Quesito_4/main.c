#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ok

// Si codifichi in C una funzione void sdoppia( Lista lis, Lista * pPos, Lista * pNeg) che riceve una lista lis e,
// modificando solo i collegamenti tra i nodi (senza allocare né deallocare memoria), costruisce e rende disponibili
// al chiamante due liste così definite: una (puntata da pPos) che contiene tutti gli elementi con valore positivo e
// una (puntata da pNeg) che contiene tutti gli elementi con valore negativo, preservandone l’ordine originale.


// List node
typedef struct nd {
    int valore;
    struct nd * next;
} Nodo;
// List
typedef Nodo * Lista;

void printList(Lista lis);
bool addToList(Lista lis, int v);
void sdoppia(Lista lis, Lista * pPos, Lista * pNeg);

int main(){

    Lista lis = NULL, pos = NULL, neg = NULL; /* Inizializzazioni: tre liste vuote */

    lis = (Nodo*) malloc(sizeof(Nodo));
    lis->valore = 1;
    lis->next = NULL;

    addToList(lis, 5);
    addToList(lis, -2);
    addToList(lis, 4);
    addToList(lis, -12);
    addToList(lis, -15);
    addToList(lis, 3);
    addToList(lis, 4);
    addToList(lis, -1);

    printf("Lista originale: ");
    printList(lis);

    sdoppia( lis, &pos, &neg ); /* Invocazione. pos e neg devono essere ancora vuote */
    lis = NULL; /* Per evitare effetti collaterali - lis ora è “svuotata” */

    printf("Lista positivi: ");
    printList(pos);

    printf("Lista negativi: ");
    printList(neg);

    return 0;
}

void printList(Lista lis){
    Lista n = lis;
    while (n != NULL) {
        printf("%d ", n->valore);
        n = n->next;
    }
    printf("\n");
}

bool addToList(Lista lis, int v){

    Lista n = lis;
    while (n->next != NULL) {
        n = n->next;
    }

    Nodo* new = (Nodo*) malloc(sizeof(Nodo));
    if(new == NULL) return false; // memoria non allocata
    new->next = NULL;
    new->valore = v;
    n->next = new;

    return true;
}

void sdoppia(Lista lis, Lista * pPos, Lista * pNeg){
    if(lis == NULL) return; // lista vuota

    Lista cur = lis, next = NULL, cur_pos = NULL, cur_neg = NULL;
    while (cur != NULL) {

        next = cur->next; // memorizzo l'indirizzo del prossimo nodo

        if (cur->valore > 0) { // strettamente maggiore di 0

            if (cur_pos == NULL) {
                *pPos = cur;
                cur_pos = cur;
            } else {
                cur_pos->next = cur;
                cur_pos = cur_pos->next;
            }
            cur_pos->next = NULL;
        } else if (cur->valore < 0) { // strettamente minore di 0
            if (cur_neg == NULL) {
                *pNeg = cur;
                cur_neg = cur;
            } else {
                cur_neg->next = cur;
                cur_neg = cur_neg->next;
            }
            cur_neg->next = NULL;
        }

        cur = next;
    }

}
