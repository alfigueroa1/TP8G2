#include <stdio.h>
#include "entrada.h"

#define num1(x) ((x)>='0')
#define num2(x) ((x)<='9')


int getInput(char *a, char *b, char *op) {
    enum {INIT , SIGN , ENT , DEC , OP , ERROR};
    int c, estado = INIT;
    char *p;
    
    while((c = getchar()) != '\n') {
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
                printf("\nError. Ingrese de nuevo.\n");
                estado = INIT;
                return 0;
                break;
                
            default: 
                estado = INIT; 
                return 0;
                break;
        }
    }
    *p = '\0';
    return 1;
}
