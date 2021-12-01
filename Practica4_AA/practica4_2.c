//Ethan Emiliano Vaquera Aguilera - Andr�s Vanegas Garc�a
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define widht 256

FILE *onion;
char mat[16][16];
int contg = 0;

void principal();
int llenar2(int A[][16]);
void imprimir2(int A[][16], int n);
int rotar2(int A[][16], int n);

int main(){

    system("cls");
    principal();

    return 0;    
}

void principal(){

    int n = 0;
    int A[16][16];

    n = llenar2(A);
    imprimir2(A, n);
    printf("\n");

    onion = fopen("prueba.csv", "at");

    rotar2(A, n);

    fclose(onion);

}



void imprimir2(int A[][16], int n){

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d", A[i][j]);     
    }
    printf("\n");
  }             
}

int llenar2(int A[][16]){

    int cont = 0, cont2 = 0, j = 0;
    char leer[16];
    onion = fopen("arte.txt", "rb");

    while (feof(onion)==0)
    {
        fscanf(onion, "%s", leer);

        cont2 = sizeof(leer);

        for(j = 0; j < sizeof(leer); j++){
          
          A[cont][j] = leer[j] - '0';

        }
        cont++;
        
    }
    
    printf("Filas: %d, Columnas: %d\n", cont, cont2);

    fclose(onion);
    free(onion);

    return cont;

}

int rotar2(int A[][16], int n){

    int B[16][16]; (contg++);

    for (int i = 0; i < n; i++) 
    {(contg++);
        for (int j = 0; j < n; j++)
        {(contg++);
            B[i][j] = A[j][i]; (contg++);
        }(contg++);
    }(contg++);

    for (int i = 0; i < n; i++)
    {(contg++);
        for (int j = 0; j < n; j++)
        {(contg++);
            printf("%d", B[i][j]);(contg++);
        }(contg++);
        printf("\n");(contg++);
    }(contg++);
  
  (contg++);
  return 0;

}
