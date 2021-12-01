#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <complex.h>
// 
#define TAM 10000

FILE *onion;    

int raicescomplejas(int n, double r, double i, int cont, int nf);
int raicescomplejasI(int n, double r, double i, int cont);
void principal();

int main(){

    system("cls");

    onion = fopen("ejemplo1.csv","w+");

    principal();

    fclose(onion);

    return 0;    
}

void principal(){

    double r = 0, i = 0;
    int n = 0;
    int cont = 0;

    while(n<20){

        r = 0; 
        i = 0;
        cont = 0;

        srand(time(NULL));
        r = rand()%(1+100);
        i = rand()%(1+100);

        printf("----------------------------------------------------------------------------------\n");
        //cont = raicescomplejas(n, r, i, cont, n);
        cont = raicescomplejasI(n, r, i, cont);
        printf("----------------------------------------------------------------------------------\n");

        fprintf(onion,"%d,%d\n",n,cont);

        n++;

    }

}

int raicescomplejas(int n, double r, double i, int cont, int nf){

    double rc = 0, ic = 0, mod1 = 0, mod2 = 0, div = 0, angu = 0; (cont++);
    double cose = 0, sine = 0, z1 = 0, z2 =0, z3 = 0; (cont++);

    rc = pow(r, 2), ic = pow(i, 2); (cont++);
    mod1 = (rc + ic); (cont++);
    mod2 = sqrt(mod1); (cont++);
    div = (i/r); (cont++);
    angu = atan(div); (cont++);

    if(n==0){
        (cont++);
        z1 = sqrt(mod2); (cont++);
        z2 = z1 * (cos(90)); (cont++);
        z3 = z1 * (sin(90)); (cont++);
        printf("%.2f + %.2fi\n ", z2, z3); (cont++);
        return cont; (cont++);
    }
    else{
        (cont++);

        cose = (angu+(360*n))/nf; (cont++);
        sine = (angu+(360*n))/nf; (cont++);
        z1 = pow(mod2, 1/nf); (cont++);
        z2 = z1 * (cos(cose)); (cont++);
        z3 = z1 * (sin(sine)); (cont++);

        printf("%.2f + %.2fi\n", z2, z3); (cont++);

        cont = raicescomplejas(n-1, r, i, cont, nf); (cont++);

    }
     (cont++);
}

int raicescomplejasI(int n, double r, double i, int cont){

    double rc = 0, ic = 0, mod1 = 0, mod2 = 0, div = 0, angu = 0; (cont++);
    double cose = 0, sine = 0, z1 = 0, z2 =0, z3 = 0; (cont++);
    int j = 0; (cont++);

    rc = pow(r, 2), ic = pow(i, 2); (cont++);
    mod1 = (rc + ic); (cont++);
    mod2 = sqrt(mod1); (cont++);
    div = (i/r); (cont++);
    angu = atan(div); (cont++);

        for (j = 0; j <= n; j++)
        {
        (cont++);

            if(j==0){
                (cont++);
                z1 = sqrt(mod2); (cont++);
                z2 = z1 * (cos(90)); (cont++);
                z3 = z1 * (sin(90)); (cont++);
                printf("%.2f + %.2fi\n ", z2, z3); (cont++);
            }
            else{
            (cont++);

                cose = (angu+(360*n))/j; (cont++);
                sine = (angu+(360*j))/j; (cont++);
                z1 = pow(mod2, 1/j); (cont++);
                z2 = z1 * (cos(cose)); (cont++);
                z3 = z1 * (sin(sine)); (cont++);

                printf("%.2f + %.2fi\n", z2, z3); (cont++);
            }

        }
        (cont++);

    return cont;
}

