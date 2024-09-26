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
        result += vector1[i]*vector2[i];
      }
      return result;
}
