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

//Function to calculate the dot product of two vectors
double dot_product(double vector1[],double vector2[], int size){
      double result = 0.0;
      for(int i = 0; i < size; i++){
        result += vector1[i] * vector2[i];
      }
      return result;
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

