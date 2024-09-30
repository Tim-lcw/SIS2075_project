#include <stdio.h>
#include "convertor.h"

// Convert decimal to binary and print 
void decToBi(int decimal) {
    int binary[32];
    int i = 0;
    if (decimal == 0) {
        printf("0");
    } else {
        while (decimal > 0) {
            binary[i] = decimal % 2;
            decimal /= 2;
            i++;
        }
        for (i = i - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }
    }
    printf("\n");
}

// Convert decimal to binary and print 
void decToBinary(int n){
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// Convert binary to decimal
long long convertBinaryToDecimal(long long n){
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
