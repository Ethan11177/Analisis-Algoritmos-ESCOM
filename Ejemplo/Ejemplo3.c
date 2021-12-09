#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define TAM 4000

FILE *onion;

void pri();
void llenar(int *t, int n);
void imprimir(int *t, int n);
int divide(int *t, int min, int med, int max, int sum);

int cont;

int main(){

    onion = fopen("ejemplo3.csv", "w+");

    system("cls");

    pri();

    fclose(onion);

    return 0;

}

void pri(){

    srand(time(NULL));

    int n = rand()%(199)+1;
    int t[TAM] = {0};
    int why = 10;

    while(why != 0){

        cont++;

        llenar(t, n);
        
        imprimir(t, n);
        printf("--------------\n");

        int a = divide(t, 0, n/2, n, t[0]);

        printf("\n***************%d*************\n", a);

        fprintf(onion, "%d,%d\n", cont, n);

        n += 5;

        why--;

    }
}

int divide(int *t, int min, int med, int max, int sum){

    if(min<=max){
        (cont++);
        
        return sum;(cont++);

    }
    else{
        (cont++);

        if(t[max] < t[max - 1]){
            (cont++);

            sum = t[max] + 1;(cont++); 

        }
        (cont++);
        if(t[max] > t[max - 1]){
            (cont++);

            sum = t[max] - 1;(cont++); 

        }
        else{
            (cont++);

            sum = sum;(cont++);

        }        
        (cont++);

        return divide(t, 0, max/2, med, sum) + divide(t, med+1, (med+max)/2, max, sum);(cont++);

    }
    (cont++);

}

void imprimir(int *t, int n){

    for (int i = 0; i < n; i++){
        
        printf("%d\n", t[i]);

    }
    

}

void llenar(int *t, int n){

    for (int i = 0; i < n; i++){

        t[i] = rand()%50;
        
    }

}