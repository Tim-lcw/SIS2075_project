#include <stdio.h>
#include "permutation_combination.h" // Include your permutation and combination functions
#include "matrix_determinant.h"    // Include your matrix determinant functions
#include "matrix_inverse.h"       // Include your matrix inverse functions
#include "matrix_lu.h"           // Include your LU decomposition functions
#include "matrix_qr.h"          // Include your QR decomposition functions
#include "matrix_rank.h"               // Include your matrix rank functions
#include "matrix_hadamard.h"           // Include your hadamard functions
#include "matrix_eigen.h"                     // Include your eigenvalue decomposition functions
#include "matrix_add_sub_multiply.h"          // Include your basic matrix functions
#include "matrix_svd.h"                       // Include your SVD functions
#include "matrix_cholesky.h"                  // Include your Cholesky decomposition functions

// Function to display the menu
void display_menu_matrix() {
    printf("======================================\n");
    printf("Operations Menu\n");
    printf("======================================\n");
    printf("1. Permutation and Combination Operations\n");
    printf("2. Matrix Determinant\n");
    printf("3. Matrix Inverse\n");
    printf("4. LU Decomposition\n");
    printf("5. QR Decomposition\n");
    printf("6. Matrix Rank\n");
    printf("7. Hadamard Product\n");
    printf("8. Eigenvalue Decomposition\n");
    printf("9. Basic Matrix Operations (Addition, Subtraction, Multiplication)\n");
    printf("10. Singular Value Decomposition (SVD)\n");
    printf("11. Cholesky Decomposition\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
}

// Main menu function
void menu_matrix() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                permutation_operations(); // Call the permutation operations function
                break;
            case 2:
                matrix_determinant();      // Call the matrix determinant function
                break;
            case 3:
                matrix_inverse();          // Call the matrix inverse function
                break;
            case 4:
                matrix_lu();               // Call the LU decomposition function
                break;
            case 5:
                matrix_qr();               // Call the QR decomposition function
                break;
            case 6:
                matrix_rank();             // Call the matrix rank function
                break;
            case 7:
                matrix_hadamard();         // Call the Hadamard product function
                break;
            case 8:
                matrix_eigen();            // Call the eigenvalue decomposition function
                break;
            case 9:
                matrix_add_sub_multiply();  // Call the basic matrix operations function
                break;
            case 10:
                matrix_svd();              // Call the SVD function
                break;
            case 11:
                matrix_cholesky();         // Call the Cholesky decomposition function
                break;
            case 12:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 12);
}