#ifndef SOLVER_H
#define SOLVER_H

#include<complex.h>

//function prototypes 
complex double eval_polynomial(complex double coeffs[], int deg, complex double z);
complex double eval_polynomial_derivative(complex double coeffs[], int deg, complex double z);
complex double jenkins_traub_step(complex double coeffs[], int deg, complex double z0);
void deflate_polynomial(complex double coeffs[], int deg, complex double root, complex double deflated_coeffs[]);
void jenkins_traub(complex double coeffs[], int deg, complex double roots[]);

#endif // SOLVER_H
