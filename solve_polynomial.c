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