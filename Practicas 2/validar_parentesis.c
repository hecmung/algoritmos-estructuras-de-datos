/*
2021630428
MUNGUIA AGUILERA HECTOR ADRIAN 2CV4
*/
#include <stdio.h>
#include <windows.h>
#define MAX_CAD 200
typedef struct Elemento
{
	char i;
	//double d;
	//float f;
	//int i;
}elemento;
typedef struct Stack
{
	//elemento pila[TAM];
	elemento *pila;
	int top;
}stack;
void menu(void);
int vacia(stack *);  
int llena(stack *,int);//(pila,tam)
void ini(stack *);//inicializa
void push(stack *,elemento);
elemento pop(stack *);
void imp(stack *);
elemento * reserva(stack *,int);//(pila,tam)
//NUEVA
elemento * redim(stack *,int);//redimensiona(pila,tam) 
void convertirInfijoPostfijo(char [], stack*);// FUNCION NUEVA PARA HACER LA CONVERSION DE LAS OPERACIONES
void main(void)
{	
	int tam=200;
    char cadena[MAX_CAD];
	stack pila1;
	if(reserva(&pila1,tam))
	{
        printf("\nPuedes ingresar un maximo de %d caracteres. ", MAX_CAD);
		//NUEVA
		system("pause");
		elemento obj;
		int opc;
		do
		{
			menu();
			scanf("%d",&opc);
			switch(opc)
			{
				case 1:
                    fflush(stdin);
                    printf("Ingresa tus operaciones: ");
                    gets(cadena);
                    printf("Ingresaste: %s", cadena);
                    break;
				case 2: if(!llena(&pila1, tam))
                        {
                            
                        }
                        else
                            printf("Overflow\n");
						break;
				case 9: printf("Hasta luego....!");
						break;
				default: printf("Opción inválida, vuelve a intentar..."); break;
			}
			system("pause");
		}while(opc!=9);
	}
	else
		printf("Error. No se pudo crear el arreglo dinámico para la pila.");
}
void menu(void)
{
	system("cls");
	printf("Menú validacion de parentesis.\n\n");
	printf("1) Ingresar operaciones.\n");
	printf("2) Convertir de infijo -> postfijo.\n");
	printf("9) Salir.\n");
	printf("Opción: ");
}
int vacia(stack *s)  
{
	if(s->top==-1)
		return 1;
	else
		return 0;	
}
int llena(stack *s,int tam)
{
	//return (s->top==TAM-1?1:0);
	if(s->top==tam-1)
		return 1;
	else
		return 0;
}
void ini(stack *s)
{
	s->top=-1;
}
void push(stack *s,elemento obj)
{
	s->top++;
	s->pila[s->top]=obj;
	//s->pila[++s->top]=obj;
}
elemento pop(stack *s)
{
	elemento tmp=s->pila[s->top];
	s->top--;
	//elemento tmp=s->pila[s->top--];
	return tmp;
}
void imp(stack *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d\n",s->pila[i].i);
}
elemento * reserva(stack *s,int tam)
{
	s->pila=(elemento *)malloc(sizeof(elemento)*tam);
	return s->pila;
}
//TOLA LA FUNCIÓN redim es NUEVA
elemento * redim(stack *s,int tam)//redimensiona(pila,tam)
{
	s->pila =(elemento *)realloc(s->pila,tam);
	return s->pila;
}
void convertirInfijoPostfijo(char cadena[MAX_CAD], stack *s){

}