// ok

// Quesito 3 (6 punti). Funzioni Ricorsive.

// Si codifichi ricorsivamente in C una funzione char min_ch( char s[] )cherestituisceilminimocaratteredi s
// (nel consueto ordine alfabetico). E’ necessario, per il punteggio pieno, che il risultato sia individuato
// con il metodo ricorsivo.

#include <stdio.h>
#include <string.h>

char min_ch(char s[]){

    // L'idea della funzione è restringere s ad ogni chiamata successiva mantenendo il carattere minore tra gli ultimi due

    const int len = strlen(s);
    if(len == 1) return s[0]; // se ho un carattere rimanente finisco le ripetizioni

    char new_str[len-1]; // nuova stringa (ha un carattere in meno di s)
    strncpy(new_str, s, len-1);

    if(s[len-1] < s[len-2]) // verifico tra gli ultimi due caratteri quale è il minore
        new_str[len-2] = s[len-1]; // -> decido di tenermi il minore (quindi se necessario scambio)

    return min_ch(new_str);
}

int main(){

    printf("%c \n", min_ch("ciao"));

    return 0;
}
