#include <stdio.h>

void MERGE(int *A, int b, int m, int e)

{       

        printf("\n MERGE %d, %d, %d\n", b, m, e);
        
        printf("\nARRAY\n");
        for (int i = 0; i < e; i++)
        {
            printf("%d, ", A[i]);
        }
        printf("\n");
        

        int l = m-b+1, r = e-m, i;
        int L[l+1], R[r+1];
        for(i=0; i< l; i++)
        {
            L[i] = A[b+i];
        }

        for (i=0; i< r; i++)
        {
            R[i] = A[m+i+1];
        }
        L[l] = 32767;
        R[r] = 32767;
        l = 0;
        r = 0;

        for(i=0; i< e-b+1; i++)
       {
            if(L[l] < R[r])
            {
                A[b+i] = L[l];
                l ++;
            }
            else            {
                A[b+i] = R[r];
                r ++;
            }
        }
}

 

void MERGE_SORT(int *A, int b, int e)

{
        if(b < e)

        {
            int m = (b + e) / 2;
            MERGE_SORT(A, b, m);
            printf("\n Izquierda %d, %d, %d\n", b, m, e);
            MERGE_SORT(A, m+1, e);
            printf("\n Derecha %d, %d, %d\n", b, m, e);
            MERGE(A, b, m, e);
        }
}

int main()

{
        int A[500];
        int lens, i;
        printf("Please Enter the lenghth of array:");
        scanf("%d", &lens);
 

        printf("Please Enter the elements of the array:");

        for(i=0; i< lens; i++)
           scanf("%d", &A[i]);

        MERGE_SORT(A, 0, lens-1); 

        printf("the result of the sort is:\n");
        for(i=0; i< lens; i++)
        {
           printf("%d ", A[i]);
        }
        return 0;

}