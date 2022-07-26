#include "interfazELEMENTO.h"

T_ele carga_ele(){   /*carga una cadena por teclado*/
	T_ele nuevo;
	leeCad(nuevo.cadena,80);
	return nuevo;
}

T_ele carga_ele_parametro(Tcadena cad){   /*carga una cadena mandandole la cadena como parametro*/
	T_ele uno;
	strcpy(uno.cadena, cad);
	return uno;
}

void muestra_ele(T_ele uno){       /*muestra la cadena*/
	printf("%s", uno.cadena);
}

int compara_ele(T_ele a, T_ele b){ /*compara las cadenas, devuelve valor -1, 0, 1*/
	int r;
	if(a.cadena==" "){
		r=0;
	}
	else{
		r=strcmp(a.cadena, b.cadena);
	}
	return r;
}

void retorna_ele(T_ele uno,Tcadena aux){     /*retorna la cadena de la estructura EN la cadena c*/
	strcpy(aux, uno.cadena);
}

T_ele carga_caracter_ele(char a){                 /*retorna un T_ele que contenga una cadena que comience con el char a, seguido de 0*/
	Tcadena c;
	c[0]=a;
	c[1]=0;
	return carga_ele_parametro(c);
}
