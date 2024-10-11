#ifndef MATRIX_DETERMINANT_H
#define MATRIX_DETERMINANT_H

#include <stdio.h>
#include "menu_matrix.h"

// Function to input a matrix from the user
static inline void inputMatrix(int matrix[10][10], int n) {
    printf("Enter the elements of the matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to calculate the determinant of a matrix
static inline int determinant(int matrix[10][10], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else {
        int temp[10][10];
        for (int p = 0; p < n; p++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == p) continue;
                    temp[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += matrix[0][p] * determinant(temp, n - 1) * (p % 2 == 0 ? 1 : -1);
        }
    }
    return det;
}

// Main function to run the determinant calculation
static inline void run_determinant() {
    int matrix[10][10];
    int n;

    // Input for the square matrix
    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    // Check if the matrix size is valid
    if (n <= 0 || n > 10) {
        printf("Invalid matrix size. It should be between 1 and 10.\n");
        return;
    }

    inputMatrix(matrix, n);

    // Calculate and display the determinant
    int det = determinant(matrix, n);
    printf("\nThe determinant of the matrix is: %d\n", det);
}

#endif // MATRIX_DETERMINANT_H

