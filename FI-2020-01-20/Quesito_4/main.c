#include <stdio.h>
#include <stdlib.h>

// ok

// Data una matrice di interi mat, di dimensione NxM (N e M costanti), si scriva una funzione per individuare se Mat
// contiene almeno una sottomatrice, di dimensioni r e c, i cui elementi abbiano somma uguale a 0. La funzione
// riceve come parametro la matrice mat, le dimensioni r e c della sottomatrice e ogni altro parametro ritenuto
// necessario. Quindi, restituisce all’ambiente chiamante gli indici dell’angolo superiore sinistro della prima
// sottomatrice individuata. Se mat non contiene una sottomatrice di somma 0, la funzione restituisce indici di
// valore -1, -1.

#define N 4
#define M 4

typedef struct {
    int r;
    int c;
} point_t;

point_t contieneSottomatice(int mat[][M], int r, int c){

    point_t estremo;

    for (int i = 0; i <= N-r; i++) {
        for (int j = 0; j <= M-c; j++) {
            // mat[i][j] è il mio estremo superiore
            // printf("Estremo superiore: %d (%d, %d)", mat[i][j], i, j);
            int somma = 0;
            for (int a = 0; a < r; a++)
                for (int b = 0; b < c; b++)
                    somma += mat[a+i][b+j];

            // printf(" Somma: %d \n", somma);
            if (somma == 0) {
                estremo.r = i;
                estremo.c = j;
                return estremo;
            }
        }
    }

    estremo.r = -1;
    estremo.c = -1;
    return estremo;
}


int main(int argc, char *argv[]){

    int mat[N][M] = {
        {15, 4, -21, 8},
        {-7, 7, -4, -34},
        {-3, 9, -2, 18},
        {-15, -5, 3, 29}
    };
    int r = 2, c = 3;

    point_t estremoSuperiore = contieneSottomatice(mat, r, c);
    if(estremoSuperiore.c == -1 && estremoSuperiore.r == -1){
        printf("La matrice non contiene sottomatrici con i parametri specificati \n");
        return -1;
    }

    printf("Cordinate estremo superiore sottomatrice: (%d, %d) \n", estremoSuperiore.r, estremoSuperiore.c);

    return 0;
}
