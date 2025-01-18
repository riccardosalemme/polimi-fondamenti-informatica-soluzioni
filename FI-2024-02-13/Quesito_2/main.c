#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ok

#define MAX_LEN_COD         5       // 4+1 (ricordare il carattere terminatore per le stringhe)

int minutiLavorati(FILE *file, char cod[MAX_LEN_COD]) {

    char codLetto[MAX_LEN_COD];
    int ora, min, entrata = -1, uscita = -1;

    bool found = false;
    while (!feof(file) && !found) {
        fscanf(file, "%d %d %s", &ora, &min, codLetto);
        if (strcmp(codLetto, cod) == 0) {
            if (entrata < 0) {
                entrata = ora * 60 + min;
            } else {
                uscita = ora * 60 + min;
                found = true;
            }
        }
    }

    return uscita - entrata;
}


void stampaFile(FILE *file) {

    char codLetto[MAX_LEN_COD];
    int ora, min;

    while (!feof(file)) {
        fscanf(file, "%d %d %s \n", &ora, &min, codLetto);
        printf("Dipendente: %5s | Orario: %2d:%2d \n", codLetto, ora, min);
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 3) {
        printf("Programma invocato con i parametri errati \n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Impossibile aprire il file \n");
        return -1;
    }

    if (argc == 2) { // restituisco l'intero contenuto del file
        stampaFile(file);
    } else if (argc == 3) { // restituisco i minuti lavorati per dipendente
        int minLavorati = minutiLavorati(file, argv[2]);
        if (minLavorati == 0) {
            printf("Dipendente non trovato \n");
        } else {
            printf("Minuti lavorati per il dipendente %5s: %d minuti \n", argv[2], minLavorati);
        }
    }

    fclose(file);

    return 0;
}
