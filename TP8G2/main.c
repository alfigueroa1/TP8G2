/* 
 * File:   main.c
 * Author: Grupo 2
 *
 * Created on May 15, 2019, 8:35 PM
 */

#include <stdio.h>
#include "constants.h"
#include "input.h"
#include "operaciones.h"


void getInput(float *a, float *b, char *c);
float calcRes(float x, float y, char op);

//Arreglos recomendados por la catedra
char operators[MAX_OPERATORS] = {'+','-','*','/','e',};
float (* actions[MAX_OPERATORS]) (float, float) = {sum, sub, mul, div, expo};

int main(void) {
    float x,y,op;
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
    
    input(&x,&y,&op);    //Se recibe el input del usuario
    
    printf("Result = %f", calcRes(x,y,op)); //Se informa el resultado
    return 0;
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


