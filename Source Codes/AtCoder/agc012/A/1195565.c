#include <stdio.h>

void QSort(int x[ ], int left, int right);
void Swap(int x[ ], int i, int j);

int main(void){
    int n, i, j;
    scanf("%d", &n);
    int a[3*n];
    for(i=0; i<3*n; i++){
      scanf("%d", &a[i]);
    }
    //end to read
    QSort(a, 0, 3*n-1);
    unsigned long long ans=0;
    for(j=0; j<n; j++){
      ans += a[3*n-2*j-2];
    }
    printf("%llu\n", ans);
    return 0;
}

void QSort(int x[ ], int left, int right)
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
        i++;                       /* ????? */
        j--;
    }

    if (left < i - 1)              /* ?????? 2 ???????? */
        QSort(x, left, i - 1);     /* ????? Q ????? */
    if (j + 1 <  right)            /* ?????? 2 ???????? */
        QSort(x, j + 1, right);    /* ????? Q ????? */
}

  /* ?????????? */
void Swap(int x[ ], int i, int j)
{
    int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &a[i]);
       ^