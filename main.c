#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.h"

int main(void) {
    // factorielle , puissance , permutation 
    printf("========== EXERCICES 1-3 ==========\n\n");
    printf("1. Factorielle:\n");
    printf("   6! = %u\n", factorielle(6));
    printf("   5! = %u\n", factorielle(5));
    
    printf("\n2. Puissance:\n");
    printf("   2^3 = %d\n", puissance(2, 3));
    printf("   5^2 = %d\n", puissance(5, 2));
    
    printf("\n3. Permutation:\n");
    int x = 10, y = 20;
    printf("   Avant: x=%d, y=%d\n", x, y);
    permuterVariables(&x, &y);
    printf("   Apres: x=%d, y=%d\n", x, y);
   
    printf("\n4. Tableau:\n");
    afficherTableau();
    
    // exercices 7 equations du second degre 
    printf("\n========== EXERCICE 7 ==========\n\n");
    printf("Test 1: x^2 - 3x + 2 = 0\n");
    resoudreEtAfficherEquation(1.0, -3.0, 2.0);
    
    printf("Test 2: x^2 - 4x + 4 = 0\n");
    resoudreEtAfficherEquation(1.0, -4.0, 4.0);
    
    printf("Test 3: x^2 + x + 1 = 0\n");
    resoudreEtAfficherEquation(1.0, 1.0, 1.0);
    
    printf("Test 4: 2x - 4 = 0\n");
    resoudreEtAfficherEquation(0.0, 2.0, -4.0);

    printf("Test 5: 0 = 0\n");
    resoudreEtAfficherEquation(0.0, 0.0, 0.0);    
    
    printf("Test 6: 5 = 0\n");
    resoudreEtAfficherEquation(0.0, 0.0, 5.0);
    
    // exercice 12 verification des nombres premiers
    printf("\n========== EXERCICE 12a ==========\n\n");
    
    // Tests de base
    printf("Tests de base :\n");
    unsigned int tests[] = {0, 1, 2, 3, 4, 5, 17, 20, 29, 100};
    for (int i = 0; i < 10; i++) {
        printf("   %u : %s\n", tests[i], 
               estNombrePremier(tests[i]) ? "premier" : "non premier");
    }
    
    // Vérification avec un nombre de votre choix 
    printf("\n--- Verification de votre nombre ---\n");
    unsigned int monNombre = 85;  // Changez le nombre ici pour tester 
    printf("Votre nombre : %u\n", monNombre);
    if (estNombrePremier(monNombre)) {
        printf("   -> %u EST PREMIER\n", monNombre);
    } else {
        printf("   -> %u N'EST PAS PREMIER\n", monNombre);
    }
    
    // exercice 13 structures pour les points et calcul de distances 
    printf("\n========== EXERCICE 13 ==========\n\n");
    printf("Calcul de distances entre points\n");
    printf("--------------------------------\n");
    
    // Test 1 : Distance simple
    Point p1 = {0.0, 0.0};
    Point p2 = {3.0, 4.0};
    printf("Test 1 : Points ");
    afficherPoint(p1);
    printf(" et ");
    afficherPoint(p2);
    printf("\n");
    printf("   Distance = %.2f (attendu : 5.00)\n", distanceEntrePoints(p1, p2));
    
    // Test 2 : Points avec coordonnées négatives
    Point p3 = {-2.0, 1.0};
    Point p4 = {1.0, 5.0};
    printf("\nTest 2 : Points ");
    afficherPoint(p3);
    printf(" et ");
    afficherPoint(p4);
    printf("\n");
    printf("   Distance = %.2f (attendu : 5.00)\n", distanceEntrePoints(p3, p4));
    
    // Test 3 : Points avec coordonnées décimales
    Point p5 = {1.5, 2.5};
    Point p6 = {4.5, 6.5};
    printf("\nTest 3 : Points ");
    afficherPoint(p5);
    printf(" et ");
    afficherPoint(p6);
    printf("\n");
    printf("   Distance = %.2f (attendu : 5.00)\n", distanceEntrePoints(p5, p6));
    
    // Test 4 : Distance nulle (même point)
    Point p7 = {3.0, 7.0};
    Point p8 = {3.0, 7.0};
    printf("\nTest 4 : Points ");
    afficherPoint(p7);
    printf(" et ");
    afficherPoint(p8);
    printf("\n");
    printf("   Distance = %.2f (attendu : 0.00)\n", distanceEntrePoints(p7, p8));
    
    return EXIT_SUCCESS;
}