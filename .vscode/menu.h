#include<stdio.h>

int menu()
{
	float result;
	int choice, num;

	printf("\n\n\n\n\n\t-----\t WELCOME TO Algo Minds \t-----\n");
    printf("\n\n\n\t----\t You don't need to use your minds \t----\n");
	printf("\n\n\t-----\t MENU \t -----\n");

	printf("1. For Polynomials \n");
	printf("2. For Binary Convert \n");
	
	printf("Enter your choice:");
	scanf("%d", &choice);
	//choice = input();
	
	switch (choice) {
	case 1: {
		//solve_polynomial();
		break;
	}
	case 2: {
		//call supplier menu
		//Convertor();
		break;
	}
	default:
		printf("wrong Input\n");
	}
	return 0;
}