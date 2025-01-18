#include <stdio.h>
#include <stdlib.h>

// ok

// Si codifichi in C una funzione Lista filtra(Lista lis) che riceve una lista lis e la modifica in modo
// che, per ciascuna coppia formata da un nodo in posizione dispari e dal successivo nodo in posizione pari, la
// lista risultante contenga solo il nodo con il valore massimo della coppia. I nodi che non hanno valore massimo
// nella loro coppia devono essere rimossi dalla lista. Se la lista ha un numero dispari di elementi, l’ultimo
// elemento viene conservato nella lista modificata. Se una coppia ha i due elementi di ugual valore, entrambi
// vengono conservati nella lista modificata.

typedef struct nd {
    int valore;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;

Lista filtra(Lista lis){

    if (lis == NULL) return lis; // esco se la lista è vuota

    Lista next_node, tmp = lis;

    while (tmp->next != NULL) {
        int val_a = tmp->valore;
        int val_b = tmp->next->valore;

        if (val_b != val_a) { // valori diversi -> mantengo il più grande

            if (val_a < val_b) val_a = val_b;
            tmp->valore = val_a; // scelgo il massimo

            next_node = tmp->next->next;
            tmp->next = next_node;
            tmp = next_node;

        } else if (val_a == val_b) { // valori uguali -> mantengo entrambi
            val_a = val_b;

            next_node = tmp->next->next;
            tmp = next_node;
        }

        if (tmp == NULL)
            return lis;

    }

    return lis;
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

int main(int argc, char *argv[]){

    Lista lista = NULL;

    addToList(&lista, 1);
    addToList(&lista, 2);
    addToList(&lista, 5);
    addToList(&lista, 3);
    addToList(&lista, 7);
    addToList(&lista, 7);
    addToList(&lista, 4);

    printf("Lista originale: \n");
    printList(lista);

    lista = filtra(lista);

    printf("\nLista filtrata: \n");
    printList(lista);

    return 0;
}
