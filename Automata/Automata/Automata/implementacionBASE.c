#include "interfazBASE.h"

T_ele carga_ele(){   /*carga una cadena por teclado*/
	T_ele nuevo;
	printf("  ");
	leecad(nuevo.valor,80);
	
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

int compara_ele(T_ele a, T_ele b){      /*compara las cadenas, devuelve valor -1, 0, 1*/
	return strcmp(a.cadena, b.cadena);
}

void retorna_ele(T_ele uno,Tcadena aux){     /*retorna la cadena de la estructura EN la cadena c*/
	strcpy(aux, uno.cadena);
}

T_ele carga_caracter_ele(char a){                 /*ni idea*/
	Tcadena c;
	c[0]=a;
	c[1]=0;
	return carga_ele(c);
}
