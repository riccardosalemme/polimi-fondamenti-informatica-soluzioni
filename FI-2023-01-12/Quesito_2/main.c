#include <stdio.h>
#include <stdlib.h>

// ok

// Quesito 2 (5 punti)

// Si definisca una funzione ricorsiva che, ricevuti come parametri un array di interi, a, due valori interi, x e y, e
// qualsiasi altro parametro ritenuto necessario, restituisca:
// - il numero di volte in cui x è seguito da y, oppure
// - il valore -1 nel caso in cui l’array non contenga alcuna occorrenza di x.

// Per esempio, dato l’larray a[8]= {5,3,2,5,3,5,3,3},
// - se x = 5 e y = 3 la funzione restituirà 3
// - se x = 5 e y = 4 la funzione restituirà 0
// - se x = 4, e quindi x non è presente nell’array, la funzione restituirà il valore -1


int seguito(int a[], int n, int x, int y) {

    // caso base
    if (n <= 1) { // ho un solo elemnto rimanente
        if (a[0] != x) {
            return -1;
        } else {
            return 0;
        }
    }

    // se trovo che x è seguito da y allora controllo se dopo questi due elementi ho altri casi favorevoli
    // se si, restituisco il numero dei successivi favorevoli + 1 (il caso corrente)
    // se no, restituisco comunque 1 perchè ho almeno un'occorrenza del caso favorevole
    if (a[0] == x && a[1] == y) {
        int next = seguito(a+2, n-2, x, y);
        if (next > 0) {
            return next + 1;
        } else {
            return 1;
        }
    }

    // se non trovo un caso favorevole controllo se successivamente ce ne sono (guardo all'elemento immediamtamente successivo)
    // se non ho casi favorevoli (next < 0) ma ho trovato alemeno nel caso corrente x restituisco 0
    // altrimenti restituisco il numero dei casi favorevoli dopo l'elemnto corrente
    else {
        int next = seguito(a+1, n-1, x, y);
        if (next < 0 && a[0] == x) {
            return 0;
        } else {
            return next;
        }
    }

}

int main() {

    const int n = 8;
    int a[n]= {5, 3, 2, 5, 3, 5, 3, 3};

    int x = 5;
    int y = 12;

    int ris = seguito(a, n, x, y);
    printf("x = %d è seguito da y = %d esattamente %d volte \n", x, y, ris);

    return 0;
}
