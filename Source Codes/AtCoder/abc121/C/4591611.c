#include <stdio.h>

  /* ?????????? */
void Swap(long x[ ], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

void QSort(long x[ ], long y[], int left, int right)
{
    int i, j;
    int pivot;

    i = left;                      /* ?????????????????? */
    j = right;                     /* ?????????????????? */

    pivot = x[(left + right) / 2]; /* ?????????????? */

    while (1) {                    /* ????? */

        while (x[i] < pivot)       /* pivot ??????? */
            i++;                   /* ???? i ?????? */

        while (pivot < x[j])       /* pivot ??????? */
            j--;                   /*  ???? j ?????? */
        if (i >= j)                /* i >= j ?? */
            break;                 /* ?????????? */

        Swap(x, i, j);             /* x[i] ? x[j]??? */
        Swap(y, i, j);  
        i++;                       /* ????? */
        j--;
    }

    if (left < i - 1)              /* ?????? 2 ???????? */
        QSort(x, y, left, i - 1);     /* ????? Q ????? */
    if (j + 1 <  right)            /* ?????? 2 ???????? */
        QSort(x, y, j + 1, right);    /* ????? Q ????? */
}



int main(void){
    // Your code here!
    long money = 0;
    int N,M;
    long A[100000], B[100000];
    
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++)
    {
        scanf("%ld %ld",&A[i], &B[i]);
    }
    QSort(A,B,0,N-1);
    
    int j = 0;
    while(M>0)
    {
        if(B[j] < M)
        {
            money += A[j]*B[j];
            M -= B[j];
        }
        else
        {
            money += A[j]*M;
            M = 0;
        }
        j++;
    }
    printf("%ld\n",money);
} ./Main.c: In function ‘main’:
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:56:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld %ld",&A[i], &B[i]);
         ^