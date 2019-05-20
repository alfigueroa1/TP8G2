/***************************************************************************//**
  @file     +const-y-vars.h+
  @brief    +contiene constantes y variables de uso general+
  @author   +Grupo 2+
 ******************************************************************************/
#ifndef CONST_Y_VARS_H
#define	CONST_Y_VARS_H
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MAX_OPERATORS 5

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
//Arreglos recomendados por la catedra
char operators[MAX_OPERATORS];
float (* actions[MAX_OPERATORS]) (float, float);

#endif	/* CONST_Y_VARS_H */

