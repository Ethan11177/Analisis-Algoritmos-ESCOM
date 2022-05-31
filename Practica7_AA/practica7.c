s// Ethan Emiliano Vaquera Aguilera - Andres Vanegas Garcia
// IPN - Escuela Superior de Computacion
// Profesor: LUNA BENOSO BENJAMIN
// Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define N 10

FILE *onion;


int cont;

void principal();
int incluir(int i, int tam, int mconex[][tam], int vcaminho[], int pos);
int verifica_CicloHamiltoniano(int tam, int mconex[][tam], int vcaminho[], int pos);
void imprimir(int tam, int vcaminho[]);

int main(){

    onion = fopen("busqueda.csv", "w+");

    system("cls");

    principal();

    fclose(onion);
    
    return 0;
}

void principal(){

    int tam = N;

    int vcaminho[tam];
    for( int i=0 ; i<tam ; i++)
        vcaminho[i] = -1;
    vcaminho[0] = 0;    

    int mconex[N][N] = { {0, 1, 1, 1, 0, 1, 1, 0, 1, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0, 1, 0}, {1, 0, 1, 0, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 0, 0, 1, 1, 1, 0}, {1, 0, 1, 1, 0, 0, 1, 1, 0, 0}, {1, 0, 1, 0, 0, 0, 1, 0, 1, 0}, {1, 0, 1, 0, 0, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

    for (int i = 0; i < tam; i++)
    {
        printf("Nodo %d: \n", i);
        for (int j = 0; j < tam; j++)
        {   
            printf("%d\n", mconex[i][j]);
        }
        printf("\n");
    }

    if( verifica_CicloHamiltoniano(tam, mconex, vcaminho, 1) ){
        printf("Ciclo Hamiltoniano\n");
        imprimir(tam, vcaminho);
    }
    else
        printf("No es un ciclo Hamiltoniano\n");

    fprintf(onion, "%d,%d", tam, cont);

}

int incluir(int i, int tam, int mconex[][tam], int vcaminho[], int pos){

    for(int j=0 ; j<tam ; j++){
        
        (cont++);

        if( vcaminho[j] == i ){
            (cont++);
            return 0; (cont++);  ///////////////O(n)
        }
        (cont++);
    }
    (cont++);

    if( ! mconex[ vcaminho[pos-1] ][ i ] ){
        (cont++);
        return 0;(cont++);
    }
    (cont++);

    return 1; (cont++);
}

int verifica_CicloHamiltoniano(int tam, int mconex[][tam], int vcaminho[], int pos){

    if(pos == tam){
        (cont++);
        return mconex[ vcaminho[pos-1] ][ vcaminho[0] ];  (cont++);  ///O(1)
    }
    (cont++);

    for(int i=0 ; i<tam ; i++){
        (cont++);

        if( incluir(i, tam, mconex, vcaminho, pos) ){ //O(n)
            (cont++);
            vcaminho[pos] = i;(cont++); //O(n-1)
            
            if( verifica_CicloHamiltoniano(tam, mconex, vcaminho, pos+1) ){  //T(n) = T(n-1) + O(n^2) = O(n^3) --------------- T(n+1)
                (cont++);
                return 1;(cont++);
            }
            (cont++);
            
            vcaminho[pos] = -1;(cont++);  
        }
        (cont++); 
    } //O(n-1)
    (cont++);

    return 0;(cont++);
}

/*************************************
 * 
 *      FUNCION IMPRESION
 * 
 * *************************************/
/*Eta funcion es la encargada de imprimir el uno de los posible ciclos que puede hacer el sistema para completar el grafo*/
void imprimir(int tam, int vcaminho[]){

    printf("Uno de los caminoes es:\n"); 

    for( int i=0 ; i<tam ; i++)
        printf("%d -> ", vcaminho[i]); 

    printf("%d\n", vcaminho[0]);

}