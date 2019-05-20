/*******************************************************************************
  @file     +input.c+
  @brief    +Levanta la entrada, la valida y la convierte a float.+
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
static float conv2float (char *num);                                              //Esta funcion convierte un arreglo de tipo char que contiene un numero signado a un float
static int power(int a);                                                          //Esta funcion devuelve 10 elevado a la a
static void clrbuffer();                                                          

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void input (float *a , float *b, char *c) {
    const int maxlong = 30;                                                         //maxima cantidad de caracteres por numero.
    char arr1[maxlong];                                                             //crea arreglos para los numeros.
    char arr2[maxlong];
    if(getInput(arr1,arr2,maxlong,c)){                                              //si la entrada es válida.
        *a = conv2float(arr1);                                                      //convierte cada arreglo al respectivo número en punto flotante.
        *b = conv2float(arr2);
    }
    else {
        input (a , b, c);                                                           //levanta nueva entrada.
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
    int c, cod_error=1, estado = INIT;
    char *p;
    *op = 0;
    while((c = getchar()) != '\n' && maxlong--) {                               //Toma todos los caracteres hasta el máximo establecido.
        switch (estado) {
            case INIT:
                p = a;                                                          //modificamos el primer arreglo.
                if(num1(c) && num2(c)) {                                        //Si ingresa un numero lo guardamos y pasamos a estado ENT.                      
                    *p++ = c;
                    estado = ENT;
                }
                else if(c == '.') {                                             //Si ingresa un punto lo guardamos y pasamos a estado DEC.
                    *p++ = c;
                    estado = DEC;
                }
                else if(c == '-' || c == '+') {                                 //Si ingresa un signo, lo guardamos y pasamos a estado SIGN.
                    *p++ = c;
                    estado = SIGN;
                }
                else if(c == 'X'){                                              //Si ingresa una X se corta la ejecución del programa.
                    *op = 'X';
                    return 1;
                }
                else {                                                          //En cualquier otro caso, la entra es inválida.
                    estado = ERROR;
                }
                break;
                
            case SIGN:                                                          
                if (num1(c)&&num2(c)) {                                         //Si ingresa un número lo guardamos y pasamos a estado ENT.
                   *p++ = c; 
                   estado = ENT;
                }
                else if (c == '.') {                                            //Si ingresa un punto lo guardamos y pasamos a estado DEC.
                    *p++ = c;
                    estado = DEC;
                } 
                else {                                                          //En cualquier otro caso, la entrada es inválida.
                    estado = ERROR;
                }
                break;
                
            case ENT:                                                           
                if (num1(c)&&num2(c)) {                                         //Si ingresa un número lo guardamos y nos quedamos en estado ENT.
                    *p++ = c;
                }
                else if (c == '.') {                                            //Si ingresa un punto lo guardamos y pasamos a estado DEC.
                    *p++ = c;
                    estado = DEC;
                }
                else if (c == '+' || c== '-' || c == '*' || c == '/' || c == '^' || c == 'E' || c == 'e') {
                    if (*op != 0) {                                             //Si ingresa un operador y  había operador, activamos el código de error y la entrada no es válida.
                        estado = ERROR;
                        cod_error = 1;     //codigo de error
                    }
                    else {                                                      //Si ingresa un operador y no había operador, lo guardamos y pasamos a estado OP.
                        *op = c;
                        estado = OP;
                    }
                }
                else {                                                          //En cualquier otro caso, la entrada es inválida.
                    estado = ERROR;
                }
                break;
                
            case DEC:
                if(num1(c)&&num2(c)) {                                          //Si se ingresa un número los guardamos y nos quedamos en estado DEC.
                    *p++ = c;
                }
                else if(c == '+' || c== '-' || c == '*' || c == '/' || c == 'e' || c == 'E') {
                    if (*op != 0) {                                             //Si ingresa un operador y  había operador, activamos el código de error y la entrada no es válida.
                        estado = ERROR;
                        cod_error = 1;    //codigo de error                       
                    }
                    else {                                                      //Si ingresa un operador y no había operador, lo guardamos y pasamos a estado OP.
                        *op = c;
                        estado = OP;
                    }
                }
                else {                                                          //En cualquier otro caso, la entrada es inválida.
                    estado = ERROR;
                }
                break;
                
            case OP:
                *p++ = '\0';                                                    //Agregamos el terminador de la cadena del primer operando.
                p = b;                                                          //Modificamos el segundo arreglo.
                cod_error = 0;
                if (c == '-' || c == '+') {                                     //Si ingresa un signo, los guardamos y pasamos a estado SIGN.
                    *p++ = c;
                    estado = SIGN;
                }
                else if (num1(c)&&num2(c)) {                                    //Si ingresa un número lo guardamos y pasamos a estado ENT.
                    *p++ = c;
                    estado = ENT;
                }
                else if (c == '.') {                                            //Si ingresa un punto lo guardamos y pasamos a estado DEC.
                    *p++ = c;
                    estado = DEC;
                }
                else {                                                          //En cualquier otro caso, la entrada es inválida.
                    estado = ERROR;
                }
                break;
                
            case ERROR: 
                clrbuffer;
                printf("Error. Ingrese todo de nuevo.\n");                                  //si la entrada fue inválida.
                return 0;                                                       //denota entrada inválida.
                break;
                
            default:                                                            //default defensivo
                clrbuffer;
                printf("Error. Ingrese todo de nuevo.\n");                                  //si la entrada fue inválida.
                return 0;
                break;
        }
    }

    if(!maxlong){                                                              //si se excedió el máximo la entrada es inválida
        printf("Error. Ingrese todo de nuevo.\n");                                  //si la entrada fue inválida.
        
        return 0;                                                            
    }
    else if(cod_error){                                                               //Si está activiado el código de error la entrada es inválida.
        printf("Error. Ingrese todo de nuevo.\n");                                  //si la entrada fue inválida.
        clrbuffer;
        return 0;
    }
    else if(!(num1(*(p-1))&&num2(*(p-1)))) {                                           //Si el último caracter ingresado no es un número, la entrada es inválida.
        printf("Error. Ingrese todo de nuevo.\n");                                  //si la entrada fue inválida.
        return 0;
    }
    *p++ = '\0';                                                                //Agrega el terminador a la segunda cadena
    return 1;
}

//clrbuffer limpia el buffer después de detectar un error.
static void clrbuffer() {    
    while(getchar() != 'n') { }
}

//Esta funcion convierte un arreglo de un numero decimal a float
static float conv2float (char *num){
    int i = 0;
    int cant = 0;
    int dp = -1;
    float res = 0;
    if (num[0] == '+'){                                                         //Si el numero empieza con +, se lo ignora
        while((num[i] != '\0')){                                                //Se busca la cantidad de elementos del arreglo
            if(num[i] == '.'){                                                  //Se identifica el punto decimal, si lo hubiera
                dp = i;                                                         //Y se lo guarda
            }
            i++;
        }
        cant = i;                                                               //Se guarda la cantidad de elementos
        if(dp == -1){
            dp = cant;                                                          //Si no hay punto decimal, se lo toma al final
        }
        for(i = 1; i < dp; i++){
            res += ((num[i]-48)* (power(dp-i-1)));                              //Se suman los numeros a la izquierda del decimal
        }                                                                       //con su respectiva potencia asociada
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){
            res += ((float)(num[i]-48)/ (power(i-dp)));                         //Se suman los numeros a la derecha del decimal
        }                                                                       //con su respectiva potencia asociada
        return res;
    }
    else if(num[0] == '-'){                                                     //Si el numero empieza con -
        while((num[i] != '\0')){                                                //Se usa la misma metodologia
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
        return (res*(-1));                                                      //Y se devuelve el numero pero con signo negativo
    }
    else{                                                                       //Si no hay signo, se lo toma como positivo
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