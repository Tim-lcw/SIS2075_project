#include "finder.h"


float poly(float a[], int deg, float x){
    float p = a[0];
    for (int i = 1; i <= deg; i++) {
        p = p * x + a[i]; 
    }
    return p;
}


float deriv(float a[], int deg, float x){
    float pd = 0;
    for (int i = 0; i < deg; i++){ 
        pd = pd * x + (deg - i) * a[i];
    }
    return pd;
}
