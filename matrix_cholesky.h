#ifndef MATRIX_CHOLESKY_H
#define MATRIX_CHOLESKY_H

#include <stdio.h>
#include <math.h>
#include "menu_matrix.h"

// Function to input matrix elements
static inline void input_matrix(int rows, int cols, double matrix[rows][cols]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// Function to print matrix
static inline void print_matrix(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Cholesky decomposition
static inline int cholesky_decomposition(int n, double A[n][n], double L[n][n]) {
    // Initialize L to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0.0;

            if (i == j) { // Diagonal elements
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * L[j][k];
                }
                double value = A[j][j] - sum;
                if (value <= 0) {
                    // Matrix is not positive-definite
                    return -1;
                }
                L[j][j] = sqrt(value);
            } else { // Off-diagonal elements
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    return 0; // Successful decomposition
}

// Main function to execute the program logic
static inline int run_cholesky() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    double A[n][n];
    input_matrix(n, n, A);

    double L[n][n];  // Lower triangular matrix

    // Perform Cholesky decomposition
    if (cholesky_decomposition(n, A, L) == 0) {
        printf("Cholesky decomposition succeeded.\n");
        printf("Matrix L (Lower triangular matrix):\n");
        print_matrix(n, n, L);
    } else {
        printf("Cholesky decomposition failed. The matrix is not positive definite.\n");
    }

    return 0;
}

#endif // MATRIX_CHOLESKY_H
