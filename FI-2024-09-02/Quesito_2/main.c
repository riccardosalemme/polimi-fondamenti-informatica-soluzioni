#include <stdio.h>
#include <stdlib.h>

// OK

// Scrivere una funzione ricorsiva in C che, ricevuto come parametro un numero intero positivo n, costruisce e
// restituisce un nuovo numero ottenuto sostituendo a ciascuna cifra di n la sua successiva. N.B.: la cifra 9 viene
// sostituita con 0.
//
// Es: Se n = 34979, allora la funzione restituisce il valore 45080
//
// N.B.: Per il punteggio pieno è necessario che il risultato sia individuato ricorsivamente. Una soluzione
// sostanzialmente iterativa varrà al più 4 punti.

int sostituisciRicorsivo(int n){

    if(n <= 0) return 0; // Caso base

    // Incremento l'ultima cifra (considerando che 9 -> 0)
    int ultima_cifra = n % 10;
    if(ultima_cifra < 9) ultima_cifra++;
    else ultima_cifra = 0;

    // printf("cifra: %d \n", ultima_cifra);

    return ultima_cifra + sostituisciRicorsivo(n/10) * 10;
}

int sostituisciIterativo(int n){
    int ultima_cifra, risultato = 0, molt = 1;

    while (n > 0) {
        ultima_cifra = n % 10; // estraggo l'ultima cifra
        n /= 10;

        // Incremento l'ultima cifra (considerando che 9 -> 0)
        if(ultima_cifra < 9) ultima_cifra++;
        else ultima_cifra = 0;

        risultato += ultima_cifra * molt;
        molt *= 10;
    }

    return risultato;

}

int main(int argc, char *argv[]){

    int n = 3476;

    int resRi = sostituisciRicorsivo(n);
    int resIt = sostituisciIterativo(n);

    printf("Risultato ricorsivo: %d \n", resRi);
    printf("Risultato itarativo: %d \n", resIt);

    return 0;

}
