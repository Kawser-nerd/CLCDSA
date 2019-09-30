#include<stdio.h>

  /* ?????????? */
void QSort(long x[ ], long left, long right)
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
void Swap(long x[ ], int i, int j)
{
    long temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

int main(){
  int n,i;
  long a[200000],x[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
    x[i]=a[i];
  }
  QSort(a, 0, n - 1);
  for(i=0;i<n;i++){
    if(x[i]<a[n/2]) printf("%d\n",a[n/2]);
    else printf("%d\n",a[n/2-1]);
  }
} ./Main.c: In function ‘QSort’:
./Main.c:24:9: warning: implicit declaration of function ‘Swap’ [-Wimplicit-function-declaration]
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: At top level:
./Main.c:35:6: warning: conflicting types for ‘Swap’
 void Swap(long x[ ], int i, int j)
      ^
./Main.c:24:9: note: previous implicit declaration of ‘Swap’ was here
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: In function ‘main’:
./Main.c:54:28: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
     if(x[i]<a[n/2]) printf("%d\n",a[n/2]);
                            ^
./Main.c:55:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
     else printf("%d\n",a[n/2-1]);
                 ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:49:5: warning: ignor...