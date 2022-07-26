#include "interfazARBOL.h"

//TRABAJO PRACTICO TRANSVERSAL (SEGUNDO AVANCE)

//Integrantes:
//           CARDOZO GÓMEZ PAULA NICOLE
//           CHIRI JAIRO MAURICIO

//FUNCION: Carga AF.
//		   Muestra AF.

int menu();

int main(){
	Tarbol arbol;
	int opc;
	
	do{
		opc=menu();
		switch(opc){
		case 1:
			arbol=carga_arbol();
			break;
		case 2:
			break;
		case 0:
			printf("FIN DEL PROGRAMA.");
			break;
		}
	} while(opc);
	return 0;
}

int menu(){
	int b;
	printf("       MENU");
	printf("\n\n1) CARGAR AF.");
	printf("\n2) MOSTRAR AF.");
	printf("\n0) SALIR.");
	do{
		printf("\nElija una opcion: ");
	    scanf("%d", &b);
	}while(b!=0 && b!=1 && b!=2);
	
	return b;
}
