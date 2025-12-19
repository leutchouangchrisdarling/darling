#include "bibliotheque.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Exercice 1
unsigned int factorielle(unsigned int n) {
    if (n == 0 || n == 1) return 1;
    unsigned int resultat = 1;
    for (unsigned int i = 2; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}

// Exercice 2
int puissance(int base, unsigned int exposant) {
    if (exposant == 0) return 1;
    int resultat = 1;
    for (unsigned int i = 0; i < exposant; i++) {
        resultat *= base;
    }
    return resultat;
}

// Exercice 3A
void permuterVariables(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Exercice 3B
void afficherTableau() {
    int tableau[5] = {1, 2, 4, 8, 16};
    for (int i = 0; i < 5; i++) {
        printf("tableau[%d] = %d\n", i, tableau[i]);
    }
}

// Exercice 7 - RESOLUTION D'EQUQTION DU SECOND DEGRES 
SolutionEquation2Degre resoudreEquation2Degre(double a, double b, double c) {
    SolutionEquation2Degre solutions = {0};
    
    // CAS 1 : Equation lineaire (a = 0)
    if (a == 0.0) {
        solutions.est_lineaire = 1;
        if (b != 0.0) {
            solutions.type_solution = 1;
            solutions.solution1 = -c / b;
        }
        else if (c != 0.0) {
            solutions.type_solution = 0;
        }
        else {
            solutions.type_solution = -1;
        }
        return solutions;
    }
    
    // CAS 2 : Equation du second degre (a != 0)
    solutions.est_lineaire = 0;
    double discriminant = b * b - 4 * a * c;
    
    // Discriminant > 0 : deux solutions reelles
    if (discriminant > 0) {
        solutions.type_solution = 2;
        solutions.sont_complexes = 0;
        double racine_delta = sqrt(discriminant);
        solutions.solution1 = (-b + racine_delta) / (2 * a);
        solutions.solution2 = (-b - racine_delta) / (2 * a);
    }
    // Discriminant = 0 : solution double
    else if (discriminant == 0) {
        solutions.type_solution = 1;
        solutions.sont_complexes = 0;
        solutions.solution1 = -b / (2 * a);
        solutions.solution2 = solutions.solution1;
    }
    // Discriminant < 0 : solutions complexes
    else {
        solutions.type_solution = 2;
        solutions.sont_complexes = 1;
        solutions.partie_reelle = -b / (2 * a);
        solutions.partie_imag = sqrt(-discriminant) / (2 * a);
    }
    
    return solutions;
}

void afficherSolutionsEquation(SolutionEquation2Degre solutions, double a, double b, double c) {
    // Affichage DES EQUATIONS ET DES SOLUTIONS
    printf("Equation: ");
    
    if (a != 0) {
        if (a == 1.0) printf("x^2 ");
        else if (a == -1.0) printf("-x^2 ");
        else printf("%.2fx^2 ", a);
    }
    
    if (b != 0) {
        if (b > 0 && a != 0) printf("+ ");
        if (b == 1.0) printf("x ");
        else if (b == -1.0) printf("-x ");
        else printf("%.2fx ", b);
    }
    
    if (c != 0) {
        if (c > 0 && (a != 0 || b != 0)) printf("+ ");
        printf("%.2f ", c);
    }
    
    printf("= 0\n");
    
    if (solutions.est_lineaire) {
        if (solutions.type_solution == -1) {
            printf("-> Infinite de solutions\n");
        }
        else if (solutions.type_solution == 0) {
            printf("-> Aucune solution\n");
        }
        else {
            printf("-> Solution: x = %.2f\n", solutions.solution1);
        }
    }
    else {
        if (solutions.sont_complexes) {
            printf("-> Solutions complexes:\n");
            printf("   x1 = %.2f + %.2fi\n", solutions.partie_reelle, solutions.partie_imag);
            printf("   x2 = %.2f - %.2fi\n", solutions.partie_reelle, solutions.partie_imag);
        }
        else if (solutions.type_solution == 1) {
            printf("-> Solution double: x = %.2f\n", solutions.solution1);
        }
        else if (solutions.type_solution == 2) {
            printf("-> Deux solutions reelles:\n");
            printf("   x1 = %.2f\n", solutions.solution1);
            printf("   x2 = %.2f\n", solutions.solution2);
        }
    }
    printf("\n");
}

void resoudreEtAfficherEquation(double a, double b, double c) {
    SolutionEquation2Degre solutions = resoudreEquation2Degre(a, b, c);
    afficherSolutionsEquation(solutions, a, b, c);
}

// Exercice 12a - Vérification nombre premier
int estNombrePremier(unsigned int n) {
    // 0 et 1 ne sont pas premiers
    if (n <= 1) {
        return 0;
    }
    
    // 2 est premier
    if (n == 2) {
        return 1;
    }
    
    // Les nombres pairs > 2 ne sont pas premiers
    if (n % 2 == 0) {
        return 0;
    }
    
    // Vérifions  les divisibilités de 3 à n (on incrémente de 2 pour ne tester que les  chiffrs impairs)
    for (unsigned int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;  // n est divisible par i, donc pas premier
        }
    }
    
    return 1;  // n est premier
}


// Exercice 13 - Structure pour les  Point dans le plan  et le calcul des distance
double distanceEntrePoints(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

void lirePoint(Point *p) {
    printf("Entrez la coordonnee x : ");
    scanf("%lf", &(p->x));
    printf("Entrez la coordonnee y : ");
    scanf("%lf", &(p->y));
}

void afficherPoint(Point p) {
    printf("(%g, %g)", p.x, p.y);// pour eviter l'ajout de decimal 
}