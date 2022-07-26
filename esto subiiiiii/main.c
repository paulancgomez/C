#include "interfazARBOL.h"

//TRABAJO PRACTICO TRANSVERSAL

//Integrantes:
//           CARDOZO GOMEZ PAULA NICOLE
//           CHIRI JAIRO MAURICIO

//FUNCION: Carga AF
//		   Muestra AF.

int menu();

int main(){
	Tarbol arbol;
	int opc;
	
	arbol=arbol_vacio();
	
	do{
		opc=menu();
		
		printf("\n");
		system("pause");
		system("cls");
		
		switch(opc){
		case 1:
			printf("\n                       USTED ELIGIO OPCION 1: CARGA DE UN AFND.");
			arbol=carga_arbol();
			muestra_arbol(arbol);
			
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 0:
			printf("\nFIN DEL PROGRAMA!");
			break;
		}
	}while(opc);
	
	return 0;
}

int menu(){
	int b;
	printf("\n          MENU");
	printf("\n\n(1) CARGAR UN AFND.");
	printf("\n(0) SALIR.\n");
	do{
		printf("Elija una opcion: ");
		scanf("%d", &b);
	}while(b!=0 && b!=1);
	return b;
}
