#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.h"

int main(void) {
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
    
    printf("\n========== EXERCICE 7 ==========\n\n");
    // MR PEUT MODIFIER LES VALEURS ICI POUR TESTER MON  CODE 
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
    
    return EXIT_SUCCESS;
}