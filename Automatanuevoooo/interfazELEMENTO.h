#ifndef INTERFAZELEMENTO_H
#define INTERFAZELEMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfazCADENA.h"

typedef struct {
	Tcadena valor;
}T_ele;


void retornaValor(T_ele, Tcadena);
T_ele carga_caracter(char);
int leecad(Tcadena ,int );
T_ele carga_uno();
/*char * retornavalor(T_ele);*/
T_ele carga_ele(Tcadena);
//char * retorna_valor(T_ele);
void mostrar_uno(T_ele);
int compara_ele(T_ele, T_ele);//DEVUELVE 1 SI EL PRIMERO ES MAYOR QUE SEGUNDO, -1 VICEVERSA Y 0 SI SON IGUALES
//
/*typedef struct {
char valor;
}T_ele;

T_ele carga_uno();
T_ele carga_ele(char );
char retorna_valor(T_ele);
void mostrar_uno(T_ele);
int compara_ele(T_ele, T_ele);//DEVUELVE 1 SI EL PRIMERO ES MAYOR QUE SEGUNDO, -1 VICEVERSA Y 0 SI SON IGUALES
//*/

#endif
