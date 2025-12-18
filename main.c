#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.h"

int main( void ) {
    int result = power( 2, 3 );
    int x = 1;
    int y = 2;

    printf("\nAvant permutation :\nx = %d\ny = %d", x, y);
    switchVar(&x, &y);
    printf("\nApres permutation :\nx = %d\ny = %d", x, y);

    printf( "2³ == %d\n", result );
    result = fact( 6 );
    printf( "6! == %d\n", result );

    arrayView();

    return EXIT_SUCCESS;
}
