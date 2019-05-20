/***************************************************************************//**
  @file     +operaciones.c+
  @brief    +operaciones matemáticas+
  @author   +Grupo 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "operaciones.h" 

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


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

//Esta funcion toma como parametros dos numeros del tipo float y una operacion
// Devuelve el resultado de la operacion en tipo float
float calcRes(float x, float y, char op){
    float res = 0;
    int i;
    for(i = 0; operators[i] != op; i++){       //Se identifica la operacion deseada
    }
    res = actions[i](x,y);                     //Se llama a la funcion de dicha operacion
    
    return res;
}


