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
#include <stdbool.h>
#include <time.h>
#define TAM 1000

FILE *onion; //Aqui crea la variable apuntador para la creacion del archivo donde se iran guardando las muestras del archivo 

void generaArreglo(int *A, int n);
void principal();
void imprimearrglo(int *A, int n);
int busquedaI(int *A, int n, int num, int cont);
int busquedaR(int *A, int i, int j, int fin, int cont, int num);


int main(){
    
    principal();

}

void principal(){

    system("cls");

    onion=fopen("busqueda.csv","w+"); //En esta parte se crea el archivo para la funcion 

    int a[TAM];
    int tam=9;
    int num=0, cont=0, bus=0;

    for(int i=0; i<20; i++){ //Aqui se usa en contador para 

        cont=0;   //Aqui reinicializamos los valores de estas tres variables a cero para evitar corromper memoria
        num=0;

        srand(time(NULL)); //Se declara un reloj donde vamos a tener cierto tienpo donde vamos a poder generar pseudo numeros aleatorios reales 
        num = rand()%(1+tam);

        generaArreglo(a, tam); 

        imprimearrglo(a, tam); //Esta es una funcion que se usa para imprimir el arreglo



        //cont = busquedaI(a, tam, num, cont);

        cont = busquedaR(a, tam/3, tam-(tam/3), tam, cont, num);

        
        fprintf(onion,"%d,%d\n",tam,cont); //Aqui se mandan los datos al archivo csv donde se guardan los datos de la muestra

        
        tam+=9; /*Valor del aunmento para el arreglo y 
        alamcenar sus respectivos valores, notando que el aumento se va dando de 9 en 9*/
    }
    fclose(onion);
}

/*Esta es una funcion que genera numeros aleatorios para el arreglo*/

void generaArreglo(int *A, int n){       
    srand(time(NULL));
    /*Generacion de valores para el arreglo donde el valor 
    total para los valores ingresados sismpre va aumentar dependiendo de n que recibe la variable tam*/
    int i;
    for(i=0; i<=n; i++)
        A[i]=i+5; /*Uso de valores que aumentaran cada vez de 5 eb 5, igual se pude usar una funcion de random.*/
}

void imprimearrglo(int *A, int n){
    printf("\n------------------------------------------------------------------\n");
    for(int i=0; i<n; i++){

        printf("[%d]",A[i]);

    }
    printf("\n------------------------------------------------------------------\n");
}

int busquedaI(int *A, int n, int num, int cont){

    int i = 0, j = 0, ini = 0, fin = n;
    bool bus = false;

    i = n/3; /*Division para el primer indice donde vamos a 
    ubicarlo a un punto ini + (ini+fin)/3*/
    j = n-i; /*Ubicacion para el indice j donde su ubicacion 
    se da por el valor de i + i o el valor de i - fin por ser un valor 
    que esta mas cerca del final que otro*/

    printf("%d %d\n",i,j);

    while(bus == false){ //Inicio de la iteracion donde se detrenda cuando la condicion deje de ser falsa
        
        //Inicia de las comparaciones donde el sistema pide comprara si el numero esta en la pocision dada por los indices
        if((A[ini] == num)){
            
            printf("Numero %d en pocision %d", num, ini+1);
            bus = true; /*De encontrara el numero en el arreglo se cambia el estado de la variable booleana para detener el 
            ciclo, una vez que se detiene se regresan los valores del contador para el analisis a porteriori */

        }
        if((A[fin] == num)){
            
            printf("Numero %d en pocision %d", num, fin+1);
            bus = true;

        }
        if(A[j] == num){

            printf("Numero %d en pocision %d", num, j+1);
            bus = true;

        }
        if(A[i] == num){

            printf("Numero %d en pocision %d", num, i+1);
            bus=true;

        }
        else {
            /*De ser que el numero no se encuientre en el arreglo se resta un 1 a los indices para hacer la siguienet 
            busqueda dentro del arreglo y seguir con el sistema*/
            i--;
            j--;
            fin--;

            if(i==ini){ /*En caso de eestar en una estado en el que el indice ya regreso a la posicion 0 se termina el ciclo ya
            que los indices estan en la pocision sucesiva menor al origen de su indice menor siendo que el numero no due encontrado*/
                bus = true;
                printf("Numero no encontrado %d", num);
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }

    return cont; //Retorno del contador para el analisis a priori

}

int busquedaR(int *A, int i, int j, int fin, int cont, int num){

    if((A[0] == num)){ /*Inicio de la compraciones para encontrar el numero dentro del arreglo denotar 
    que este caso tenemos que la primera compracion no ponemos unvalor inicial, solo vrificamos si el numero 
    que deseamos no esta en el inidice 0 y que la iteracion ya no se encuentra*/
            
            printf("Numero %d en pocision 1", num);
            return cont; /*En el caso dado en que encontremos el numero en alguno de los indices se hace un
            return a la funcion y detenemos el sistema ya con el valor correspondiente encontrado*/
        }
        if((A[fin] == num)){
            
            printf("Numero %d en pocision %d", num, fin+1);
            return cont;

        }
        if(A[j] == num){

            printf("Numero %d en pocision %d", num, j+1);
            return cont;

        }
        if(A[i] == num){

            printf("Numero %d en pocision %d", num, i+1);
            return cont;

        }
        else {

            if((i-1)==0){/*Este es el caso de que no encontraramos el numero solo devolvemos lo que esta en 
            nustro contador y salimos de la funcion*/
                printf("Numero no encontrado %d", num);
                return cont;
            }

             return busquedaR(A, i-1, j-1, fin-1, cont, num);/*Despues de la verificacion de que el arreglo no se ha completado
             tenemos la sentencia que llama de nuevo a la funcion y le mandamos los indices correspoendiente menos uno para 
             seguir con la busqueda junto con el contadory el numero que seguimos buscando*/
        }

    return cont;
}