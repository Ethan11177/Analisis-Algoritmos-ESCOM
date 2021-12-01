#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define TAM 40000

FILE *onion;
FILE *shrek;

char A[TAM];
char B[TAM];

void principal();
int leerarchivo(char *a, int ban);
void imprimir(int ban, int cont);

int main(){

    system("cls");

    principal();

    return 0;
}

void principal(){

    int cont = 0;
    char archivo[] = "archivo1.txt";

    cont = leerarchivo(archivo, 0);
    imprimir(0, cont);
    printf("\n/////////////////////////////////////////////////////////////\n");

    strcpy(archivo, "archivo2.txt");

    cont = leerarchivo(archivo, 1);
    imprimir(1, cont);

}

void imprimir(int ban, int cont){

    if (ban == 0)
        for (int i = 0; i < cont; i++)
        {
            printf("%c", A[i]);
        }
    else
        for (int i = 0; i < cont; i++)
        {
            printf("%c", B[i]);
        }
}

int leerarchivo(char *a, int ban){

    int j = 0;
    char aux[TAM];

    shrek = fopen(a, "rb");

    while(feof(shrek)==0){
        
        fscanf(shrek, "%s", aux);
        
        if(ban == 0)
            for (int i = 0; i < strlen(aux); i++){

                A[j] = aux[i];
                j++;
            }
        else 
            for (int i = 0; i < strlen(aux); i++){

                B[j] = aux[i];
                j++;
            }

    }

    fclose(shrek);

    return j;

}