#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// ok

// (6 punti) Si definisca una funzione che, ricevuto come parametro il puntatore a un file di testo (e qualsiasi altro
// parametro ritenuto necessario), determini quale dei 26 caratteri minuscoli dell’alfabeto compare nel file con
// maggiore frequenza. Il programma restituisce all’ambiente chiamante il carattere e la sua frequenza.

// (2 punti) Scrivere un programma che acquisisce il nome del file di testo da riga di comando. Quindi, dopo aver
// aperto il file, richiama la funzione definita al punto precedente e stampa i valori restituiti.


char carattereFrequente(FILE *file) {

    const int lunghezzaAlfabeto = 'z' - 'a'; // 26
    char contaCaratteri[lunghezzaAlfabeto];
    for (int i = 0; i < lunghezzaAlfabeto; i++) // inizializzo l'array
        contaCaratteri[i] = 0;


    while (!feof(file)) {
        char c = fgetc(file);
        if(isalpha(c) && islower(c)){ // considero solo i caratteri alfabetici minuscoli
            contaCaratteri[c - 'a'] += 1;
        }
    }

    int maxC = 0, maxN = contaCaratteri[0];
    for (int i = 0; i < lunghezzaAlfabeto; i++) {
        if (contaCaratteri[i] > maxN) {
            maxN = contaCaratteri[i];
            maxC = i;
        }
    }

    return 'a' + maxC;
}


int main(int argc, char *argv[]){

    if (argc != 2) {
        printf("Non sono stati passati i paramteri necessari \n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Impossibile aprire il file specificato \n");
        return -1;
    }

    char c = carattereFrequente(file);
    printf("Il carattere più frequente nel file è: %c \n", c);


    fclose(file);

    return 0;
}
