#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#define TAM 100000

FILE *onion; //Aqui crea la variable apuntador para la creacion del archivo donde se iran guardando las muestras del archivo 

void principal();
void generaArreglo(int *A, int n);
void imprimearrglo(int *A, int n);
int perfecto(int *A, int tam, int *cont);

int main(){

    system("cls");

    principal();

    return 0;

}

void principal(){

    onion=fopen("busqueda.csv","w+"); //En esta parte se crea el archivo para la funcion 

    int a[TAM];
    int tam=10;
    int cont =0;
    int num = 0;
    int p = 0;


    //for(int i=0; i<20; i++){ 

        cont=0;

        generaArreglo(a, TAM); 
        //imprimearrglo(a, TAM); //Esta es una funcion que se usa para imprimir el arreglo
        p = perfecto(a, TAM, &cont);

        fprintf(onion,"%d,%d\n",tam,cont); //Aqui se mandan los datos al archivo csv donde se guardan los datos de la muestra

        //tam+=10;
    //}

    fclose(onion);

}

/*Esta es una funcion que genera numeros aleatorios para el arreglo*/

void generaArreglo(int *A, int n){       
    srand(time(NULL));
    int i;
    for(i=0; i<n; i++)
        A[i]=i+1;
}

void imprimearrglo(int *A, int n){
    printf("\n------------------------------------------------------------------\n");
    for(int i=0; i<n; i++){

        printf("[%d]",A[i]);

    }
    printf("\n------------------------------------------------------------------\n");
}

int perfecto(int *A, int tam, int *cont){

    int i=0, j=0, n=0, num=0;
    int Div[TAM];

    for(j=1; j<1000000000000; j++){

        for(i=1; i<j; i++){
            
            if(j%i == 0){

                n = n + i;
                num++;
               
            } 
        }

        if(n==j){

            Div[j]=n;
            printf("P: %d Numero:%d\n", num, Div[j]);
                
        }   

        n=0;   
        num=0;

    }

    return num;

}

