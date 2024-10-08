#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>   // Standard input/output library
#include <complex.h> // Used to implement complex numbers
#include <math.h>    // Used to implement mathematical functions
#include <stdbool.h> // For boolean values

// Function to evaluate polynomial at complex z using Horner's Method
double complex eval_polynomial(double complex coeffs[], int deg, double complex z) {
    double complex sum = coeffs[0];
    for (int i = 1; i <= deg; i++) {
        sum = sum * z + coeffs[i];
    }
    return sum;
}

// Function to evaluate the derivative of the polynomial at complex z using Horner's Method
double complex eval_polynomial_derivative(double complex coeffs[], int deg, double complex z) {
    double complex sum = deg * coeffs[0];
    for (int i = 1; i < deg; i++) {
        sum = sum * z + (deg - i) * coeffs[i];
    }
    return sum;
}

// Jenkins-Traub iteration for a single root
double complex jenkins_traub_step(double complex coeffs[], int deg, double complex z0) {
    const int max_iterations = 1000;
    const double tolerance = 1e-8;
    int iteration = 0;
    
    double complex z = z0;
    
    while (iteration < max_iterations) {
        double complex fz = eval_polynomial(coeffs, deg, z);
        double complex fz_prime = eval_polynomial_derivative(coeffs, deg, z);
        if (cabs(fz_prime) < tolerance) { // If derivative too small, stop iteration
            break;
        }
        double complex dz = fz / fz_prime;
        z = z - dz;
        // Check if the change is within tolerance
        if (cabs(dz) < tolerance) {
            break;
        }
        iteration++;
    }
    return z;
}

// Function to deflate the polynomial after finding a root
void deflate_polynomial(double complex coeffs[], int deg, double complex root, double complex deflated_coeffs[]) {
    deflated_coeffs[0] = coeffs[0];
    for (int i = 1; i < deg; i++) {
        deflated_coeffs[i] = coeffs[i] + root * deflated_coeffs[i - 1];
    }
}

// Jenkins-Traub algorithm for finding all roots of the polynomial
void jenkins_traub(double complex coeffs[], int deg, double complex roots[]) {
    double complex deflated_coeffs[deg + 1];
    double complex current_coeffs[deg + 1];
    for (int i = 0; i <= deg; i++) {
        current_coeffs[i] = coeffs[i];
    }
    for (int i = deg; i >= 1; i--) {
        double complex z0 = 0.4 + 0.9 * I;  // Improved initial guess
        double complex root = jenkins_traub_step(current_coeffs, i, z0);   
        roots[deg - i] = root;
        deflate_polynomial(current_coeffs, i, root, deflated_coeffs);
    
        for (int j = 0; j < i; j++) {
            current_coeffs[j] = deflated_coeffs[j];
        }
    }
}

// Function to run the solver program
void runSolver() {
    int deg;
    printf("Enter the degree of the polynomial: "); // Prompt user to enter degree of polynomial
    scanf("%d", &deg);
    double complex coeffs[deg + 1];
    double complex roots[deg];

    // Prompt user to enter real coefficients
    printf("Enter real coefficients of the polynomial:\n");
    for (int i = 0; i <= deg; i++) {
        double real;
        printf("Coefficient of x^%d: ", deg - i);
        scanf("%lf", &real);
        coeffs[i] = real + 0 * I;
    }

    // Call Jenkins-Traub algorithm to find all roots
    jenkins_traub(coeffs, deg, roots);

    // Open output file to write the results
    FILE *outputFile = fopen("outputroots.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write start marker to console and file
    printf("--------start solver--------\n");
    fprintf(outputFile, "--------start solver--------\n");
    fflush(outputFile);  // Flush the file buffer to ensure the markers are written

    // Output the roots of the polynomial
    printf("The roots of the polynomial are:\n");
    fprintf(outputFile, "The roots of the polynomial are:\n");
    for (int i = 0; i < deg; i++) {
        printf("Root %d: %.5f + %.5fi\n", i + 1, creal(roots[i]), cimag(roots[i]));
        fprintf(outputFile, "Root %d: %.5f + %.5fi\n", i + 1, creal(roots[i]), cimag(roots[i]));
    }
    fflush(outputFile);  // Flush the file buffer after writing the roots

    // Write end marker to console and file
    printf("--------end solver--------\n");
    fprintf(outputFile, "--------end solver--------\n");
    fflush(outputFile);  // Ensure the end markers are written

    // Close the file after writing the results
    fclose(outputFile);

    #ifdef _WIN32
        system("notepad outputroots.txt");  // For Windows
    #else
        system("open outputroots.txt");  // For MacOS (use 'xdg-open' for Linux)
    #endif
}

#endif // SOLVER_H
