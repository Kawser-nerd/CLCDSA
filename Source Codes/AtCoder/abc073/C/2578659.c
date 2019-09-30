#include<stdio.h>

void QSort(long x[ ], int left, int right)
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
  long a[100000],n,i,cnt=0,cnt2=0,j,b,c=1;
  scanf("%ld",&n);
  for(i=0;i<n;i++)
    scanf("%ld",&a[i]);
  QSort(a, 0, n - 1);
  /*for(i=0;i<n;i++)
    printf("%d\n",a[i]);*/
  b=a[0];
  for(i=1;i<n;i++){
    if(a[i]==b){
      c=(c+1)%2;
      if(i==n-1)
        cnt+=c;
    }
    else{
      cnt+=c;
      c=1;
      b=a[i];
      if(i==n-1)
        cnt++;
    }
  }
  printf("%ld\n",cnt);
} ./Main.c: In function ‘QSort’:
./Main.c:23:9: warning: implicit declaration of function ‘Swap’ [-Wimplicit-function-declaration]
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: At top level:
./Main.c:35:6: warning: conflicting types for ‘Swap’
 void Swap(long x[ ], int i, int j)
      ^
./Main.c:23:9: note: previous implicit declaration of ‘Swap’ was here
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: In function ‘main’:
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^