#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define TAM 100

FILE *onion;

struct horario
{
    int inicio;
    int fin;
};

struct horario2
{
    int inicio;
    int fin;
};


struct horario C[TAM];
struct horario2 S[TAM];

void principal();
void generar(int n);
void imprimir(int n, int b);
void selactividades(int n);
void sort(int b, int e);
void mergesort(int b, int m, int e);

int cont = 0;

int main(){

    srand(time(NULL));

    system("cls");

    onion = fopen("ejemplo2.csv", "w+");

    principal();

    fclose(onion);

    return 0;

}

void principal(){

    int n = 10;
    int tam = 5;

    while(n){

        cont = 0;

        generar(tam);

        imprimir(tam, 0);
        
        selactividades(tam);

        imprimir(tam, 0);

        n--;
        tam += 5;

        printf("----------------------------------------------------------------------\n");

        fprintf(onion,"%d,%d\n",tam,cont);

    }

}

void selactividades(int n){

    sort(0, n); (cont++);

    S[0].inicio = C[0].inicio;(cont++);
    S[0].fin = C[0].fin;(cont++);

    int i = 0, prev = 0;(cont++);

    printf("\n*********************************************\nHoras factibles\n");(cont++);

    while(i < n){
        (cont++);

        int x = C[i+1].fin;(cont++);
        int y = C[i+1]. inicio;(cont++);

        if(y >= S[prev].fin){
            (cont++);

            printf("Inicio: %d Fin: %d\n", S[prev].inicio, S[prev].fin);(cont++);
            S[prev+1].inicio = y;(cont++);
            S[prev+1].fin = x;(cont++);
            prev++;(cont++);
            
        }
        (cont++);

        i++;(cont++);
    }
    (cont++);

    printf("**************************************************\n");(cont++);

}

void sort(int b, int e){

    if(b < e){
        int m = (b+e)/2;
        sort(b, m);
        sort(m+1, e);
        mergesort(b, m, e);
    }
}

void mergesort(int b, int m, int e){      

        int l = m-b+1, r = e-m, i;
        int L1[l+1], L2[l+1], R1[r+1], R2[r+1];

        for(i=0; i< l; i++)
        {
            L1[i] = C[b+i].fin;
            L2[i] = C[b+i].inicio;
        }

        for (i=0; i< r; i++)
        {
            R1[i] = C[m+i+1].fin;
            R2[i] = C[m+i+1].inicio;
        }
        L1[l] = 32767;
        R1[r] = 32767;
        l = 0;
        r = 0;

        for(i=0; i< e-b+1; i++)
       {

            if(L1[l] < R1[r]){
                C[b+i].fin = L1[l];
                C[b+i].inicio = L2[l];
                l ++;
            }
            else{
                C[b+i].fin = R1[r];
                C[b+i].inicio = R2[r];
                r ++;
            }

        }
}

void generar(int n){

    for (int i = 0; i < n; i++)
    {
        C[i].inicio = rand()%12;
        C[i].fin = C[i].inicio + 2;
    }
}

void imprimir(int n, int b){

    for (int i = 0; i < n; i++)
    {
        printf("Inicio: %d Fin: %d\n", C[i].inicio, C[i].fin);  
    }

}