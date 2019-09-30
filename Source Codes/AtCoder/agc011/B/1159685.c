#include <stdio.h>
#include <stdlib.h>

int A[100000];

int cmpfunc (const void * a, const void * b){
  return *(int *)a - *(int *)b;
}

int main(){
  int i, n;
  long long int s;
  scanf("%d", &n);
  s=0;
  for(i=0;i<n;i++){
    scanf("%d",A+i);
    s+=A[i];
  }

  qsort(A, n, sizeof(int), cmpfunc);

  s -= A[n-1];
  for(i=n-2;i>=0;i--){
    if(2*s < A[i+1]) break;
    s -= A[i];
  }

  printf("%d\n", n-1-i);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",A+i);
     ^