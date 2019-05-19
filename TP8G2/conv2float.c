/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "conv2float.h"

float conv2float (char *num){
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

int power(int a){
    int res = 1;
    while(a>0){
        res *=10;
        a--;
    }
    return res;
}