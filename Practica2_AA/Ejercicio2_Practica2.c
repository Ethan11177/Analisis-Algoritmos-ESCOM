//Ethan Emiliano Vaquera Aguilera - Andrés Vanegas García
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>

int Perfectos(int n, int *ct);
void MostrarPerfectos(int n,int *ct);

int main() {
	int i,j,n;
	int ct;
	FILE*pf=fopen("perfectos.csv","at");
	
	
	
	for(i=0;i<=4;i++){
		ct=0;
		
		MostrarPerfectos(i,&ct);
		
		fprintf(pf,"%d,%d\n",i,ct);
	}
	
	fclose(pf);
	
	return 0;
}

int Perfectos(int n,int *ct){
	int factor ,SumFactores = 0; 
	(*ct)++;
	
	(*ct)++;
	for(factor=n/2 ; factor>=1 ; factor--){
		(*ct)++;
		
		if(n%factor == 0){
			
			SumFactores = SumFactores + factor;(*ct)++;
		}
		(*ct)++;
		
		(*ct)++;
	}
	(*ct)++;
	
	(*ct)++;
	if(SumFactores == n){
		(*ct)++;
		return 1;
	}

	(*ct)++;
	return 0;
}

void MostrarPerfectos(int n,int *ct){
	int i,j; (*ct)++;
	
	(*ct)++;
	(*ct)++;
	for(i=1,j=n;j>=1;i++){
		(*ct)++;
		
		if(Perfectos(i, &(*ct))){
			j--;
			printf(" Perfecto %d \n",i);
			(*ct)++;	
		}
		(*ct)++;
		
		(*ct)++;
	}
	(*ct)++;
}
