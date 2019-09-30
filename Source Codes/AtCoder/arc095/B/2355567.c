#include<stdio.h>
#include<math.h>

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

int search(long a[],long target,int left,int right){
  int m;
  if(left>right) return 0;
  m=(left+right)/2;
  if(target==a[m]) return 1;
  else if(left==right) return 0;
  else if(target<a[m]){
    return search(a,target,left,m-1);
  }
  else{
    return search(a,target,m+1,right);
  }
}

int main(){
  int n,i,j;
  long a[200000],x[200000],max=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  QSort(a, 0, n - 1);
  max=a[n-1];
  for(i=0;i<n-1;i++){
    if(labs(a[i]-(a[n-1]/2))<=max){
      j=a[i];
      max=labs(a[i]-(a[n-1]/2));
    }
  }
  printf("%ld %ld\n",a[n-1],j);
} ./Main.c: In function ‘QSort’:
./Main.c:25:9: warning: implicit declaration of function ‘Swap’ [-Wimplicit-function-declaration]
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: At top level:
./Main.c:36:6: warning: conflicting types for ‘Swap’
 void Swap(long x[ ], int i, int j)
      ^
./Main.c:25:9: note: previous implicit declaration of ‘Swap’ was here
         Swap(x, i, j);             /* x[i] ? x[j]??? */
         ^
./Main.c: In function ‘main’:
./Main.c:69:8: warning: implicit declaration of function ‘labs’ [-Wimplicit-function-declaration]
     if(labs(a[i]-(a[n-1]/2))<=max){
        ^
./Main.c:69:8: warning: incompatible implicit declaration of built-in function ‘labs’
./Main.c:69:8: note: include ‘<stdlib.h>’ or provide a declaration of ‘labs’
./Main.c:74:10: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 3 has type ‘int’ [-Wformat=]
   printf("%ld %ld\n",a[n-1],j);
          ^
./Main.c:62:3: warning: ignoring return value of ‘scanf’, decla...