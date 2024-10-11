#ifndef PERMUTATION_COMBINATION_H
#define PERMUTATION_COMBINATION_H

#include <stdio.h>
#include "menu_matrix.h"

// Function to compute factorial of a number
static inline long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function for Permutation P(n, r) = n! / (n - r)!
static inline long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function for Combination C(n, r) = n! / (r! * (n - r)!)
static inline long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function for Permutation with Repetition P(n, r) = n^r
static inline long long permutationWithRepetition(int n, int r) {
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= n;
    }
    return result;
}

// Function for Combination with Repetition C(n + r - 1, r)
static inline long long combinationWithRepetition(int n, int r) {
    return combination(n + r - 1, r);
}

// Function for Circular Permutation P_circular(n) = (n - 1)!
static inline long long circularPermutation(int n) {
    return factorial(n - 1);
}

// Function for Distinguishable Permutation P(n; n1, n2, ..., nk) = n! / (n1! * n2! * ... * nk!)
static inline long long distinguishablePermutation(int n, int freq[], int k) {
    long long result = factorial(n);
    for (int i = 0; i < k; i++) {
        result /= factorial(freq[i]);
    }
    return result;
}

// Function for Derangement D(n)
static inline long long derangement(int n) {
    long long derange[n + 1];
    derange[0] = 1;  // D(0) = 1
    derange[1] = 0;  // D(1) = 0
    for (int i = 2; i <= n; i++) {
        derange[i] = (i - 1) * (derange[i - 1] + derange[i - 2]);
    }
    return derange[n];
}

// Function to display the menu and run operations
static inline void run_permutation_combination_operations() {
    int choice, n, r, k, freq[10];

    printf("======================================\n");
    printf("Permutation and Combination Operations\n");
    printf("======================================\n");
    printf("Choose an operation to perform:\n");
    printf("1. Permutation P(n, r)\n");
    printf("2. Combination C(n, r)\n");
    printf("3. Permutation with Repetition P(n, r)\n");
    printf("4. Combination with Repetition C(n + r - 1, r)\n");
    printf("5. Circular Permutation P_circular(n)\n");
    printf("6. Distinguishable Permutation\n");
    printf("7. Derangement !n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter n (total items): ");
            scanf("%d", &n);
            printf("Enter r (items to arrange): ");
            scanf("%d", &r);
            printf("Permutation P(%d, %d) = %lld\n", n, r, permutation(n, r));
            break;
        case 2:
            printf("Enter n (total items): ");
            scanf("%d", &n);
            printf("Enter r (items to choose): ");
            scanf("%d", &r);
            printf("Combination C(%d, %d) = %lld\n", n, r, combination(n, r));
            break;
        case 3:
            printf("Enter n (total items): ");
            scanf("%d", &n);
            printf("Enter r (items to arrange with repetition): ");
            scanf("%d", &r);
            printf("Permutation with Repetition P(%d, %d) = %lld\n", n, r, permutationWithRepetition(n, r));
            break;
        case 4:
            printf("Enter n (total items): ");
            scanf("%d", &n);
            printf("Enter r (items to choose with repetition): ");
            scanf("%d", &r);
            printf("Combination with Repetition C(%d + %d - 1, %d) = %lld\n", n, r, r, combinationWithRepetition(n, r));
            break;
        case 5:
            printf("Enter n (total items in a circle): ");
            scanf("%d", &n);
            printf("Circular Permutation P_circular(%d) = %lld\n", n, circularPermutation(n));
            break;
        case 6:
            printf("Enter n (total items): ");
            scanf("%d", &n);
            printf("Enter the number of distinct groups (k): ");
            scanf("%d", &k);
            printf("Enter the frequency of each distinct group (separated by space): ");
            for (int i = 0; i < k; i++) {
                scanf("%d", &freq[i]);
            }
            printf("Distinguishable Permutation = %lld\n", distinguishablePermutation(n, freq, k));
            break;
        case 7:
            printf("Enter n (total items for derangement): ");
            scanf("%d", &n);
            printf("Derangement !%d = %lld\n", n, derangement(n));
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

#endif // PERMUTATION_COMBINATION_H
