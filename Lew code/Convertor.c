#include<stdio.h>

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

int main(){
    int choice;
     while (1){
    printf("Select an operation to perform:\n");
    printf("1. Convert Hexadecimal to Denary\n");
    printf("2. Convert Hexadecimal to Binary\n");
    printf("3. Convert Decimal to Hexadecimal\n");
    printf("4. Convert Decimal to Binary\n");
    printf("5. Convert Binary to Hexadecimal\n");
    printf("6. Convert Binary to Decimal\n");
    printf("7. Exit\n");
    printf("Insert choice [1-7]: ");
    scanf("%d", &choice);
   
    
    switch (choice) {
        case 1: { // Hexadecimal to Denary
            int n;
            printf("Insert Hexadecimal value: ");
            scanf("%x", &n);
            printf("Denary number is: %d\n", n);
            break;
        }
        case 2: { // Hexadecimal to Binary
            int num;
            printf("Insert Hexadecimal value: ");
            scanf("%x", &num);
            printf("Binary number is: ");
            decToBi(num);
            break;
        }
        case 3: { // Decimal to Hexadecimal
            int num;
            printf("Insert Decimal number: ");
            scanf("%d", &num);
            printf("Hexadecimal number is: %X\n", num);
            break;
        }
        case 4: { // Decimal to Binary
            int num;
            printf("Insert Decimal number: ");
            scanf("%d", &num);
            printf("Binary number is: ");
            decToBinary(num);
            printf("\n");
            break;
        }
        case 5: { // Binary to Hexadecimal
            long int biNum, hexNum = 0, i = 1, remainder;
            printf("Insert Binary number: ");
            scanf("%ld", &biNum);
            while (biNum != 0) {
                remainder = biNum % 10;
                hexNum = hexNum + remainder * i;
                i = i * 2;
                biNum = biNum / 10;
            }
            printf("Equivalent hexadecimal value: %lX\n", hexNum);
            break;
        }
        case 6: { // Binary to Decimal
            long long n;
            printf("Enter a binary number: ");
            scanf("%lld", &n);
            printf("%lld in binary is %lld in decimal\n", n, convertBinaryToDecimal(n));
            break;
        }
        case 7: { 
                printf("Exiting...\n");
                return 0;
        default:
            printf("Invalid option\n");
    }
    }
    
}
}