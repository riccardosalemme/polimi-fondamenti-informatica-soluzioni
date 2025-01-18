// ok

// Esercizio 4. Matrici (6 punti).
//
// Scrivere un sottoprogramma che, ricevuta in ingresso una matrice
// quadrata di interi (e qualsiasi altro parametro ritenuto strettamente necessario),
// verifichi se esistono
// almeno una riga e una colonna identiche, cioè contenenti gli stessi valori e nello stesso ordine. In caso
// positivo il sottoprogramma restituisce 1 altrimenti 0.

#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 10


void printMatrix(int mat[MAX_ROW][MAX_COL], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int esisteIdentico(int mat[MAX_ROW][MAX_COL], int rows, int cols){
    if(rows != cols) return 0;

    for(int i = 0; i < rows; i++){ // per ogni riga
        for(int j = 0; j < cols; j++){ // per ogni colonna
            bool valid = true;
            for(int k = 0; k < rows; k++){ // verifico siano uguali
                if(mat[i][k] != mat[k][j]) valid = false;
            }
            if(valid) return 1;
        }
    }

    return 0;
}

int main(){

    int mat[MAX_ROW][MAX_COL] = {
        {1, 2, 3, 4},
        {2, 4, 5, 6},
        {5, 5, 3, 4},
        {4, 6, 5, 6}
    };

    int res = esisteIdentico(mat, 4, 4);

    printf("Risultato: %d \n", res);


    return 0;
}
