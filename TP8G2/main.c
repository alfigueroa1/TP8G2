/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: HP
 *
 * Created on May 15, 2019, 8:35 PM
 */

#include <stdio.h>
#include "constants.h"
#include "conv2float.h"

float sum(float a, float b);
float sub(float a, float b);
float mul(float a, float b);
float div(float a, float b);
float expo(float a, float b);

void getInput(float *a, float *b, char *c);
float calcRes(float x, float y, char op);

char operators[MAX_OPERATORS] = {'+','-','*','/','e',};
float (* actions[MAX_OPERATORS]) (float, float) = {sum, sub, mul, div, expo};

int main(void) {
    
    float x,y;
    char op;
    
    getInput(&x,&y,&op);
    
    printf("Result = %f", calcRes(x,y,op));
    return 0;
}

void getInput(float *x, float *y, char *op){
    return;
}

float calcRes(float x, float y, char op){
    float res = 0;
    int i;
    //VALORES DE PRUEBA
    x = 1.5;
    y = 3.7;
    op = '/';
    //FIN DE PRUEBA
    for(i = 0; operators[i] != op; i++){
        
    }
    res = actions[i](x,y);
    
    return res;
}

float sum(float a, float b){
    return (a + b);
}

float sub(float a, float b){
    return (a - b);
}

float mul(float a, float b){
    return (a * b);
}

float div(float a, float b){
    return (a / b);
}

float expo(float a, float b){   //funca para b entero
    float c;
    c =  a;
    for(;b > 0; b--){
        c = a*c;
    }
    return c;
}

