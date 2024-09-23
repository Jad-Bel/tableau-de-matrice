#include <stdio.h>
#include <math.h>
#define MAX 50
int i, j;  

void remplirMatrice(int mat[MAX][MAX], int lignes, int colonnes) {
    for(i = 0; i < lignes; i++) {
        for(j = 0; j < colonnes; j++) {
            printf("Entrer l'élément de la matrice [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);  
        }
    }
}

void afficheMatrice(int mat[MAX][MAX], int lignes, int colonnes) {
    printf("Voici votre matrice:\n");
    for(i = 0; i < lignes; i++) {
        for(j = 0; j < colonnes; j++) {
            printf("%d\t", mat[i][j]);  
        }
        printf("\n"); 
    }
}

int sommeLigne(int mat[MAX][MAX], int colonnes, int ligne) {
    int somme = 0;  
    for(j = 0; j < colonnes; j++) {
        somme += mat[ligne][j];  
    }
    return somme;
}

int sommeColonne(int mat[MAX][MAX], int lignes, int colonne) {
    int somme = 0;
    for(i = 0; i < lignes; i++) {
        somme += mat[i][colonne];  
    }
    return somme;
}

int produitMatrice(int mat[MAX][MAX], int lignes, int colonnes) {
    int produit = 1;
    for(i = 0; i < lignes; i++) {
        for(j = 0; j < colonnes; j++) {
            produit *= mat[i][j];  
        }
    }
    return produit;
}

void multiplierMatricePourReel(int mat[MAX][MAX], int lignes, int colonnes, float reel) {
    printf("Matrice après multiplication par %.2f:\n", reel);
    for(i = 0; i < lignes; i++) {
        for(j = 0; j < colonnes; j++) {
            printf("%.2f\t", mat[i][j] * reel); 
        }
        printf("\n");
    }
}

int main() {
    int mat[MAX][MAX];  
    int lignes, colonnes;
    float reel;
    
    printf("Entrer le nombre de lignes: ");
    scanf("%d", &lignes);
    printf("Entrer le nombre de colonnes: ");
    scanf("%d", &colonnes);

    remplirMatrice(mat, lignes, colonnes);

    afficheMatrice(mat, lignes, colonnes);

    int ligne;
    printf("Entrer le numéro de la ligne à sommer: ");
    scanf("%d", &ligne);
    printf("Somme de la ligne %d: %d\n", ligne, sommeLigne(mat, colonnes, ligne));

    int colonne;
    printf("Entrer le numéro de la colonne à sommer: ");
    scanf("%d", &colonne);
    printf("Somme de la colonne %d: %d\n", colonne, sommeColonne(mat, lignes, colonne));

    printf("Produit de la matrice: %d\n", produitMatrice(mat, lignes, colonnes));

    printf("Entrer un nombre réel pour multiplier la matrice: ");
    scanf("%f", &reel);
    multiplierMatricePourReel(mat, lignes, colonnes, reel);

    return 0;
}
