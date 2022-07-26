#include "interfazARBOL.h"
#include <stdlib.h>

void muestra_arbol_rec(Tarbol raiz, int e);
void carga_conjunto_trans(Tarbol raiz, int t, Conjunto T);
void carga_N(Conjunto*, Conjunto);
int repe_transiciones(Conjunto,T_ele);
T_ele retorna_dato_cadena(Tstring);
Tarbol despuesComa_arbol(Tcadena);
int repe_transiciones_arbol(Tarbol T, T_ele elem);
int contiene_arbol(Tarbol a,Tarbol b);
int pertenece_arboles(Tarbol T, Tarbol bus);

Tstring crea_nodo_string(){
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=carga_ele();
	return nodo;
}

Tstring crea_nodo_string_parametro(T_ele cadena){
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=cadena;
	return nodo;
}

Tarbol crea_nodo_arbol(){
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo_arbol));
	nodo->tipo=SET;
	nodo->dato_arbol=NULL;
	nodo->sig=NULL;
	return nodo;
}

void inicia_arbol(Tarbol *raiz){
	(*raiz)->dato_arbol=NULL;
	(*raiz)->sig=NULL;
}

void agrega_der(Tarbol *raiz, Tarbol nuevo){
	(*raiz)->dato_arbol=nuevo;
}

void agrega_izq(Tarbol *raiz, Tarbol nuevo){
	(*raiz)->sig=nuevo;
}

void muestra_arbol(Tarbol raiz){ 
	
	printf("\n\nMUESTRA ESTADOS");
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ALFABETO");
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADO INICIAL");	
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADOS DE ACEPTACION");
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA TRANSICIONES");
    raiz=raiz->sig;
	muestra_trans(raiz);
}

void muestra_trans(Tarbol raiz){  //muestra el conjunto de transiciones
	printf("\n{");
	while(raiz!=NULL){
		muestra_conjunto_trans(raiz->dato_arbol);
		raiz=raiz->sig;
		if(raiz!=NULL)
			printf(", ");
	}
	printf("}");
}

void muestra_conjunto_trans(Tarbol raiz){  //muestra una transicion
	int i=1, b=0, s=0;
	printf("(");
	while(raiz->sig!=NULL){
		if(i<=2 || b==0){
			i++;
		}
		else{
			b=1;
		}
		muestra_nodo_string((Tstring)raiz->dato_arbol);
		printf(", ");
		raiz=raiz->sig;
		if(i>2 && raiz->sig!=NULL && s==0){
			s=1;
			printf("{");
		}
	}
	muestra_nodo_string((Tstring)raiz->dato_arbol);
	if(s==1){
		printf("}");
	}
	printf(")");
}
void muestra_conjunto(Tarbol raiz){
	if(raiz!=NULL){
	printf("\n{");
	while(raiz->sig!=NULL){
		muestra_nodo_string((Tstring)raiz->dato_arbol);
		printf(", ");
	    raiz=raiz->sig;
	}
	muestra_nodo_string((Tstring)raiz->dato_arbol);
	printf("}");
	}
	else
	   printf("\nCONJUNTO VACIO");
}

void muestra_nodo_string(Tstring nodo){
	if(nodo!=NULL){
		muestra_ele(nodo->dato_cadena);
	}
}
/*
void carga_N(Conjunto *N, Conjunto T){
	Tcadena cadena, aux_cadena;
	T_ele antes, entre;
	Conjunto acep;
	
	retorna_ele(T->dato, cadena);
	
	strcpy(aux_cadena, cadena);
	antes=antesComa(aux_cadena);
	agregar_elemento(N, antes);
	
	strcpy(aux_cadena, cadena);
	entre=entreComa(aux_cadena);
	agregar_elemento(N, entre);
	
	strcpy(aux_cadena, cadena);
	acep=despuesComa(aux_cadena);
	
	while(acep!=NULL){
		agregar_elemento(N, acep->dato);
		acep=acep->sig;
	}
}
*/
void carga_alfabeto_arbol(Tarbol E){
	Tarbol aux;
	int tam,i,B; 
	T_ele sim; 
	B=0;
	aux=E;
	printf("\n");
	do{
		printf("Ingrese cantidad de simbolos del alfabeto: ");
		scanf("%i",&tam);
	}while(tam<=0);
	for(i=1; i<tam; i++){
		printf("Ingrese simbolo: ");
		sim=carga_ele();
		B=pertenece_arbol(E,sim);
		while(B==1){
			printf("SIMBOLO NO VALIDO. Ingrese otro simbolo: ");
			sim=carga_ele();
			B=pertenece_arbol(E, sim);
		}
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(sim);
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
	}
	printf("Ingrese simbolo: ");
	sim=carga_ele();
	B=pertenece_arbol(E,sim);
	while(B==1){
		printf("SIMBOLO NO VALIDO. Ingrese otro simbolo: ");
		sim=carga_ele();
		B=pertenece_arbol(E, sim);
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(sim);
	aux->sig=NULL;
}

void carga_estados_arbol(Tarbol Q, Tarbol *q_0){
	Tarbol aux;
	T_ele x, vacio;
	int i,b,c,z;
	aux=Q;
	printf("\n");
	do{
		printf("Ingrese la cantidad de estados: ");
		scanf("%d",&c);
	}while(c<=0);
	printf("**El primer estado que ingrese se le asignara como ESTADO INICIAL**\n");
	for(i=1;i<c;i++){
		vacio=carga_ele_parametro(" ");
		printf("Ingrese el nombre del estado: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
		while(b==1 || z==0){
			printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
			x=carga_ele();
			b=pertenece_arbol(Q, x);
			z=compara_ele(x,vacio);
		}
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
		if(i==1){
			agrega_elemento_arbol(q_0,x);
		}
	}
	vacio=carga_ele_parametro(" ");
	printf("Ingrese el nombre del estado: ");
	x=carga_ele();
	b=pertenece_arbol(Q, x);
	z=compara_ele(x,vacio);
	while(b==1 || z==0){
		printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
	aux->sig=NULL;
}

void carga_estado_ini(Tarbol q_0, Tarbol estado){
	q_0->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)estado->dato_arbol));
	q_0->sig=arbol_vacio();
}

void carga_estado_acep(Tarbol F, Tarbol Q){
	int opc,B1,B2; // CA, CEst;
	T_ele etiqueta;
	Tarbol aux;
	Q=retorna_Q(Q);
	opc=0;  //CA=0;
	//CEst=Cant_estados(Est);
	aux=F;
	printf("\n");
	do{
		printf("Ingrese estado de aceptacion: ");
		etiqueta=carga_ele();
		B1=pertenece_arbol(Q, etiqueta);
		B2=pertenece_arbol(F,etiqueta);
		while(B1!=1 || B2==1){
			printf("ESTADO NO VALIDO. Ingrese otro: ");
			etiqueta=carga_ele();
			B1=pertenece_arbol(Q, etiqueta);
			B2=pertenece_arbol(F, etiqueta);
		}
		printf("Desea ingresar otro estado? SI (1) - NO (0): ");
		scanf("%i",&opc);
	//	CA++;
		if(opc){
			aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(etiqueta);
			aux->sig=crea_nodo_arbol();
			aux=aux->sig;
		}
		else{
			aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(etiqueta);
			aux->sig=NULL;
		}
	} while(opc!=0); //&& CA<=CEst
}

int cant_estados_arbol(Tarbol raiz){
	int c=0;
	while(raiz!=NULL){
		c++;
		raiz=raiz->sig;
	}
	return c;
}

void carga_transi_arbol(Tarbol T, Tarbol arbol){
	Tarbol Q, E, aux, T_recorre, acep, nuevo;
	char res;
	T_ele elemTran1, elemTran2;
	Tcadena tranLeida,auxTranLeida;
	
	aux=acep=nuevo=arbol_vacio();
		
	Q=retorna_Q(arbol);
	E=retorna_alfabeto(arbol);
	T_recorre=T;
	
	//printf("\nmuestra estados");
	//muestra_conjunto(Q);
	//printf("\nmuestra alfabeto");
	//muestra_conjunto(E);
	
	//system("pause");
	
	printf("\n\n");
	aux=T_recorre;
	
	do{
		//printf("\nentro do");
		printf("Ingrese transicion: ");	
		leeCad(tranLeida,100);
		strcpy(auxTranLeida,tranLeida);
		elemTran1=antesComa(auxTranLeida);  //antes de la coma
		//printf("\npertenece: %d ", pertenece_arbol(Q,elemTran1));
		//printf("muestra elemtran1: ");
		//muestra_ele(elemTran1);
		//system("pause");
		//printf("\nrepe: %d ", repe_transiciones_arbol(T, elemTran1));
		//printf("\ncant: %d", cant_estados_arbol(E));
		if(pertenece_arbol(Q,elemTran1)==1 && repe_transiciones_arbol(T, elemTran1)<=cant_estados_arbol(E)){//EN ESTE CASO USO Cant_estados PARA SABER LA CANTIDAD DE ELEMENTOS DE E
			//printf("\nentro primer if");
			strcpy(auxTranLeida,tranLeida);
			elemTran2=entreComa(auxTranLeida);  //entre coma
			if(pertenece_arbol(E,elemTran2)==1){
				//printf("\nentro segundo if");
				strcpy(auxTranLeida,tranLeida);
				acep=despuesComa_arbol(auxTranLeida);
				//printf("\nmuestra acep");
				//muestra_conjunto(acep);
				agrega_elemento_arbol(&nuevo, elemTran1);  //que me devuelva un arbol
				//printf("\nmuestra nuevo: ");
				//muestra_conjunto(nuevo);
				agrega_elemento_arbol(&nuevo, elemTran2);
				//printf("\nmuestra nuevo: ");
				//muestra_conjunto(nuevo);
				agrega_repetidos_arbol(&nuevo, acep);
				//printf("\nmuestra nuevo: ");
				//muestra_conjunto(nuevo);
				//printf("\ncontiene: %d", contiene_arbol(acep, Q));
				//printf("\npertenece: %d", pertenece_arboles(T,nuevo));
				if(contiene_arbol(acep, Q) && pertenece_arboles(T,nuevo)==0){ //hacer un pertenece para dos arboles
					//printf("\nentro tercer if");
					printf("Desea ingresar otra transicion? SI(1) - NO(0): ");
					scanf("%c",&res);
					fflush(stdin);
					
					if(res=='1'){
						agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=crea_nodo_arbol();
					//	printf("\nmostrando aux");
					//	muestra_conjunto(aux->dato_arbol);
						T_recorre=T_recorre->sig;
						nuevo=arbol_vacio();
						aux=aux->sig;
					//	if(aux==NULL){
					//		printf("aux es igual a null");
					//	}
					//	else
					//	   printf("aux es distinto de null");
					}
					else{
					//	if(aux==NULL){
					//		printf("aux es igual a null");
					//	}
					//	else
					//	   printf("aux es distinto de null");
					    agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=arbol_vacio();
					//	printf("\nmostrando aux");
					//	muestra_conjunto(aux->dato_arbol);
					}
				}
				else{
					printf("ESTADOS DE LLEGADA NO VALIDOS.");
					res='1';
				}
				
			}
			else{
				printf("ELEMENTO DE ALFABETO NO VALIDO.");
				res='1';
			}
		}
		else{
			printf("\nESTADO DE PARTIDA NO VALIDO.");
			res='1';}
	} while(res!='0');
}

int pertenece_arboles(Tarbol T, Tarbol bus){
	Tarbol aux_T, aux_bus;
	aux_T=T;
	int b=0;
	aux_bus=bus;
	if(aux_T!=NULL){
	    while(aux_T!=NULL && aux_bus!=NULL){
	 	    aux_T=aux_T->dato_arbol;
			while(aux_T!=NULL && aux_bus!=NULL && b==0){
		        if(compara_ele(retorna_dato_cadena((Tstring)aux_T->dato_arbol), retorna_dato_cadena((Tstring)aux_bus->dato_arbol))==0){
				    aux_T=aux_T->sig;
			        aux_bus=aux_bus->sig;
		        }
				else
					b=1;
			}
			if(aux_T!=NULL || aux_bus!=NULL){
				return pertenece_arboles(T->sig, bus);
			}
			else
			   return 1;
	    }
	    if(aux_T==NULL && aux_bus==NULL)
			return 1;
	    else
	     	return 0;   //bus no pertenece  a T
	}
	else
	   return 0;
}

int contiene_arbol(Tarbol a, Tarbol b){
	if(a!=NULL){
		if(b!=NULL){
			int ban=0;
			while(a!=NULL && ban==0){
				if(pertenece_arbol(b, retorna_dato_cadena((Tstring)a->dato_arbol))==0)
					ban=1;
				a=a->sig;
			}
			if(ban==1)
				  return 0;
			else
				return 1;
		}
		else
		   return 0;
	}
	else
	   return 1;
}

int repe_transiciones_arbol(Tarbol T, T_ele elem){//PARA CONTROLAR QUE LAS CANTIDADES DE TRANSICIONES DESDE UN ESTADO NO SEAN MAYOR QUE LAS DEL ALFABETO
	int c=0;
	T_ele aux_elem;
	Tarbol aux_T;
	aux_T=T;
	if(aux_T->dato_arbol!=NULL){
		//printf("dento de repe entro if");
	    while(aux_T->dato_arbol!=NULL){
			//printf("dentro de repe entro while");
			aux_T=aux_T->dato_arbol;
			
			//printf("muestra aux");
			//muestra_conjunto(aux_T);
		    
			//printf("muestra elem parametro");
			//muestra_ele(elem);
			
			
			aux_elem=retorna_dato_cadena((Tstring)aux_T->dato_arbol);
		   
			//printf("muestra aux_elem estado incial de aux_t: ");
			//muestra_ele(aux_elem);
			
			if(compara_ele(aux_elem,elem)==0)//VER SI SE BURLA EL ENCAPSULAMIENTO
				c++;
		    aux_T=T->sig;
	     	T=T->sig;
	    }
	}
	//printf("valor de c: %d", c);
	return c;
}

Tarbol despuesComa_arbol(Tcadena n){
	//Tcadena n;
	Tarbol nuevo=arbol_vacio();
	T_ele aux;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	auxc=strtok(NULL,",{}");
	while(auxc!=NULL){
		aux=carga_ele_parametro(auxc);
		agrega_elemento_arbol(&nuevo,aux);
		/*		if(auxc[0]!='\0')*/
		/*		{*/
		/*			aux=carga_ele(auxc);*/
		/*			agregar_elemento(&nuevo,aux);*/
		/*		}*/
		auxc=strtok(NULL,",{}");
	}
	return nuevo;
}

Tarbol carga_arbol(){
	Tarbol arbol, aux, estado_ini;
	
	arbol=aux=estado_ini=arbol_vacio();
	
	printf("\nINGRESO DE ESTADOS");
	arbol=crea_nodo_arbol();
	crea_hijos(&arbol);
	carga_estados_arbol(arbol->dato_arbol, &estado_ini);
	
	
	printf("\nINGRESO DE ALFABETO");
    aux=arbol->sig;
	crea_hijos(&aux);
	carga_alfabeto_arbol(aux->dato_arbol);
	
	
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_ini(aux->dato_arbol, estado_ini);
	
	printf("\nINGRESO DE ESTADOS DE ACEPTACION");
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_acep(aux->dato_arbol, arbol);
	
	printf("\nINGRESO DE TRANSICIONES");
	printf("\nPARA AFD: LA CARGA DE TRANSICION ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,EstadoLlegada");
	printf("\nPARA AFND: LA CARGA DE TRANSICION ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,{EstadoLlegada1,EstadoLlegada2,...}");
	
	//T_aux=T;
	
	aux=aux->sig;
	crea_nodo_arbol(&aux);
	carga_transi_arbol(aux, arbol);
	
	/*if(T_aux->sig==NULL)  //si hay un solo nodo en las transiciones
		crea_hijos_ultimo(&aux);
	else
		crea_hijos(&aux);
	
	for(i=1;i<t;i++){
		N=conjuntovacio();
		carga_N(&N, T_aux);
		n=Cant_estados(N);
		carga_conjunto(aux->dato_arbol, n, N);
		aux=aux->sig;
		T_aux=T_aux->sig;
		if(T_aux->sig==NULL)
			crea_hijos_ultimo(&aux);
		else
			crea_hijos(&aux);
	}
	
	N=conjuntovacio();
	carga_N(&N, T_aux);
	n=Cant_estados(N);
	carga_conjunto(aux->dato_arbol, n, N);
	*/
	printf("\n");
	system("PAUSE");
	system("cls");

	return arbol;
}

void crea_hijos(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=crea_nodo_arbol();
}

void crea_hijos_ultimo(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=NULL;
}

void carga_conjunto_arbol(Tarbol aux, int cont, int e, T_ele cadena){
	while(cont<e){
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
		aux->sig=crea_nodo_arbol();
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
}

Tarbol retorna_Q(Tarbol raiz){
	raiz=raiz->dato_arbol;
	return raiz;
}

Tarbol retorna_alfabeto(Tarbol raiz){
	raiz=raiz->sig;
	return raiz->dato_arbol;
}

Tarbol retorna_estado_inicial(Tarbol raiz){
	int i;
	for(i=1; i<=2; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_estado_acep(Tarbol raiz){
	int i;
	for(i=1; i<=3; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_transi(Tarbol raiz, int n){
	int i;
	for(i=1; i<=n; i++){
		raiz=raiz->sig;
	}
	return raiz;
}

T_ele retorna_dato_cadena(Tstring nodo){
	return nodo->dato_cadena;
}

void acepta_cadena(Tarbol arbol){
	Tarbol q_0, F, T, T_recorre, aux_T, nuevo, acep, ant, auxAnt;
	Tcadena leido;
	T_ele elemAnt;
	int i=0,b1,b2, n=4;
	char cara; 
	q_0=retorna_estado_inicial(arbol);
	F=retorna_estado_acep(arbol);
	T=retorna_transi(arbol, n);
	ant=auxAnt=nuevo=acep=T_recorre=arbol_vacio();
	agrega_elemento_arbol(&ant,retorna_dato_cadena((Tstring)q_0->dato_arbol));
	auxAnt=ant;
	T_recorre=T;
	printf("\n\nSe respondera si una cadena es aceptada o no. ");
	printf("\nIngrese cadena: ");
	leeCad(leido,tam_max);
	cara=leido[i];
	while(cara!='\0'){
		while(auxAnt!=NULL){
				aux_T=T->dato_arbol;
				T_recorre=T;
			    while(aux_T!=NULL){
					elemAnt=retorna_dato_cadena((Tstring)auxAnt->dato_arbol);
				    b1=strcmp(retorna_dato_cadena((Tstring)aux_T->dato_arbol).cadena, elemAnt.cadena);
				    aux_T=aux_T->sig;
				    b2=strcmp(retorna_dato_cadena((Tstring)aux_T->dato_arbol).cadena, carga_caracter_ele(cara).cadena);
				    if(b1==0 && b2==0){
						aux_T=aux_T->sig;
					    agrega_repetidos_arbol(&nuevo,aux_T);
				}
				aux_T=T_recorre->sig;
				T_recorre=T_recorre->sig;
				if(aux_T!=NULL)
					aux_T=aux_T->dato_arbol;
			}
			auxAnt=auxAnt->sig;
		}
		ant=nuevo;
		auxAnt=ant;
		nuevo=arbol_vacio();
		i++;
		cara=leido[i];
	}
	if(interseccion_arbol(ant, F)!=NULL)
		  printf("\nLA CADENA ES ACEPTADA!");
	else
		printf("\nLA CADENA NO ES ACEPTADA!");
}

Tarbol arbol_vacio(){
	return NULL;
}
void interseccion_arbol_rec(Tarbol a,Tarbol b, Tarbol *nuevo){
	if(a!=NULL){
		if(pertenece_arbol(b, retorna_dato_cadena((Tstring)a->dato_arbol))==1)  //si es igual a 1 pertenece
			agrega_elemento_arbol(nuevo, retorna_dato_cadena((Tstring)a->dato_arbol));
		a=a->sig;
		interseccion_arbol_rec(a, b, nuevo);
	}
}

Tarbol interseccion_arbol(Tarbol a, Tarbol b){
	Tarbol nuevo=arbol_vacio();
	interseccion_arbol_rec(a, b, &nuevo);
	return nuevo;
}

int pertenece_arbol(Tarbol a, T_ele e){ //si lo encontro retorna 1
	if(a!=NULL){
		if(a->dato_arbol!=NULL){
			if(a!=NULL && compara_ele(retorna_dato_cadena((Tstring)a->dato_arbol), e)!=0){
				a=a->sig;
			    return pertenece_arbol(a, e);
		    }
		    if(a==NULL)
				return 0;
			else 
				return 1; 
	    }
		else
			return 0;
	}
	else 
	   return 0;
}

void agrega_repetidos_arbol(Tarbol *a, Tarbol b){
	Tarbol aux;
	aux=arbol_vacio();
	//printf("\nentro a agrega repetidos arbol");
	while(b!=NULL){
		if(*a==NULL){
			*a=crea_nodo_arbol();
			crea_hijos_parametro(a, retorna_dato_cadena((Tstring)b->dato_arbol));
		}
		else{
			aux=*a;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=crea_nodo_arbol();
			crea_hijos_parametro(&aux->sig, retorna_dato_cadena((Tstring)b->dato_arbol));
		}
     	b=b->sig;
	}
}

void crea_hijos_parametro(Tarbol *raiz, T_ele dato){
	(*raiz)->dato_arbol=(Tarbol)crea_nodo_string_parametro(dato);
	(*raiz)->sig=NULL;
}

void agrega_elemento_arbol(Tarbol *lis, T_ele dato){
	Tarbol aux;
	Tarbol nodo;
	nodo=crea_nodo_arbol();
	crea_hijos_parametro(&nodo, dato);
	
	if(*lis==NULL){
		*lis=nodo;
	}
	else{
		aux=*lis;
		while(aux->sig!=NULL)
			aux=aux->sig;
	    aux->sig=nodo;
	}
}

/*
void carga_elemento_arbol(Tarbol *lis, T_ele dato){
	Tarbol aux;
	Tarbol nodo;
	nodo=crea_nodo_arbol();
	crea_hijos_parametro(&nodo, dato);
	
	if(*lis->dato_arbol==NULL){
		*lis->dato_arbol=nodo;
	}
	else{
		aux=*lis;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=nodo;
	}
}
*/
