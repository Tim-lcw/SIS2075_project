#ifndef MATRIX_RANK_H
#define MATRIX_RANK_H

#include <stdio.h>
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

// Function to perform row reduction and calculate rank
static inline int calculateRank(float matrix[10][10], int row, int col) {
    int rank = col;  // Assume initial rank is the number of columns

    for (int r = 0; r < rank; r++) {
        // Check if the leading element of the row is non-zero
        if (matrix[r][r] != 0) {
            // Normalize the row by dividing by the leading element
            for (int c = 0; c < col; c++) {
                matrix[r][c] /= matrix[r][r];
            }

            // Eliminate the current column in rows below the current row
            for (int i = 0; i < row; i++) {
                if (i != r) {
                    float factor = matrix[i][r];
                    for (int c = 0; c < col; c++) {
                        matrix[i][c] -= factor * matrix[r][c];
                    }
                }
            }
        } else {
            // If the leading element is zero, swap the row with a lower row
            int reduce = 1;
            for (int i = r + 1; i < row; i++) {
                if (matrix[i][r] != 0) {
                    for (int c = 0; c < col; c++) {
                        float temp = matrix[r][c];
                        matrix[r][c] = matrix[i][c];
                        matrix[i][c] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }

            // If no row could be swapped, reduce the rank
            if (reduce) {
                rank--;

                // Move all columns left
                for (int i = 0; i < row; i++) {
                    for (int j = r; j < col - 1; j++) {
                        matrix[i][j] = matrix[i][j + 1];
                    }
                }
            }
            r--;
        }
    }

    return rank;
}

// Function to run the matrix rank calculation program
static inline void run_matrix_rank() {
    int row, col;
    float matrix[10][10];

    // Input the number of rows and columns of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &row, &col);

    if (row <= 0 || col <= 0 || row > 10 || col > 10) {
        printf("Invalid matrix size. Rows and columns should be between 1 and 10.\n");
        return;
    }

    // Input matrix elements
    inputMatrix(matrix, row, col);

    // Calculate the rank of the matrix
    int rank = calculateRank(matrix, row, col);
    printf("\nThe rank of the matrix is: %d\n", rank);
}

#endif // MATRIX_RANK_H

