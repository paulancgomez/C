#include "interfazELEMENTO.h"

T_ele carga_uno(){   /*carga una cadena en la estructura llamada T_ele. Nuevo es una cadena, es un campo de T_ele*/
	T_ele nuevo;
	printf("  ");
	leeCad(nuevo.valor,80);
	
	return nuevo;
}
T_ele carga_ele(Tcadena n){   /*carga una cadena mandandole la cadena como parametro*/
	T_ele nuevo;
	strcpy(nuevo.valor,n);
	return nuevo;
}

void mostrar_uno(T_ele e){       /*muestra la cadena*/
	printf("%s",e.valor);
}
int compara_ele(T_ele a, T_ele b){      /*compara las cadenas, devuelve valor -1, 0, 1*/
	return strcmp(a.valor,b.valor);
}

void retornaValor(T_ele elem,Tcadena c){     /*retorna la cadena de la estructura EN la cadena c*/
	strcpy(c,elem.valor);
}
T_ele carga_caracter(char a){                 /*ni idea*/
	Tcadena c;
	c[0]=a;
	c[1]=0;
	return carga_ele(c);
}
