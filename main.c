#include <stdio.h>
#include <stdlib.h>

typedef struct canzone {
    char *name;
    char *artista;
    int min;
    int sec;
}canzone;

static int denision = 5;

void aggiunta();

void visualizzaPlay();

int length();

int main(void) {
    canzone *libraries = (canzone *) malloc(denision * sizeof(canzone));

    printf("premi 1 per: Aggiungi una canzone.\n");
    printf("Premi 2 per: Visualizza libreria.\n");
    printf("Premi qualsiasi tasto per uscire.\n");
    int denio = 0;
    scanf("%d", &denio);
    switch (denio) {
        case 1:
            aggiunta(libraries);
            break;
        case 2:
            visualizzaPlay(libraries);
            break;
        default:
            return 0;
    }

    free(libraries);
    return 0;
}

void aggiunta(canzone **lib) {
    int denis = length(**lib);
    if (denis > denision) {
        denision = denision * 2;
        realloc(lib, denision * sizeof(canzone *));
    }
    printf("Inserisci in input il nome della canzone: \n");
    fgets(lib[denis]->name, 100, stdin);
    printf("Inserisci in input il nome dell'artista: \n");
    fgets(lib[denis]->artista, 100, stdin);
    printf("Inserisci in input i minuti della canzone: \n");
    scanf("%d", &lib[denis]->min);
    printf("Inserisci in input i second della canzone: \n");
    scanf("%d", &lib[denis]->sec);
}

void visualizzaPlay(canzone **lib) {
    int denis = length(**lib);
    for (int i = 0; i < denis; i++) {
        printf("Nome della canzone: %s\n",lib[i]->name);
        printf("Nome della artista: %s\n",lib[i]->artista);
        printf("Minuti della conzone: %d\n",lib[i]->min);
        printf("Secondi della canzone: %d",lib[i]->sec);
    }
}

int length(canzone **str) {
    int i = 0;
    for (i; str[i] != NULL; i++);
    return i;
}