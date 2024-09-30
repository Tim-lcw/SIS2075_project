#include <stdio.h>
#include "finder.h"

int main() {
    float x, a[10], y1, dy1;
    int deg, i;
    printf("Enter the degree of polynomial equation: ");
    scanf("%d", &deg);
    printf("Enter the value of x for which the equation is to be evaluated: ");
    scanf("%f", &x);
    
    for (i = 0; i <= deg; i++) {
        printf("Enter the coefficient of x to the power %d: ", deg - i);
        scanf("%f", &a[i]);
    }

    y1 = poly(a, deg, x);
    dy1 = deriv(a, deg, x);

    printf("The value of the polynomial equation for x = %.2f is: %.2f\n", x, y1);
    printf("The value of the derivative of the polynomial at x = %.2f is: %.2f\n", x, dy1);

    return 0;
}
