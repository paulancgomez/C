#include <stdio.h>

int main(int argc, char *argv[]) {
	int num1, num2, producto;
	float resto, cociente;
	
	printf("INGRESE UN VALOR PARA NUM1: ");
	scanf("%d", &num1);
	printf("INGRESE UN VALOR PARA NUM2: ");
	scanf("%d", &num2);
	
	producto=num1*(float)num2;
	resto=num1%num1;
	cociente=num1/(float)num2;
	
	printf("\nEL RESULTADO DE NUM1 * NUM2 ES: %d", producto);
	printf("\nEL RESTO ENTRE NUM1 Y NUM2 ES: %f", resto);
	printf("\nEL RESULTADO DE NUM1 / NUM2 ES: %f", cociente);
	
	return 0;
}

