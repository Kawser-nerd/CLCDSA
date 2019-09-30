#include<stdio.h>

  void QSort(long long int x[ ],long long int left, long long int  right)
{
    long long int i, j;
    long long int pivot;

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
void Swap(long long int x[ ], long long int i, long long int j)
{
    long long int temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}

int main(){
  long long int a,s[200001],i,n,cnt=0,sum=0,j;
  scanf("%ld",&n);
  s[0]=0;
  for(i=0;i<n;i++){
    scanf("%ld",&a);
    s[i+1]=s[i]+a;
    if(s[i+1]==0) sum++;
  }
  QSort(s, 1, n);
  for(i=1;i<n;i++){
    cnt=0;

    for(j=i+1;j<n+1;j++){
      if(s[i]==s[j]) cnt++;
      else break;
    }
    i+=cnt;
    sum+=cnt*(cnt+1)/2;

  }
  printf("%ld\n",sum);
} ./Main.c: In function ‘QSort’:
./Main.c:23:9: warning: implicit declaration of function ‘Swap’ [-Wimplicit-function-declaration]
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: At top level:
./Main.c:34:6: warning: conflicting types for ‘Swap’
 void Swap(long long int x[ ], long long int i, long long int j)
      ^
./Main.c:23:9: note: previous implicit declaration of ‘Swap’ was here
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: In function ‘main’:
./Main.c:45:9: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%ld",&n);
         ^
./Main.c:48:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld",&a);
           ^
./Main.c:64:10: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%ld\n",sum);
          ^
./Main.c:45:3...