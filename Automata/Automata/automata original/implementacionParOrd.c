#include "interfazParOrd.h"

Tpar crearUnPar(T_ele x,T_ele y){
	Tpar nuevo;
	nuevo.a=x;
	nuevo.b=y;
	return nuevo;
}
int parIguales(Tpar x,Tpar y){
	if(compara_ele(x.a,y.a)==0 && compara_ele(x.b,y.b)==0)
		return 1;
	else 
		return 0;
}
void mostrarPar(Tpar x){
	printf("(");mostrar_uno(x.a);printf(",");mostrar_uno(x.b);printf(")");
}
