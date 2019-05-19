/* 
 * File:   main.c
 * Author: Grupo 2
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

//Arreglos recomendados por la catedra
char operators[MAX_OPERATORS] = {'+','-','*','/','e',};
float (* actions[MAX_OPERATORS]) (float, float) = {sum, sub, mul, div, expo};

int main(void) {
    float x,y;
    char op;
    //Incicializacion de arreglo Operators
    operators[0] = '+';
    operators[1] = '-';
    operators[2] = '*';
    operators[3] = '/';
    operators[4] = 'e';
    //Incicializacion de arreglo actions
    actions[0] = &sum;
    actions[1] = &sub;
    actions[2] = &mul;
    actions[3] = &div;
    actions[4] = &expo;
    
    getInput(&x,&y,&op);    //Se recibe el input del usuario
    
    printf("Result = %f", calcRes(x,y,op)); //Se informa el resultado
    return 0;
}
//Esta funcion toma como parametros las direcciones de los dos floats usados en la operacion
// y la operacion que se les aplicara. Luego de recibir los datos de parte del usuario,
// escribe dichos datos en las direcciones recibidas como parametro.
void getInput(float *x, float *y, char *op){
    return;
}
//Esta funcion toma como parametros dos numeros del tipo float y una operacion
// Devuelve el resultado de la operacion en tipo float
float calcRes(float x, float y, char op){
    float res = 0;
    int i;
    //VALORES DE PRUEBA
    x = 1.5;
    y = 3.7;
    op = '/';
    //FIN DE PRUEBA
    for(i = 0; operators[i] != op; i++){       //Se identifica la operacion deseada
    }
    res = actions[i](x,y);                     //Se llama a la funcion de dicha operacion
    
    return res;
}

//Esta funcion toma como parametros dos numeros del tipo float.
//Devuelve la suma de ambos.
float sum(float a, float b){
    return (a + b);
}
//Esta funcion toma como parametros dos numeros del tipo float.
//Devuelve la resta de ambos.
float sub(float a, float b){
    return (a - b);
}
//Esta funcion toma como parametros dos numeros del tipo float.
//Devuelve la multiplicaicon de ambos.
float mul(float a, float b){
    return (a * b);
}
//Esta funcion toma como parametros dos numeros del tipo float.
//Devuelve la division de ambos.
float div(float a, float b){
    return (a / b);
}
//Esta funcion toma como parametros dos numeros del tipo float.
//Devuelve el primero elevado al segundo.
float expo(float a, float b){   //funca para b entero
    float c;
    c =  a;
    for(;b > 0; b--){
        c = a*c;
    }
    return c;
}

