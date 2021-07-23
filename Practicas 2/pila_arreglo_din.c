/*
2021630428
MUNGUIA AGUILERA HECTOR ADRIAN 2CV4
*/
#include <stdio.h>
#include <windows.h>
typedef struct Elemento
{
	//char c;
	//double d;
	//float f;
	int i;
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
void main(void)
{	
	int tam=3, factor = 0;
	stack pila1;
	if(reserva(&pila1,tam))
	{
		//NUEVA
		printf("El tamaño inicial de la pila es de %d\n",tam);
		ini(&pila1);
		//NUEVA
		printf("Pila inicializada a vacía!\n");
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
				case 1: if(!llena(&pila1,tam))
						{
							printf("Dame un objeto entero: ");
							scanf("%d",&obj.i);
							push(&pila1,obj);
							printf("Elemento apilado!\n");
						}
						else
                        {
                            printf("Overflow.\nIngrese el factor (numero entero) para aumentar la pila: "); scanf("%d", &factor);
                                tam += factor;
                                if(redim(&pila1,(tam)))
                                {
                                    printf("\nSe agrego el factor con exito.\n");
                                    printf("El nuevo tamano de la pila es de %d\n", tam);
                                }
                        }
						break;
				case 2: if(!vacia(&pila1))
						{
							printf("\n\t1. Eliminar un solo elemento.\n\t2. Eliminar N elementos (se pide el factor N).\nSelecciona un numero:"); scanf("%d", &opc);
                            if(opc == 1)
							{
                                printf("Salio %d\n",pop(&pila1));
                            }
                            else if(opc == 2)
                                {
                                    printf("\nIngrese el factor (N entero) para eliminar de la pila: "); scanf("%d", &factor);
                                    if(factor < 0)
                                    {    
                                        printf("Numero invalido");
                                    }
                                    else
                                    {    
                                        while(factor > 0)
                                        {
                                            factor --;
                                            printf("Salio %d\n",pop(&pila1));
                                        }
                                    }
                                }
                            else
                            {
                                printf("Opcion invalida.");
                            }
						}
						else
							printf("Underflow");
						break;
				case 3: if(!vacia(&pila1))
							imp(&pila1);
						else
							printf("Pila vacía");
						break;
				//TODO EL CASE 4 NUEVO
				case 4: printf("Introduzca el nuevo tamaño de la pila: ");
						scanf("%d",&tam);
						if(redim(&pila1,tam))
						{
							printf("La pila se redimensionó con éxito!\n");
							ini(&pila1);
							printf("La pila se inicializó a vacía!\n");
						}
						else
							printf("Error. No se pudo redimensionar la pila.");
						break;
				case 9: printf("Hasta luego....!");
						break;
				default: printf("Opción inválida, vuelve a intentar...");
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
	printf("Menú Pila (Arreglo estático)\n\n");
	printf("1) Push.\n");
	printf("2) Pop.\n");
	printf("3) Imprimir.\n");
	//NUEVA
	printf("4) Cambiar de tamaño la pila.\n");
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