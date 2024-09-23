#include <stdio.h>
#include <string.h>git add README.md
#define MAX 100

typedef struct {
    char reference[20];
    char marque[20];
    int capaciteMemoire;  
    int capaciteDisque;  
    char systemeExploitation[20];
} Ordinateur;

void Ajouter(Ordinateur TO[], int *n) {
    if (*n >= MAX) {
        printf("Tableau plein, impossible d'ajouter.\n");
        return;
    }

    printf("Ajout d'un nouvel ordinateur :\n");
    printf("Référence : ");
    scanf("%s", TO[*n].reference);
    printf("Marque : ");
    scanf("%s", TO[*n].marque);
    printf("Capacité Mémoire (en Go) : ");
    scanf("%d", &TO[*n].capaciteMemoire);
    printf("Capacité Disque (en Go) : ");
    scanf("%d", &TO[*n].capaciteDisque);
    printf("Système d'Exploitation : ");
    scanf("%s", TO[*n].systemeExploitation);

    (*n)++;  
}

void Afficher(Ordinateur TO[], int n) {
    if (n == 0) {
        printf("Aucun ordinateur à afficher.\n");
        return;
    }

    printf("Liste des ordinateurs :\n");
    for (int i = 0; i < n; i++) {
        printf("Ordinateur %d :\n", i + 1);
        printf("Référence : %s\n", TO[i].reference);
        printf("Marque : %s\n", TO[i].marque);
        printf("Mémoire : %d Go\n", TO[i].capaciteMemoire);
        printf("Disque : %d Go\n", TO[i].capaciteDisque);
        printf("Système d'exploitation : %s\n", TO[i].systemeExploitation);
        printf("-----------------------------\n");
    }
}

void Modifier(Ordinateur TO[], int n) {
    char reference[20];
    printf("Entrez la référence de l'ordinateur à modifier : ");
    scanf("%s", reference);

    for (int i = 0; i < n; i++) {
        if (strcmp(TO[i].reference, reference) == 0) {  
            scanf("%s", TO[i].marque);
            printf("Nouvelle capacité Mémoire (en Go) : ");
            scanf("%d", &TO[i].capaciteMemoire);
            printf("Nouvelle capacité Disque (en Go) : ");
            scanf("%d", &TO[i].capaciteDisque);
            printf("Nouveau système d'exploitation : ");
            scanf("%s", TO[i].systemeExploitation);
            printf("Modification effectuée avec succès.\n");
            return;
        }
    }
    printf("Ordinateur non trouvé.\n");
}

void Supprimer(Ordinateur TO[], int *n) {
    char reference[20];
    
    printf("Entrez la référence de l'ordinateur à supprimer : ");
    scanf("%s", reference);

    for (int i = 0; i < *n; i++) {
        if (strcmp(TO[i].reference, reference) == 0) {
            for (int j = i; j < *n - 1; j++) {
                TO[j] = TO[j + 1];  
            }
            
         
            (*n)--;
            
            printf("Ordinateur supprimé avec succès.\n");
            return;  
        }
    }
    printf("Ordinateur non trouvé.\n");
}
void Trier(Ordinateur TO[], int n) {
    Ordinateur temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(TO[i].reference, TO[j].reference) > 0) {
                temp = TO[i];
                TO[i] = TO[j];
                TO[j] = temp;
            }
        }
    }
    printf("Tableau trié par référence.\n");
}

void Sauvegarder(Ordinateur TO[], int n) {
    FILE *fichier = fopen("ordinateurs.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fichier, "%s %s %d %d %s\n", TO[i].reference, TO[i].marque, TO[i].capaciteMemoire, TO[i].capaciteDisque, TO[i].systemeExploitation);
    }
    fclose(fichier);
    printf("Les ordinateurs ont été sauvegardés dans le fichier 'ordinateurs.txt'.\n");
}

void Lire(Ordinateur TO[], int *n) {
    FILE *fichier = fopen("ordinateurs.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    *n = 0;
    while (fscanf(fichier, "%s %s %d %d %s", TO[*n].reference, TO[*n].marque, &TO[*n].capaciteMemoire, &TO[*n].capaciteDisque, TO[*n].systemeExploitation) != EOF) {
        (*n)++;
    }
    fclose(fichier);
    printf("Les ordinateurs ont été chargés depuis le fichier 'ordinateurs.txt'.\n");
}

int main() {
    Ordinateur TO[MAX];  
    int n = 0;  
    int choix;

    do {
        printf("\n\t *** Menu ***\n");
        printf("1. Ajouter un ordinateur\n");
        printf("2. Afficher tous les ordinateurs\n");
        printf("3. Modifier un ordinateur\n");
        printf("4. Supprimer un ordinateur\n");
        printf("5. Trier le tableau\n");
        printf("6. Sauvegarder les ordinateurs\n");
        printf("7. Lire les ordinateurs\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter(TO, &n);
                break;
            case 2:
                Afficher(TO, n);
                break;
            case 3:
                Modifier(TO, n);
                break;
            case 4:
                Supprimer(TO, &n);
                break;
            case 5:
                Trier(TO, n);
                break;
            case 6:
                Sauvegarder(TO, n);
                break;
            case 7:
                Lire(TO, &n);
                break;
            case 8:
                printf("Quitter le programme...\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
        }
    } while (choix != 8);

    return 0;
}
