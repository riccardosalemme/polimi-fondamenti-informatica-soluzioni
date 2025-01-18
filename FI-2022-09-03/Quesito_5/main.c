// ok

// Esercizio 5. Array (5 punti).

// Si vuole definire una funzione che verifichi la validità di una password. La
// funzione riceve in ingresso la stringa passwd, che rappresenta la password da verificare, un array di
// caratteri, speciali, che memorizza un insieme di caratteri speciali ammessi, e due interi, min e max.
// La funzione quindi verifica che la stringa:
// - sia lunga almeno min caratteri e non superi max caratteri,
// - contenga almeno uno tra i caratteri memorizzati nella stringa speciali.

// Nel caso in cui la password sia valida, la funzione restituisce 1, altrimenti restituisce:
// - -2 se la lunghezza è minore di min,
// - -1 se è maggiore di max,
// - 0 se non contiene caratteri speciali.


#include <stdio.h>
#include <string.h>

int isPasswordValid(char password[], char speciali[], int min, int max){

    int len = strlen(password);
    if(len > max) return -1;
    if(len < min) return -2;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < strlen(speciali); j++){
            if(password[i] == speciali[j]) return 1; // basta ci sia almeno un carattere speciale
        }
    }

    return 0;
}

int main(){

    char password[] = "cndj";
    char speciali[] = "@!_";
    int min = 5, max = 12;

    int res = isPasswordValid(password, speciali, min, max);

    printf("Risultato: %d \n", res); // 1 = password valida

    return 0;
}
