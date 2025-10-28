#include <stdio.h>
#include <stdlib.h>

typedef struct canzone {
    char name[100];
    char artista[100];
    int min;
    int sec;
} canzone;

static int denision = 5;
static int count = 0;

void aggiunta(canzone *lib);
void visualizzaPlay(canzone *lib);

void rimuovi_n(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

int main(void) {
    canzone *libraries = (canzone *) malloc(denision * sizeof(canzone));
    int denisio = 0;
    while (denisio == 0) {
        int denio = 0;
        printf("Premi 1 per: Aggiungi una canzone.\n");
        printf("Premi 2 per: Visualizza libreria.\n");
        printf("Premi qualsiasi tasto per uscire.\n");
        if (scanf("%d", &denio) != 1) {
            free(libraries);
            return 0;
        }
        getchar(); // leva dal buffer /n

        switch (denio) {
            case 1:
                aggiunta(libraries);
                break;
            case 2:
                visualizzaPlay(libraries);
                break;
            default:
                free(libraries);
                return 0;
        }
    }
}

void aggiunta(canzone *lib) {
    if (count >= denision) {
        denision *= 2;
        lib = realloc(lib, denision * sizeof(canzone));
        if (lib == NULL) {
            printf("Errore realloc\n");
            exit(1);
        }
    }

    printf("Inserisci il nome della canzone: ");
    fgets(lib[count].name, 100, stdin);
    rimuovi_n(lib[count].name);

    printf("Inserisci il nome dell'artista: ");
    fgets(lib[count].artista, 100, stdin);
    rimuovi_n(lib[count].artista);

    printf("Inserisci i minuti della canzone: ");
    scanf("%d", &lib[count].min);
    printf("Inserisci i secondi della canzone: ");
    scanf("%d", &lib[count].sec);
    getchar();

    count++;
}

void visualizzaPlay(canzone *lib) {
    if (count == 0) {
        printf("La libreria è vuota.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nCanzone %d:\n", i + 1);
        printf("Nome: %s\n", lib[i].name);
        printf("Artista: %s\n", lib[i].artista);
        printf("Durata: %d:%02d\n", lib[i].min, lib[i].sec);
    }
}
