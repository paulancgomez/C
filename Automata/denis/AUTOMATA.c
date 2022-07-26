#include <stdio.h>
#include "AUTOMATA.h"
#include <stdlib.h>
#include <string.h>

//PRIVADOS

t_ptr_char crearchar_1(char);
t_ptr crearnodo_c_char(char);
t_ptr crearnodo();
t_ptr crear(int);
void mostrar1(t_ptr);
void mostrar_char(Ttipochar*);
t_ptr_char crearchar();
t_ptr crearupla(int);
t_ptr upla_transiciones_completa(int,int, t_ptr, t_ptr);
t_ptr upla_transiciones(int,int,t_ptr,t_ptr);
t_ptr transiciones(char,char,t_ptr);
t_ptr crear_una_transicion(char,char,t_ptr);
void mostrar_transiciones(t_ptr);
void mostrar1_transiciones(t_ptr);



t_ptr crearupla(int i){
	tnodo* aux;
	aux=(tnodo*)malloc(sizeof(tnodo));
	aux->nodetype=SET;
	aux->izq=crear(i);
	aux->der=NULL;
	return aux;
}

t_ptr crearnodo(){
	tnodo* aux;
	Ttipochar* nuevo=crearchar();
	aux=(tnodo*)malloc(sizeof(tnodo));
	aux->nodetype=SET;
	aux->izq=(t_ptr)nuevo;
	aux->der=NULL;
	return aux;
}

t_ptr crearnodo_c_char(char letra){
	tnodo* aux;
	Ttipochar* nuevo=crearchar_1(letra);
	aux=(tnodo*)malloc(sizeof(tnodo));
	aux->nodetype=SET;
	aux->izq=(t_ptr)nuevo;
	aux->der=NULL;
	return aux;
}

t_ptr_char crearchar_1(char letra){
	Ttipochar* nuevo;
	nuevo=(Ttipochar*)malloc(sizeof(Ttipochar));
	nuevo->nodetype=CHAR;
	nuevo->valor=letra;
	return nuevo;
}


t_ptr crear(int j){
	int i;
	tnodo* ulti;
	char letra;
	int band;
	int band1=0;
	tnodo* x;
	t_ptr a=NULL;
	t_ptr rec;
	for(i=1;i<=j;i++){
		band=1;
		if(a==NULL){
			printf("ingrese letra: ");
			scanf("%c",&letra);
			fflush(stdin);
			ulti=crearnodo_c_char(letra);
			//ulti=crearnodo();
			a=ulti;
		}
		else{
			
			while(band==1){
				printf("\ningrese letra: ");
				scanf("%c",&letra);
				fflush(stdin);	
				rec=a;
				band1=0;
				while(rec!=NULL && band1==0){
					if(((Ttipochar*)rec->izq)->valor==letra)
						band1=1;
					else
						rec=rec->der;
				}
				if(band1==1){
					printf("\nerror letra ya fue ingresada\n");
				}
				else
				   if(rec==NULL)
				   band=0;
			}
			x=crearnodo_c_char(letra);
			ulti->der=x;
			ulti=x;
			band=0;
		}
	}
	return a;
}

void mostrar(t_ptr L){//aqui junto a todas las llamadas de funciones mostramos el automata completo
	int i=1;
	printf("\n\n-----------------------PARTES DEL AUTOMATA-------------------------\n\n");
	while(L!=NULL){
		switch(i){
		case 1:
			printf("simbolos del automata:\n");
			mostrar1(L->izq);
			L=L->der;
			i++;
			break;
		case 2:
			printf("\nestados del automata:\n");
			mostrar1(L->izq);
			i++;
			L=L->der;
			break;
		case 3:
			printf("\nestado inicial:\n");
			mostrar1(L->izq);
			i++;
			L=L->der;
			break;
		case 4:
			printf("\nestados de aceptacion:\n");
			mostrar1(L->izq);
			i++;
			L=L->der;
			break;
		case 5:
			printf("\nfuncion de transicion: orden(estado+simbolo+estados de la funcion de transicion)\n");
			mostrar_transiciones(L->izq);
			i++;
			L=L->der;
			break;
		}
	}
	
}

void mostrar_transiciones(t_ptr L){
	while(L!=NULL){
		mostrar1_transiciones(L->izq);
		printf("\n------------------------------------\n");
		L=L->der;
	}
}

void mostrar1_transiciones(t_ptr L){
	int i=1;
	
	while(L!=NULL){
		switch(i){
		case 1:
			printf("estados:\n");
			printf("{");
			mostrar_char((Ttipochar*)L->izq);
			L=L->der;
			printf("}");
			i++;
			break;
			case 2:
				printf("\nsimbolos:\n");
				printf("{");
				mostrar_char((Ttipochar*)L->izq);
				printf("}");
				L=L->der;
				i++;
				break;
				default:
					printf("\nestados de la funcion de transicion:\n");
					printf("{");
					mostrar_char((Ttipochar*)L->izq);
					printf("}");
					L=L->der;
					i++;
					break;
		}
	}
}
void mostrar1(t_ptr L){
	printf("{");
	while(L!=NULL){
		mostrar_char((Ttipochar*)L->izq);
		
		L=L->der;
	}
	printf("}");
}
void mostrar_char(Ttipochar* a){
	printf("%c\t",a->valor);
}

t_ptr_char crearchar(){
	Ttipochar* nuevo;
	char j;
	nuevo=(Ttipochar*)malloc(sizeof(Ttipochar));
	nuevo->nodetype=CHAR;
	printf("ingrese letra: ");
	fflush(stdin);
	scanf("%c",&j);
	nuevo->valor=j;
	return nuevo;
}

t_ptr crearAF(int* n,int* m, tcadena estados){//aqui junto a todas las llamadas de funciones creamos el automata
	int i,j,es,si;
	tnodo* x;
	Ttipochar* nuevo;
	tnodo* x1;
	tnodo* aux1;
	tnodo* ulti;
	t_ptr a=NULL;
	t_ptr a1=a;
	t_ptr a2=a;
	for(i=1;i<=5;i++){
		switch(i){
		case 1:
			printf("ingrese la cantidad de simbolos:");
			fflush(stdin);
			scanf("%d",&j);
			*m=j;
			si=j;
			fflush(stdin);
			ulti=crearupla(j);
			ulti->der=a;
			a=ulti;
			printf("\n\n");
			system("cls");
			break;
		case 2:
			printf("ingrese la cantidad de estados: ");
			fflush(stdin);
			scanf("%d",&j);
			fflush(stdin);
			*n=j;
			es=j;
			x=crearupla(j);
			ulti->der=x;
			ulti=x;
			
			aux1=x->izq;
			printf("%c",((Ttipochar*)aux1->izq)->valor);
			estados[0]=((Ttipochar*)aux1->izq)->valor;
			printf("\n\n");
			system("cls");
			break;
		case 3:
			printf("el estado inicial es el primer estado insertado\n");
			nuevo=(Ttipochar*)malloc(sizeof(Ttipochar));
			nuevo->nodetype=CHAR;
			nuevo->valor=((Ttipochar*)aux1->izq)->valor;
			x1=(tnodo*)malloc(sizeof(tnodo));
			x1->nodetype=SET;
			x1->izq=(t_ptr)nuevo;
			x1->der=NULL;
			x=(tnodo*)malloc(sizeof(tnodo));
			x->nodetype=SET;
			x->izq=x1;
			x->der=NULL;
			ulti->der=x;
			ulti=x;
			printf("\n\n");
			system("cls");
			break;
		case 4:
			a2=a;
			printf("ingrese estados de aceptacion: \n");
			a2=a2->der;
			a2=a2->izq;
			x=(tnodo*)malloc(sizeof(tnodo));
			x->nodetype=SET;
			x->izq=crear_e_d_aceptacion(a2);
			x->der=NULL;
			ulti->der=x;
			ulti=x;
			printf("\n\n");
			system("cls");
			break;
		case 5:
			a1=a;
			a2=a;
			printf("transiciones\n");
			a1=a1->izq;
			a2=a2->der;
			a2=a2->izq;
			x=upla_transiciones_completa(es,si,a1,a2);
			ulti->der=x;
			ulti=x;
			printf("\n\n");
			system("cls");
			break;
		}
	}
	return a;
}

t_ptr upla_transiciones_completa(int n, int m, t_ptr simb, t_ptr est){//aqui junto a todas las llamadas de funciones creamos las transiciones completas
	tnodo* aux;
	aux=(tnodo*)malloc(sizeof(tnodo));
	aux->nodetype=SET;
	aux->izq=upla_transiciones(n,m,simb,est);
	aux->der=NULL;
	return aux;
}
t_ptr upla_transiciones(int n, int m, t_ptr simb, t_ptr est){
	int i;
	t_ptr simb_aux=simb;
	t_ptr est_aux=est;
	int j=m;
	tnodo* ulti;
	tnodo* x;
	printf("ingrese todos las transiciones: \n");
	t_ptr trans=NULL;
	for(i=1;i<=n*m;i++){
		if(trans==NULL){
			ulti=transiciones((((Ttipochar*)simb_aux->izq)->valor),(((Ttipochar*)est_aux->izq)->valor),est);
			trans=ulti;
			j--;
			simb_aux=simb_aux->der;
		}
		else{
			if(j!=0){
				x=transiciones((((Ttipochar*)simb_aux->izq)->valor),(((Ttipochar*)est_aux->izq)->valor),est);
				ulti->der=x;
				ulti=x;
				j--;
				simb_aux=simb_aux->der;
			}
			else{
				simb_aux=simb;
				j=m;
				est_aux=est_aux->der;
				x=transiciones((((Ttipochar*)simb_aux->izq)->valor),(((Ttipochar*)est_aux->izq)->valor),est);
				ulti->der=x;
				ulti=x;
				simb_aux=simb_aux->der;
				j--;
			}
		}
	}
	return trans;
}

t_ptr transiciones(char s,char e,t_ptr est){
	tnodo* aux;
	aux=(tnodo*)malloc(sizeof(tnodo));
	aux->nodetype=SET;
	aux->izq=crear_una_transicion(s,e,est);
	aux->der=NULL;
	return aux;
}

t_ptr crear_una_transicion(char si, char e, t_ptr est){
	t_ptr a=NULL;
	tnodo* x;
	t_ptr nuevo;
	tnodo* ulti;
	ulti=crearnodo_c_char(e);
	a=ulti;
	x=crearnodo_c_char(si);
	ulti->der=x;
	ulti=x;
	printf("\ningrese el estado de realizar la funcion de transicion del estado %c con el simbolo %c: \n",e, si);
	nuevo=crear_e_f_t(est);
	ulti->der=nuevo;
	return a;
}

int leecad(tcadena cadena, int tam){
	int j,ret;
	char c;
	j=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<tam-1){
		cadena[j]=c;
		j++;
		c=getchar();
		ret=1;
	}
	cadena[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
	return ret;
}

t_ptr crear_e_f_t(t_ptr estados){
	tnodo* ulti;
	char letra;
	char s='S';
	int band;
	int band1=0;
	tnodo* x;
	t_ptr a=NULL;
	t_ptr rec;
	t_ptr estados_aux;
	t_ptr estados_aux1=estados;
	while(s=='S' && estados_aux1!=NULL){
		band=1;
		if(a==NULL){
			while(band==1){
				band1=0;
				printf("ingrese letra: ");
				scanf("%c",&letra);
				fflush(stdin);
				estados_aux=estados;
				while(estados_aux!=NULL && band1==0){
					if(((Ttipochar*)estados_aux->izq)->valor==letra || letra=='V')
						band1=1;
					else
						estados_aux=estados_aux->der;
				}
				if(band1==0)
					  printf("\n error letra no pertenece al conjunto de estados ni al estado V (vacio)\n");
				else{
					if(band1==1)
						band=0;
				}
			}
			ulti=crearnodo_c_char(letra);
			estados_aux1=estados_aux1->der;
			a=ulti;
		}
		else{
			
			while(band==1){
				printf("\ningrese letra: ");
				scanf("%c",&letra);
				fflush(stdin);	
				rec=a;
				band1=0;
				while(rec!=NULL && band1==0){
					if(((Ttipochar*)rec->izq)->valor==letra )
						band1=1;
					else
						rec=rec->der;
				}
				if(band1==1){
					printf("\nerror letra ya fue ingresada\n");
				}
				else{
					band1=0;
					estados_aux=estados;
					while(estados_aux!=NULL && band1==0){
						if(((Ttipochar*)estados_aux->izq)->valor==letra || letra=='V')
							band1=1;
						else
							estados_aux=estados_aux->der;
					}
					if(band1==0)
						  printf("\n error letra no pertenece al conjunto de estados ni al estado V (vacio)\n");
					else
						if(band1==1)
						band=0;
				}
			}
			x=crearnodo_c_char(letra);
			estados_aux1=estados_aux1->der;
			ulti->der=x;
			ulti=x;
			band=0;
		}
		printf("quiere seguir ingresando otro estado?? S/N: ");
		fflush(stdin);
		scanf("%c",&s);
		fflush(stdin);
		while(s!='S' && s!='N'){
			printf("quiere seguir ingresando otro estado?? S/N: ");
			fflush(stdin);
			scanf("%c",&s);
			fflush(stdin);
		}
		
		printf("\n");
	}
	if(estados_aux1==NULL){
		printf("\nya no existe mas estados\n");
		return a;
	}
	else
	   return a;
}

void verificacion_de_cadenas(tcadena cadena, tcadena estados, t_ptr transiciones, int *tam){
	int encontrado=0;
	int vacio=0;
	int band_vacio=0;
	int cont=0;
	int i=0;
	int j=0;
	int k=0;
	t_ptr aux;
	tcadena estados_aux;
	t_ptr aux0_trans;
	while(cadena[i]!='\0' && vacio==0){
		cont=0;
		
		for(j=0;j<=k;j++){
			encontrado=0;
			aux=transiciones;
			while(aux!=NULL && encontrado==0){
				aux0_trans=aux;
				aux0_trans=aux0_trans->izq;
				if(((Ttipochar*)aux0_trans->izq)->valor==estados[j]){
					aux0_trans=aux0_trans->der;
					if(((Ttipochar*)aux0_trans->izq)->valor==cadena[i]){
						aux0_trans=aux0_trans->der;
						while(aux0_trans!=NULL){
							estados_aux[cont]=((Ttipochar*)aux0_trans->izq)->valor;
							aux0_trans=aux0_trans->der;
							cont++;
						}
						encontrado=1;
					}
					else
						aux=aux->der;
				}
				else
					aux=aux->der;
			}
			if(encontrado==0){
				estados_aux[cont]=estados[j];
				cont++;
			}
		}
		cont--;
		j=0;
		while(j<=cont && band_vacio==0){
			if(estados_aux[j]!='V')
				band_vacio=1;
			else
				j++;
		}
		if(band_vacio==0){
			printf("\nla cadena se fue al vacio total\n");
			vacio=1;
			for(j=0;j<=cont;j++)
				estados[j]=estados_aux[j];
			k=cont;
			i++;
		}
		else{
			for(j=0;j<=cont;j++)
				estados[j]=estados_aux[j];
			k=cont;
			i++;
		}
	}
	*tam=k;
	
}

void aceptacion_de_cadenas_1(tcadena estados, t_ptr est_acep, int tam){
	int i=0;
	int band1=0;
	t_ptr aux=est_acep;
	int band=0;
	while(band==0 && aux!=NULL){
		
		i=0;
		while((band1==0 && i<tam+1)|| i==0){
			if(((Ttipochar*)aux->izq)->valor==estados[i]){
				band1=1;
				i++;
			}
			else
				i++;
		}
		if(band1==1)
			band=1;
		else
			aux=aux->der;
	}
	
	if(band==1)
		  printf("LA CADENA ES ACEPTADA\n");
	else
		printf("CADENA NO ACEPTADA\n");
}

int cadena_pertenece(tcadena cadena, t_ptr sigma){
	t_ptr aux;
	int tam=strlen(cadena);
	int i=0,band=0,band1=0;
	while(i<tam && band==0){
		aux=sigma;
		band1=0;
		while(aux!=NULL && band1==0){
			if(((Ttipochar*)aux->izq)->valor==cadena[i])
				band1=1;
			else 
				aux=aux->der;
		}
		if(band1==0)
			  band=1;
		else 
			i++;
	}
	if(band==1)
		  return 0;
	else 
		return 1;
}


t_ptr crear_e_d_aceptacion(t_ptr estados){
	tnodo* ulti;
	char letra;
	char s='S';
	int band;
	int band1=0;
	tnodo* x;
	t_ptr a=NULL;
	t_ptr rec;
	t_ptr estados_aux;
	t_ptr estados_aux1=estados;
	while(s=='S' && estados_aux1!=NULL){
		band=1;
		if(a==NULL){
			while(band==1){
				band1=0;
				printf("ingrese letra: ");
				scanf("%c",&letra);
				fflush(stdin);
				estados_aux=estados;
				while(estados_aux!=NULL && band1==0){
					if(((Ttipochar*)estados_aux->izq)->valor==letra )
						band1=1;
					else
						estados_aux=estados_aux->der;
				}
				if(band1==0)
					  printf("\n error letra no pertenece al conjunto de estados\n");
				else{
					if(band1==1)
						band=0;
				}
			}
			ulti=crearnodo_c_char(letra);
			estados_aux1=estados_aux1->der;
			a=ulti;
		}
		else{
			
			while(band==1){
				printf("\ningrese letra: ");
				scanf("%c",&letra);
				fflush(stdin);	
				rec=a;
				band1=0;
				while(rec!=NULL && band1==0){
					if(((Ttipochar*)rec->izq)->valor==letra )
						band1=1;
					else
						rec=rec->der;
				}
				if(band1==1){
					printf("\nerror letra ya fue ingresada\n");
				}
				else{
					band1=0;
					estados_aux=estados;
					while(estados_aux!=NULL && band1==0){
						if(((Ttipochar*)estados_aux->izq)->valor==letra)
							band1=1;
						else
							estados_aux=estados_aux->der;
					}
					if(band1==0)
						  printf("\n error letra no pertenece al conjunto de estados\n");
					else
						if(band1==1)
						band=0;
				}
			}
			x=crearnodo_c_char(letra);
			estados_aux1=estados_aux1->der;
			ulti->der=x;
			ulti=x;
			band=0;
		}
		printf("quiere seguir ingresando otro estado?? S/N: ");
		fflush(stdin);
		scanf("%c",&s);
		fflush(stdin);
		while(s!='S' && s!='N'){
			printf("quiere seguir ingresando otro estado?? S/N: ");
			fflush(stdin);
			scanf("%c",&s);
			fflush(stdin);
		}
		
		printf("\n");
	}
	if(estados_aux1==NULL){
		printf("\nya no existe mas estados\n");
		return a;
	}
	else
	   return a;
}




