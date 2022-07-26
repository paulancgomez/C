#include "interfazParOrd.h"

Tpar crearUnPar(T_ele x,T_ele y){   /*crea un par ordenado de dos cadenas enviadas como parametro*/
	Tpar uno;
	uno.a=x;
	uno.b=y;
	return uno;
}
int parIguales(Tpar x,Tpar y){      /*comparo elementos de la primera componente y luego comparo elementos de la segunda componente*/
	if(compara_ele(x.a,y.a)==0 && compara_ele(x.b,y.b)==0)
		return 1;     /*son iguales*/
	else 
		return 0;      /*son distintos*/
}
void mostrarPar(Tpar x){       /*muestra el par ordenado enviado como parametro*/
	printf("(");                   /*muestra de la forma ( , )*/
	mostrar_uno(x.a);
	printf(",");
	mostrar_uno(x.b);
	printf(")");
}
