#include <stdio.h>
#include <complex.h>
#include "solver.h"
#include <math.h>

//Function to evaluate polynomial at complex z using Horner's Method
complex double eval_polynomial(complex double coeffs[], int deg, complex double z){
    complex double sum = coeffs[0];
    for (int i = 1; i <= deg; i++) {
        sum = sum * z + coeffs[i];
    }
    return sum;
}

//Function to evaluate the derivative of the polynomial at complex z using Horner's Method
complex double eval_polynomial_derivative(complex double coeffs[], int deg, complex double z){
    complex double sum = deg * coeffs[0];
    for (int i = 1; i < deg; i++) {
        sum = sum * z + (deg - i) * coeffs[i];
    }
    return sum;
}

// Jenkins-Traub iteration 
complex double jenkins_traub_step(complex double coeffs[], int deg, complex double z0){
    const int max_iterations = 1000;
    const double tolerance = 1e-8;
    int iteration = 0;
    
    complex double z = z0;
    
    while (iteration < max_iterations) {
        complex double fz = eval_polynomial(coeffs, deg, z);
        complex double fz_prime = eval_polynomial_derivative(coeffs, deg, z);
        if (cabs(fz_prime) < tolerance) { // If derivative too small, stop iteration
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

// Deflate polynomial 
void deflate_polynomial(complex double coeffs[], int deg, complex double root, complex double deflated_coeffs[]){
    deflated_coeffs[0] = coeffs[0];
    for (int i = 1; i < deg; i++) {
        deflated_coeffs[i] = coeffs[i] + root * deflated_coeffs[i - 1];
    }
}

// Jenkins-Traub algorithm for finding all roots
void jenkins_traub(complex double coeffs[], int deg, complex double roots[]){
    complex double deflated_coeffs[deg + 1];
    complex double current_coeffs[deg + 1];
    for (int i = 0; i <= deg; i++){
        current_coeffs[i] = coeffs[i];
    }
    for (int i = deg; i >= 1; i--){
        complex double z0 = 0.4 + 0.9 * I;  // Improved initial guess
        complex double root = jenkins_traub_step(current_coeffs, i, z0);   
        roots[deg - i] = root;
        deflate_polynomial(current_coeffs, i, root, deflated_coeffs);
    
        for (int j = 0; j < i; j++){
            current_coeffs[j] = deflated_coeffs[j];
        }
    }
}
