#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// ok

// Si codifichi ricorsivamente in C una funzione int distingui( char s[], char up[], char low[]) che riceve una stringa s (da
// analizzare) e due stringhe inizialmente vuote, ma già allocate e di dimensione pari a quella di s. La funzione dovrà
// (i) copiare nelle stringhe up e low i caratteri alfabetici rispettivamente maiuscoli e minuscoli di s, nello stesso ordine
// in cui compaiono in s, e (ii) restituire al chiamante il numero di caratteri non alfabetici di s (non copiati). Esempio:
// con s[] = "2Ew?jm7y9TR£" avremmo up[] = " ETR", low[] = "wjmy", valore restituito: 5 (caratteri 2 ? 7 9 e £ ).
// Per il punteggio pieno è necessario che il risultato sia individuato ricorsivamente . Una soluzione sostanzialmente
// iterativa varrà al più 4 punti.

int distingui(char s[], char up[], char low[]){

    if(s[0] == '\0')  // caso base: stringa vuota
        return 0;

    if(isupper(s[0])) {
        up[0] = s[0];
        return distingui(s+1, up+1, low);
    } else if (islower(s[0])) {
        low[0] = s[0];
        return distingui(s+1, up, low+1);
    } else {
        return 1 + distingui(s+1, up, low);
    }
}

int main(int argc, char *argv[]){

    char str[50] = "ci22TTr98-erWSA";
    char low[50], up[50];

    int caratteri_non_alfabetici = distingui(str, up, low);

    printf("Upper: %s \n", up);
    printf("Lower: %s \n", low);
    printf("Non alfabetici: %d \n", caratteri_non_alfabetici);

    return 0;
}
