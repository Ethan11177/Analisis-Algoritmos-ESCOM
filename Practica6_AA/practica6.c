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
int lcs(int i, int j);
int maxt(int a, int b);

int main(){

    system("cls");

    principal();

    return 0;
}

void principal(){

    int cont1 = 0, cont2 = 0;
    char archivo[] = "archivo1.txt";

    cont1 = leerarchivo(archivo, 0);
    printf("\t\t\tCadena 1:\n\n");
    imprimir(0, cont1);
    printf("\n\n\n\n\n\n\n\n");

    strcpy(archivo, "archivo2.txt");

    cont2 = leerarchivo(archivo, 1);
    printf("\t\t\tCadena 2:\n\n");
    imprimir(1, cont2);

    int i = lcs(cont1, cont2);

    printf("\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
    system("pause");
    system("cls");

    printf("La LCS es: %d\n",i);
    int tot = ((i * 100)/(cont1 + cont2))*2;

    printf("Porcentaje Igualdad: %d", tot);

}

int lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    if (A[i - 1] == B[j - 1])
        return 1 + lcs(i - 1, j - 1);
    else
        return maxt(lcs(i, j - 1), lcs(i - 1, j));
}

int maxt(int a, int b)
{
    if (a > b)
        return a;

    else
        return b;
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