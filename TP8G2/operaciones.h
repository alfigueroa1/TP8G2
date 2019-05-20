/* 
 * File:   operaciones.h
 * Author: Pablo
 *
 * Created on 19 de mayo de 2019, 18:11
 */

#ifndef OPERACIONES_H
#define	OPERACIONES_H

#define FORM_LN(x) (((x)-1)/((x)+1))
#define SQUARE(x) ((x)*(x))

#define LN_2 0.693147
#define	VAL_MAX_LN	2.0
#define PAR	2.0
#define NINIT 1.0
#define VAL_INIT 1.0
#define EPSILON 0.000001
#define VAL_E 2.718281

float sum(float a, float b);
float sub(float a, float b);
float mul(float a, float b);
float div(float a, float b);
float expo(float base, float exp);

#endif	/* OPERACIONES_H */

