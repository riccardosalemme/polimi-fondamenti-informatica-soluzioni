#include <stdio.h>
#include <stdlib.h>

// ok

// Esercizio 3. Liste dinamiche (5 punti). Scrivere una funzione che, ricevuta in ingresso una lista dinamica L
// che memorizza interi, modifichi la lista cancellando eventuali ripetizioni. Per esempio, data la lista:
// 4-> 3-> 1-> 3-> 7-> 6-> 7-|
// la lista sarà modificata nel seguente modo:
// 4 -> 3-> 1-> 7-> 6--|

typedef struct nd {
    int valore;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

void printList(Lista);
void addToList(Lista*, int);

void eliminaDoppi(Lista lis) {
    Lista current = lis;

    while (current->next != NULL) {

        Lista succ = current->next, prec = current;
        while (succ != NULL) {

            if (current->valore == succ->valore) {
                prec->next = succ->next;
                succ = succ->next;
            } else {
                prec = succ;
                succ = succ->next;
            }
        }

        current = current->next;
    }
}


int main() {

    Lista lista = NULL;

    addToList(&lista, 4);
    addToList(&lista, 3);
    addToList(&lista, 1);
    addToList(&lista, 3);
    addToList(&lista, 7);
    addToList(&lista, 6);
    addToList(&lista, 7);

    printf("Lista originale: \n");
    printList(lista);

    eliminaDoppi(lista);

    printf("\nLista filtrata: \n");
    printList(lista);

    return 0;
}

void addToList(Lista *lis, int val){
    // Primo elemento
    if(*lis == NULL){
        *lis = (Lista) malloc(sizeof(Nodo));
        (*lis)->valore = val;
        (*lis)->next = NULL;
        return;
    }

    // Successivi
    Lista tmp = *lis;

    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = (Lista) malloc(sizeof(Nodo));
    tmp->next->next = NULL;
    tmp->next->valore = val;
}

void printList(Lista lis){
    Lista tmp = lis;
    while(tmp != NULL){
        printf("%d  -->  ", tmp->valore);
        tmp = tmp->next;
    }
    printf("END \n");
}
