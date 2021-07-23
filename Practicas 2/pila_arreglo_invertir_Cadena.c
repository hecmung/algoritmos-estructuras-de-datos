#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h> 
#define TAM 5
typedef struct Elemento
{
	char i;
	//double d;
	//float f;
	//int i;
}elemento;
typedef struct Stack
{
	elemento pila[TAM];
	int top;
}stack;
void menu(void);
int vacia(stack *);  
int llena(stack *);
void ini(stack *);//inicializa
void push(stack *,elemento);
elemento pop(stack *);
void imprimirPila(stack *);
void main(void)
{
	stack pila1;
	elemento obj;
	ini(&pila1);
	int opc;
	do
	{
		menu();
		scanf("%d",&opc);
		switch(opc)
		{
			case 1: if(!llena(&pila1))
					{
						printf("Dame un caracter: ");
						fflush(stdin);
						scanf("%c",&obj.i);
						push(&pila1,obj);
						printf("Elemento agregado a la pila.\n");
					}
					else
						printf("Overflow\n");
					break;
			case 2: if (vacia(&pila1))
					{
						printf("Empyt\n");
					}
					else
					{
						imprimirPila(&pila1);
						do
						{
							printf("\nBorrado %c de la pila.", pop(&pila1));
						}while(!(vacia(&pila1)));
					}
					break;
			case 9: printf("Hasta luego....!");
					break;
			default: printf("Opción inválida, vuelve a intentar...");
		}
		system("pause");
	}while(opc!=9);
}
void menu(void)
{
	setlocale(LC_ALL, "");
	system("cls");
	printf("Menú Pila (Arreglo estático)\n\n");
	printf("1) Push.\n");
	printf("2) Imprimir.\n");
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
int llena(stack *s)
{
	//return (s->top==TAM-1?1:0);
	if(s->top==TAM-1)
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
	//s->pila[++top]=obj;
}
elemento pop(stack *s)
{
	elemento tmp=s->pila[s->top];
	s->top--;
	return tmp;
}
void imprimirPila(stack *s){
	int j;
	elemento actual = s->pila[s->top];
	printf("Tu pila es: ");
	for(int i = 0; i <= s->top; i ++){
		printf("%c, ", s->pila[i]);
	}
	printf("\nTu pila invertida es: ");
	for(j = s->top; j >= 0; j--)
	{
		printf("%c, ", actual.i);
		actual = s->pila[j-1];
	}
}