#include<stdio.h>
#include<math.h>



//Function to evaluate polynomial at a point x
float poly(float a[], int deg, float x) {
    float p = a[0];
    for (int i = 1; i <= deg; i++) {
        p = p * x + a[i]; // Using Horner's method for efficient evaluation
    }
    return p;
}
