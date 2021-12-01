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
int cont; //Aqui se crea la variable del tipo contador para daterminar las muestras del archivo 

/*Inicializacion de las funciones que van a ser utilizadas para la resolucion del programa*/

int euclides(int m, int n);
void generaArreglo(int *A, int n);
void imprimearrglo(int *A, int n);
void principal();
void fibonacci(int *A, int n);


/*Esta es la funcion principal la cual se encarga de hacer el llamado a la funcion 
principal, adedmas de mandar un return 0 para terminar el programa*/
int main(){

    principal();
    return 0;

}

/*Funcion principal donde se manda a llamar a las demas funciones, como la funcion que manda a generar 
el array, la que manda a generar la funcion en base a los numeros de la serie de fibonacci, ademas de 
declarar varias variables, junto el aumento de los numeros generados para esto mismo*/

void principal(){

    system("cls");

    onion=fopen("busqueda.csv","w+"); //En esta parte se crea el archivo para la funcion 

    int a[TAM];
    int tam=10;
    int r=0, m=0, n=0;

    for(int i=0; i<20; i++){ //Aqui se usa en contador para 

        cont=0;
        r=0; 
        m=0;    //Aqui reinicializamos los valores de estas tres variables a cero para evitar corromper memoria
        n=0;
        srand(time(NULL)); //Se declara un reloj donde vamos a tener cierto tienpo donde vamos a poder generar pseudo numeros aleatorios reales 

        /*Generacion de numeros aleatorios*/
        m = rand()%(tam); 
        n = rand()%(tam);
        /**********************************/

        /*Aqui se manda a llamar la generacion de numeros por medio de pseudo numeros aleatorios de c, o se utiliza la serie de fibonacci para la generacion de los numeros,
        esto solo para introducir los numeros dentro del array, y determinar el peor y el caso esperimental dentro del programa*/

        //fibonacci(a, tam);     //Para el uso del programa se documenta una funcion o otra para poder generar los numeros entre fibonacci y los numeros generados de manera aleatoria solo de manera experimental
        generaArreglo(a, tam); 

        /********************************************************************************************/

        imprimearrglo(a, tam); //Esta es una funcion que se usa para imprimir el arreglo
        r = euclides(a[m],a[n]);
        
        fprintf(onion,"%d,%d\n",tam,cont); //Aqui se mandan los datos al archivo csv donde se guardan los datos de la muestra

        printf("M: %d, N: %d\n%d",a[m],a[n], r); 
        tam+=10;
    }
    fclose(onion);
}

/*Esta es la funcion de euclides encargada de hacer el calculo para encontrar el minimo comun divisor de dos numeros*/

int euclides(int m, int n){
    
    int r=0; (cont)++; 

    while(n!=0){
        (cont)++; 
        r = m%n; (cont)++; 
        m = n; (cont)++; 
        n = r; (cont)++; 
        (cont)++; 
    }
    (cont)++; 

    return m; (cont)++; 

}

/*Esta es una funcion que genera numeros aleatorios para el arreglo*/

void generaArreglo(int *A, int n){       
    srand(time(NULL));
    int i;
    for(i=0; i<n; i++)
        A[i]=rand()%(n+10);
}

/*Esta es la funcion que te imprime el arreglo ya generado de manera correcta*/

void imprimearrglo(int *A, int n){
    printf("\n------------------------------------------------------------------\n");
    for(int i=0; i<n; i++){

        printf("[%d]",A[i]);

    }
    printf("\n------------------------------------------------------------------\n");
}

/*Esta es la funcion que se usa para generar los numeros de fibonacci para el array*/

void fibonacci(int *A, int n){

    int a = 2, b = 1, i;

    for(i = 0; i < n; i+=2){
        
        A[i]=b;

        if((i+1)<n)
            A[i+1]=a;

        b = b + a;
        a = a + b;
    }

}