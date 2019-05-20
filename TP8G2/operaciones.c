/***************************************************************************//**
  @file     +operaciones.h+
  @brief    +contiene las operaciones matemáticas+
  @author   +Grupo 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "operaciones.h" 


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static float ln(float x);
static float ln_1_2(float y);
static float expo_e (float x);
static float expo_0_1(float x);

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
float expo(float base, float exp) {
	float z;
	float result;
	float lnbase;
	if (base < 0.0){
            lnbase = ln(-base);
	}
	else if (base == 0.0){
            return 0;
	}
	else{
            lnbase = ln (base);
		}
	
	z = exp*lnbase;			//exp*lnbase = z => e^(exp*lnbase) = e^z => base^(exp) = e^z
	
	if (z < 0.0){
		result = 1/expo_e(z);
	}
	else{
		result = expo_e(z);
	}
}
 
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
static float ln(float x) {
	int count;
	float y = x;
	float lny;
	while (y>VAL_MAX_LN){			//transformo x para que quede expresada como una potencia de 2 por un decimal entre 1 y 2
		y/=VAL_MAX_LN;
		count++;
	}
									
	lny = ln_1_2(y);
	
	return (count*LN_2 + lny);		//x = (2^count)*y => ln(x) = ln((2^count)*y) => ln(x) = count*ln(2) + ln(y)

}


static float ln_1_2(float y){
	float sn0 = 0.0;				//se calcula el logaritmo natural de y usando su serie de Taylor con una sustitución
	float denom = NINIT;			//esta operacion solo es valida para valores de y entre 1 y 2 (radio de convergencia)
	float term = FORM_LN (y);
	float term_2 = SQUARE(FORM_LN(y));
	float sn = term;
		
	while (sn!=sn0){
		sn0 = sn;
		denom += PAR;
		term *= term_2;
		sn += (term/denom);
	}
	
	return PAR*sn;

}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static float expo_e (float x){
	int count;
	int a = x;						//trunco el valor de x
	float b = x - a;				//x = a + b => e^x = e^(a+b) => e^x = e^(a)*e^(b)
	float ex = VAL_INIT;
	for (count = 1; count<=a; count++){
		ex*=VAL_E;
	}
	return ex*expo_0_1(b);
}

static float expo_0_1(float x){			//se calcula usando su serie de Taylor centrada en 0
	int n = 1, count;				//solo es valida para 0<x<1 (radio de convergencia)
	float ni, nf;
	float y;
	float sn0 = 0.0;
	float sn = VAL_INIT;
	
    while((sn-sn0) > EPSILON){
		sn0 = sn;
		y = x;
		ni = NINIT;
	    nf = ni++;
		for (count = 2; count<=n; count++){
			y*=x;
			nf*=ni;
			ni++;
		}
		sn+=y/nf;
		n++;
	}
	
	return sn;
	
}

