#include <stdio.h>
#include "convertor.h"

int main() {
    int choice;
    while (1) {
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
            case 1:{ 
                int n;
                printf("Insert Hexadecimal value: ");
                scanf("%x", &n);
                printf("Denary number is: %d\n", n);
                break;
            }
            case 2:{ 
                int num;
                printf("Insert Hexadecimal value: ");
                scanf("%x", &num);
                printf("Binary number is: ");
                decToBi(num);
                break;
            }
            case 3:{ 
                int num;
                printf("Insert Decimal number: ");
                scanf("%d", &num);
                printf("Hexadecimal number is: %X\n", num);
                break;
            }
            case 4:{ 
                int num;
                printf("Insert Decimal number: ");
                scanf("%d", &num);
                printf("Binary number is: ");
                decToBinary(num);
                printf("\n");
                break;
            }
            case 5:{ 
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
            case 6:{ 
                long long n;
                printf("Enter a binary number: ");
                scanf("%lld", &n);
                printf("%lld in binary is %lld in decimal\n", n, convertBinaryToDecimal(n));
                break;
            }
            case 7:{
                printf("Exiting...\n");
                return 0;
            }
            default:
                printf("Invalid option\n");
        }
    }
}
