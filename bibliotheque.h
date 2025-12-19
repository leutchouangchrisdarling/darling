#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

// FONCTION FACTORIELLE exercice 1
unsigned int factorielle(unsigned int n);

// fonction puissance exercice 2
int puissance(int base, unsigned int exposant);

// fonction permutation exercice 3a
void permuterVariables(int *a, int *b);

// permet d'afficher les tableaux exercice 3b
void afficherTableau();

// exercice 7 : resolution d'une equation du second degre en language c
// structures de donnees pour gerer toutes les solutions  
typedef struct {
    int type_solution;
    int est_lineaire;
    int sont_complexes;
    double solution1;
    double solution2;
    double partie_reelle;
    double partie_imag;
} SolutionEquation2Degre;

// fonctions qui permettent de resoudre les equations et d'afficher les solutions dans les differents cas 
SolutionEquation2Degre resoudreEquation2Degre(double a, double b, double c);
void afficherSolutionsEquation(SolutionEquation2Degre solutions, double a, double b, double c);
void resoudreEtAfficherEquation(double a, double b, double c);

// Exercice 12a - Vérification nombre premier
// un peu comme dans le cas du factorielle  int estNombrePremier(unsigned int n)  
int estNombrePremier(unsigned int n);

// Exercice 13 - Structure  pour les Point et la gestion du calcul des  distances
// definition de la structure 
typedef struct {
    double x;
    double y;
} Point;

double distanceEntrePoints(Point p1, Point p2);
void lirePoint(Point *p);
void afficherPoint(Point p);

#endif  // BIBLIOTHEQUE_H