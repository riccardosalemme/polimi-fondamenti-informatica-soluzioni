#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ok


#define MAX_FILENAME 200

const int Anno[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// definizione nuovo tipo
struct _Data {
    int giorno; // 1 -> 31
    int mese; // 1 -> 12
};
typedef struct _Data Data;

// Differenza tra due date

int diffDate(Data a, Data b){

    // date valide per il 2024
    if(!(a.mese >= 1 && a.mese <= 12 && b.mese >= 1 && b.mese <= 12))
        return -1; // mese errato

    if(!(a.giorno >= 1 && a.giorno <= Anno[a.mese-1] && b.giorno >= 1 && b.giorno <= Anno[b.mese-1]))
        return -1; // giorno non valido per l'anno in corso

    // a precedente a b
    if(a.mese > b.mese)
        return -1; // a non è precedente a b
    else if(a.mese == b.mese && a.giorno > b.giorno)
        return -1; // a non è precedente a b

    // calcolo la differenza in giorni

    if(a.mese == b.mese){ // se il mese è lo stesso faccio solo la differenza dei giorni
        return b.giorno - a.giorno;
    }

    int giorni_diff = 0;
    giorni_diff += Anno[a.mese-1] - a.giorno;

    for(int i = a.mese; i < b.mese-1; i++)
        giorni_diff += Anno[i];

    giorni_diff += b.giorno;

    return giorni_diff;
}

int main(int argc, char *argv[]){

    char filename[MAX_FILENAME] = "soggiorni.txt";
    FILE *file;

    // Lettura del nome del file da riga di comando
    if (argc != 2) {
        printf("Programma eseguito senza i parameti adeguati \n");
        return -1;
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Impossibile aprire il file! \n");
        return -1;
    }

    printf("File aperto correttamente \n");

    int numero_soggiorni = 0;
    long tempo_medio_soggiorno = 0;

    while (!feof(file)) {
        Data a, b;
        if(fscanf(file, "%d %d %d %d \n", &a.giorno, &a.mese, &b.giorno, &b.mese) == 4){
            int diff = diffDate(a, b);
            if(diff < 0){
                printf("Date ignorate \n");
            }else{
                printf("Durata soggiorno %d: %d \n", numero_soggiorni+1, diff);
                tempo_medio_soggiorno += diff;
                numero_soggiorni++;
            }
        }
    }

    printf("Durata soggiorno medio (in giorni): %.0lf (arrotondato a 0 cifre decimali) \n", tempo_medio_soggiorno / (float)numero_soggiorni);

    fclose(file);

    return 0;
}
