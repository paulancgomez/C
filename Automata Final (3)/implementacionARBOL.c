#include "interfazARBOL.h"
#include <stdlib.h>

//CREA NODOS
Tarbol crea_nodo_arbol();
Tstring crea_nodo_string();
Tstring crea_nodo_string_parametro(T_ele);

//INICIALIZA
void crea_hijos(Tarbol*);
void crea_hijos_ultimo(Tarbol*);
void crea_hijos_parametro(Tarbol*, T_ele);

//CARGA ARBOL
void carga_alfabeto_arbol(Tarbol);
void carga_conjunto_arbol(Tarbol, int, int, T_ele);
void carga_estado_ini(Tarbol, Tarbol);
void carga_estados_arbol(Tarbol);
void carga_estado_acep(Tarbol, Tarbol);
void carga_transi_arbol(Tarbol, Tarbol);

//MUESTRA ARBOL
void muestra_conjunto(Tarbol);
void muestra_nodo_string(Tstring);
void muestra_trans(Tarbol);
void muestra_conjunto_trans(Tarbol);

//RETORNA
T_ele retorna_dato_cadena(Tstring);
Tarbol retorna_Q(Tarbol raiz);
Tarbol retorna_alfabeto(Tarbol raiz);
Tarbol retorna_estado_acep(Tarbol);
Tarbol retorna_estado_inicial(Tarbol);
Tarbol retorna_transi(Tarbol);

//OTROS
Tarbol despuesComa_arbol(Tcadena);
int repe_transiciones_arbol(Tarbol, T_ele);
int contiene_arbol(Tarbol,Tarbol );
int pertenece_arboles(Tarbol, Tarbol);
void agrega_elemento_arbol(Tarbol *, T_ele);
Tarbol interseccion_arbol(Tarbol, Tarbol);
void interseccion_arbol_rec(Tarbol a,Tarbol b, Tarbol *nuevo);
void agrega_repetidos_arbol(Tarbol *, Tarbol);
int pertenece_arbol(Tarbol, T_ele);
int cant_estados_arbol(Tarbol);
void analiza_transi(Tarbol, Tarbol*, Tarbol*);
Tarbol busca_retorna_estado_acep(Tarbol, Tarbol, T_ele, Tarbol*);
Tarbol busca_retorna_estado_acep_2(Tarbol, T_ele, T_ele);
int pertenece_arboles_2(Tarbol, Tarbol);
void agrega_repetidos_arbol_2(Tarbol *a, Tarbol b);
void agrega_arbol_ultimo(Tarbol *, Tarbol);
void pertenece_arboles_union_simple(Tarbol *, Tarbol);
void muestra_trans_especial(Tarbol raiz, Tarbol);
void muestra_conjunto_trans_especial(Tarbol, Tarbol);
void muestra_conjunto_especial(Tarbol);
void interseccion_arbol_especial(Tarbol, Tarbol, Tarbol*);
void crea_nuevo_conjunto_parametro(Tarbol *, Tarbol);
void agrega_arbol_ultimo_parametro(Tarbol *, T_ele);

//DESARROLLO


//MODULOS PUBLICOS

Tarbol arbol_vacio(){
	return NULL;
}

Tarbol carga_arbol(){
	Tarbol arbol, aux, Q;
	
	printf("\n\nCARGANDO AUTOMATA..");
	
	arbol=aux=arbol_vacio();
	
	printf("\n\nINGRESO DE ESTADOS");
	arbol=crea_nodo_arbol();
	crea_hijos(&arbol);
	carga_estados_arbol(arbol->dato_arbol);
	Q=arbol->dato_arbol;
	
	printf("\nINGRESO DE ALFABETO");
	aux=arbol->sig;
	crea_hijos(&aux);
	carga_alfabeto_arbol(aux->dato_arbol);
	
	printf("\nINGRESO DE ESTADO INICIAL");
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_ini(aux->dato_arbol, Q);
	
	printf("\nINGRESO DE ESTADOS DE ACEPTACION");
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_acep(aux->dato_arbol, arbol);
	
	printf("\nINGRESO DE TRANSICIONES");
	printf("\nNOTA: LA CARGA DE TRANSICION CUANDO TIENE UN SOLO ESTADO DE LLEGADA ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,EstadoLlegada");
	printf("\nNOTA: LA CARGA DE TRANSICION CUANDO TIENE MAS DE UN ESTADO DE LLEGADA ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,{EstadoLlegada1,EstadoLlegada2,...}");
	printf("\nNOTA: LA CARGA DE TRANSICION DE UN ESTADO QUE LLEGA AL VACIO ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,");
	
	aux=aux->sig;
	crea_nodo_arbol(&aux);
	carga_transi_arbol(aux, arbol);
	
	printf("\nAUTOMATA CARGADO.");
	
	printf("\n\n");
	system("PAUSE");
	system("cls");
	
	return arbol;
}

Tarbol convertir(Tarbol arbol){   //el problema esta en la interseccion
	Tarbol nuevo_arbol, aux, nuevo_Q, nuevo_T, nuevo_F, E, q_0;
	
	nuevo_arbol=nuevo_F=nuevo_Q=nuevo_T=arbol_vacio();
	E=retorna_alfabeto(arbol);
    q_0=retorna_estado_inicial(arbol);
	
	analiza_transi(arbol, &nuevo_Q, &nuevo_T);
	interseccion_arbol_especial(nuevo_Q, arbol, &nuevo_F);
	
	nuevo_arbol=crea_nodo_arbol();
	crea_hijos(&nuevo_arbol);
	nuevo_arbol->dato_arbol=nuevo_Q; //carga los estados
	aux=nuevo_arbol->sig;
	crea_hijos(&aux);
	aux->dato_arbol=E;  //carga el alfabeto
	aux=aux->sig;
	crea_hijos(&aux);
	aux->dato_arbol=q_0;  //carga el estado inicial
	aux=aux->sig;
	crea_hijos(&aux);
	aux->dato_arbol=nuevo_F; //carga los estados finales
	aux->sig=nuevo_T; //carga las transiciones

	return nuevo_arbol;
}


void acepta_cadena(Tarbol arbol){    //acepta cadena
	Tarbol q_0, F, T, T_recorre, aux_T, nuevo, acep, ant, auxAnt;
	Tcadena leido;
	T_ele elemAnt;
	int i=0,b1,b2;
	char cara; 
	
	q_0=retorna_estado_inicial(arbol);
	F=retorna_estado_acep(arbol);
	T=retorna_transi(arbol);
	
	ant=auxAnt=nuevo=acep=T_recorre=arbol_vacio();
	agrega_elemento_arbol(&ant, retorna_dato_cadena((Tstring)q_0->dato_arbol));  //ant contiene el estado inicial
	auxAnt=ant;    //auxant contiene el estado inicial
	T_recorre=T;
	printf("\n\nSe respondera si una cadena es aceptada o no. ");
	printf("\nNOTA: La tecla Enter representara la cadena vacia. ");
	printf("\nIngrese cadena: ");
	leeCad(leido,tam_max);   //leido contiene la cadena
	cara=leido[i];  //cara es el primer caracter de la cadena
	while(cara!='\0'){
		while(auxAnt!=NULL){
			aux_T=T->dato_arbol;  //aux_t son las transicones   
			T_recorre=T;   //t_recorre es la raiz
			while(aux_T!=NULL){
				elemAnt=retorna_dato_cadena((Tstring)auxAnt->dato_arbol);  //elemAnt es el estado inicial
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
		
		printf("\nmuestra aux_ant");
		muestra_conjunto(auxAnt);
	}
	printf("\nmuestra ant");
	muestra_conjunto(ant);
	printf("\nmuestra F");
	muestra_conjunto(F);
	
	if(interseccion_arbol(ant, F)!=NULL)
		  printf("\nLA CADENA ES ACEPTADA!");
	else
		printf("\nLA CADENA NO ES ACEPTADA!");
}

void muestra_arbol(Tarbol raiz){ 
	printf("\nMOSTRANDO DATOS DEL AUTOMATA..");
	printf("\n\n*******************************");
	printf("\nMUESTRA ESTADOS");
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
	printf("\n\n*******************************");
}

void muestra_arbol_especial(Tarbol raiz){ 
	Tarbol E;
	printf("\n\nMOSTRANDO DATOS DEL AUTOMATA..");
	printf("\n\n*******************************");
	printf("\n\nMUESTRA ESTADOS");
	muestra_conjunto_especial(raiz->dato_arbol);
	printf("\n\nMUESTRA ALFABETO");
	raiz=raiz->sig;
	E=raiz->dato_arbol;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADO INICIAL");	
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADOS DE ACEPTACION");
	raiz=raiz->sig;
	muestra_conjunto_especial(raiz->dato_arbol);
	printf("\n\nMUESTRA TRANSICIONES");
	raiz=raiz->sig;
	muestra_trans_especial(raiz, E);
	printf("\n\n*******************************");
}

//CREA NODOS

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


//MUESTRA ARBOL

void muestra_trans(Tarbol raiz){  //muestra el conjunto de transiciones
	if(raiz!=NULL){
		printf("\n{");
	    while(raiz!=NULL){
			muestra_conjunto_trans(raiz->dato_arbol);
		    raiz=raiz->sig;
		    if(raiz!=NULL)
				printf(", ");
	    }
	    printf("}");
	}
	else
	   printf("\nCONJUNTO VACIO.");
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
	if(i==2){
		muestra_nodo_string((Tstring)raiz->dato_arbol);
		printf(", EstadoVacio");
	}
	else
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

void muestra_trans_especial(Tarbol raiz, Tarbol E){  //muestra el conjunto de transiciones
	printf("\n{");
	while(raiz!=NULL){
		muestra_conjunto_trans_especial(raiz->dato_arbol, E);
		raiz=raiz->sig;
		if(raiz!=NULL)
			printf(", ");
	}
	printf("}");
}

void muestra_conjunto_trans_especial(Tarbol raiz, Tarbol E){  //muestra una transicion
	Tarbol aux;
	T_ele vacio;
	int i=0;
	vacio=carga_ele_parametro("*");
	printf("({");
	while(raiz->sig!=NULL){ //si no es la ultima
		//printf("muestra pertenece arbol: %d", pertenece_arbol(E, retorna_dato_cadena((Tstring)(raiz->sig)->dato_arbol)));
		
		if(compara_ele(retorna_dato_cadena((Tstring)raiz->dato_arbol), vacio)==0)
			printf("EstadoVacio");
		else
			muestra_nodo_string((Tstring)raiz->dato_arbol);
		if(i==1){
			printf(", {");
			i++;
		}
		aux=raiz->sig;
		if(pertenece_arbol(E, retorna_dato_cadena((Tstring)aux->dato_arbol))==0 && i<2)//verdadero si la siguiente no llego a la letra
			printf(", ");
		else{
			if(i<2){
				printf("}, ");
				i++;
			}
			else{
				i++;
				if(i>3)
					printf(", ");
			}
		}
		raiz=raiz->sig;
	}
	if(compara_ele(retorna_dato_cadena((Tstring)raiz->dato_arbol), vacio)==0)
		  printf("EstadoVacio");
	else
		muestra_nodo_string((Tstring)raiz->dato_arbol);
	printf("})");
}

void muestra_conjunto_especial(Tarbol raiz){
	Tarbol aux;
	T_ele vacio;
	vacio=carga_ele_parametro("*");
	if(raiz!=NULL){
		printf("\n{");
	    while(raiz->sig!=NULL){
			if((raiz->dato_arbol)->tipo==STRING){
				printf("{");
			    if(compara_ele(retorna_dato_cadena((Tstring)raiz->dato_arbol), vacio)==0)
					printf("EstadoVacio");
			    else
					muestra_nodo_string((Tstring)raiz->dato_arbol);
			    printf("}, ");
		    }
		    else{
				aux=raiz->dato_arbol;
			    printf("{");
			    while(aux->sig!=NULL){
					muestra_nodo_string((Tstring)aux->dato_arbol);
				    printf(", ");
				    aux=aux->sig;
			    }
			    muestra_nodo_string((Tstring)aux->dato_arbol);
			    printf("}, ");
		    }
		    raiz=raiz->sig;
	    }
	    if((raiz->dato_arbol)->tipo==STRING){
			printf("{");
		    if(compara_ele(retorna_dato_cadena((Tstring)raiz->dato_arbol), vacio)==0)
				printf("EstadoVacio");
		    else
				muestra_nodo_string((Tstring)raiz->dato_arbol);
		    printf("}}");
	    }
	    else{
			raiz=raiz->dato_arbol;
		    printf("{");
		    while(raiz->sig!=NULL){
			    muestra_nodo_string((Tstring)raiz->dato_arbol);
			    printf(", ");
			    raiz=raiz->sig;
		    }
		    muestra_nodo_string((Tstring)raiz->dato_arbol);
		    printf("}}");
	    }
	}
	else
	   printf("\nCONJUNTO VACIO");
}

//CARGA ARBOL

void carga_conjunto_arbol(Tarbol aux, int cont, int e, T_ele cadena){
	while(cont<e){
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
		aux->sig=crea_nodo_arbol();
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
}

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
		if(tam<=0)
			printf("Por favor ingrese una cantidad positiva.\n");
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

void carga_estados_arbol(Tarbol Q){
	Tarbol aux;
	T_ele x, vacio;
	int i,b,c,z;
	aux=Q;
	printf("\n");
	do{
		printf("Ingrese la cantidad de estados: ");
		scanf("%d",&c);
		if(c<=0)
			printf("Por favor ingrese una cantidad positiva.\n");
	}while(c<=0);
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

void carga_estado_ini(Tarbol q_0, Tarbol Q){
	T_ele x;
	int b;
	printf("\nIngrese el nombre del estado: ");
	x=carga_ele();
	b=pertenece_arbol(Q, x);
	while(b==0){
		printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
	}
	q_0->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
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
		printf("Desea ingresar otro estado de aceptacion? SI (1) - NO (0): ");
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

void carga_transi_arbol(Tarbol T, Tarbol arbol){
	Tarbol Q, E, aux, T_recorre, acep, nuevo; 
	int res;
	T_ele elemTran1, elemTran2;
	Tcadena tranLeida,auxTranLeida;
	res=1;
	aux=acep=nuevo=arbol_vacio();
	Q=retorna_Q(arbol);
	E=retorna_alfabeto(arbol);
	T_recorre=T;
	printf("\n\n");
	aux=T_recorre;
	do{
		printf("Ingrese transicion: ");	
		leeCad(tranLeida,100);
		strcpy(auxTranLeida,tranLeida);
		elemTran1=antesComa(auxTranLeida);  
		if(pertenece_arbol(Q,elemTran1)==1 && repe_transiciones_arbol(T, elemTran1)<=cant_estados_arbol(E)){
			strcpy(auxTranLeida,tranLeida);
			elemTran2=entreComa(auxTranLeida); 
			if(pertenece_arbol(E,elemTran2)==1){
				strcpy(auxTranLeida,tranLeida);
				acep=despuesComa_arbol(auxTranLeida);
				agrega_elemento_arbol(&nuevo, elemTran1);
				agrega_elemento_arbol(&nuevo, elemTran2);
				agrega_repetidos_arbol(&nuevo, acep);
				if(contiene_arbol(acep, Q) && pertenece_arboles(T,nuevo)==0){
					printf("Desea ingresar otra transicion? SI(1) - NO(0): ");
					scanf("%d",&res);
					fflush(stdin);
					if(res==1){
						agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=crea_nodo_arbol();
						T_recorre=T_recorre->sig;
						nuevo=arbol_vacio();
						aux=aux->sig;
					}
					else{
						agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=arbol_vacio();
					}
				}
				else
					printf("ESTADO DE LLEGADA NO VALIDO.");
				
			}
			else
				printf("ELEMENTO DE ALFABETO NO VALIDO.");
		}
		else
			printf("\nESTADO DE PARTIDA NO VALIDO.");
	} while(res!=0);
}


//INICIALIZA

void crea_hijos(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=crea_nodo_arbol();
}

void crea_hijos_ultimo(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=NULL;
}

void crea_hijos_parametro(Tarbol *raiz, T_ele dato){
	(*raiz)->dato_arbol=(Tarbol)crea_nodo_string_parametro(dato);
	(*raiz)->sig=NULL;
}


//RETORNA

Tarbol retorna_Q(Tarbol raiz){ //retorna el puntero a los estados
	raiz=raiz->dato_arbol;
	return raiz;
}

Tarbol retorna_alfabeto(Tarbol raiz){ //retorna el puntero al alfabeto
	raiz=raiz->sig;
	return raiz->dato_arbol;
}

Tarbol retorna_estado_inicial(Tarbol raiz){  //retorna el puntero al estado incial
	int i;
	for(i=1; i<=2; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_estado_acep(Tarbol raiz){  //retorna el puntero a los estados de aceptacion
	int i;
	for(i=1; i<=3; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_transi(Tarbol raiz){   //retorna el punteroa a las transiciones
	int i;
	for(i=1; i<=4; i++){
		raiz=raiz->sig;
	}
	return raiz;
}

T_ele retorna_dato_cadena(Tstring nodo){   //retorna el dato del puntero tipo String
	return nodo->dato_cadena;
}


//OTROS
	
int cant_estados_arbol(Tarbol raiz){  //retorna la cantidad de nodos del arbol
	int c=0;
	while(raiz!=NULL){
		c++;
		raiz=raiz->sig;
	}
	return c;
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
			return 0;
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

int repe_transiciones_arbol(Tarbol T, T_ele elem){//calcula que la cantidad de transiciones desde un mismo estado de partida no sea mayor a la del alfabeto
	int c=0;
	T_ele aux_elem;
	Tarbol aux_T;
	aux_T=T;
	if(aux_T->dato_arbol!=NULL){
		while(aux_T->dato_arbol!=NULL){
			aux_T=aux_T->dato_arbol;
			aux_elem=retorna_dato_cadena((Tstring)aux_T->dato_arbol);
			if(compara_ele(aux_elem,elem)==0)//VER SI SE BURLA EL ENCAPSULAMIENTO
				c++;
			aux_T=T->sig;
			T=T->sig;
		}
	}
	return c;
}

Tarbol despuesComa_arbol(Tcadena n){
	Tarbol nuevo=arbol_vacio();
	T_ele aux;
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	auxc=strtok(NULL,",{}");
	while(auxc!=NULL){
		aux=carga_ele_parametro(auxc);
		agrega_elemento_arbol(&nuevo,aux);
		auxc=strtok(NULL,",{}");
	}
	return nuevo;
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

void crea_nuevo_conjunto_parametro(Tarbol *a, Tarbol b){
	Tarbol aux, nodo;
	nodo=crea_nodo_arbol();
	
	while(b!=NULL){
		nodo=crea_nodo_arbol();
		crea_hijos_parametro(&nodo, retorna_dato_cadena((Tstring)b->dato_arbol));
		if(*a==NULL){
			*a=nodo;
		}
		else{
			aux=*a;
			while(aux->sig!=NULL)
				aux=aux->sig;
			aux->sig=nodo;
		}
		b=b->sig;
	}
}

void crea_nuevo_conjunto_transi_parametro(Tarbol *a, Tarbol b){
	Tarbol rama, aux_rama, aux_b, aux;
	*a=arbol_vacio();
	
	while(b!=NULL){
		rama=crea_nodo_arbol();
		crea_hijos_ultimo(&rama);
		aux_rama=rama->dato_arbol;
		aux_b=b->dato_arbol;
		
		while(aux_b->sig!=NULL){
			crea_hijos(&aux_rama);
			aux_rama->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)aux_b->dato_arbol));
			aux_rama=aux_rama->sig;
			aux_b=aux_b->sig;
			
		}
		crea_hijos_ultimo(&aux_rama);
		aux_rama->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)aux_b->dato_arbol));
		
		if(*a==NULL){
			*a=rama;
		}
		else{
			aux=*a;
			while(aux->sig!=NULL)
				aux=aux->sig;
			aux->sig=rama;
		}
		b=b->sig;
	}
}

void crea_nuevo_conjunto_especial_parametro(Tarbol *a, Tarbol b){
	Tarbol rama, aux_rama, aux_b, aux;
	*a=arbol_vacio();
	
	while(b!=NULL){
		if((b->dato_arbol)->tipo==STRING){
			rama=crea_nodo_arbol();
		    crea_hijos_parametro(&rama, retorna_dato_cadena((Tstring)b->dato_arbol));
		}
		else{
			rama=crea_nodo_arbol();
		    crea_hijos_ultimo(&rama);
		    aux_rama=rama->dato_arbol;
		    aux_b=b->dato_arbol;	
			while(aux_b->sig!=NULL){
				crea_hijos(&aux_rama);
			    aux_rama->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)aux_b->dato_arbol));
			    aux_rama=aux_rama->sig;
			    aux_b=aux_b->sig;
			}
		    crea_hijos_ultimo(&aux_rama);
		    aux_rama->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)aux_b->dato_arbol));
		}
		if(*a==NULL){
			*a=rama;
		}
		else{
			aux=*a;
			while(aux->sig!=NULL)
				aux=aux->sig;
			aux->sig=rama;
		}
		b=b->sig;
	}
}

void analiza_transi(Tarbol arbol, Tarbol *nuevo_Q, Tarbol *nuevo_T){
	Tarbol aux_E, aux_ori_E, estados_acep, aux_estados_acep, aux_ori_T, ori_T, aux_T, aux_nuevo_T, Q_recorre, E, T, Q_recorre_aux, aux_nuevo_Q, q_0;
	aux_E=estados_acep=aux_ori_E=aux_ori_T=aux_T=ori_T=*nuevo_T=aux_nuevo_Q=aux_estados_acep=Q_recorre=aux_nuevo_T=Q_recorre_aux=arbol_vacio();
	
	q_0=retorna_estado_inicial(arbol);
	E=retorna_alfabeto(arbol);
	T=retorna_transi(arbol);

	crea_nuevo_conjunto_parametro(&aux_ori_E, E);
	crea_nuevo_conjunto_parametro(nuevo_Q, q_0);
	crea_nuevo_conjunto_parametro(&Q_recorre, q_0);
	crea_nuevo_conjunto_transi_parametro(&ori_T, T);
	
	aux_E=aux_ori_E;
	
	while(Q_recorre!=NULL){
		while(aux_E!=NULL){
			crea_nuevo_conjunto_especial_parametro(&Q_recorre_aux, Q_recorre);
			aux_nuevo_T=arbol_vacio();
			crea_nuevo_conjunto_transi_parametro(&aux_ori_T, ori_T);
			aux_T=arbol_vacio();
			estados_acep=busca_retorna_estado_acep(aux_ori_T, Q_recorre_aux, retorna_dato_cadena((Tstring)aux_E->dato_arbol), &aux_T);    //contiene la union de los estados de llegada
			Q_recorre=arbol_vacio();
			crea_nuevo_conjunto_especial_parametro(&Q_recorre, Q_recorre_aux);
			aux_nuevo_Q=arbol_vacio();
			crea_nuevo_conjunto_especial_parametro(&aux_nuevo_Q, *nuevo_Q);
			aux_estados_acep=arbol_vacio();
			crea_nuevo_conjunto_especial_parametro(&aux_estados_acep, estados_acep);
			aux_nuevo_Q=arbol_vacio();
			crea_nuevo_conjunto_especial_parametro(&aux_nuevo_Q, *nuevo_Q);
			aux_estados_acep=arbol_vacio();
			crea_nuevo_conjunto_especial_parametro(&aux_estados_acep, estados_acep);
			if(pertenece_arboles_2(aux_nuevo_Q, aux_estados_acep)==0){ //no pertenece
				aux_estados_acep=arbol_vacio();
				crea_nuevo_conjunto_especial_parametro(&aux_estados_acep, estados_acep);
				agrega_arbol_ultimo(nuevo_Q, aux_estados_acep);   //agrego al conjunto original de los estados
				aux_estados_acep=arbol_vacio();
				crea_nuevo_conjunto_especial_parametro(&aux_estados_acep, estados_acep);
				agrega_arbol_ultimo(&Q_recorre, aux_estados_acep);
			}
			aux_nuevo_T=arbol_vacio();
			crea_nuevo_conjunto_transi_parametro(&aux_nuevo_T, *nuevo_T);
			if(pertenece_arboles(aux_nuevo_T, aux_T->dato_arbol)==0){  //pregunta si la transi pertenece (0) a 
				
				agrega_arbol_ultimo(nuevo_T, aux_T);
			}
		    aux_E=aux_E->sig;
	    }
		Q_recorre=Q_recorre->sig;
		aux_E=aux_ori_E;
	}
}

int pertenece_arboles_2(Tarbol a, Tarbol bus){  //1 si pertenece
	Tarbol aux_a, aux_bus;
	int ret, b;
	ret=0;
	b=0;
	if(a!=NULL){
		while(a!=NULL && ret!=1){
		    if((a->dato_arbol)->tipo==STRING && (bus->dato_arbol)->tipo==STRING){   //estructura simple
				if(compara_ele(retorna_dato_cadena((Tstring)a->dato_arbol), retorna_dato_cadena((Tstring)bus->dato_arbol))==0){
				    ret=1;
				}
		    }
			else{
			    if((a->dato_arbol)->tipo==SET && (bus->dato_arbol)->tipo==SET){
					aux_a=a->dato_arbol;
			        aux_bus=bus->dato_arbol;
					while(aux_bus->sig!=NULL){
						while(aux_a!=NULL && b!=1){
							if(compara_ele(retorna_dato_cadena((Tstring)aux_a->dato_arbol), retorna_dato_cadena((Tstring)aux_bus->dato_arbol))==0)
								b=1;
					        aux_a=aux_a->sig;
						}
						if(b==1){
							aux_bus=aux_bus->sig;
							aux_a=a->dato_arbol;
							if(aux_bus->sig==NULL)
								b=2;
							else
								b=0;
						}
						else{
							b=3;
							while(aux_bus->sig!=NULL){
								aux_bus=aux_bus->sig;
							}
						}
				    }
					if(b==2){
						aux_a=a->dato_arbol;
					    b=0;
					    while(aux_a!=NULL && b!=1){
							if(compara_ele(retorna_dato_cadena((Tstring)aux_a->dato_arbol), retorna_dato_cadena((Tstring)aux_bus->dato_arbol))==0)
								b=1;
						    aux_a=aux_a->sig;
					    }
					    if(b==1){
							if(cant_estados_arbol(a->dato_arbol)==cant_estados_arbol(bus->dato_arbol)){
							    ret=1;
							}
					    }
					}  
			    } //if
			} //else
		    a=a->sig;
			b=0;
		}
	}
	else
	   ret=0;  //no pertenece
	return ret;
}

Tarbol busca_retorna_estado_acep(Tarbol T, Tarbol Q, T_ele E, Tarbol *nuevo_T){ //retorna estados aceptacion de uno o mas estados de partida y su simbolo
	Tarbol estado_acep, union_estado_acep, aux, aux_union, aux_T;
	T_ele vacio;
	estado_acep=union_estado_acep=aux_union=arbol_vacio();
	*nuevo_T=arbol_vacio();
	if(Q!=NULL){
		if((Q->dato_arbol)->tipo==STRING){  //para un solo estado de partida
			vacio=carga_ele_parametro("*");
			if(compara_ele(retorna_dato_cadena((Tstring)Q->dato_arbol), vacio)==0){
				fflush(stdin);
				agrega_arbol_ultimo_parametro(&union_estado_acep, vacio);
			}
			else
				union_estado_acep=busca_retorna_estado_acep_2(T, retorna_dato_cadena((Tstring)Q->dato_arbol), E);
			*nuevo_T=crea_nodo_arbol();
			crea_hijos_ultimo(nuevo_T);
			aux_T=(*nuevo_T)->dato_arbol;
			crea_hijos(&aux_T);
			aux_T->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)Q->dato_arbol));
			aux_T=aux_T->sig;
			crea_hijos_ultimo(&aux_T);
			aux_T->dato_arbol=(Tarbol)crea_nodo_string_parametro(E);
			if(union_estado_acep==NULL){
				fflush(stdin);
				agrega_arbol_ultimo_parametro(&union_estado_acep, vacio);
			}
			agrega_repetidos_arbol_2(&aux_T->sig, union_estado_acep);
		}
		else{                                               //para mas de un estado de partida
			aux=Q->dato_arbol;	
			*nuevo_T=crea_nodo_arbol();
			crea_hijos_ultimo(nuevo_T);
			aux_T=(*nuevo_T)->dato_arbol;
			crea_hijos(&aux_T);
			while(aux!=NULL){
				estado_acep=busca_retorna_estado_acep_2(T, retorna_dato_cadena((Tstring)aux->dato_arbol), E);
				aux_T->dato_arbol=(Tarbol)crea_nodo_string_parametro(retorna_dato_cadena((Tstring)aux->dato_arbol));
				aux_T=aux_T->sig;
				if(aux->sig!=NULL)
					crea_hijos(&aux_T);
				else
					crea_hijos_ultimo(&aux_T);
				aux=aux->sig;
				pertenece_arboles_union_simple(&union_estado_acep, estado_acep);
			}
			aux_T->dato_arbol=(Tarbol)crea_nodo_string_parametro(E);
			agrega_repetidos_arbol_2(&aux_T->sig, union_estado_acep);
		}
	}
	if(union_estado_acep==NULL){
		fflush(stdin);
	    agrega_arbol_ultimo_parametro(&union_estado_acep, vacio);
	}
	if(union_estado_acep->sig!=NULL){
		aux_union=crea_nodo_arbol();
		agrega_arbol_ultimo(&aux_union->dato_arbol, union_estado_acep);
		return aux_union;
	}
	else{
		return union_estado_acep;
	}
}

void pertenece_arboles_union_simple(Tarbol *a, Tarbol b){  //union de conjuntos simple
	Tarbol aux_a;
	int band=0;
	if(*a!=NULL){
		while(b!=NULL){
			aux_a=*a;
		    while(aux_a!=NULL && b!=NULL && band==0){
			    if(compara_ele(retorna_dato_cadena((Tstring)aux_a->dato_arbol), retorna_dato_cadena((Tstring)b->dato_arbol))==0){
				    band=1;
			    }
			    aux_a=aux_a->sig;
		    }
			if(aux_a==NULL && band==0){
				agrega_elemento_arbol(a, retorna_dato_cadena((Tstring)b->dato_arbol));
			}
			b=b->sig;
			band=0;
		}
	}
	else
		*a=b;
}

void agrega_repetidos_arbol_2(Tarbol *a, Tarbol b){
	Tarbol aux;
	aux=arbol_vacio();
	while(b!=NULL){
		if(*a==NULL){
			*a=crea_nodo_arbol();
			crea_hijos_ultimo(a);
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
Tarbol busca_retorna_estado_acep_2(Tarbol T, T_ele Q, T_ele E){ //retorna estados aceptacion de un estado de partida y su simbolo (busco en T)
	Tarbol estado_acep, aux_T;
	T_ele estado;
	estado_acep=arbol_vacio();
	aux_T=T;
	while(estado_acep==NULL && aux_T!=NULL){
		aux_T=aux_T->dato_arbol;
		estado=retorna_dato_cadena((Tstring)aux_T->dato_arbol);
		if(compara_ele(estado, Q)==0){
			aux_T=aux_T->sig;
			estado=retorna_dato_cadena((Tstring)aux_T->dato_arbol);
			if(compara_ele(estado, E)==0){
				estado_acep=aux_T->sig;
			}
		}
		aux_T=T->sig;
		T=T->sig;
	}
	return estado_acep;
}

void agrega_arbol_ultimo(Tarbol *a, Tarbol ins){
	Tarbol aux;
	if(*a==NULL){
		*a=ins;
	}
	else{
		aux=*a;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=ins;
	}
}

void agrega_arbol_ultimo_parametro(Tarbol *a, T_ele b){
	Tarbol aux;
	Tarbol nodo;
	crea_hijos_ultimo(&nodo);
	crea_hijos_parametro(&nodo, b);
	if(*a==NULL){
		*a=nodo;
	}
	else{
		aux=*a;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=nodo;
	}
}

void interseccion_arbol_especial(Tarbol a, Tarbol arbol, Tarbol *retorno){  //a contiene el nuevo_Q y b contiene los estados_acep viejo
	Tarbol aux_a, b, otro_aux, aux_a_ori, raiz, nuevo;
	int band=1;
	*retorno=arbol_vacio();
	nuevo=arbol_vacio();
	crea_nuevo_conjunto_especial_parametro(&aux_a, a);
	crea_nuevo_conjunto_especial_parametro(&aux_a_ori, a);
	raiz=crea_nodo_arbol();
	b=retorna_estado_acep(arbol);
	fflush(stdin);
	while(b!=NULL){
	    while(aux_a!=NULL){  //nuevo_Q
			if((aux_a->dato_arbol)->tipo==STRING){   //estructura simple
				if(compara_ele(retorna_dato_cadena((Tstring)aux_a->dato_arbol), retorna_dato_cadena((Tstring)b->dato_arbol))==0){
					nuevo=crea_nodo_arbol();
					crea_hijos_parametro(&nuevo, retorna_dato_cadena((Tstring)aux_a->dato_arbol));
					if(pertenece_arboles_2(*retorno, nuevo)==0){
						agrega_arbol_ultimo(retorno, nuevo);
					}
			    }
		    }
			else{
			    if((aux_a->dato_arbol)->tipo==SET){
					otro_aux=aux_a->dato_arbol;
				    while(otro_aux!=NULL && band!=0){
						if(compara_ele(retorna_dato_cadena((Tstring)otro_aux->dato_arbol), retorna_dato_cadena((Tstring)b->dato_arbol))==0){
							raiz=crea_nodo_arbol();
						    crea_hijos_ultimo(&raiz);
						    raiz->dato_arbol=aux_a->dato_arbol;
							if(pertenece_arboles_2(*retorno, raiz)==0){
								agrega_arbol_ultimo(retorno, raiz);
								band=0;
							}
					    }
					    otro_aux=otro_aux->sig;
				    }
			    }
		    }
		    aux_a=aux_a_ori->sig;
		    aux_a_ori=aux_a_ori->sig;
		    band=1;
	    }
		b=b->sig;
		crea_nuevo_conjunto_especial_parametro(&aux_a, a);
		crea_nuevo_conjunto_especial_parametro(&aux_a_ori, a);
		nuevo=arbol_vacio();
	}
}
