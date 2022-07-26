#include "interfazAF.h"

int main(){
	
	int opc
	T_AF af;
	
	af=crea_AFND();
	muestra_AF(af);
	
	do{
		AceptaCadena(af);
		printf("¿Desea ingresar otra cadena?(0) N0 - (1) SI:  ");
		scanf("%d",&opc);
	} while(opc!=0);
	
	return 0;
}
