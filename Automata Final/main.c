#include "interfazARBOL.h"

//TRABAJO PRACTICO TRANSVERSAL

//Integrantes:
//           CARDOZO GOMEZ PAULA NICOLE
//           CHIRI JAIRO MAURICIO

//FUNCION: Carga automata, determina si una cadena ingresada es aceptada por tal, muestra automata.

int main(){
	int opc;
	Tarbol arbol;
	arbol=arbol_vacio();
	
	printf("\nESTE PROGRAMA DETERMINA SI UNA CADENA ES ACEPTADA POR UN AUTOMATA FINITO, CARGA TANTO AFD COMO AFND\n");
	
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
