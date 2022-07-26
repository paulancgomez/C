#include "interfazPAR.h"

T_par carga_par(T_ele x, T_ele y){   /*crea un par ordenado de dos cadenas enviadas como parametro*/
	T_par uno;
	uno.a=x;
	uno.b=y;
	return uno;
}

int par_iguales(T_par x,T_par y){      /*comparo elementos de la primera componente y luego comparo elementos de la segunda componente*/
	if(compara_ele(x.a,y.a)==0 && compara_ele(x.b,y.b)==0)
		return 1;     /*son iguales*/
	else 
		return 0;      /*son distintos*/
}

void muestra_par(T_par uno){       /*muestra el par ordenado enviado como parametro*/
	printf("(");                   /*muestra de la forma ( , )*/
	muestra_ele(uno.a);            /*muestra cadena*/
	printf(",");
	muestra_ele(uno.b);            /*muestra cadena*/
	printf(")");
}
