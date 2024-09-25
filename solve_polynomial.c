#include <stdio.h>   // Standard input output library
#include <complex.h> // Used to implement complex numbers
#include <math.h> // Used to implement mathematical functions
#include <stdbool.h>  // For boolean values


//Function to evaluate polynomial at complex z using Horner's Method
complex double eval_polynomial(complex double coeffs[], int deg, complex double z) {
    complex double sum = coeffs[0];
    for (int i = 1; i <= deg; i++) {
        sum = sum * z + coeffs[i];
    }
    return sum;
}

// Function to evaluate the derivative of the polynomial at complex z using Horner's Method
complex double eval_polynomial_derivative(complex double coeffs[], int deg, complex double z) {
    complex double sum = deg * coeffs[0];
    for (int i = 1; i < deg; i++) {
        sum = sum * z + (deg - i) * coeffs[i];
    }
    return sum;
}

//Jenkins-Traub iteration 
complex double jenkins_traub_step(complex double coeffs[], int deg, complex double z0) {
    const int max_iterations = 1000;
    const double tolerance = 1e-8;
    int iteration = 0;
    
    complex double z = z0;
    
    while (iteration < max_iterations) {
        complex double fz = eval_polynomial(coeffs, deg, z);
        complex double fz_prime = eval_polynomial_derivative(coeffs, deg, z);
        if (cabs(fz_prime) < tolerance) { //If derivative too small, stop iteration
            break;
        }
        complex double dz = fz / fz_prime;
        z = z - dz;
        // Check if the change is within tolerance
        if (cabs(dz) < tolerance) {
            break;
        }
        iteration++;
    }
    return z;
}
