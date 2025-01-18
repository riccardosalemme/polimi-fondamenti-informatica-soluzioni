#include <stdio.h>
#include <stdlib.h>

// ok

// Si consideri una lista dinamica di interi definita come sopra. Si codifichi in C una funzione
// che riceve come parametro una lista e, a partire dall’inizio, la modifica nel seguente modo: per ciascuna tripletta (tre
// nodi consecutivi) modifica il valore del primo nodo, sostituendolo con la somma dei tre valori della tripletta, e rimuove
// i due nodi successivi.

typedef struct nd {
    int valore;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

void printList(Lista lis);
void addToList(Lista *lis, int val);

void somma_triplette(Lista lis){

    Lista current = lis, next;

    // conto il numero dei nodi
    int numero_nodi = 0;
    while (current != NULL) {
        current = current->next;
        numero_nodi++;
    }

    current = lis;
    // itero per triplette (gli ultimi nodi non verranno toccati)
    for (int i = 0; i < numero_nodi/3; i++) {

        int val = (current->valore) + (current->next->valore) + (current->next->next->valore);

        // printf("Valore nodo corrente: %d \n", current->valore);
        // printf("Valore somma 3 nodi: %d \n\n", val);

        current->valore = val; // sostituisco il valore
        next = current->next->next->next; // trovo il primo nodo della prossima tripletta (se quest è l'ultima tripletta il sarà null)
        current->next = next;
        current = current->next;
    }

}

int main(int argc, char *argv[]){

    Lista lista = NULL;
    addToList(&lista, 1);
    addToList(&lista, 1);
    addToList(&lista, 1);
    addToList(&lista, 2);
    addToList(&lista, 2);
    addToList(&lista, 2);
    addToList(&lista, 3);
    addToList(&lista, 3);
    addToList(&lista, 3);
    addToList(&lista, 4);
    addToList(&lista, 5);
    addToList(&lista, 6);
    addToList(&lista, 7);
    addToList(&lista, 8);


    printf("Lista originale:  ");
    printList(lista);

    somma_triplette(lista);

    printf("Lista modificata: ");
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
        printf("%2d -> ", tmp->valore);
        tmp = tmp->next;
    }
    printf("END \n");
}
