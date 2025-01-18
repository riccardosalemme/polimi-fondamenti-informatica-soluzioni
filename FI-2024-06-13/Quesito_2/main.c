#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ok

// Un file testuale contiene informazioni sulla provenienza dei partecipanti a un congresso
// scientifico: ogni riga, nel formato cognome nazione , riguarda un diverso partecipante. Dal
// file, esemplificato a lato, si vuole estrarre una struttura dati che a ciascuna nazione associ
// il numero di partecipanti da essa provenienti

// Si codifichi in C una funzione … provenienze( FILE * fp, … ) che riceve un file (già aperto in
// modalità lettura ) e rende disponibile all’ambiente chiamante una opportuna struttura dati
// (da definire) che contiene le coppie ⟨nazione, numero_partecipanti ⟩. Si consideri, per
// semplicità, che il file sia sempre ben formato (ogni riga, cioè, ha sempre esattamente due stringhe, ciascuna di
// massimo 25 caratteri).

// Si codifichi in C un programma (main) che, ricevuto da linea di comando il nome di un file come quello d’esempio,
// lo apre, invoca la funzione sopra definita, e stampa opportunamente su stdout le statistiche calcolate dall’invocazione.
// Si gestiscano gli eventuali errori nei parametri del main e nell’apertura del file.

#define MAX_STR_LEN     25
#define MAX_RECORDS     100

struct _Provenienze {
    char nazione[MAX_STR_LEN];
    unsigned int numero;
};
typedef struct _Provenienze Provenienze;

int provenienze(FILE *fp, Provenienze records[]){

    char nome[MAX_STR_LEN], paese[MAX_STR_LEN];
    int count_provenienze = 0;

    for (int i = 0; !feof(fp) && i < MAX_RECORDS; i++) {
        fscanf(fp, "%s %s \n", nome, paese);

        // printf("Nome: %s Paese: %s \n", nome, paese);

        bool found = false;
        for (int j = 0; j < count_provenienze && !found; j++) {
            if (strcmp(records[j].nazione, paese) == 0) {
                records[j].numero++;
                found = true;
            }
        }
        if (!found) {
            strcpy(records[count_provenienze].nazione, paese);
            records[count_provenienze].numero = 1;
            count_provenienze++;
        }

    }

    return count_provenienze;
}

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Impossibile eseguire il programma. Non è sato passato il parametro come richiesto \n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Impossibile aprire il file specificato \n");
        return -1;
    }

    Provenienze records[MAX_RECORDS];
    int count_provenienze = provenienze(file, records);

    printf("Statistiche: \n");
    for (int i = 0; i < count_provenienze; i++) {
        printf("- %s : %d \n", records[i].nazione, records[i].numero);
    }

    fclose(file);

    return 0;
}
