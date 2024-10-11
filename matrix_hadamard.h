#ifndef MATRIX_HADAMARD_H
#define MATRIX_HADAMARD_H

#include <stdio.h>
#include "menu_matrix.h"


// Function to input a matrix from the user
static inline void inputMatrix(int matrix[10][10], int row, int col, char name) {
    printf("Enter the elements of Matrix %c (%dx%d):\n", name, row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
static inline void printMatrix(int matrix[10][10], int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the Hadamard product of two matrices
static inline void hadamardProduct(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];  // Element-wise multiplication
        }
    }
}

// Main function to perform the Hadamard product calculation
static inline void run_hadamard_product() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row, col;

    // Input the number of rows and columns for the matrices
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &row, &col);

    // Check if the dimensions are valid
    if (row <= 0 || col <= 0 || row > 10 || col > 10) {
        printf("Invalid matrix size. Rows and columns should be between 1 and 10.\n");
        return;
    }

    // Input both matrices
    inputMatrix(matrix1, row, col, 'A');
    inputMatrix(matrix2, row, col, 'B');

    // Calculate Hadamard product
    hadamardProduct(matrix1, matrix2, result, row, col);

    // Print the resulting Hadamard product
    printf("\nThe Hadamard product of the matrices is:\n");
    printMatrix(result, row, col);
}

#endif // MATRIX_HADAMARD_H

