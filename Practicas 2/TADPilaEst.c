/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA ESTÁTICA (TADPilaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2016
VERSIÓN: 1.0

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando se le 
asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc TADPilaEst.c -c 
*/

//LIBRERAS
#include<stdio.h>
#include<stdlib.h>
#include "TADPilaEst.h"

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(pila *s);
Descripción: Inicializar pila (Iniciar una pila para su uso)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1; 
	return;
}

/*
void Push(pila *s, elemento e);
Descripción: Empilar (Introducir un elemento a la pila)
Recibe: pila *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida el indice del arreglo (tope) esta fuera del arreglo es decir hay desbordamiento
y se causará en error.
*/
void Push(pila *s, elemento e)
{
	s->tope++;
	
	//Si el tope alcanzo a MAX_ELEMENT, ya no hay más espacio para elementos en el arreglo
	if(s->tope==MAX_ELEMENT)
	{
		printf("\nERROR-Push(&s,e): Desbordamiento de la pila, no hay mas espacio en la pila");
		exit(1);
	}
	
	//Insertar el elemento si no hubo error
	s->arreglo[s->tope]=e;
	return;
}

/*
elemento Pop(pila *s);
Descripción: Desempilar (Extraer un elemento de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia (tope == -1) antes de desempilar (causa error desempilar si esta esta vacía)
*/
elemento Pop (pila *s)
{
	elemento r;
	
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Pop(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	r=s->arreglo[s->tope];
	s->tope--;
	return r; 	
}

/*
boolean Empy(pila *s);
Descripción: //Vacia (Preguntar si la pila esta vacia)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE según sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;	
	if(s->tope==-1)
	{
		r= TRUE;	
	}	
	else
	{
		r= FALSE;
	}	
	return r;	
}

/*
elemento Top(pila *s);
Descripción: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemento del tope (causa error si esta esta vacía).
*/
elemento Top(pila *s)
{
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	return s->arreglo[s->tope];	
}

/*
int Size(pila *s);
Descripción: Tamaño de la pila (Obtener el número de elementos en la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: int (Tamaño de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	return s->tope+1;
}
/*
void Destroy(pila *s);
Descripción: Elimina pila (Borra a todos los elementos en a la pila de memoria* Memoria estática (No se puede eleminar realmente)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella.
*/
void Destroy(pila *s)
{
	//s->tope=-1;
	Initialize(s);
	return;
}
// HECHA POR: MUNGUIA AGUILERA HECTOR ADRIAN. 	BOLETA: 2021630428. 	GRUPO: 2CV4
//FUNCION NUEVA RETORNA ELEMENTO N INGRESADO
elemento Element(pila *s, int n)
{
	if(n <= 0 || n > Size(s))
	{
		printf("Numero fuera de rango.");
		exit(1);
	}
	printf("\nEl elemento %d es: %c.\n", n, (*s).arreglo[n-1]);
	system("pause");
}
//FUNCION NUEVA INVIERTE LOS VALORES DE LA PILA
void Flip(pila *s)
{
	int tam = Size(s), j = 0;
	pila tmp;
	Initialize(&tmp);
	elemento e;
	for(int i = 0; i <= s->tope; i ++)
	{
		e = s->arreglo[i];
		Push(&tmp, e);
	}
	printf("Los elementos de tu pila son: |");
	for(int i = 0; i <= tmp.tope; i ++)
			printf(" %c |", tmp.arreglo[i]);
	printf("\nCon | %c | en la posicion 1 y | %c | en la posicion %d.", tmp.arreglo[0], tmp.arreglo[tmp.tope], tam);
	Destroy(s);
	for(int i = tmp.tope; i >= 0; i --)
		{
				e = tmp.arreglo[i];
				Push(s, e);
				j ++;
		}
	printf("\nTu pila invertida es: |");
	for(int i = 0; i <= (*s).tope; i ++)
		printf(" %c |", (*s).arreglo[i]);
	printf("\nCon | %c | en la posicion 1 y | %c | en la posicion %d.\n", (*s).arreglo[0], (*s).arreglo[(*s).tope], tam);
	system("pause");
}
//FUNCION NUEVA DESPLIEGA EL MENU
void Menu()
{
	printf("\n\t1. Push.\n\t2. Pop.\n\t3. Mostrar N elemento.\n\t4. Invertir pila.\n\t5. Destuir pila.\n\t6. Finalizar ejecucion.\nSelecciona una opcion: ");
}
void main(void){
	elemento e;
	pila s;
	Initialize(&s);
	int opc, n;
	do
	{
		boolean b = Empty(&s);
		int tam = Size(&s);
		Menu();
		scanf("%d", &opc);
		switch (opc)
		{
		case 1:
			printf("\n\t1. Push.\nDame un caracter: ");
			fflush(stdin);
			scanf("%c", &e.c);
			Push(&s, e);
			break;
		case 2:
			if(b == TRUE){
				printf("Pila vacia.");
				break;
			}
			printf("Salio %c", Pop(&s));
			break;
		case 3:
			if(b == TRUE)
			{
				printf("Pila vacia");
				break;
			}
			printf("\nTienes %d elementos en tu pila.\nIngresa la posicion del elemento a mostrar (del 1-%d): ", tam, tam);
			fflush(stdin);
			scanf("%d", &n);
			Element(&s, n);
			break;
		case 4:
			if(b == TRUE){
				printf("Pila vacia.");
				break;
			}
			Flip(&s);
			break;
		case 5:
			Destroy(&s);
			printf("Pila destruida.");
			break;
		case 6:
			printf("Finalizado...");
			break;
		default:
			printf("Opcion no valida.");
			break;
		}
	}while (opc != 6);
	
}