#include "operaciones.h" 

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

