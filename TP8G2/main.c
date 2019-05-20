/***************************************************************************//**
  @file     +main.c+
  @brief    +Calculadora. Realiza operaciones de suma resta. multiplicación,
            división y potencia con números en formato punto flotante. Permite colocar
            el signo de cada número. 
            Ej. 1: +.12*-10
            Ej. 2: -018.010/150.80
            Se pueden realizar múltiples operaciones seguidas y se puede "apagar"
            la calculadora presionado 'X' (mayúscula).
                                                                              
  @author   Grupo 2. 
            Alejo Figueroa
            Olivia de Vincenti
            Pablo Gonzalez
            Brenda Mattaloni Varona
 ******************************************************************************/

#include <stdio.h>
#include "constants.h"
#include "input.h"
#include "operaciones.h"


float calcRes(float x, float y, char op);

//Arreglos recomendados por la catedra
char operators[MAX_OPERATORS];
float (* actions[MAX_OPERATORS]) (float, float);

int main(void) {
    float x,y;
    char op = 0;
    
    //Incicializacion de arreglo operators
    operators[0] = '+';
    operators[1] = '-';
    operators[2] = '*';
    operators[3] = '/';
    operators[4] = '^';
    //Incicializacion de arreglo actions
    actions[0] = &sum;
    actions[1] = &sub;
    actions[2] = &mul;
    actions[3] = &div;
    actions[4] = &expo;
    while(op != 'X') {
        input(&x,&y,&op);    //Se recibe el input del usuario
        if(op == 'X'){
            break;
        }
        printf("Result = %f\n", calcRes(x,y,op)); //Se informa el resultado
    }
    return 0;
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


