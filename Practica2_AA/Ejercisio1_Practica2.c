/*
//Ethan Emiliano Vaquera Aguilera - Andrés Vanegas García
//IPN - Escuela Superior de Computacion
//Profesor: LUNA BENOSO BENJAMIN
//Grupo: 3CV11
*/

/*Declaracion de las bibliotecas que se vana a utilizar para la realizacion del programa*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define TAM 1000

FILE *onion; //Aqui crea la variable apuntador para la creacion del archivo donde se iran guardando las muestras del archivo 

/*Inicializacion de las funciones que van a ser utilizadas para la resolucion del programa*/

//void generaArreglo(long *A, long n);
void imprimearrglo(long *A, long n);
void principal();
long fibonacci(long *A, long n, long cont);
long fibonacciINFINITOBv(long a, long b, long n, long cont);



/*Esta es la funcion principal la cual se encarga de hacer el llamado a la funcion 
principal, adedmas de mandar un return 0 para terminar el programa*/
long main(){

    principal();
    return 0;

}

/*Funcion principal donde se manda a llamar a las demas funciones, como la funcion que manda a generar 
el array, la que manda a generar la funcion en base a los numeros de la serie de fibonacci, ademas de 
declarar varias variables, junto el aumento de los numeros generados para esto mismo*/

void principal(){

    system("cls");

    onion=fopen("busqueda.csv","w+"); //En esta parte se crea el archivo para la funcion 

    long a[TAM];
    long tam=10;
    long r=0, m=0, n=0, cont=0;

    for(long i=0; i<20; i++){ //Aqui se usa en contador para 

        cont=0;
        r=0; 
        m=0;    //Aqui reinicializamos los valores de estas tres variables a cero para evitar corromper memoria
        n=0;

        /*Aqui se manda a llamar la generacion de numeros por medio de pseudo numeros aleatorios de c, o se utiliza la serie de fibonacci para la generacion de los numeros,
        esto solo para introducir los numeros dentro del array, y determinar el peor y el caso esperimental dentro del programa*/

        cont = fibonacci(a, tam, cont);     //Para el uso del programa se documenta una funcion o otra para poder generar los numeros entre fibonacci y los numeros generados de manera aleatoria solo de manera experimental
        /********************************************************************************************/

        imprimearrglo(a, tam);

        //cont = fibonacciINFINITOBv(0 ,1 , tam, cont);
        //printf("\n\n");

        
        
        fprintf(onion,"%d,%d\n",tam,cont); //Aqui se mandan los datos al archivo csv donde se guardan los datos de la muestra

        //printf("M: %d, N: %d\n%d",a[m],a[n], r); 
        tam+=10;
    }
    fclose(onion);
}

/*Esta es una funcion que genera numeros aleatorios para el arreglo

void generaArreglo(long *A, long n){       
    srand(time(NULL));
    long i;
    for(i=0; i<n; i++)
        A[i]=rand()%(1+100);
}*/

/*Esta es la funcion que te imprime el arreglo ya generado de manera correcta*/

void imprimearrglo(long *A, long n){
    printf("\n------------------------------------------------------------------\n");
    for(long i=0; i<n; i++){

        printf("[%d]",A[i]);

    }
    printf("\n------------------------------------------------------------------\n");
}

/*Esta es la funcion que se usa para generar los numeros de fibonacci para el array*/

long fibonacci(long *A, long n, long cont){

    long a = 1, b = 0, i=0; (cont++);

    A[0]=0;
    A[1]=1;
    (cont++);
    (cont++);

    for(i = 2; i < n; i+=2){
        
        (cont++);
        b = b + a;  (cont++);
        a = a + b;  (cont++);

        A[i]=b; (cont++);
        A[i+1]=a;   (cont++);

    }
    (cont++);

    return cont;    (cont++);

}

long fibonacciINFINITOBv(long a, long b, long n, long cont){

    long c; (cont++);

    printf("[%d] ", b); (cont++);
    if(n>1){

        c = a + b; (cont++);
        n--; (cont++);
        cont = fibonacciINFINITOBv(b, c, n, cont); (cont++);

    }

    return cont; (cont++);

}



