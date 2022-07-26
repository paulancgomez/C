#include "interfazARBOL.h"

int main(){
	int opc;
	Tarbol arbol=NULL;
	
	printf("\nESTE PROGRAMA DETERMINA SI UNA CADENA ES ACEPTADA POR UN AF, CARGA TANTO AFD COMO AFND\n");
	
	arbol=carga_arbol();
	printf("\nAUTOMATA CARGADO.");
	
	do{
		printf("\n\nMOSTRANDO DATOS DEL AUTOMATA..");
		muestra_arbol(arbol);
		acepta_cadena(arbol);
		printf("\n\nIngresar otra cadena? (0)NO - (1)SI:  ");
	    scanf("%i",&opc);
		if(opc!=0){
			printf("\n");
			system("pause");
			system("cls");
		}
	}while(opc!=0);
	
	return 0;
}
