#include "interfazbase.h"


/*char * retornavalor(T_ele x){*/
/*	return x.valor;*/
/*}*/
T_ele carga_uno(){   /*carga una cadena en la estructura llamada T_ele. Nuevo es una cadena, es un campo de T_ele*/
	T_ele nuevo;
	printf("  ");
	leecad(nuevo.valor,80);
	
	return nuevo;
}
T_ele carga_ele(Tcadena n){   /*carga una cadena mandandole la cadena como parametro*/
	T_ele nuevo;
	strcpy(nuevo.valor,n);
	return nuevo;
}
/*char retorna_valor(T_ele e){
	return e.valor;
}*/
void mostrar_uno(T_ele e){       /*muestra la cadena*/
	printf("%s",e.valor);
}
int compara_ele(T_ele a, T_ele b){      /*compara las cadenas, devuelve valor -1, 0, 1*/
	return strcmp(a.valor,b.valor);
}

int leecad(Tcadena cadena,int tam)
{
	int ret,j,m;
	m=getchar();
	if(m==EOF)
	{
		cadena[0]='\0';
		ret=0;		
	}
	else
	{
		ret=1;
		if(m=='\n')
			j=0;
		else
		{
			cadena[0]=m;
			j=1;
		}
		for(;j<tam && (m=getchar())!=EOF && m!='\n';j++)
			cadena[j]=m;
		cadena[j]='\0';
	}
	if(m!=EOF && m!='\n')	
	   while((m=getchar())!=EOF && m!='\n');
	return ret;
}

//NUEVOS
void retornaValor(T_ele elem,Tcadena c){     /*retorna la cadena de la estructura EN la cadena c*/
	strcpy(c,elem.valor);
}
T_ele carga_caracter(char a){                 /*ni idea*/
	Tcadena c;
	c[0]=a;
	c[1]=0;
	return carga_ele(c);
}


/*T_ele carga_uno(){
	T_ele nuevo;
	printf("ingrese el caracter");
	scanf("%c",&nuevo.valor);
	return nuevo;
}
T_ele carga_ele(char n){
	T_ele nuevo;
	nuevo.valor=n;
	return nuevo;
}
char retorna_valor(T_ele e){
	return e.valor;
}
void mostrar_uno(T_ele e){
	printf("%c",e.valor);
}
int compara_ele(T_ele a, T_ele b){
	if(a.valor>b.valor)
		return 1;
	else
		if(a.valor==b.valor)
		return 0;
		else 
			return -1;
}
*/
