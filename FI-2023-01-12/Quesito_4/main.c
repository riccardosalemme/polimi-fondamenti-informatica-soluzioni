// ok

// Quesito 4. (9 punti)

// Scrivere una funzione che, ricevendo in ingresso una lista dinamica e un intero k > 0, individui il nodo che si trova
// k posizioni dopo il nodo centrale e ne restituisca il puntatore al chiamante. Se tale nodo non esiste, ad esempio
// a causa di un insufficiente numero di nodi nella lista, la funzione deve restituire il valore NULL.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void printList(node_t* list){
    node_t *n = list;
    while (n != NULL) {
        printf("%d  -->  ", n->val);
        n = n->next;
    }
    printf("NULL \n");
}

bool initList(node_t** head, int val){
    *head = (node_t*) malloc(sizeof(node_t));
    if(*head == NULL) return false;

    (*head)->val = val;
    (*head)->next = NULL;
    return true;
}

bool pushBack(node_t* list, int val){
    // if(list == NULL) return initList(list, val);

    node_t *n = list;
    while (n->next != NULL) {
        n = n->next;
    }

    node_t *new = (node_t*) malloc(sizeof(node_t));
    if(new == NULL) return false;
    new->val = val;
    new->next = NULL;

    n->next = new;
    return true;
}


int main(){

    node_t *list;

    initList(&list, 6);

    pushBack(list, 8);
    pushBack(list, 3);
    pushBack(list, 1);
    pushBack(list, 10);
    pushBack(list, 56);
    pushBack(list, 21);


    printf("Lista: \n");
    printList(list);


    // ----
    //

    int k = 2; // k > 0

    node_t *c = list; // testa della lista
    int c_index = 0;
    node_t *n = list;

    int len = 0;
    int elm_index;

    while(n->next != NULL){
        elm_index = len/2 + k;
        if(c_index <= elm_index) {
            c = c->next;
            c_index++;
        }
        n = n->next;
        len++;
    }

    printf("Nodo distante %d dal nodo centrale: \n", k);
    printList(c);


    return 0;
}
