#include <stdio.h>

int multiply_int_int(int a,int b){
    int c = a * b;
    return c;
}

float multiply_int_float(int a,float b){
    float c = a * b;
    return c;
}

float multiply_float_int(float a,int b){
    float c = a * b;
    return c;
}

int multiply(int a,int b){
    int c = a * b;
    return c;
}

float multiply(int a,float b){
    float c = a * b;
    return c;
}

float multiply(float a,int b){
    float c = a * b;
    return c;
}

int main(){

    printf("%f",multiply_int_int(2.0,2,0));

    return 0;
}