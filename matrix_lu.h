#ifndef MATRIX_LU_H
#define MATRIX_LU_H

#include <stdio.h>
#include "menu_matrix.h"


// Function to input a matrix from the user
static inline void inputMatrix(float matrix[10][10], int n) {
    printf("Enter the elements of the matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
static inline void printMatrix(float matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform LU decomposition
static inline int luDecomposition(float matrix[10][10], float L[10][10], float U[10][10], int n) {
    // Initialize L and U
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                L[i][j] = 1;  // Diagonal elements of L are 1
            } else {
                L[i][j] = 0;
            }
            U[i][j] = 0;
        }
    }

    // LU decomposition
    for (int k = 0; k < n; k++) {
        // Upper Triangular Matrix U
        for (int j = k; j < n; j++) {
            U[k][j] = matrix[k][j];
            for (int s = 0; s < k; s++) {
                U[k][j] -= L[k][s] * U[s][j];
            }
        }

        // Lower Triangular Matrix L
        for (int i = k + 1; i < n; i++) {
            L[i][k] = matrix[i][k];
            for (int s = 0; s < k; s++) {
                L[i][k] -= L[i][s] * U[s][k];
            }
            if (U[k][k] == 0) {
                return 0; // Singular matrix, cannot decompose
            }
            L[i][k] /= U[k][k];
        }
    }

    return 1;
}

// Main function to run LU decomposition
static inline void run_lu_decomposition() {
    int n;
    float matrix[10][10], L[10][10], U[10][10];

    // Input the size of the square matrix
    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid matrix size. It should be between 1 and 10.\n");
        return;
    }

    // Input matrix elements
    inputMatrix(matrix, n);

    // Perform LU decomposition
    if (luDecomposition(matrix, L, U, n)) {
        // Print L and U matrices
        printf("\nLower Triangular Matrix L:\n");
        printMatrix(L, n);

        printf("\nUpper Triangular Matrix U:\n");
        printMatrix(U, n);
    } else {
        printf("Matrix is singular, LU decomposition is not possible.\n");
    }
}

#endif // MATRIX_LU_H

