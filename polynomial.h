#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <math.h>

// Function to evaluate polynomial at a point x using Horner's method
float poly(float a[], int deg, float x) {
    float p = a[0];
    for (int i = 1; i <= deg; i++) {
        p = p * x + a[i];  // Using Horner's method for efficient evaluation
    }
    return p;
}

// Function for evaluating the derivative at some value of x
float deriv(float a[], int deg, float x) {
    float pd = 0;
    for (int i = 0; i < deg; i++) {  // Differentiate term by term
        pd = pd * x + (deg - i) * a[i];
    }
    return pd;
}

// Function to run the polynomial evaluation and derivative computation
void runPolynomial() {
    float x, a[10], y1, dy1;
    int deg, i;

    // Open the output file in write mode (to refresh/overwrite the file each time)
    FILE *outputFile = fopen("outputpolynomial.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Prompt the user for polynomial degree and x value
    printf("Enter the degree of polynomial equation: ");
    scanf("%d", &deg);
    printf("Enter the value of x for which the equation is to be evaluated: ");
    scanf("%f", &x);
    
    // Input polynomial coefficients
    for (i = 0; i <= deg; i++) {
        printf("Enter the coefficient of x to the power %d: ", deg - i);
        scanf("%f", &a[i]);
    }

    // Evaluate the polynomial and its derivative at x
    y1 = poly(a, deg, x);
    dy1 = deriv(a, deg, x);

    // Write the results to the output file with a start and end delimiter
    fprintf(outputFile, "----------------Start Polynomial----------------\n");
    fprintf(outputFile, "The value of the polynomial equation for x = %.2f is: %.2f\n", x, y1);
    fprintf(outputFile, "The value of the derivative of the polynomial at x = %.2f is: %.2f\n", x, dy1);
    fprintf(outputFile, "----------------End Polynomial----------------\n");

    // Also print the results to the console
    printf("The value of the polynomial equation for x = %.2f is: %.2f\n", x, y1);
    printf("The value of the derivative of the polynomial at x = %.2f is: %.2f\n", x, dy1);

    // Close the file after writing the results
    fclose(outputFile);

    // Optionally, open the output file automatically after the program finishes (platform dependent)
    #ifdef _WIN32
        system("notepad outputpolynomial.txt");  // For Windows
    #else
        system("open outputpolynomial.txt");  // For MacOS (use 'xdg-open' for Linux)
    #endif
}

#endif // POLYNOMIAL_H
