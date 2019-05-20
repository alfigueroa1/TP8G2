/* 
 * File:   main.c
 * Author: Grupo 2
 *
 * Created on May 15, 2019, 8:35 PM
 */

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "input.h"
#include "operaciones.h"
#include "constantes.h"

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
//Arreglos recomendados por la catedra
char operators[MAX_OPERATORS];
float (* actions[MAX_OPERATORS]) (float, float);

/*******************************************************************************
 * MAIN
 ******************************************************************************/
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



