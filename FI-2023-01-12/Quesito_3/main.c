// ok

// Quesito 3. (12 punti).

// Si vuole definire un programma in C che aiuti la mamma a capire se una ricetta può essere preparata con gli
// ingredienti disponibili in cucina. Il programma fa uso di due file:

// ● Un primo file di testo contiene la lista e la quantità degli alimenti disponibili in cucina. Ogni riga riporta
// il nome di un alimento (una stringa di max 20 caratteri) e la quantità disponibile in cucina (un numero
// intero). Si può assumere che il file memorizzi al massimo N alimenti (N costante).

// ● Un secondo file di testo contiene gli ingredienti necessari per la ricetta. Ogni riga riporta il nome di un
// ingrediente (una stringa di max 20 caratteri) e la quantità necessaria (un numero intero).

// Il programma deve confrontare le quantità richieste dalla ricetta con quelle disponibili; quindi, per ogni
// ingrediente della ricetta indica se esso sia disponibile o meno. Infine, il programma produce un messaggio che
// dice se la ricetta scelta può essere preparata o no.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

struct _Product{
    char name[MAX_LEN];
    int qta;
} ;
typedef struct _Product Product;

bool readFile(char filename[], Product elements[], int *n){

    FILE *file = fopen(filename, "r");
    if(file == NULL) return false;

    int count = 0;

    // suppongo che i nomi degli ingredienti non abbiano spazi (siano una sola parola)
    while (fscanf(file, "%s %d", elements[count].name, &elements[count].qta) == 2) {
        count++;
    }

    *n = count;

    fclose(file);

    return true;
}

void printProducts(Product elements[], int n){
    for(int i = 0; i < n; i++){
        printf("- %s %d \n", elements[i].name, elements[i].qta);
    }
}

#define MAX_PRODUCTS 100

int main(){

    Product pantry[MAX_PRODUCTS], recipe[MAX_PRODUCTS];
    int pantry_count, recipe_count;

    if(readFile("ricetta.txt", recipe, &recipe_count) && readFile("dispensa.txt", pantry, &pantry_count)){
        printf("File aperti correttamente... \n");
    }else{
        printf("Impossibile aprire i file! \n");
        return -1;
    }

    printf("Proodotti per la ricetta: \n");
    printProducts(recipe, recipe_count);
    printf("Proodotti in dispensa: \n");
    printProducts(pantry, pantry_count);

    // Verifica ricetta
    bool valid = true;
    for(int i = 0; i < recipe_count; i++){
        bool found = false;
        for(int j = 0; j < pantry_count && !found; j++){
            if(strcmp(recipe[i].name, pantry[j].name) == 0){
                found = true;
                if(recipe[i].qta <= pantry[j].qta){
                    printf("%s: OK \n", recipe[i].name);
                }else{
                    printf("%s: manaca %d \n", recipe[i].name, recipe[i].qta - pantry[j].qta);
                    valid = false;
                }
            }
        }
        if(!found){
            printf("%s: manaca %d \n", recipe[i].name, recipe[i].qta);
        }
    }

    printf(valid ? "La ricetta può essere preparata \n" : "La ricetta NON può essere preparata \n");


    return 0;
}
