#include "interfazAF.h"
#include <stdlib.h>

int main(){
	
	int opc;
	T_AF af;
	printf("\nESTE PROGRAMA CARGA TANTO AFD COMO AFND\n");
	printf("\nRECORDAR\nCUANDO DEBA CARGAR UNA TRANSCICION DEBE USAR EL SIGUENTE FORMATO\n (SI SE TRATA DE UN AFD SOLO DEBE CARGAR UN ESTADO): \nEstadoPartida,Elemento Del Alfabeto,{EstadoLlegada1,EstadoLlegada2,...}\n");
	system("pause");
	printf("\n");
	af=crea_AFND();
	muestra_AF(af);
	do{
		AceptaCadena(af);
		printf("\nIngresar otra cadena?\t(0)No\t(cualquier numero)Si:  ");
		scanf("%i",&opc);
	} while(opc!=0);
	
}
