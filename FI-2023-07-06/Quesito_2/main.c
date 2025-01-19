#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ok

// Quesito 2 (8 punti). In una matrice di valori interi, si definisce dominante ogni elemento che è strettamente
// maggiore di tutti gli elementi della (sotto)matrice che si trova in basso a destra rispetto all’elemento stesso (si
// veda la figura). Dal calcolo devono essere esclusi gli elementi presenti nell’ultima colonna e nell’ultima riga.

// Si realizzi una funzione, Dominante (...), che, ricevuti in ingresso una matrice m di dimensione N x M (N ed M
// costanti predefinite) e qualsiasi altro parametro ritenuto necessario, individui gli elementi dominanti della
// matrice e li memorizzi in una lista i cui nodi specificano i valori dominanti e la loro posizione nella matrice
// (indice di riga e indice di colonna).

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

    return 0;
}

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
