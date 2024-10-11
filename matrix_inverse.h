#ifndef MATRIX_INVERSE_H
#define MATRIX_INVERSE_H

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

// Function to print the matrix
static inline void printMatrix(float matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the inverse of a matrix using Gaussian elimination
static inline int inverseMatrix(float matrix[10][10], float inverse[10][10], int n) {
    float augmented[10][20]; // To hold the augmented matrix (matrix + identity)
    
    // Initializing the augmented matrix with input matrix and identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];       // Left side: original matrix
            augmented[i][j + n] = (i == j) ? 1 : 0; // Right side: identity matrix
        }
    }

    // Applying Gaussian Elimination
    for (int i = 0; i < n; i++) {
        if (augmented[i][i] == 0) {
            printf("Matrix is singular and cannot be inverted.\n");
            return 0;
        }

        float pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot; // Make the pivot element 1
        }

        // Make all rows except this one 0 in the current column
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extracting the inverse matrix from the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return 1;
}

// Main function to execute matrix inverse calculation
static inline void run_matrix_inverse() {
    int n;
    float matrix[10][10], inverse[10][10];

    // Input for the square matrix
    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid matrix size. It should be between 1 and 10.\n");
        return;
    }

    // Input matrix elements
    inputMatrix(matrix, n);

    // Calculate inverse
    if (inverseMatrix(matrix, inverse, n)) {
        printf("\nThe inverse of the matrix is:\n");
        printMatrix(inverse, n);
    } else {
        printf("\nThe matrix does not have an inverse.\n");
    }
}

#endif // MATRIX_INVERSE_H

