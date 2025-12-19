#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.h"

void menu() {
    printf("\n          MENU PRINCIPAL\n");
    printf("-----------------------------------\n");
    printf("1. Calcul de factorielle (Exo 1)\n");
    printf("2. Calcul de puissance (Exo 2)\n");
    printf("3. Permutation de variables (Exo 3a)\n");
    printf("4. Afficher un tableau (Exo 3b)\n");
    printf("5. Resolution d'equation du 2nd degre (Exo 7)\n");
    printf("6. Verifier nombre premier (Exo 12a)\n");
    printf("7. Calculer distance entre points (Exo 13)\n");
    printf("0. Quitter\n");
    printf("-----------------------------------\n");
    printf("Votre choix : ");
}

int main() {
    int choix;
    
    printf("\nPROJET C - Leutchouang Chris Darling - InfoTel3\n");
    printf("Programme interactif de fonctions mathematiques\n");
    
    do {
        menu();
        scanf("%d", &choix);
        
        // Vider le buffer d'entrée
        while (getchar() != '\n');
        
        switch (choix) {
            case 1: { // Factorielle
                unsigned int n;
                printf("\n--- FACTORIELLE ---\n");
                printf("Entrez un nombre entier positif : ");
                scanf("%u", &n);
                printf("Resultat : %u! = %u\n\n", n, factorielle(n));
                break;
            }
            
            case 2: { // Puissance
                int base;
                unsigned int exposant;
                printf("\n--- PUISSANCE ---\n");
                printf("Entrez la base (entier) : ");
                scanf("%d", &base);
                printf("Entrez l'exposant (entier positif) : ");
                scanf("%u", &exposant);
                printf("Resultat : %d^%u = %d\n\n", base, exposant, puissance(base, exposant));
                break;
            }
            
            case 3: { // Permutation
                int a, b;
                printf("\n--- PERMUTATION ---\n");
                printf("Entrez la premiere valeur : ");
                scanf("%d", &a);
                printf("Entrez la deuxieme valeur : ");
                scanf("%d", &b);
                printf("Avant permutation : a = %d, b = %d\n", a, b);
                permuterVariables(&a, &b);
                printf("Apres permutation : a = %d, b = %d\n\n", a, b);
                break;
            }
            
            case 4: { // Tableau
                printf("\n--- TABLEAU ---\n");
                afficherTableau();
                printf("\n");
                break;
            }
            
            case 5: { // Équation du 2nd degré
                double a, b, c;
                printf("\n--- EQUATION DU 2ND DEGRE ---\n");
                printf("Equation de la forme: ax² + bx + c = 0\n");
                printf("Entrez le coefficient a : ");
                scanf("%lf", &a);
                printf("Entrez le coefficient b : ");
                scanf("%lf", &b);
                printf("Entrez le coefficient c : ");
                scanf("%lf", &c);
                resoudreEtAfficherEquation(a, b, c);
                break;
            }
            
            case 6: { // Nombre premier
                unsigned int n;
                printf("\n--- NOMBRE PREMIER ---\n");
                printf("Entrez un nombre entier positif : ");
                scanf("%u", &n);
                if (estNombrePremier(n)) {
                    printf("Resultat : %u est un nombre premier.\n\n", n);
                } else {
                    printf("Resultat : %u n'est pas un nombre premier.\n\n", n);
                }
                break;
            }
            
            case 7: { // Distance entre points
                Point p1, p2;
                printf("\n--- DISTANCE ENTRE POINTS ---\n");
                printf("Point 1 :\n");
                lirePoint(&p1);
                printf("Point 2 :\n");
                lirePoint(&p2);
                
                printf("\nResultat :\n");
                printf("Distance entre ");
                afficherPoint(p1);
                printf(" et ");
                afficherPoint(p2);
                printf(" = %.2f\n\n", distanceEntrePoints(p1, p2));
                break;
            }
            
            case 0: {
                printf("\nAu revoir mr !\n");
                break;
            }
            
            default: {
                printf("\nChoix invalide ! Veuillez reessayer.\n");
                break;
            }
        }
        
        if (choix != 0) {
            printf("Appuyez sur Entree pour continuer...");
            while (getchar() != '\n');
        }
        
    } while (choix != 0);
    
    return EXIT_SUCCESS;
}