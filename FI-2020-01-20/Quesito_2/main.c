#include <stdio.h>
#include <stdlib.h>

// ok

// Si scriva una funzione ricorsiva che, ricevuti come parametri un array di interi, a, un intero
// positivo, val, e altri parametri eventualmente ritenuti necessari, restituisce 1 se il numero d
// i valori negativi in a è maggiore di val, 0 altrimenti.

int contaNegativi(int a[], int len, int val){

    // Caso base: array vuoto (len = 0)
    if (len == 0 && val >= 0)
        return 0;
    else if (len == 0 && val < 0)
        return 1; // numero negativi > val inserito

    // if (a[0] < 0) {
    //     return contaNegativi(a+1, len-1, val-1);
    // } else {
    //     return contaNegativi(a+1, len-1, val);
    // }

    if (a[0] < 0)
        val--;
    return contaNegativi(a+1, len-1, val);
}

void stampaArray(int a[], int len){
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d  ", a[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[]){

    int a[] = {-3, 4, -1, 2, -7};
    int len = sizeof(a) / sizeof(a[0]);
    int val1 = 3, val2 = 4, val3 = 2;

    int ris1 = contaNegativi(a, len, val1);
    int ris2 = contaNegativi(a, len, val2);
    int ris3 = contaNegativi(a, len, val3);

    printf("Array di lunghezza %d \n", len);
    stampaArray(a, len);

    printf("Risultato con val = %d: %d \n", val1, ris1);
    printf("Risultato con val = %d: %d \n", val2, ris2);
    printf("Risultato con val = %d: %d \n", val3, ris3);

    return 0;
}
