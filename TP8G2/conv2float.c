#include "conv2float.h"

//Esta funcion convierte un arreglo de un numero decimal a float
float conv2float (char *num){
    int i = 0;
    int cant = 0;
    int dp = -1;
    float res = 0;
    if (num[0] == '+'){                         //Si el numero tiene un '+' al inicio, este es obviado
        while((num[i] != '\0')){                //Se busca donde esta el punto decimal
            if(num[i] == '.'){
                dp = i;                         //Y se guarda
            }
            i++;
        }
        cant = i;                               //Se guarda la cantidad de elementos del arreglo
        for(i = 1; i < dp; i++){                //Se trabaja con los numeros a la izquierda del decimal
            res += ((num[i]-48)* (power(dp-i-1)));  //Se los suma uno por uno, multiplicados por su respectiva potencia de 10
        }
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){          //Se trabaja con los numeros a la derecha del decimal
            res += ((float)(num[i]-48)/ (power(i-dp)));
        }
        return res;                             //Se devuelve el resultado
    }
    else if(num[0] == '-'){                 //Si el numero tiene un '-' al inicio, se lo aplica al final
        while((num[i] != '\0')){
            if(num[i] == '.'){
                dp = i;
            }
            i++;
        }
        cant = i;
        for(i = 1; i < dp; i++){
            res += ((num[i]-48)* (power(dp-i-1)));
        }
    
        //ahora i = dp
        for(i = dp+1 ; i < cant; i++){
            res += ((float)(num[i]-48)/ (power(i-dp)));
        }
        return (res*(-1));
    }
    else{                                       //Si solo se tiene el numero, no se aplica ningun criterio
        while((num[i] != '\0')){
            if(num[i] == '.'){
                dp = i;
            }
            i++;
        }
        cant = i;
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
int power(int a){
    int res = 1;
    while(a>0){         //Se multiplica res por 10 las veces necesarias
        res *=10;
        a--;
    }
    return res;
}