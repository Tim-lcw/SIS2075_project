#ifndef MATRIX_EIGEN_H
#define MATRIX_EIGEN_H

#include <stdio.h>
#include <math.h>
#include "menu_matrix.h"


// Function to input matrix elements
static inline void input_matrix(int rows, int cols, double matrix[rows][cols]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// Function to print matrix
static inline void print_matrix(int rows, int cols, double matrix[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the Euclidean norm of a vector
static inline double norm(int n, double vector[n]) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Function to multiply a matrix by a vector
static inline void matrix_vector_multiply(int n, double matrix[n][n], double vector[n], double result[n]) {
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

// Power iteration method to calculate the dominant eigenvalue and eigenvector
static inline void power_iteration(int n, double matrix[n][n], double eigenvector[n], double *eigenvalue) {
    double tolerance = 1e-6;
    int max_iterations = 1000;
    double old_eigenvalue = 0;
    
    // Initialize the eigenvector with arbitrary values (e.g., all 1s)
    for (int i = 0; i < n; i++) {
        eigenvector[i] = 1.0;
    }

    for (int k = 0; k < max_iterations; k++) {
        double next_vector[n];
        matrix_vector_multiply(n, matrix, eigenvector, next_vector);

        double next_norm = norm(n, next_vector);
        for (int i = 0; i < n; i++) {
            eigenvector[i] = next_vector[i] / next_norm;
        }

        *eigenvalue = next_norm;

        if (fabs(*eigenvalue - old_eigenvalue) < tolerance) {
            break;
        }
        old_eigenvalue = *eigenvalue;
    }
}

// Main function to run the eigenvalue calculation
static inline void run_eigenvalue_computation() {
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    double matrix[n][n];
    input_matrix(n, n, matrix);

    double eigenvector[n];
    double eigenvalue;

    power_iteration(n, matrix, eigenvector, &eigenvalue);

    printf("Dominant Eigenvalue: %lf\n", eigenvalue);
    printf("Corresponding Eigenvector:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf\n", eigenvector[i]);
    }
}

#endif // MATRIX_EIGEN_H

