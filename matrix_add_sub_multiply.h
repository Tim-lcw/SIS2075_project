#ifndef MATRIX_ADD_SUB_MULTIPLY_H
#define MATRIX_ADD_SUB_MULTIPLY_H

#include <stdio.h>
#include "matrix_add_sub_multiply.h"
#include "menu_matrix.h" 

void inputMatrix(int matrix[10][10], int row, int col, char name) {
    printf("Enter elements of Matrix %c:\n", name);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void run_matrix_adm() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row1, col1, row2, col2, choice;

    // Input for Matrix 1
    printf("Enter the number of rows and columns of Matrix 1: ");
    scanf("%d %d", &row1, &col1);
    inputMatrix(matrix1, row1, col1, 'A');

    // Input for Matrix 2
    printf("Enter the number of rows and columns of Matrix 2: ");
    scanf("%d %d", &row2, &col2);
    inputMatrix(matrix2, row2, col2, 'B');

    // Operation choice
    printf("\nChoose the operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            if (row1 == row2 && col1 == col2) {
                addMatrices(matrix1, matrix2, result, row1, col1);
                printf("\nMatrix Addition Result:\n");
                printMatrix(result, row1, col1);
            } else {
                printf("\nMatrix addition is not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 2: // Subtraction
            if (row1 == row2 && col1 == col2) {
                subtractMatrices(matrix1, matrix2, result, row1, col1);
                printf("\nMatrix Subtraction Result:\n");
                printMatrix(result, row1, col1);
            } else {
                printf("\nMatrix subtraction is not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 3: // Multiplication
            if (col1 == row2) {
                multiplyMatrices(matrix1, matrix2, result, row1, col1, col2);
                printf("\nMatrix Multiplication Result:\n");
                printMatrix(result, row1, col2);
            } else {
                printf("\nMatrix multiplication is not possible. The number of columns in Matrix 1 must equal the number of rows in Matrix 2.\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}


#endif /* MATRIX_ADD_SUB_MULTIPLY_H*/
