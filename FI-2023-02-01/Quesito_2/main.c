// ok

// Quesito 2. (6 punti).
//
// Si scriva un sottoprogramma ricorsivo void(...) che riceve due array ordinati e le loro dimensioni, e copia i loro
// elementi in un terzo array, che dovrà risultare anch'esso ordinato. Anche il terzo array dovrà esser passato come
// parametro al sottoprogramma. Ad esempio, dati i due array a : [1, 4, 6, 10] e b : [2, 3, 6, 9], il sottoprogramma
// costruisce l’array c : [1, 2, 3, 4, 6, 6, 9, 10].
//
// NOTA: si suppone che il terzo array sia stato dichiarato (nel programma chiamante) con dimensione sufficiente
// per poter sempre ospitare gli elementi dei primi due array.

#include <stdio.h>

void copiaRicorsiva(int a[], int dim_a, int b[], int dim_b, int c[]){

    int n = dim_a + dim_b - 1; // posizione elemento in c

    // ultima ricorsione
    if(dim_a == 0){
        c[n] = b[dim_b-1];
    }else if(dim_b == 0){
        c[n] = a[dim_a-1];

    // trovo il massimo (riempio l'array dall'ultimo elemento)
    }else if(a[dim_a-1] > b[dim_b-1]){
        c[n] = a[dim_a-1];
        copiaRicorsiva(a, dim_a-1, b, dim_b, c);
    }else{
        c[n] = b[dim_b-1];
        copiaRicorsiva(a, dim_a, b, dim_b-1, c);
    }

}

void stampaVettore(int x[], int dim){
    for(int i = 0; i < dim; i++)
        printf("%d  ", x[i]);
    printf("\n");
}

int main(){

    int a[] = {3, 7, 9, 12};
    int b[] = {1, 7, 23};

    int c[20] = {};

    const int dim_a = sizeof(a) / sizeof(a[0]);
    const int dim_b = sizeof(b) / sizeof(b[0]);

    const int dim_c = dim_a + dim_b;

    copiaRicorsiva(a, dim_a, b, dim_b, c);
    stampaVettore(c, dim_c);

    return 0;
}
