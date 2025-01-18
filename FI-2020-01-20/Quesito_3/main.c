#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ok


// Sia data una lista che memorizza una sequenza di interi. La lista contiene almeno due nodi.
// Dopo aver opportunamente definito il tipo dei nodi della lista, si scriva una funzione che riceve come parametro
// la testa della lista e ne modifica i valori sommando a ogni elemento il valore dell'elemento precedente. Il primo
// nodo rimane invariato.

// Per esempio, se la lista contiene i valori 5-> 1-> 3-> 9-> 8, allora la funzione la modifica in 5-> 6-> 4-> 12-> 17.

struct node {
    int val;
    struct node *next;
};
typedef struct node node_t;

void sommaCoppie(node_t *list){

    if(list == NULL || list->next == NULL) return; // la lista deve avere almeno due nodi

    node_t *tmp = list->next;
    int curr_val, prev_val = list->val;

    while (tmp != NULL) {
        curr_val = tmp->val;
        tmp->val = curr_val + prev_val;
        prev_val = curr_val;
        tmp = tmp->next;
    }

}

void addToList(node_t **list, int val){

    // lista vuota -> inserisco il primo elemento
    if (*list == NULL) {
        *list = (node_t*) malloc(sizeof(node_t));
        if(*list == NULL) return;
        (*list)->next = NULL;
        (*list)->val = val;
        return;
    }

    // la lista ha già dei valori -> scorro la lista fino all'ultimo elemento
    node_t *tmp = *list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    // creo e inserisco l'ultimo elemento
    tmp->next = (node_t*) malloc(sizeof(node_t));
    if((tmp)->next == NULL) return;
    (tmp)->next->next = NULL;
    (tmp)->next->val = val;
}

void printList(node_t *list){
    node_t *tmp = list;
    while (tmp != NULL) {
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf(" END \n");
}

int main(int argc, char *argv[]){

    node_t *list = NULL;

    // Lista traccia: 5-> 1-> 3-> 9-> 8
    // Lista soluzione: 5-> 6-> 4-> 12-> 17.

    addToList(&list, 5);
    addToList(&list, 1);
    addToList(&list, 3);
    addToList(&list, 9);
    addToList(&list, 8);

    printList(list);

    sommaCoppie(list);

    printList(list);

    return 0;
}
