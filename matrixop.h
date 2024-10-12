#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdio.h>
#include <stdlib.h>  // For system()

// Function prototypes (declarations)
void inputMatrix(int matrix[10][10], int row, int col, char name);
void printMatrix(int matrix[10][10], int row, int col, FILE *file);
void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col);
void subtractMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col);
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row1, int col1, int col2);
int matrixRank(int matrix[10][10], int row, int col);

// Function to input matrix elements
void inputMatrix(int matrix[10][10], int row, int col, char name) {
    printf("Enter elements of Matrix %c:\n", name);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix to the console and to a file
void printMatrix(int matrix[10][10], int row, int col, FILE *file) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);         // Print to console
            fprintf(file, "%d\t", matrix[i][j]);  // Print to file
        }
        printf("\n");
        fprintf(file, "\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
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

// Function to calculate the rank of a matrix using Gaussian elimination
int matrixRank(int matrix[10][10], int row, int col) {
    int rank = col;

    for (int r = 0; r < rank; r++) {
        if (matrix[r][r] != 0) {
            for (int c = 0; c < row; c++) {
                if (c != r) {
                    double factor = (double)matrix[c][r] / matrix[r][r];
                    for (int i = 0; i < col; i++) {
                        matrix[c][i] -= factor * matrix[r][i];
                    }
                }
            }
        } else {
            int reduce = 1;
            for (int i = r + 1; i < row; i++) {
                if (matrix[i][r] != 0) {
                    for (int j = 0; j < col; j++) {
                        int temp = matrix[r][j];
                        matrix[r][j] = matrix[i][j];
                        matrix[i][j] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < row; i++) {
                    matrix[i][r] = matrix[i][rank];
                }
            }
            r--;
        }
    }
    return rank;
}

void runMatOp() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row1, col1, row2, col2, choice;

    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open results.txt for writing.\n");
        return ;
    }

    // Input for Matrix 1
    printf("Enter the number of rows of Matrix A: ");
    scanf("%d", &row1);
    printf("Enter the number of columns of Matrix A: ");
    scanf("%d", &col1);
    inputMatrix(matrix1, row1, col1, 'A');

    // Input for Matrix 2
    printf("Enter the number of rows of Matrix B: ");
    scanf("%d", &row2);
    printf("Enter the number of columns of Matrix B: ");
    scanf("%d", &col2);
    inputMatrix(matrix2, row2, col2, 'B');

    fprintf(file, "--------Original Matrices--------\n");
    printf("--------Original Matrices--------\n");
    fprintf(file, "Matrix A:\n");
    printf("Matrix A:\n");
    printMatrix(matrix1, row1, col1, file);
    fprintf(file, "Matrix B:\n");
    printf("Matrix B:\n");
    printMatrix(matrix2, row2, col2, file);

    printf("\nChoose the operation[1-6]:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Rank of Matrix A\n5. Rank of Matrix B\n6. Go Back\n");
    printf("Choice: ");
    scanf("%d", &choice);

    fprintf(file, "--------Matrix Operation--------\n");
    printf("--------Matrix Operation--------\n");

    switch (choice) {
        case 1:
            if (row1 == row2 && col1 == col2) {
                addMatrices(matrix1, matrix2, result, row1, col1);
                fprintf(file, "Matrix Addition Result:\n");
                printMatrix(result, row1, col1, file);
                printf("--------End----------\n");
            }
            break;
        case 2:
            if (row1 == row2 && col1 == col2) {
                subtractMatrices(matrix1, matrix2, result, row1, col1);
                fprintf(file, "Matrix Subtraction Result:\n");
                printMatrix(result, row1, col1, file);
             printf("--------End----------\n");

            }
            break;
        case 3:
            if (col1 == row2) {
                multiplyMatrices(matrix1, matrix2, result, row1, col1, col2);
                fprintf(file, "Matrix Multiplication Result:\n");
                printMatrix(result, row1, col2, file);
                printf("--------End----------\n");
            }
            break;
        case 4:
            fprintf(file, "Rank of Matrix A: %d\n", matrixRank(matrix1, row1, col1));
            printf("Rank of Matrix A: %d\n", matrixRank(matrix1, row1, col1));
            break;
        case 5:
            fprintf(file, "Rank of Matrix B: %d\n", matrixRank(matrix2, row2, col2));
            printf("Rank of Matrix B: %d\n", matrixRank(matrix2, row2, col2));
            printf("--------End----------\n");
            break;
        case 6:
            printf("No operaions performed\n");
            printf("--------End----------\n");
         fprintf(file, "No operaions performed\n");
         fprintf(file, "--------End----------\n");
         fclose(file);
         #ifdef _WIN32
    system("cmd /c start notepad results.txt");
#elif __APPLE__
    system("open results.txt");
#else
    system("xdg-open results.txt");
#endif
           return;
           
        default:
            fprintf(file, "Invalid choice\n");
            printf("Invalid choice\n");
            break;
    }
     printf("--------End----------\n");
    fprintf(file, "--------End----------\n");
    fclose(file);

#ifdef _WIN32
    system("cmd /c start notepad results.txt");
#elif __APPLE__
    system("open results.txt");
#else
    system("xdg-open results.txt");
#endif

    return ;
}

#endif /* MATRIXOP_H */
