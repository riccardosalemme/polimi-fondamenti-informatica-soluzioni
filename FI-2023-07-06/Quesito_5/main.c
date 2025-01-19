#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ok

// Quesito 5 (5 punti). Si scriva un programma in C, completo di parti dichiarative che, dopo aver letto i valori della
// matrice da un file, invochi in modo opportuno le funzioni definite ai punti precedenti per costruire la lista
// ordinata degli elementi dominanti della matrice. Il programma stampa quindi la lista.
// Per la lettura della matrice dal file, si consideri che:
// 1. Il nome del file da cui leggere la matrice deve essere letto da riga di comando (deve cioè essere gestito
// come parametro del main).
// 2. Il file è organizzato in modo che la prima riga memorizzi le dimensioni effettive della matrice, n e m. Si
// può assumere che questi valori siano minori o uguali alle costanti predefinite N e M, che invece
// rappresentano le dimensioni massime costanti della matrice.
// 3. Ogni riga successiva del file memorizza i valori delle righe della matrice separati da uno spazio. Per
// esempio, il file che memorizza la matrice riportata come esempio nel quesito 2 sarà organizzato nel
// seguente modo:

#define N 20 // numero massimo di righe
#define M 20 // numero massimo di colonne

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
void Ordina(node_t **lista);

int main(int argc, char *argv[]) {

    int mat[N][M], r, c;
    node_t *lista = NULL;

    if (argc != 2) {
        printf("Impossibile avviare il programma (controllare di aver passato correttamente i parametri) \n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Impossibile aprire il file. Controllare che esista \n");
        return -1;
    }

    fscanf(file, "%d %d", &c, &r); // leggo numero di colonne e righe
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(file, "%d", &mat[i][j]);
        }
    }

    fclose(file);

    printf("Matrice %dx%d letta da file: \n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Lista dominanti: \n");
    Dominante(mat, r, c, &lista);
    stampaLista(lista);

    printf("Lista dominanti (ordinata): \n");
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

void Ordina(node_t **lista) {
    if ((*lista)->next == NULL)
        return;
    return minimoInTesta(&(*lista)->next);
}
