#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 120
#define MAX_B 15
#define MAX_G 32
//NUESTRO STRUCT DE ALUMNO, AQUÍ VAN LOS DATOS.
struct Alumno
{
    char nombreAlumno[MAX];
    int edad;
    char boleta[MAX_B];
};
//VARIABLES QUE OCUPAREMOS
struct Alumno grupo[MAX_G], *ptrGrupo, *ptrMismoGrupo;
//FUNCION PARA AGREGAR ALUMNOS (ALTAS)
void introducirAlumno(int i){
    while(getchar() != '\n');
    printf("Ingrese el nombre del alumno: ");
    gets(grupo[i].nombreAlumno);
    printf("Ingrese la boleta del alumno: ");
    gets(grupo[i].boleta);
    printf("Ingrese la edad del alumno: ");
    scanf("%d", &grupo[i].edad);
}
//FUNCION PARA MOSTRAR ALUMNOS ESTO ES POR INDICE
void imprimirAlumnos(int numeroAlumnos){
    printf("\n---Grupo---\n");
    for (int i = 0; i < numeroAlumnos; i++)
    {
               printf("%d.\nAlumno: %s\n", (i+1), grupo[i].nombreAlumno);
               printf("Boleta: %s\n", grupo[i].boleta);
               printf("Edad del alumno: %d\n\n", grupo[i].edad);           
    }
}
//MUESTRA ALUMNOS, PERO OCUPANDO PUNTEROS
void imprimirAlumnosPuntero(int numeroAlumnos){
    ptrGrupo = grupo;
    printf("\n---Grupo---\n---(Con apuntador)---\n");
    for (int i = 0; i < numeroAlumnos; i++)
    {
        printf("%d.\nAlumno: %s\n", (i+1), ptrGrupo->nombreAlumno);
        printf("Boleta: %s\n", ptrGrupo->boleta);
        printf("Edad: %d\n\n", ptrGrupo->edad);
        *ptrGrupo ++;
    }
}
//FUNCION PARA ELIMINAR UN ALUMNO, SE PIDE EL NUMERO DE ALUMNO QUE SE ADJUNTA EN PANTALLA, CUANDO SE INGRESA EL NUMERO, SE BORRA ESE ALUMNO. REALIZADO CON INDICES
int eliminarAlumno(int numeroAlumnos){
    int alumno;
    imprimirAlumnos(numeroAlumnos);
    printf("----------\nIngrese el numero del alumno que desea eliminar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
       printf("Numero no valido.\n");
       return 1;
    }
    else
    {
        alumno --;
        for (int i = alumno; i < numeroAlumnos; i++)
        {
                strcpy(grupo[i].nombreAlumno, grupo[i+1].nombreAlumno);
                strcpy(grupo[i].boleta, grupo[i+1].boleta);
                grupo[i].edad = grupo[i+1].edad;        
        }
        return 0;
    }
}
//TAMBIEN ELIMINA UN ALUMNO, DESPUES DE QUE SE INGRESA EL NUMERO, ESTÁ REALIZADO CON PUNTEROS. (BAJAS)
int eliminarAlumnoPuntero(int numeroAlumnos){
    int alumno;
    imprimirAlumnosPuntero(numeroAlumnos);
    ptrGrupo = grupo;
    ptrMismoGrupo = grupo;
    printf("----------\nIngrese el numero del alumno que desea eliminar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
        return 1;
    }
    else
    {    
        alumno --;
        ptrGrupo += alumno;
        ptrMismoGrupo += alumno;
        ptrMismoGrupo ++;

        for (int i = alumno; i < numeroAlumnos; i++)
        {
            strcpy(ptrGrupo->nombreAlumno, ptrMismoGrupo->nombreAlumno);
            strcpy(ptrGrupo->boleta, ptrMismoGrupo->boleta);
            ptrGrupo->edad = ptrMismoGrupo->edad;
            ptrGrupo ++;
            ptrMismoGrupo ++;
        }
        return 0;
    }
}
//MODIFICA AL ALUMNO, PIDE EL NUMERO DEL ALUMNO, QUE ES ADJUNTADO EN PANTALLA Y DESPUES DE MODIFICA, ESTA REALIZADO CON INDICE. (CAMBIOS)
void modificarAlumno(int numeroAlumnos){
    imprimirAlumnos(numeroAlumnos);
    int alumno;
    printf("----------\nIngrese el numero del alumno que desea modificar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
    }
    else
    {    
        alumno --;
        introducirAlumno(alumno);
    }
}
//MODIFICA DE LA MISMA FORMA, LA DIFERENCIA ES QUE AQUÍ SE OCUPAN PUNTEROS (CAMBIOS)
void modificarAlumnoPuntero(int numeroAlumnos){
    imprimirAlumnosPuntero(numeroAlumnos);
    int alumno;
    ptrGrupo = grupo;
    printf("----------\nIngrese el numero del alumno que desea modificar: ");
    scanf("%d", &alumno);
    if(alumno <= 0 || alumno > numeroAlumnos)
    {
        printf("Numero no valido.\n");
    }
    else
    {    
        alumno --;
        ptrGrupo += alumno;
        while(getchar() != '\n');
        printf("Nombre del alumno: ", (alumno + 1));
        gets(ptrGrupo->nombreAlumno);
        printf("Boleta: ");
        gets(ptrGrupo->boleta);
        printf("Edad: ");
        scanf("%d", &ptrGrupo->edad);
    }
}
//MENU SIMPLE PARA DESPLEGAR LAS OPCIONES DISPONIBLES EN EL PROGRAMA
int menu(){
    int opcion, numeroAlumnos = 0;
    while (1)
    {
        printf("Elija una accion a realizar.\n\t1. Introducir alumno.\n\t2. Imprimir alumnos (Indice).\n\t3. Imprimir alumnos (Apuntador).\n\t4. Eliminar un alumno (Indice).\n\t5. Eliminar un alumno (Apuntador).\n\t6. Modificar datos del alumno (Indice).\n\t7. Modificar datos del alumno (Apuntador).\n\t8. Salir.\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
                introducirAlumno(numeroAlumnos);
                //printf("%d ALUMNOS.", numeroAlumnos);
                numeroAlumnos++;
            break;
        case 2:
            imprimirAlumnos(numeroAlumnos);
            break;
        case 3:
            imprimirAlumnosPuntero(numeroAlumnos);
            break;
        case 4:
        printf("ALUMNOS: %d", numeroAlumnos);
            //eliminarAlumno(numeroAlumnos);
            if(eliminarAlumno(numeroAlumnos) == 0)
            {
                numeroAlumnos --;
                printf("\nAlumno eliminado.\n");

            }
            break;
        case 5:
        printf("ALUMNOS: %d", numeroAlumnos);
            //eliminarAlumnoPuntero(numeroAlumnos);
            if(eliminarAlumnoPuntero(numeroAlumnos) == 0)
            {
                numeroAlumnos --;
                printf("\nAlumno eliminado.\n");
            }
            break;
        case 6:
            modificarAlumno(numeroAlumnos);
            break;
        case 7:
            modificarAlumnoPuntero(numeroAlumnos);
            break;
        case 8:
            printf("Adios");
            return 0;
            break;
        default:
            printf("Opcion no valida!!\n");
            break;
        }
    }
}
//FUNCION MAIN, LLAMA A MENU
int main(int argc, char *argv[]){
    menu();
    return 0;
}