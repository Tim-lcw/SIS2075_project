#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdio.h>
#include <stdlib.h>
#include"menu.h"

// Function prototypes
void decToBi(int decimal, FILE *outputFile);
void decToBinary(int n, FILE *outputFile);
long long convertBinaryToDecimal(long long n);
void runProgram();

// Function to convert decimal to binary and write to the file
void decToBi(int decimal, FILE *outputFile) {
    int binary[32];
    int i = 0;
    if (decimal == 0) {
        fprintf(outputFile, "0");
    } else {
        while (decimal > 0) {
            binary[i] = decimal % 2;
            decimal /= 2;
            i++;
        }
        for (i = i - 1; i >= 0; i--) {
            fprintf(outputFile, "%d", binary[i]);
        }
    }
    fprintf(outputFile, "\n");
}

// Function to convert decimal to binary and write to file
void decToBinary(int n, FILE *outputFile) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        fprintf(outputFile, "%d", binaryNum[j]);
    }
    fprintf(outputFile, "\n");
}

// Function to convert binary to decimal
long long convertBinaryToDecimal(long long n) {
    long long dec = 0;
    int i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        dec += rem << i;
        n /= 10;
        ++i;
    }
    return dec;
}

// Main logic moved to runProgram function
void runConvertor() {
    int choice, num;
    long long binaryNum;

printf("Select options for conversions and Insert [7] to show results\n");

    // Open the output file in write mode (to refresh/overwrite the file each time)
    FILE *outputFile = fopen("outputConvertor.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(outputFile, "----------Conversion Start-------------\n");
    while (1) {
        // Display menu and prompt for user input
        printf("Select an operation to perform:\n");
        printf("1. Convert Hexadecimal to Denary\n");
        printf("2. Convert Hexadecimal to Binary\n");
        printf("3. Convert Decimal to Hexadecimal\n");
        printf("4. Convert Decimal to Binary\n");
        printf("5. Convert Binary to Hexadecimal\n");
        printf("6. Convert Binary to Decimal\n");
        printf("7. Show results\n");
        printf("Insert choice [1-7]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { //Hexadecimal to Denary
                int hexValue;
                printf("Insert Hexadecimal value: ");
                scanf("%x", &hexValue);
                fprintf(outputFile, "The denary number of %X is: %d\n", hexValue, hexValue);
                fflush(outputFile);  // Ensure the file is updated immediately
                break;
            }
            case 2: { //Hexadecimal to Binary
                printf("Insert Hexadecimal value: ");
                scanf("%x", &num);
                fprintf(outputFile, "The binary number of %X is: ", num);
                decToBi(num, outputFile);
                fflush(outputFile);  // Ensure the file is updated immediately
                break;
            }
            case 3: { // Decimal to Hexadecimal
                printf("Insert Decimal number: ");
                scanf("%d", &num);
                fprintf(outputFile, "The hexadecimal number of %d is: %X\n", num, num);
                fflush(outputFile);  // Ensure the file is updated immediately
                break;
            }
            case 4: { //Decimal to Binary
                printf("Insert Decimal number: ");
                scanf("%d", &num);
                fprintf(outputFile, "The binary number of %d is: ", num);
                decToBinary(num, outputFile);
                fflush(outputFile);
                break;
            }
            case 5: { //Binary to Hexadecimal
                long int hexNum = 0, i = 1, remainder;
                printf("Insert Binary number: ");
                scanf("%lld", &binaryNum);
                long int originalBinary = binaryNum; //Store original input for display
                while (binaryNum != 0) {
                    remainder = binaryNum % 10;
                    hexNum = hexNum + remainder * i;
                    i = i * 2;
                    binaryNum = binaryNum / 10;
                }
                fprintf(outputFile, "The hexadecimal number of %ld in binary is: %lX\n", originalBinary, hexNum);
                fflush(outputFile);  
                break;
            }
            case 6: { //Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNum);
                fprintf(outputFile, "The decimal number of %lld in binary is: %lld\n", binaryNum, convertBinaryToDecimal(binaryNum));
                fflush(outputFile); 
                break;
            }
           case 7: { 
                fprintf(outputFile, "----------Conversion Complete-------------\n");
                fclose(outputFile);  
                
                // Open the output file after the program exits
                #ifdef _WIN32
                    system("notepad outputConvertor.txt"); 
                #else
                    system("open outputConvertor.txt");  
                #endif
                
                return;
            }
            
            default:
                printf("Invalid option\n");
        }
    }
}

#endif // CONVERSION_H
