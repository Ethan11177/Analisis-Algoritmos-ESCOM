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
int contg =0;

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

    imprimir2(A, n);

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

    fprintf(onion, "%d,%d\n", n, contg);

  n = n/2; (contg++);
  int j = 0, i = 0; (contg++);
  int aux1[n][n]; (contg++);
  int aux2[n][n];(contg++);
  int aux3[n][n];(contg++);
  int aux4[n][n];(contg++);
  int auxt[16][16];(contg++);

  if(n == 1){   //--------------------------------------------------------------------------------------------------------Aqui esta el if----------------------------------------------------------------
    (contg++);
    for (i = 0; i < n; i++)
    {(contg++);
      for (j = 0; j < n; j++)
      {(contg++);
        aux1[i][j] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    auxt[0][0] = aux1[0][0];(contg++);
    auxt[0][1] = aux1[0][1];(contg++);
    auxt[1][0] = aux1[1][0];(contg++);
    auxt[1][1] = aux1[1][1];(contg++);

    aux1[0][0] = auxt[0][1];(contg++);
    aux1[0][1] = auxt[1][1];(contg++);
    aux1[1][0] = auxt[0][0];(contg++);
    aux1[1][1] = auxt[1][0];(contg++);

    i = 0;(contg++);
    j = 0;(contg++);

    for (int i = n; i < n+n; i++)
    {(contg++);
      for (int j = 0; j < n; j++)
      {(contg++);
        aux2[i-n][j] = A[i][j];
      }(contg++);
    }(contg++);
    
    auxt[0][0] = aux2[0][0];(contg++);
    auxt[0][1] = aux2[0][1];(contg++);
    auxt[1][0] = aux2[1][0];(contg++);
    auxt[1][1] = aux2[1][1];(contg++);

    aux2[0][0] = auxt[0][1];(contg++);
    aux2[0][1] = auxt[1][1];(contg++);
    aux2[1][0] = auxt[0][0];(contg++);
    aux2[1][1] = auxt[1][0];(contg++);

    i = 0;(contg++);
    j = 0;(contg++);

    for (int i = 0; i < n; i++)
    {(contg++);
      for (int j = n; j < n+n; j++)
      {(contg++);
        aux3[i][j-n] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    auxt[0][0] = aux3[0][0];(contg++);
    auxt[0][1] = aux3[0][1];(contg++);
    auxt[1][0] = aux3[1][0];(contg++);
    auxt[1][1] = aux3[1][1];(contg++);

    aux3[0][0] = auxt[0][1];(contg++);
    aux3[0][1] = auxt[1][1];(contg++);
    aux3[1][0] = auxt[0][0];(contg++);
    aux3[1][1] = auxt[1][0];(contg++);

    i = 0;(contg++);
    j = 0;(contg++);
   
    for (int i = n; i < n+n; i++)
    {(contg++);
      for (int j = n; j < n+n; j++)
      {(contg++);
        aux4[i-n][j-n] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    auxt[0][0] = aux4[0][0];(contg++);
    auxt[0][1] = aux4[0][1];(contg++);
    auxt[1][0] = aux4[1][0];(contg++);
    auxt[1][1] = aux4[1][1];(contg++);

    aux4[0][0] = auxt[0][1];(contg++);
    aux4[0][1] = auxt[1][1];(contg++);
    aux4[1][0] = auxt[0][0];(contg++);
    aux4[1][1] = auxt[1][0];(contg++);

    A[0][0] = aux2[0][0];(contg++);
    A[0][1] = aux2[0][1];(contg++);
    A[1][0] = aux2[1][0];(contg++);
    A[1][1] = aux2[1][1];(contg++);

    A[0][2] = aux4[0][0];(contg++);
    A[0][3] = aux4[0][1];(contg++);
    A[1][2] = aux4[1][0];(contg++);
    A[1][3] = aux4[1][1];(contg++);

    A[2][0] = aux1[0][0];(contg++);
    A[2][1] = aux1[0][1];(contg++);
    A[3][0] = aux1[1][0];(contg++);
    A[3][1] = aux1[1][1];(contg++);

    A[2][2] = aux3[0][0];(contg++);
    A[2][3] = aux3[0][1];(contg++);
    A[3][2] = aux3[1][0];(contg++);
    A[3][3] = aux3[1][1]; (contg++);

    /*printf("\n");
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        printf("%d", A[i][j]);
      }
      printf("\n");
    }

    printf("\nEsto es el final************************************************\n");*/
    (contg++);
    return 0;
  
  }
  else{ //-------------------------------------------------------------------------------------------------------------Aqui esta el ELSE---------------------------------------------------------------------------
     
    i = j = 0;(contg++);

    for (i = 0; i < n; i++) //*****************************************AX1*************************************************
    {(contg++);
      for (j = 0; j < n; j++)
      {(contg++);
        aux1[i][j] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    i = 0;(contg++);
    j = 0;(contg++);

    for (i = n; i < n+n; i++) //*****************************************AX2*************************************************
    {(contg++);
      for (j = 0; j < n; j++)
      {(contg++);
        aux2[i-n][j] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    i = 0;(contg++);
    j = 0;(contg++);

    for (i = 0; i < n; i++) //*****************************************AX3*************************************************
    {(contg++);
      for (j = n; j < n+n; j++)
      {(contg++);
        aux3[i][j-n] = A[i][j];(contg++);
      }(contg++);
    }(contg++);
   
    i = 0;(contg++);
    j = 0;(contg++);

    for (i = n; i < n+n; i++) //*****************************************AX4*************************************************
    {(contg++);
      for (j = n; j < n+n; j++)
      {(contg++);
        aux4[i-n][j-n] = A[i][j];(contg++);
      }(contg++);
    }(contg++);

    //*****************************************************************************************************************************************************Fina de la division///////////////////////////////////
    
    /*printf("Prueba-------------------------------------------------------------------------------------------------------\n\n");
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++) //--------------------------------------------------------------------Prueeeeeeeeeeeeeeeeeeeeebaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
      {
        printf("%d", aux3[i][j]);
      }
      printf("\n");
    }
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");*/
    
    //----------------------------------------------------------------------------------------------------------------------------------/
    rotar2(aux1, n);(contg++);
    rotar2(aux2, n);(contg++);
    rotar2(aux3, n);(contg++);
    rotar2(aux4, n);(contg++);
    //----------------------------------------------------------------------------------------------------------------------------------/

    /*printf("Prueba de la UNION----------------------------------------------------------------------------------------\n\n");
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++) //--------------------------------------------------------------------Prueeeeeeeeeeeeeeeeeeeeeba
      {
        printf("%d\n", aux3[i][j]);
      }
      printf("\n");
    }
    printf("\n----------------------------------------------------------------------------------------------------------------\n\n");*/

    for (i = 0; i < n; i++)
    {(contg++);
      for (j = 0; j < n; j++) //--------------------------------------------------------------------Añadido aux4-------------------
      {(contg++);
        A[i][j] = aux4[i][j];(contg++);
      }(contg++);
    }(contg++);

    for (i = n; i < n+n; i++)
    {(contg++);
      for (j = 0; j < n; j++) //--------------------------------------------------------------------Añadido aux2-------------------
      {(contg++);
        A[i][j] = aux2[i-n][j];(contg++);
      }(contg++);
    }(contg++);

    for (i = 0; i < n; i++)
    {(contg++);
      for (j = n; j < n+n; j++) //--------------------------------------------------------------------Añadido aux1-------------------
      {(contg++);
        A[i][j] = aux1[i][j-n];(contg++);
      }(contg++);
    }(contg++);

    for (i = n; i < n+n; i++)
    {(contg++);
      for (j = n; j < n+n; j++) //--------------------------------------------------------------------Añadido aux3-------------------
      {(contg++);
        A[i][j] = aux3[i-n][j-n];(contg++);
      }(contg++);
    }(contg++);
  }
  (contg++);
  return 0;

}
