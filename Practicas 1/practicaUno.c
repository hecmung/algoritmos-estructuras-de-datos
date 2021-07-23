#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Como manejar archivos en C es muy tedioso se tiene que descomponer el archivo de entrada
// a cadena de caracteres individuales e ir agregando una por una a un archivo de salida.
void modificarSaltoDeLinea(char *ptrRenglon){
    //Se agrega el -1 para tomar el salto de linea y no el caracter de terminacion \0
    char *ptrUltimo = &ptrRenglon[strlen(ptrRenglon) - 1];
    //Comparamos caracteres 
    if(*ptrUltimo == '\n'){        
        *ptrUltimo = '\0';
    }
}
void invertirCadena(char *ptrRenglon){
    int longitud = strlen(ptrRenglon), i;
    for(i = 0; i < strlen(ptrRenglon)/2; i++){
        char auxiliar = ptrRenglon[i];
        ptrRenglon[i] = ptrRenglon[longitud - i - 1];
        ptrRenglon[longitud - i - 1] = auxiliar;
    }
}
void archivoInvertido(FILE *fpEntrada, FILE *fpSalida){
    char *ptrRenglon = NULL;
    size_t longitudBits= 0;

    while ((getline(&ptrRenglon, &longitudBits, fpEntrada)) != -1)
    {
        modificarSaltoDeLinea(ptrRenglon);
        invertirCadena(ptrRenglon);

        fwrite(ptrRenglon, sizeof(char), strlen(ptrRenglon), fpSalida);
        fwrite("\n", sizeof(char), strlen("\n"), fpSalida);
    }
    free(ptrRenglon);
    printf("Termino(:");
}
int archivos(){
    FILE *fpEntrada, *fpSalida;
    char *ptrArchivoEntrada, *ptrArchivoSalida;

    ptrArchivoEntrada = "folios_entrada.txt";
    ptrArchivoSalida = "folios_salida.txt";

    fpEntrada = fopen(ptrArchivoEntrada, "r");
    if (fpEntrada == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return 1;
    }
    fpSalida = fopen(ptrArchivoSalida, "w");
    if(fpSalida == NULL){
        printf("No se pudo abrir el archivo.");
        return 1;
    }    

    archivoInvertido(fpEntrada, fpSalida);

    fclose(fpEntrada);
    fclose(fpSalida);
}
int main(int argc, char *argv[]){
    archivos();
    return 0;
}