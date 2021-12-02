// Ethan Emiliano Vaquera Aguilera - Andres Vanegas Garcia
// IPN - Escuela Superior de Computacion
// Profesor: LUNA BENOSO BENJAMIN
// Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define TAM 40000 /*Declaracion  de tamaño numerico TAM en el caso de que el sistema requiera de \
una gran cantidad de espacio de almacenamiento para los caracteres*/

/**********************************************************************/

FILE *onion;
FILE *shrek;

/*Inicializacion de variables de archivos para el manejo de los archivos que se desean comparar
NOTA: se usan variables con nombres muy particulares */

/********************************************************************/

char A[TAM];
char B[TAM];

/*Declaracion de las cadenas de caracteres, se declaran de manera global para que esta pueda ser
mas sencilla de manejar, ademas de que el lenguaje solo permite cadenas de este tamaño de manera global*/

/**************************
 *
 * DECLARACION FUNCIONES
 *
 * *************************/
void principal();
int leerarchivo(char *a, int ban);
void imprimir(int ban, int cont);
int lcs(int i, int j);
int maxt(int a, int b);
/*Declaracion de las funciones para la implementacion del algoritmo LCS ademas de la lectura de datos,
la impresion de lo que guarda cada arreglo y la funcion principal*/

/************************
 *
 * FUNCION MAIN PRINCIPAL
 *
 * ***********************/
int main()
{

    system("cls");

    principal(); // Llamada a la funcion principal donde vamos a trabajar todas las funciones antes declaradas

    return 0;
}
/********************************/

/********************************
 *
 *      FUNCION PRINCIPAL
 *
 * *****************************/
void principal()
{

    int cont1 = 0, cont2 = 0; // Declaracion de contadores para saber el total de caracteres dentro de los archivos

    char archivo[] = "archivo1.txt"; /*Declaracion de variable auxiliar archivo para saber el archivo que debemos
    de mandar a llamar en la funcion correspindiente*/

    cont1 = leerarchivo(archivo, 0); // Llama de funcion leer archivo que recaba todos los datos del archivo1
    printf("\t\t\tCadena 1:\n\n");
    imprimir(0, cont1); // Llamada a la funcion imprimir donde le mandamos el arreglo que deseamos imprimir
    printf("\n\n\n\n\n\n\n\n");

    /*NOTA: LA IMPRESION DEL CONTENIDO DEL ARREGLO SOLO ES MUESTRAL YA QUE NO TIENE NINGUN USO AL MOMENTO DE HACER LAS OPERACIONES*/

    strcpy(archivo, "archivo2.txt"); // Llamada a la funcion strcpy que sirve para sobre escribir los datos que estan en la variable archivo

    cont2 = leerarchivo(archivo, 1); // Llama de funcion leer archivo que recaba todos los datos del archivo2
    printf("\t\t\tCadena 2:\n\n");
    imprimir(1, cont2); // Llamada a la funcion imprimir donde le mandamos el arreglo que deseamos imprimir

    int i = lcs(cont1, cont2); /*Llamada a la funcion LCS para obtener el maximo valor de la cadena mas larga de los
    archivos en comun, de igual manera esta se almacena en una variable i para saber el maximo valor de esta*/

    printf("\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
    system("pause");
    system("cls");

    printf("La LCS es: %d\n", i);                // Impresion del valor maximo de la subcadena
    int tot = ((i * 100) / (cont1 + cont2)) * 2; // Calculo del porcentaje concurrencia en base al 100 porciento de los archivos

    printf("Porcentaje Igualdad: %d", tot); // Imprecion del porcentaje de concurrencia
}
/******************************************/

/******************************************
 *
 *   FUNCION DE LA SUBSECUANCIA COMUN MAS LARGA
 *
 * ****************************************/
int lcs(int i, int j)
{
    if (i == 0 || j == 0) // Comparativa encargada de romper la recursividad en caso de que el tamaño de alguna de las cadenas se acabe
        return 0;
    if (A[i - 1] == B[j - 1])         // Comparativa que se usa para saber si la subcadena en el moemento es parecida, de ser asi esta se manda una vez mas y se le suma uno al total de cncurrencias
        return 1 + lcs(i - 1, j - 1); // Llamada a la LCS recursivo para continuar en la busqueda de subcadenas
    else
        return maxt(lcs(i, j - 1), lcs(i - 1, j)); // Fin del proceso donde se determina la cantidad maxima de subcadenas entre las dos cadenas
}
/**********************************************/

/***********************************************
 *
 *      MAXIMA SUBSECUANCIA DE LAS DOS
 *
 * ********************************************/
int maxt(int a, int b)
{
    if (a > b) // Comparativa para encontrar cual de los dos numeros de la concurrencia es mayor y retornarlo
        return a;

    else
        return b;
}
/***********************************************/

/*************************************************
 *
 *      FUNCION DE IMPRESION CADENAS
 *
 * *********************************************/
void imprimir(int ban, int cont)
{

    // Comparacion para determinar el arreglo cadena que debemos de imprimir atravez de la bandera que mandamos en la llamada de la funcion pricipal
    if (ban == 0)
        for (int i = 0; i < cont; i++) // Ciclo for para imprimir todos los elementos dentro de la cadena
        {
            printf("%c", A[i]); // Impresion de cada caracter que esta dentro de la cadena
        }
    else
        for (int i = 0; i < cont; i++)
        {
            printf("%c", B[i]);
        }
}
/***************************************************/

/****************************************************
 *
 *   FUNCION LECTURA DE LOS ELEMENTOS DEL ARCHIVOX.TXT
 *
 * **************************************************/
int leerarchivo(char *a, int ban)
{

    /*********************/
    int j = 0;
    char aux[TAM];
    /*Declaracion de variables aux para almacenar los datos del archivo y despues ingresarlos a la cadena, y j para
    contar el total de datos infresado en cada cadena*/

    shrek = fopen(a, "rb"); // Apertura del archivox.txt para sacar los datos del archivo al que este apuntando

    while (feof(shrek) == 0)
    {

        fscanf(shrek, "%s", aux);

        if (ban == 0)
            for (int i = 0; i < strlen(aux); i++)
            {

                A[j] = aux[i];
                j++;
            }
        else
            for (int i = 0; i < strlen(aux); i++)
            {

                B[j] = aux[i];
                j++;
            }
    }

    fclose(shrek);

    return j;
}
/******************************************************/