//Ethan Emiliano Vaquera Aguilera - Andrés Vanegas García
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11

#include <stdio.h>
#include <stdlib.h>

int Division1(int n, int div, int res, int *ct);
int Division2(int n, int div, int res, int *ct);
int Division3(int n, int div, int res, int *ct);

int main() {
	int i;
	int ct;
	int cos;
	
	FILE*pf=fopen("busqSec.csv","at");
	
	for(i=1; i<=100; i++){
		cos = Division3(i,i,0,&ct);
		fprintf(pf,"%d,%d\n",i,ct);
		ct=0;
	}
	
	fclose(pf);
	
	return 0;
}

int Division1(int n, int div, int res, int *ct){
	int q=0; (*ct)++;
	
	(*ct)++;
	while(n>=div){
		(*ct)++;
		n=n-div;(*ct)++;
		q=q+1;
	}
	
	res = n;
	return q;(*ct)++;
	
}

int Division2(int n, int div, int res, int *ct){
	int dd=div;
	int q=0;
	int r=n;
	(*ct)++;
	
	(*ct)++;
	while(dd<=n){
		(*ct)++;
		dd=2*dd;
		(*ct)++;
		while(dd<div){
			(*ct)++;
			dd=dd/2;
			q=2*q;
			
			(*ct)++;
			if(dd<=r){
				(*ct)++;
				r=r-dd;
				q=q+1;
			}
		}
	}
	
	return q;
}

int Division3(int n, int div, int res, int *ct){
	(*ct)++;
	if(div>n){
		return 0;(*ct)++;
	}else{
		return 1+Division3(n-div,div,0,&(*ct));(*ct)++;
	}
}
