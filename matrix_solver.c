#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10 


// Functions 
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void matrixAddition(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void matrixMultiplication(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2);
int determinant(int matrix[MAX][MAX], int n);
void cofactor(int matrix[MAX][MAX], int temp[MAX][MAX], int p, int q, int n);
void adjoint(int matrix[MAX][MAX], int adj[MAX][MAX], int n);
int inverse(int matrix[MAX][MAX], float inverse[MAX][MAX], int n);
void transpose(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols);
void luDecomposition(int matrix[MAX][MAX], int lower[MAX][MAX], int upper[MAX][MAX], int n);
void qrDecomposition(int matrix[MAX][MAX], float Q[MAX][MAX], float R[MAX][MAX], int rows, int cols);
void eigenvalueDecomposition(int matrix[MAX][MAX], int rows, int cols);
int matrixRank(int matrix[MAX][MAX], int rows, int cols);
void choleskyDecomposition(int matrix[MAX][MAX], float lower[MAX][MAX], int n);
float normMatrix(int matrix[MAX][MAX], int rows, int cols);
void singularValueDecomposition(int matrix[MAX][MAX], int rows, int cols);
void hadamardProduct(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);


// Function Definitions

// Input Matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Print Matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void matrixAddition(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix Multiplication
void matrixMultiplication(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Determinant of Matrix
int determinant(int matrix[MAX][MAX], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    int temp[MAX][MAX];
    int sign = 1;
    for (int i = 0; i < n; i++) {
        cofactor(matrix, temp, 0, i, n);
        det += sign * matrix[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

// Cofactor of Matrix (Helper function for Determinant)
void cofactor(int matrix[MAX][MAX], int temp[MAX][MAX], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Adjoint of Matrix
void adjoint(int matrix[MAX][MAX], int adj[MAX][MAX], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign, temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cofactor(matrix, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

// Inverse of Matrix
int inverse(int matrix[MAX][MAX], float inverse[MAX][MAX], int n) {
    int det = determinant(matrix, n);
    if (det == 0) {
        return 0;
    }
    int adj[MAX][MAX];
    adjoint(matrix, adj, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = adj[i][j] / (float)det;
        }
    }
    return 1;
}

// Transpose of Matrix
void transpose(int matrix[MAX][MAX], int trans[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = matrix[i][j];
        }
    }
}

// LU Decomposition
void luDecomposition(int matrix[MAX][MAX], int lower[MAX][MAX], int upper[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (lower[i][j] * upper[j][k]);
            }
            upper[i][k] = matrix[i][k] - sum;
        }
        for (int k = i; k < n; k++) {
            if (i == k) {
                lower[i][i] = 1;
            } else {
                int sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (lower[k][j] * upper[j][i]);
                }
                lower[k][i] = (matrix[k][i] - sum) / upper[i][i];
            }
        }
    }
}

// QR Decomposition (placeholder for now)
void qrDecomposition(int matrix[MAX][MAX], float Q[MAX][MAX], float R[MAX][MAX], int rows, int cols) {
    // Placeholder implementation. QR decomposition code will go here
}

// Eigenvalue Decomposition (placeholder for now)
void eigenvalueDecomposition(int matrix[MAX][MAX], int rows, int cols) {
    // Placeholder implementation. Eigenvalue/eigenvector calculation code will go here
}

// Matrix Rank Calculation
int matrixRank(int matrix[MAX][MAX], int rows, int cols) {
    // Placeholder for matrix rank calculation
    return 0; // Placeholder return value
}

// Cholesky Decomposition
void choleskyDecomposition(int matrix[MAX][MAX], float lower[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (i + 1); j++) {
            float sum = 0;
            for (int k = 0; k < j; k++) {
                sum += lower[i][k] * lower[j][k];
            }
            if (i == j) {
                lower[i][j] = sqrt(matrix[i][i] - sum);
            } else {
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j];
            }
        }
    }
}

// Matrix Norm Calculation
float normMatrix(int matrix[MAX][MAX], int rows, int cols) {
    float norm = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            norm += matrix[i][j] * matrix[i][j];
        }
    }
    return sqrt(norm);
}

// Singular Value Decomposition (placeholder for now)
void singularValueDecomposition(int matrix[MAX][MAX], int rows, int cols) {
    // Placeholder implementation. SVD code will go here
}

// Hadamard Product
void hadamardProduct(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

// Main Function 
int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int lower[MAX][MAX], upper[MAX][MAX];
    int rows, cols, choice;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    inputMatrix(matrixA, rows, cols);

    do {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. LU Decomposition\n");
        printf("2. Matrix Addition\n");
        printf("3. Matrix Multiplication\n");
        printf("4. Determinant\n");
        printf("5. Inverse\n");
        printf("6. Transpose\n");
        printf("7. QR Decomposition\n");
        printf("8. Eigenvalue Decomposition\n");
        printf("9. Cholesky Decomposition\n");
        printf("10. Norm of Matrix\n");
        printf("11. Singular Value Decomposition\n");
        printf("12. Hadamard Product\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // LU Decomposition
                if (rows == cols) {
                    luDecomposition(matrixA, lower, upper, rows);
                    printf("Lower Triangular Matrix:\n");
                    printMatrix(lower, rows, cols);
                    printf("Upper Triangular Matrix:\n");
                    printMatrix(upper, rows, cols);
                } else {
                    printf("Matrix must be square for LU Decomposition.\n");
                }
                break;
            case 2: // Matrix Addition
                printf("Enter the elements of the second matrix:\n");
                inputMatrix(matrixB, rows, cols);
                matrixAddition(matrixA, matrixB, result, rows, cols);
                printf("Result of Matrix Addition:\n");
                printMatrix(result, rows, cols);
                break;
            case 3: // Matrix Multiplication
                printf("Enter the elements of the second matrix (with same number of columns):\n");
                int cols2;
                scanf("%d", &cols2);
                inputMatrix(matrixB, cols, cols2);
                matrixMultiplication(matrixA, matrixB, result, rows, cols, cols2);
                printf("Result of Matrix Multiplication:\n");
                printMatrix(result, rows, cols2);
                break;
            case 4: // Determinant
                if (rows == cols) {
                    int det = determinant(matrixA, rows);
                    printf("Determinant of the matrix: %d\n", det);
                } else {
                    printf("Matrix must be square to calculate determinant.\n");
                }
                break;
            case 5: // Inverse
                if (rows == cols) {
                    float inv[MAX][MAX];
                    if (inverse(matrixA, inv, rows)) {
                        printf("Inverse of the matrix:\n");
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < cols; j++) {
                                printf("%.2f ", inv[i][j]);
                            }
                            printf("\n");
                        }
                    } else {
                        printf("Matrix is singular, inverse does not exist.\n");
                    }
                } else {
                    printf("Matrix must be square to calculate inverse.\n");
                }
                break;
            case 6: // Transpose
                transpose(matrixA, result, rows, cols);
                printf("Transpose of the matrix:\n");
                printMatrix(result, cols, rows);
                break;
            case 7: // QR Decomposition
                qrDecomposition(matrixA, NULL, NULL, rows, cols); // Placeholder call
                break;
            case 8: // Eigenvalue Decomposition
                eigenvalueDecomposition(matrixA, rows, cols); // Placeholder call
                break;
            case 9: // Cholesky Decomposition
                if (rows == cols) {
                    float lower[MAX][MAX];
                    choleskyDecomposition(matrixA, lower, rows);
                    printf("Cholesky Lower Triangular Matrix:\n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j <= i; j++) {
                            printf("%.2f ", lower[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Matrix must be square for Cholesky Decomposition.\n");
                }
                break;
            case 10: // Norm of Matrix
                printf("Norm of the matrix: %.2f\n", normMatrix(matrixA, rows, cols));
                break;
            case 11: // Singular Value Decomposition
                singularValueDecomposition(matrixA, rows, cols); // Placeholder call
                break;
            case 12: // Hadamard Product
                printf("Enter the elements of the second matrix:\n");
                inputMatrix(matrixB, rows, cols);
                hadamardProduct(matrixA, matrixB, result, rows, cols);
                printf("Result of Hadamard Product:\n");
                printMatrix(result, rows, cols);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
