#ifndef MATRIX_QR_H
#define MATRIX_QR_H

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

// Function to calculate dot product of two vectors
static inline double dot_product(int n, double vec1[n], double vec2[n]) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

// Function to calculate the norm of a vector
static inline double vector_norm(int n, double vec[n]) {
    return sqrt(dot_product(n, vec, vec));
}

// Function to subtract vectors
static inline void vector_subtract(int n, double vec1[n], double vec2[n], double result[n]) {
    for (int i = 0; i < n; i++) {
        result[i] = vec1[i] - vec2[i];
    }
}

// Function to copy vector
static inline void vector_copy(int n, double src[n], double dest[n]) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Gram-Schmidt QR Decomposition
static inline void gram_schmidt_qr(int m, int n, double A[m][n], double Q[m][n], double R[n][n]) {
    for (int k = 0; k < n; k++) {
        double norm = 0.0;
        for (int i = 0; i < m; i++) {
            norm += A[i][k] * A[i][k];
        }
        R[k][k] = sqrt(norm);

        for (int i = 0; i < m; i++) {
            Q[i][k] = A[i][k] / R[k][k];
        }

        for (int j = k + 1; j < n; j++) {
            R[k][j] = 0.0;
            for (int i = 0; i < m; i++) {
                R[k][j] += Q[i][k] * A[i][j];
            }

            for (int i = 0; i < m; i++) {
                A[i][j] = A[i][j] - Q[i][k] * R[k][j];
            }
        }
    }
}

// Main function to run QR decomposition
static inline void run_qr_decomposition() {
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    double A[m][n];
    input_matrix(m, n, A);

    double Q[m][n];
    double R[n][n];
    
    // Initialize R to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = 0.0;
        }
    }

    gram_schmidt_qr(m, n, A, Q, R);

    printf("Matrix Q (Orthogonal matrix):\n");
    print_matrix(m, n, Q);
    printf("Matrix R (Upper triangular matrix):\n");
    print_matrix(n, n, R);
}

#endif // MATRIX_QR_H
