#include "interfazELEMENTO.h"

T_ele carga_ele(){ 
	T_ele nuevo;
	leeCad(nuevo.cadena,80);
	return nuevo;
}

T_ele carga_ele_parametro(Tcadena cad){ 
	T_ele uno;
	strcpy(uno.cadena, cad);
	return uno;
}

void muestra_ele(T_ele uno){   
	printf("%s", uno.cadena);
}

int compara_ele(T_ele a, T_ele b){
	int r;
	r=strcmp(a.cadena, b.cadena);
	return r;
}

void retorna_ele(T_ele uno,Tcadena aux){   
	strcpy(aux, uno.cadena);
}

T_ele carga_caracter_ele(char a){        
	Tcadena c;
	c[0]=a;
	c[1]=0;
	return carga_ele_parametro(c);
}

T_ele antesComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	return carga_ele_parametro(auxc);
}
/*
T_ele entre_corchetes(Tcadena n){
	char *aux="";
	aux=strtok(n,"{");
	aux=strtok(NULL,"}");
	return carga_ele_parametro(aux);
}
*/
T_ele entreComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	return carga_ele_parametro(auxc);
}

void leeCad(Tcadena cadena, int tam){
	int j, m;
	j=0;
	
	fflush(stdin);
	
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	if(m != EOF && m != '\n') /*limpia el buffer*/
		while((m=getchar())!=EOF && m!='\n');
}
