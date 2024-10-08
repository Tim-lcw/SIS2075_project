#include<stdio.h>
#include<math.h>


//Function to calculate the magnitude of a vector
double vectorMagnitude(double vector[], int size){
    double sum =0.0;
    for(int i = 0; i < size; i++){
        sum += vector[i]*vector[i];
    }
    return sqrt(sum);
}


// Function to calculate the cross product of two 3D vectors
double dot_product(double vector1[], double vector2[], int size){
    double result = 0.0;
    for (int i = 0; i < size; i++){
        result += vector1[i] * vector2[i];
    }

    return result;
}

//Function to calculate the cross product of two 3D vectors
void cross_product(double vector1[], double vector2[], double result[]){
result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

}

int main ()
{
    int size;
    int choice;

    printf("Enter the size of the vector (2 for 2D vector or 3 for 3D vector):");
    scanf("%d",&size);

    if (size != 2 && size != 3){
        printf("This calculator is only for 2D and 3D vectors");
        return 0;
    }

    double vector1[3],vector2[3],result[3];

    //Input the first vector
    printf("Enter the elements of the elements of the first vector:\n");
    
    for (int i = 0; i < size; i++){
        printf("Element %d:", i + 1);
        scanf("%lf",&vector1[i]);
    }

    printf("Select the operation you want to perform:\n");
    printf("1. Vector magnitude\n");
    printf("2. Dot Product\n");
    printf("3.Cross Product(Only for 3D vector)\n");
    scanf("%d",&choice);

    switch(choice){

        case 1:

        printf("The magnitude of the vector is %.2lf\n", vectorMagnitude(vector1,size));
        break;

        case 2:

        printf("Enter the elements of the second vector:\n");
        for (int i = 0; i < size; i++){
            printf("Element %d:", i + 1);
            scanf("%lf", &vector2[i]);
        }

        printf("The dot product of the vector is: %.2lf\n", dot_product(vector1, vector2, size));
        break;

        case 3:
         
         if (size != 3){
            printf("Cross product is only defined for 3D vectors.\n");
            
         }
            else{

                printf("Enter the elements of the second vector:\n");
        for (int i = 0; i < size; i++){
            printf("Element %d:", i + 1);
            scanf("%lf", &vector2[i]);
        }

        cross_product(vector1,vector2, result);
        printf("The cross product of the vectors is : [%.2lf,%.2lf,%.2lf]", result[0],result[1],result[2]);


            }
            break;

            default:
            printf("Your choice is invalid.\n");
         
         return 0;
         
    }
}