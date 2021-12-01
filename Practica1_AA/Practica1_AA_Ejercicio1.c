//Ethan Emiliano Vaquera Aguilera - Andrés Vanegas García
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define TAM 1000

void generarArreglo(int *arr,int tam);
void imprimeArreglo(int *A,int *B, int tam);
int solucion(int *A, int *B, int tam, int *ct);
int pow(int exponente, int *ct);


int main(int argc, char *argv[]) {
	srand(getpid());
	
	FILE*pf=fopen("busqSec.csv","at");
	
	int A[TAM], B[TAM];
	int tam=3;
	int ct;
	int i;
	int sol;
	
	for(i=0;i<=10;i++){
		ct=0;
		generarArreglo( A, tam);
		generarArreglo( B, tam);
		//imprimeArreglo( A, B, tam);
		sol = solucion( A, B, tam, &ct);
		printf("\n La solucion es : %d \n",sol);
		printf("Numero de pasos: %d \n",ct);
		fprintf(pf,"%d,%d\n",tam,ct);
		tam+=3;
		sol=0;
	}
	
	fclose(pf);
	
	return 0;
}

void generarArreglo(int *arr,int tam){
	int i;
	for(i=0;i<tam;i++){
		
		arr[i]=rand()%2;
	}
}

void imprimeArreglo(int *A,int *B, int tam){
	int i;
	for(i=0;i<tam;i++)
		printf("A[%d]=%d, ",i,A[i]);
		
	for(i=0;i<tam;i++)
		printf("B[%d]=%d, ",i,B[i]);
}

int solucion(int *A, int *B, int tam,int *ct){
	int i;(*ct)++;
	int j;(*ct)++;
	int b;(*ct)++;
	
	(*ct)+=2;//inicializacion variable i y j
	for(i=tam-1,j=0 ;i>=0 ;i--,j++){
		(*ct)++; //Condicion
		b += (A[i]&B[i])*pow(j, &(*ct));
		(*ct)+=3;//Opreciones &,* y +
		(*ct)+=2;//incremento y decremento de variables i y j
		printf("\n %d & %d",A[i],B[i]);
	}
	(*ct)++;//condicion
	(*ct)++;//return
	return b;
}

int pow(int exponente, int *ct){
	int potencia = 1; (*ct)++;
	int i; (*ct)++;
	
	(*ct)++;// inicializacion variable i
	for(i=0;i<exponente;i++){
		(*ct)++;//Condicion
		potencia = potencia * 2; (*ct)++;
		(*ct)++;//incremento i
	}
	(*ct)++;//condicion
	(*ct)++;//return
	return potencia;
}
