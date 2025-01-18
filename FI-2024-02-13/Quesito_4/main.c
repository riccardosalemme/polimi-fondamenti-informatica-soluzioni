#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ok

// Dopo aver opportunamente definito i tipi di dati atti a rappresentare una lista dinamica di valori interi, si
// scriva una funzione Lista MaggioriDiTuttiISuccessori(Lista pL) che, ricevendo la testa
// di una lista dinamica di interi, la modifica eliminando da essa ciascun elemento E che sia minore di almeno
// uno degli elementi successivi a E.
// Per esempio, se lista passata al sottoprogramma è
// L->3->32->4->6->3->20->17->2->17->9->7->1⬎ , la lista modificata è L->32->20->17->17->9->7->1⬎
// La funzione restituisce al chiamante la testa della lista modificata.

typedef struct nd {
    int valore;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

Lista MaggioriDiTuttiISuccessori(Lista pL) {

    if (pL == NULL) return pL; // Interrompo se la lista è vuota

    Lista tmp, current = pL;

    while (current->next != NULL) {

        tmp = current->next;
        bool flag = false;

        while (tmp != NULL && !flag) { // guardo i nodi successivi; interrompo se trovo un valore maggiore di quello del nodo corrente
            if (tmp->valore > current->valore)
                flag = true;
            tmp = tmp->next;
        }

        if (flag) { // ho trovato un valore più grande -> elimino tale nodo
            current->valore = current->next->valore;
            current->next = current->next->next;
        } else { // non ho trovato un valore più granda -> passo al nodo successivo
            current = current->next;
        }
    }

    return pL;
}

void printList(Lista lis);
void addToList(Lista *lis, int val);

int main(int argc, char *argv[]) {

    Lista lista = NULL;
    addToList(&lista, 3);
    addToList(&lista, 32);
    addToList(&lista, 4);
    addToList(&lista, 6);
    addToList(&lista, 3);
    addToList(&lista, 20);
    addToList(&lista, 17);
    addToList(&lista, 2);
    addToList(&lista, 17);
    addToList(&lista, 9);
    addToList(&lista, 7);
    addToList(&lista, 1);


    printf("Lista originale:  ");
    printList(lista);


    lista = MaggioriDiTuttiISuccessori(lista);

    printf("Lista modificata: ");
    printList(lista);

    return 0;
}


void addToList(Lista *lis, int val){
    // Primo elemento
    if(*lis == NULL){
        *lis = (Lista) malloc(sizeof(Nodo));
        (*lis)->valore = val;
        (*lis)->next = NULL;
        return;
    }

    // Successivi
    Lista tmp = *lis;

    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = (Lista) malloc(sizeof(Nodo));
    tmp->next->next = NULL;
    tmp->next->valore = val;
}

void printList(Lista lis){
    Lista tmp = lis;
    while(tmp != NULL){
        printf("%2d -> ", tmp->valore);
        tmp = tmp->next;
    }
    printf("END \n");
}
