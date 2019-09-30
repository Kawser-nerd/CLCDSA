#include "stdio.h"
#include "stdlib.h"

int compare_int(const void *a, const void *b){
    return *(long long int *)a - *(long long int*)b;
}

int ch_A(int n,int m,long long int*A,long long int B){
  if(m==n){
    if(A[m]==B){
      return m;
    }else{
      return -1;
    }
  }
  if (B<A[n]||A[m]<B) {
    return -1;
  }
  int k=(int)((n+m)/2);
  if(A[k]>B){
    return ch_A(n,k-1,A,B);
  }
  if(A[k]<B){
    return ch_A(k+1,m,A,B);
  }
  if(A[k]==B){
    return k;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int N;
  int i;
  scanf("%d", &N);
  long long int A[N];
  for (i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  qsort(A, N, sizeof(long long int), compare_int);

  int B[N];
  int A_B[N];
  int t=1;
  int ind=0;
  A_B[0]=0;
  for (i = 0; i < N-1; i++) {
    if (A[i+1]==A[i]) {t++;A_B[i]=ind;}
    if (A[i+1]!=A[i]) {B[ind]=t;A_B[i]=ind;ind++;t=1;}
  }
  B[ind]=t;A_B[N-1]=ind;ind++;


  // printf("ind %d\nB ", ind);
  // for ( i = 0; i < ind; i++) {
  //   printf("%d ", B[i]);
  // }
  // printf("\nA_B ");
  // for (i = 0; i < N; i++) {
  //   printf("%d ", A_B[i]);
  // }
  // printf("\n");

  long long int C[N];
  long long int k;
  for ( i = 0; i < N; i++) {
    k=2;
    while (k<=A[i]) {k=k*2;}
    C[i]=k-A[i];
  }

  int temp;
  int ans=0;
  for (i = N-1; i >=1; i--) {
    temp=ch_A(0,i-1,A,C[i]);
    B[A_B[i]]--;
  //  printf("%d %d\n",i, temp);
    if(temp!=-1){
      if(B[A_B[temp]]>=1 && B[A_B[i]]>=0){
        B[A_B[temp]]--;
        ans++;
      }
    }
    //printf("%lld %lld %d %d\n",A[i],k-A[i],temp,ans);
  }

  printf("%d", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &A[i]);
     ^