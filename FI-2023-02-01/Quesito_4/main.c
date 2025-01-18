// ok

// Data una lista dinamica, una sua rotazione a destra fa in modo che l’ultimo valore a destra venga spostato in
// testa.

// Dopo aver definito un tipo di dato opportuno per rappresentare gli elementi di una lista di interi,
// si definisca una funzione che, ricevuta in ingresso una lista con nodi del tipo definito e un valore intero k >= 0,
// effettui k rotazioni a destra, per effetto delle quali gli ultimi k elementi della lista sono spostati in testa.

// Per esempio, data la lista 6 → 8 → 3 → 1 → 10
// - Se k = 2 la funzione modificherà la lista spostando in testa gli ultimi due elementi: 1→ 10 → 6 → 8 → 3
// - Se k = 1, la funzione sposterà in testa solo l’ultimo elemento: 10 → 6 → 8 → 3 → 1

// Nel caso in cui la lista sia vuota o k sia maggiore o uguale al numero di nodi in essa contenuti, la funzione
// restituisce la lista ricevuta in ingresso senza apportare alcuna modifica.

// NOTA: verranno premiate soluzioni che prevedano una sola scansione della lista.

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
        printf("%d -> ", n->val);
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

void pushTop(){

}

int main(){

    node_t *list;

    initList(&list, 6);

    pushBack(list, 8);
    pushBack(list, 3);
    pushBack(list, 1);
    pushBack(list, 10);

    printf("Prima della rotazione: ");
    printList(list);


    // Prima della rotazione
    // head -> .. -> new_tail -> new_head -> .. -> tail -> NULL
    //
    // Dopo la rotazione
    // new_head -> .. -> tail -> head -> .. -> new_tail -> NULL

    int rot = 2; // Numero di rotazioni

    node_t* head = list;
    node_t* tail;
    node_t* new_head = list;
    node_t* new_tail = list;

    int count = 1;
    node_t* n = list;
    while (n->next != NULL) {
        if(count == rot){
            new_tail = new_head;
            new_head = new_head->next;
            count--;
        }
        n = n->next;
        count++;
    }

    tail = n; // la coda è l'ultimo elemento della lista originaria
    list = new_head; // nuova testa
    tail->next = head;
    new_tail->next = NULL; // la nuova coda è l'ultimo elemento della nuova lista

    printf("Dopo la rotazione: ");
    printList(list);

    return 0;
}
