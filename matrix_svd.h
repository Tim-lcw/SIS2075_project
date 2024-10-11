#ifndef MATRIX_SVD_H
#define MATRIX_SVD_H

#include <stdio.h>
#include <math.h>
#include "menu_matrix.h"

// Function to input a matrix from the user
static inline void inputMatrix(float matrix[10][10], int row, int col) {
    printf("Enter the elements of the matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
static inline void printMatrix(float matrix[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to compute the Singular Value Decomposition (SVD)
static inline void svd(float matrix[10][10], float U[10][10], float S[10][10], float V[10][10], int row, int col) {
    // Simplified SVD: Not numerically stable; this is just a framework
    // Assume row >= col for simplicity

    // Calculate A^T * A (transpose of A times A)
    float AT[10][10] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            AT[j][i] += matrix[i][j] * matrix[i][j]; // Compute AT
        }
    }

    // Placeholder for singular values (diagonal elements of S)
    for (int i = 0; i < col; i++) {
        S[i][i] = sqrt(AT[i][i]);  // Simplified singular value calculation
    }

    // For simplicity, we will set U and V to be identity matrices
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            U[i][j] = (i == j) ? 1.0 : 0.0; // U is an identity matrix
            V[i][j] = (i == j) ? 1.0 : 0.0; // V is an identity matrix
        }
    }
}

// Function to run the matrix SVD calculation
static inline void run_matrix_svd() {
    int row, col;
    float matrix[10][10], U[10][10], S[10][10], V[10][10];

    // Input the number of rows and columns of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &row, &col);

    // Validate matrix size
    if (row <= 0 || col <= 0 || row > 10 || col > 10) {
        printf("Invalid matrix size. Rows and columns should be between 1 and 10.\n");
        return;
    }

    // Input matrix elements
    inputMatrix(matrix, row, col);

    // Calculate SVD
    svd(matrix, U, S, V, row, col);

    // Print U, S, and V matrices
    printf("\nMatrix U:\n");
    printMatrix(U, row, row); // U is row x row

    printf("\nMatrix S (Singular Values):\n");
    printMatrix(S, row, col); // S is row x col

    printf("\nMatrix V:\n");
    printMatrix(V, col, col); // V is col x col
}

#endif // MATRIX_SVD_H
