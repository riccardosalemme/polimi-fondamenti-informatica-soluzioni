#include <stdio.h>
#include <stdlib.h>

// ok

// Si definisca una funzione ricorsiva int coppie(int n) che restituisce il numero di coppie di cifre
// uguali in posizioni adiacenti presenti nel numero n. Nel caso n sia negativo restituisce 0.
// Esempi: coppie(772211) restituisce 3, coppie(2344) restituisce 1, coppie(2) restituisce 0,
// coppie(888) restituisce 2.

int coppie (int n){

    if (n <= 0) return 0;

    int ultima_cifra = n % 10;
    int penultima_cifra = (n/10) % 10;

    if (ultima_cifra == penultima_cifra) {
        return 1 + coppie(n / 100);
    } else {
        return coppie(n / 10);
    }

}

int main(int argc, char *argv[]) {

    int n = 1133422288;

    int numero_coppie = coppie(n);
    printf("Numero coppie: %d \n", numero_coppie);

    return 0;
}
