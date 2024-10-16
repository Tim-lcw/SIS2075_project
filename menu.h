#ifndef MENU_H
#define MENU_H


#include<stdio.h>
#include "Convertor.h"
#include "polynomial.h"
#include "solver.h"
#include"vectorCalc.h"
#include "plotFunc.h"
#include "matrixop.h"

void menuMain(){
	float result;
	int choice, num;
while(1){
	printf("\n\n\n\n\n\t-----\t AlgoMinds Calculator \t-----\n");
	printf("\n\n\t-----\t MENU \t -----\n");
    printf("Choose a Function [1-7]\n");
	printf("1. Convertor\n");
	printf("2. Find Value of f(x) and f'(x) at given point. \n");
    printf("3. Find Roots of Polynomial\n");
	printf("4. Perfom Vector operations\n");
    printf("5. Graphing Calculator\n");
	printf("6. Matrix Operations\n");
    printf("7. Exit Calculator\n");
	
	
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	
	switch (choice) {
	case 1: {
		runConvertor();
		break;
	}
	case 2: {
		runPolynomial();
		break;
	}
    case 3: {
		runSolver();
		break;
	}
    case 4: {
		vector();
		break;
	}
    case 5: {
		plotGraph();
		break;
	}
    case 6: {
		runMatOp();
		
		break;
	}
    case 7: {
        printf("Exiting...");
		return ;
		break;
	}
	default:
		printf("wrong Input\n");
	}
	
}
}
#endif //MENU_H
