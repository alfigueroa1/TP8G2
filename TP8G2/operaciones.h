/***************************************************************************//**
  @file     +operaciones.h+
  @brief    +operaciones matemáticas+
  @author   +Grupo 2+
 ******************************************************************************/

#ifndef OPERACIONES_H
#define	OPERACIONES_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "constantes.h"

 /*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
extern char operators[MAX_OPERATORS];
extern float (* actions[MAX_OPERATORS]) (float, float);

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/**
 * @brief sum: operación suma
 * @param param1 operando 1
 * @param param2 operando 2
 * @return suma de los operandos
*/
float sum(float a, float b);

/**
 * @brief sub: operación resta
 * @param param1 operando 1
 * @param param2 operando 2
 * @return resta de los operandos (1-2)
*/
float sub(float a, float b);

/**
 * @brief mul: operación multiplicación
 * @param param1 operando 1
 * @param param2 operando 2
 * @return producto de los operandos
*/
float mul(float a, float b);

/**
 * @brief div: operación división
 * @param param1 operando 1
 * @param param2 operando 2
 * @return cociente de los operandos (1/2) 
*/
float div(float a, float b);

/**
 * @brief expo: operación potencia
 * @param param1 base (a)
 * @param param2 exponente (b) 
 * @return base elevada al exponente (a^b)
*/
float expo(float a, float b);

/**
 * @brief calcRes: calcula el resultado
 * @param param1 operando 1
 * @param param2 operando 2 
 * @param param2 operacion 
 * @return resultado
*/
float calcRes(float x, float y, char op);
#endif	/* OPERACIONES_H */

