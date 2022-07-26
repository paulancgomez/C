#ifndef INTERFAZELEMENTO_H
#define INTERFAZELEMENTO_H

#include <stdio.h>
#include <string.h>
#define tam_max 80

typedef char Tcadena [tam_max];

typedef struct {
	Tcadena cadena;
}T_ele;

T_ele carga_ele();
T_ele carga_ele_parametro(Tcadena);
void muestra_ele(T_ele);
void retorna_ele(T_ele, Tcadena);
int compara_ele(T_ele, T_ele); 
T_ele carga_caracter_ele(char);
T_ele  antesComa(Tcadena n);
T_ele entreComa(Tcadena n);
void leeCad(Tcadena, int);
//T_ele entre_corchetes(Tcadena);

#endif
