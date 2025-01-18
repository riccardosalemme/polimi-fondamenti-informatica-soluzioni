// ok

// Esercizio 2. Funzioni Ricorsive (3 punti).

// Si scriva una funzione ricorsiva che, ricevuto come parametro
// un array di interi (e ogni altro parametro ritenuto necessario), individui e restituisca al chiamante il
// numero di valori pari contenuti dell’array.

#include <stdio.h>

int contaPari(int vet[], int n){

    if(n == 0) return 0;

    if(vet[n-1] % 2 == 0)
        return 1 + contaPari(vet, n-1);
    else
        return contaPari(vet, n-1);
}


int main(){

    int v[] = {3, 8, 1, 4, 6, 5, 2, 2, 8, 8, 12, 4};

    const int n = sizeof(v) / sizeof(v[0]);

    int res = contaPari(v, n);
    printf("Numero valori pari trovati: %d \n", res);

    return 0;
}
