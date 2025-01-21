#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

// ok

// Punto 1 (9 punti).

// Si codifichi in C una funzione void ripulisci(FILE * fin, FILE * fout) che riceve dal chiamante due file testuali (già aperti) (fin in modalità lettura e contenente l’elenco dei prodotti potenzialmente duplicati, fout in modalità scrittura e inizialmente vuoto), individua e unifica i prodotti duplicati, e salva in fout l'elenco compattato.
// Attenzione:
// - Nel leggere il file in input la funzione si troverà verosimilmente a riversare i dati in una qualche struttura
// dati; si badi a progettarla in modo conveniente e a definirla in modo chiaro e comprensibile.
// - Si può considerare definito un limite al numero di diversi prodotti inseribili(#define MAX_PROD 100) .
// - Si ipotizzi che le linee del file di input siano sempre ben formate (con una stringa e un intero).
// - Il file di output conterrà un nuovo elenco, senza linee duplicate, sostituite da un’unica linea con quantità
// uguale alla somma delle quantità di tutti i duplicati eliminati. Dall’esempio riportato sopra si otterrà:
// mele 7 pere 3 pane 1 pesto 2 olio 1

// Punto 2 (3 punti).

// Si codifichi un programma C (main) che riceve da linea di comando i nomi dei due file, invoca la funzione definita al punto precedente e stampa un messaggio per comunicare l’esito dell’operazione.
// Si chiede di gestire esplicitamente gli eventuali errori nei parametri del main e nell’apertura del file.

#define MAX_PROD 100
#define MAX_PROD_NAME 50

struct _CartProduct{
    char name[MAX_PROD_NAME];
    int qty;
};
typedef struct _CartProduct CartProduct;

void ripulisci(FILE * fin, FILE * fout){

    CartProduct products[MAX_PROD];
    int index = 0, qty;
    char name[MAX_PROD_NAME];

    // for (int i = 0; !feof(fin) && fscanf(fin, "%s %d", products[i].name, &products[i].qty) != 2; i++);

    while (!feof(fin) && fscanf(fin, "%s %d", name, &qty) == 2) {

        // cerco se il prodoto è già stato salvato
        bool found = false;
        for (int i = 0; i < index && !found; i++) {
            if (strcmp(products[i].name, name) == 0) {
                products[i].qty += qty;
                found = true;
            }
        }
        // aggiungo il prodotto se questa è la prima occorrenza
        if (!found) {
            strcpy(products[index].name, name);
            products[index].qty = qty;
            index++;
        }
    }

    // salvo l'elenco dei prodotti ripulito
    for (int i = 0; i < index; i++) {
        fprintf(fout, "%s %d \n", products[i].name, products[i].qty);
    }

}

int main(int argc, char* argv[]){

    FILE *fin, *fout;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Impossibile aprire il file di input \n");
        return -1;
    }
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Impossibile aprire il file di output \n");
        return -1;
    }

    ripulisci(fin, fout);

    fclose(fin);
    fclose(fout);




    return 0;
}
