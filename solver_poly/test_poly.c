#include <stdio.h>
#include <complex.h>
#include "solver.h"

int main() {
    int deg;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &deg);

    complex double coeffs[deg + 1];
    complex double roots[deg];

    printf("Enter real coefficients of the polynomial:\n");
    for (int i = 0; i <= deg; i++) {
        double real;
        printf("Coefficient of x^%d: ", deg - i);
        scanf("%lf", &real);
        coeffs[i] = real + 0 * I;
    }

    jenkins_traub(coeffs, deg, roots);

    printf("The roots of the polynomial are:\n");
    for (int i = 0; i < deg; i++) {
        printf("Root %d: %.5f + %.5fi\n", i + 1, creal(roots[i]), cimag(roots[i]));
    }

    return 0;
}
