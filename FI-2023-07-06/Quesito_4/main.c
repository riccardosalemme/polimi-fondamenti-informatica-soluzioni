#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ok

// Quesito 4 (5 punti). Scrivere un sottoprogramma Ordina(..), preferibilmente ricorsivo, che riceve in ingresso la
// lista dinamica costruita con il quesito 2 e la ordina in senso crescente, in base al valore del primo campo che
// memorizza i dominanti, avvalendosi di chiamate alla procedura MinimoInTesta(..) sviluppata con il Quesito 3.

#define N 4 // numero di righe
#define M 8 // numero di colonne

struct node {
    int val;
    int row;
    int col;
    struct node *next;
};
typedef struct node node_t;

void stampaLista(node_t *lista);
void InserisciInTesta(node_t **lista, int row, int col, int val);
void Dominante(int m[N][M], int r, int c, node_t **lista);
void minimoInTesta(node_t **lista);

void Ordina(node_t **lista) {
    if ((*lista)->next == NULL)
        return;
    return minimoInTesta(&(*lista)->next);
}

int main(int argc, char *argv[]) {

    const int r = 4, c = 8;
    int mat[N][M] = {
        5, 9, 2, 4, 1, 5, 2, 4,
        3, 5, 6, 2, 5, 6, 1, 2,
        1, 3, 4, 7, 8, 2, 4, 0,
        1, 3, 5, 6, 7, 8, 2, 1
    };

    node_t *lista = NULL;

    Dominante(mat, r, c, &lista);
    stampaLista(lista);

    Ordina(&lista);
    stampaLista(lista);

    return 0;
}

// _____________________________________________________________________

void stampaLista(node_t *lista) {
    node_t *tmp = lista;
    while (tmp != NULL) {
        printf("(%d, %d) = %d  -->  ", tmp->row, tmp->col, tmp->val);
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

void Dominante(int m[N][M], int r, int c, node_t **lista) {

    if (r > N || c > M) return;

    for (int i = 0; i < r-1; i++) { // non considero l'ultima riga e l'ultima colonna (r - 1)
        for (int j = 0; j < c-1; j++) {
            int elm = m[i][j];
            bool dominante = true;

            for (int a = i+1; a < r && dominante; a++)
                for (int b = j+1; b < c && dominante; b++)
                    if (elm <= m[a][b])
                        dominante = false;

            if (dominante) {
                InserisciInTesta(lista, i, j, elm);
            }
        }
    }
}

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
