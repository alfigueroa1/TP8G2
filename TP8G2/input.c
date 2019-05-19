/*******************************************************************************
  @file     +input.c+
  @brief    +Levanta la entrada, la valida y la convierte.+
  @author   +GRUPO 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "input.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define num1(x) ((x)>='0')
#define num2(x) ((x)<='9')

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static int getInput(char *a, char *b, int maxlong, char *op);
static float conv2float (char *num);   //Esta funcion convierte un arreglo de tipo char que contiene un numero signado a un float
static int power(int a);                //Esta funcion devuelve 10 elevado a la a

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void input (float *a , float *b, char *c) {
    int maxlong = 30;
    char arr1[maxlong];
    char arr2[maxlong];
    if(getInput(arr1,arr2,maxlong,c)){
        *a = conv2float(arr1);
        *b = conv2float(arr2);
    }
    else {
        printf("\nError. Ingrese todo de nuevo.\n");
        void input (float *a , float *b, char *c);
    }
    return;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

//getInput recibe dos punteros a arreglos de caracteres, su longitud (maxlong)
//y un puntero a una variable op para el operando.
//La función guarda los números ingresados en los arreglos y el operador en la
//variable op.
//Devuelve un 0 si hubo un error y un 1 sino.
static int getInput(char *a, char *b, int maxlong, char *op) {
    enum estados{INIT , SIGN , ENT , DEC , OP , ERROR};
    int c, estado = INIT;
    char *p;
    while((c = getchar()) != '\n' && maxlong--) {
        switch (estado) {
            case INIT:
                p = a;
    
                if(num1(c) && num2(c)) {
                    *p++ = c;
                    estado = ENT;
                }
                else if(c == '.') {
                    *p++ = c;
                    estado = DEC;
                }
                else if(c == '-' || c == '+') {
                    *p++ = c;
                    estado = SIGN;
                }
                else {
                    estado = ERROR;
                }
                break;
                
            case SIGN:
                if (num1(c)&&num2(c)) {
                   *p++ = c; 
                   estado = ENT;
                }
                else if (c == '.') {
                    *p++ = c;
                    estado = DEC;
                } 
                else {
                    estado = ERROR;
                }
                break;
                
            case ENT:
                if (num1(c)&&num2(c)) {
                    *p++ = c;
                }
                else if (c == '.') {
                    *p++ = c;
                    estado = DEC;
                }
                else if (c == '+' || c== '-' || c == '*' || c == '/' || c == '^' || c == 'E' || c == 'e') {
                    estado = OP;
                    *op = c;
                }
                else {
                    estado = ERROR;
                }
                break;
                
            case DEC:
                if(num1(c)&&num2(c)) {
                    *p++ = c;
                }
                else if(c == '+' || c== '-' || c == '*' || c == '/' || c == 'e' || c == 'E') {
                    estado = OP;
                    *op = c;
                }
                else {
                    estado = ERROR;
                }
                break;
                
            case OP:
                *p++ = '\0';
                p = b;
                if (c == '-' || c == '+') {
                    *p++ = c;
                    estado = SIGN;
                }
                else if (num1(c)&&num2(c)) {
                    *p++ = c;
                    estado = ENT;
                }
                else if (c == '.') {
                    *p++ = c;
                    estado = DEC;
                }
                else {
                    estado = ERROR;
                }
                break;
                
            case ERROR:
                estado = INIT;
                return 0;
                break;
                
            default: 
                estado = INIT; 
                return 0;
                break;
        }
    }
    if(!maxlong)
        return 0;
    if(!(num1(*(p-1))&&num2(*(p-1))))
        return 0;
    *p = '\0';
    return 1;
}

//Esta funcion convierte un arreglo de un numero decimal a float
static float conv2float (char *num){
    int i = 0;
    int cant = 0;
    int dp = -1;
    float res = 0;
    if (num[0] == '+'){
        while((num[i] != '\0')){
            if(num[i] == '.'){
                dp = i;
            }
            i++;
        }
        cant = i;
        if(dp == -1){
            dp = cant;
        }
        for(i = 1; i < dp; i++){
            res += ((num[i]-48)* (power(dp-i-1)));
        }
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){
            res += ((float)(num[i]-48)/ (power(i-dp)));
        }
        return res;
    }
    else if(num[0] == '-'){
        while((num[i] != '\0')){
            if(num[i] == '.'){
                dp = i;
            }
            i++;
        }
        cant = i;
        if(dp == -1){
            dp = cant;
        }
        for(i = 1; i < dp; i++){
            res += ((num[i]-48)* (power(dp-i-1)));
        }
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){
            res += ((float)(num[i]-48)/ (power(i-dp)));
        }
        return (res*(-1));
    }
    else{
        while((num[i] != '\0')){
            if(num[i] == '.'){
                dp = i;
            }
            i++;
        }
        cant = i;
        if(dp == -1){
            dp = cant;
        }
        for(i = 0; i < dp; i++){
            res += ((num[i]-48)* (power(dp-i-1)));
        }
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){
            res += ((float)(num[i]-48)/ (power(i-dp)));
        }
        return res;
    }
}
//Esta funcion toma como parametro un entero y devuelve
// como resultado 10 elevado a la a
static int power(int a){
    int res = 1;
    while(a>0){         //Se multiplica res por 10 las veces necesarias
        res *=10;
        a--;
    }
    return res;
}