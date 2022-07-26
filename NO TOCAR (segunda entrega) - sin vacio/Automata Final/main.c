#include "interfazARBOL.h"

//TRABAJO PRACTICO TRANSVERSAL

//Integrantes:
//           CARDOZO GOMEZ PAULA NICOLE
//           CHIRI JAIRO MAURICIO

//FUNCION: Carga AF
//		   Determina si una cadena ingresada es aceptada por un AF
//		   Convierte AFND en AFD
//		   Muestra AF.

int menu();

int main(){
	Tarbol arbol, arbol_conv;
	int opc, b;
	
	arbol=arbol_vacio();
	arbol_conv=arbol_vacio();
	b=0;
	
	do{
		opc=menu();
		
		printf("\n");
		system("pause");
		system("cls");
	    
		switch(opc){
		case 1:
			printf("\n                       USTED ELIJIO OPCION 1: CARGA DE UN AFND.");
			arbol=carga_arbol();
			muestra_arbol(arbol);
			b=1;
           
			printf("\n\n");
			system("pause");
			system("cls");
			break;
	    case 2:
			printf("\n                      USTED ELIJIO OPCION 2: CONVERTIR AFND EN AFD");
			if(!b)
				arbol=carga_arbol();
			printf("\n**SE MOSTRARA EN LA PARTE DE ARRIBA EL AFND INGRESADO Y EN LA PARTE DE ABAJO SU CONVERSION EN AFD**\n");
			muestra_arbol(arbol);
			arbol_conv=convertir(arbol);
			muestra_arbol_especial(arbol_conv);
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 3:
			if(!b){
				printf("\n                      USTED ELIJIO OPCION 3: INGRESO Y VERIFICACION DE CADENAS EN AF INGRESADO");
				arbol=carga_arbol();
			}
			do{
				printf("\n                     USTED ELIJIO OPCION 3: INGRESO Y VERIFICACION DE CADENAS EN AF INGRESADO\n");
				muestra_arbol(arbol);
				acepta_cadena(arbol);
				printf("\n\nIngresar otra cadena? (0)NO - (1)SI:  ");
				scanf("%d",&opc);
				if(opc!=0){
					printf("\n");
					system("pause");
					system("cls");
				}
			}while(opc!=0);
			
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
	printf("\n(2) CONVERTIR AFND EN AFD.");
	printf("\n(3) INGRESAR Y VERIFICAR CADENAS EN AF INGRESADO.");
	printf("\n(0) SALIR.\n");
	do{
     	printf("Elija una opcion: ");
	    scanf("%d", &b);
	}while(b!=0 && b!=1 && b!=2 && b!=3);
	return b;
}
