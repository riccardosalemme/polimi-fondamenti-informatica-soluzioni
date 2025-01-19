#include <stdio.h>
#include <stdlib.h>

// ok

// Quesito 3 (8 punti). Scrivere un sottoprogramma MinimoInTesta(..) che, ricevendo in ingresso la lista dinamica
// costruita al punto precedente, la modifica spostando in prima posizione il nodo che contiene il valore dominante
// minimo e rende la lista modificata disponibile al chiamante.

struct node {
    int val;
    int row;
    int col;
    struct node *next;
};
typedef struct node node_t;

void minimoInTesta(node_t **lista) {

    node_t *pre, *cur = *lista; // tengo traccia del nodo corrente e del suo precedente
    node_t *pre_min, *min = *lista;

    while (cur != NULL) {
        if (cur->val < min->val) {
            min = cur;
            pre_min = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    if (min != *lista) { // procedo solo se il minimo non coincide con la testa della lista
        pre_min->next = min->next; // il nodo prima del minimo punta al nodo successivo al minimo
        min->next = *lista; // il successivo del minimo è la testa della lista ricevuta
        *lista = min; // il puntatore della testa ora punta al minimo
    }
}

void stampaLista(node_t *lista) {
    node_t *tmp = lista;
    while (tmp != NULL) {
        printf("(%d %d = %d) -> ", tmp->row, tmp->col, tmp->val);
        tmp = tmp->next;
    }
    printf("END \n");
}

void InserisciInTesta(node_t **lista, int row, int col, int val) {
    node_t *new = (node_t*) malloc(sizeof(node_t));
    new->col = col;
    new->row = row;
    new->val = val;
    new->next = *lista;
    *lista = new;
}

int main(int argc, char *argv[]) {

    node_t *lista = NULL;

    InserisciInTesta(&lista, 2, 3, 2);
    InserisciInTesta(&lista, 2, 3, 7);
    InserisciInTesta(&lista, 6, 3, 34);

    InserisciInTesta(&lista, 1, 3, 1);

    stampaLista(lista);

    minimoInTesta(&lista);

    stampaLista(lista);





    return 0;
}
