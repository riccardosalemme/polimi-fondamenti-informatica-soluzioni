// ok

// Quesito 3. (12 punti).
//
// Si vuole definire un programma in C che, data una matrice di interi di dimensione massima NxM (N ed M costanti
// predefinite), individui quanti e quali elementi, di seguito detti minimoRC, sono il minimo sia della colonna sia
// della riga in cui sono posizionati.

// Punto 3.1 (7 punti).
//
// Si definisca una funzione che, ricevuta come parametro la matrice e ogni altro parametro ritenuto strettamente
// necessario, analizzi la matrice e restituisca:
// - il numero di elementi che sono minimoRC
// - le coordinate (<riga, colonna>) di tutti elementi che sono minimoRC.

// Quesito 3.2 (5 punti).
//
// Si scriva il main di un programma, completo di ogni dichiarazione, che riceve come parametro sulla linea di
// comando il nome di un file che memorizza gli elementi di una matrice di elementi interi. Quindi:
//
// 1. Legge il file e costruisce la matrice in esso memorizzata. Si assuma che il file abbia il seguente formato:
// - la prima riga memorizza il numero effettivo di righe e colonne della matrice memorizzata nel file;
// - le successive righe memorizzano le righe della matrice;
// - in ogni riga gli elementi sono separati da spazi;
// Per esempio, per la matrice nell’esempio precedente, il file sarà organizzato nel seguente modo:
// 3 4
// 1 3 8 2
// 10 5 2 0
// 3 2 12 6
// 2. Invoca la funzione definita al punto precedente per l’analisi della matrice;
// 3. Stampa il numero di elementi di tipo minimoRC trovati nella matrice e le loro coordinate.


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

bool readMatrix(char filename[], int mat[MAX_ROW][MAX_COL], int *rows, int *cols){
    FILE *file = fopen(filename, "r");

    if(file == NULL) return false;

    int r, c;
    fscanf(file, "%d %d", &r, &c);

    if(r > MAX_ROW || c > MAX_COL) return false;

    *rows = r;
    *cols = c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            fscanf(file, "%d ", &mat[i][j]);
        }
    }

    fclose(file);
    return true;
}

typedef struct {
    int row;
    int col;
} Point;

int minimoRC(int mat[MAX_ROW][MAX_COL], int rows, int cols, Point points[]){

    int count = 0;

    for(int i = 0; i < rows; i++){ // per ogni riga

        int min_row_val = mat[i][0]; // cerco il minimo per la riga
        Point min_row;
        for(int j = 0; j < cols; j++){
            if(mat[i][j] <= min_row_val){
                min_row_val = mat[i][j];
                min_row.col = j;
                min_row.row = i;
            }
        }

        bool isMinimoRC = true; // verifico sia il minimo anche per la colonna
        for(int k = 0; k < rows && isMinimoRC; k++){
            if(mat[k][min_row.col] < min_row_val) isMinimoRC = false;
        }
        if(isMinimoRC){
            // aggiungo i punti trovati
            points[count].col = min_row.col;
            points[count].row = min_row.row;
            count++;
        }
    }

    return count;

}


int main(){

    int mat[MAX_ROW][MAX_COL] = {0};
    int rows, cols;

    Point minimiRC[MAX_ROW]; // sarebbe il minimo tra righe e colonne
    int minimiRCcount = 0;

    if(!readMatrix("mat.txt", mat, &rows, &cols)){
        printf("Errore nella lettura del file! \n");
        return -1;
    }

    printf("Matrice: \n");
    printMatrix(mat, rows, cols);

    minimiRCcount = minimoRC(mat, rows, cols, minimiRC);

    printf("Numero di minimiRC: %d \n", minimiRCcount);

    printf("MinimiRC trovati: \n");
    for(int i = 0; i < minimiRCcount; i++){
        printf("- (%d, %d) \n", minimiRC[i].row, minimiRC[i].col);
    }


    return 0;
}
