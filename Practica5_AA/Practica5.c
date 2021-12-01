//Ethan Emiliano Vaquera Aguilera - Andres Vanegas Garcia
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM 1000 //Numero total para la acamulacion de numero en el array de los dias que se desea

void llenar(int *C, int n);  //Funcion llamada para la generacion de los dias que debe de usar el sistema para el calculo grady
void imprimirArreglo(int *S,int tam);
void solucion(int *C, int r, int tam, int *ct);

int main(){
	srand(getpid());
	int r = 30;
	int ct;
	int C[TAM];
	int tam = 12;
	FILE*pf=fopen("busqSec.csv","at");
	for(tam=10;tam<=100;tam=tam+10){
		printf("\n.:: Ejercicio con C de Tamaño = %d ::. \n",tam);
		llenar(C,tam);
		solucion(C, r, tam, &ct);
		fprintf(pf,"%d,%d\n",tam,ct);
		ct=0;
	}
	fclose(pf);
    return 0;
}

void solucion(int *C, int r, int tam, int *ct){
    int i=0, tamSol=0;
    int f;
    int S[TAM]; (*ct)++;
    
    S[0] = 0;
    f= 30; (*ct)++;
    
    (*ct)++;
    while(i<tam){
    	(*ct)++;
    	(*ct)++;
        if(C[i]>f){
        	(*ct)++;
        	tamSol++; 
			S[tamSol]=C[i-1]; 
		    f=C[i-1]+r; 
	    }
	    i++;
    }
    
    tamSol++;
	S[tamSol]=C[i-1]; (*ct)++;
    
    printf("C =");
	imprimirArreglo(C,tam);(*ct)++;
	printf("S =");
	imprimirArreglo(S,tamSol+1);(*ct)++;
    	
}

void imprimirArreglo(int *S, int tam){
	int i;
	printf("{");
	    for(i=0;i<tam;i++){
		    printf("%d, ",S[i]);
	    }
	printf("} \n");
}

void llenar(int *C, int n){
    int c = 0; //Declaracion variable acumualable para la sumatoria de los dias que ingresan al arreglo de dias
    int i, dia;
    
    for (i = 1; i < n; i++) //Inicio del for que se ejecutara N -> TAM cantidad de veces para llenar el arreglo
    {
        C[i] = dia;
        dia += rand() % 30+1; //Llenado de variables para el determinar los dias que se sumaran al arreglo
    }
}
