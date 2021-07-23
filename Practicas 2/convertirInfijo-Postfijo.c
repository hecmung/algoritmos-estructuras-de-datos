#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXIMO 300
struct stack {
	int t;
	char a[MAXIMO];
};
void conversionPost (char *infijo,char *postfijo);
int operando (char c)
{
	return ( c != '+' &&
		 c != '-' &&
		 c != '*' &&
		 c != '/' &&
		 c != '^' &&
		 c != ')' &&
		 c != '('    );
}
static int m[6][7] = {
	{ 1,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,1,0,1 },
	{ 0,0,0,0,0,0,0 }
};
int prioridad (char op1,char op2)
{
	int i,j;
	switch (op1) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '/' :  i = 3; break;
		case '^' :  i = 4; break;
		case '(' :  i = 5; break;
	}
	switch (op2) {
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '/' :  j = 3; break;
		case '^' :  j = 4; break;
		case '(' :  j = 5; break;
		case ')' :  j = 6; break;
	}	
	return (m [i][j]);
}
char tope (struct stack p)
{
	return ( p.a [p.t -1] );
}
void init_pila (struct stack *p)
{
	p->t = 0;
}
int pila_vacia (struct stack *p)
{
	return (!p->t);
}
void ins_pila (struct stack *p,char s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}
void retira_pila (struct stack *p,char *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}
void conversionPost (char *infijo,char *postfijo)
{
	struct stack pila;
	int i,j;
	char elemento;
	int operando (char c);
	int prioridad (char op1,char op2);
	char tope (struct stack p);
	void init_pila (struct stack *p);
	int pila_vacia (struct stack *p);
	void ins_pila (struct stack *p,char s);
	void retira_pila (struct stack *p,char *s);
	i=0;
	j=-1;
	init_pila (&pila);
	while (infijo [i] != '#') {
	   if (operando (infijo [i]) )
		   postfijo [++j] = infijo [i++];
	   else {
		     while (!pila_vacia (&pila)  &&
			 prioridad (tope (pila),infijo [i] ) )  {
			     retira_pila (&pila,&elemento);
			     postfijo [++j] = elemento;
		      }
		      if (infijo [i] == ')')
			   retira_pila (&pila,&elemento);
		      else ins_pila (&pila,infijo [i]);
		      i++;
		}
	}
	while (!pila_vacia (&pila) ) {
		retira_pila (&pila,&elemento);
		postfijo [++j] = elemento;
	}
	postfijo [++j] = '\0';
}
void main ()
{
	char postfijo [101],infijo[101];
	int i;
		printf ("Ingresa la expresion infijo:\n");
		gets (infijo);
		i = strlen (infijo);
		infijo [i] = '#';
		infijo [i+1] = '\0';
		conversionPost (infijo,postfijo);
		printf ("\nExpresion infijo: %s\nExpresion postfijo:  %s  ",infijo,postfijo);
}