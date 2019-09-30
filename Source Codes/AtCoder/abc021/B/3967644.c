#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SENTINEL 10000000000

void merge(long A[], long left, long mid, long right){
  long n1, n2, i, j, k;
  long *L,*R;
  
  n1 = mid-left;
  n2 = right-mid;
  
  L = (long*)malloc(sizeof(long) *(n1 + 1));
  R = (long*)malloc(sizeof(long) *(n2 + 1));
  
  for(i = 0; i <= n1 - 1; i++){
    L[i] = A[left + i];
  }
  for(j = 0; j <= n2 - 1; j++){
    R[j] = A[mid + j];
  }
  
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  
  i = 0;
  j = 0;
  
  for(k = left; k <= right - 1; k++){
   if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
  free(L);
  free(R);
}

void mergeSort(long A[], long left, long right){
  long mid;
  
  if(left + 1 < right){
    mid=(left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
 
int main(void){

  long N, a, b, K, i;

  scanf("%ld%ld%ld%ld", &N, &a, &b, &K);

  long P[K + 2];

  P[0] = a;
  P[1] = b;

  for(i = 2; i < (K + 2); i++){
    scanf("%ld", &P[i]);
  }

  mergeSort(P, 0, (K + 2));

  long t = 0;

  for(i = 1; i < (K + 2); i++){
    if(P[i] == P[i - 1]){
      t++;
      break;
    }
  }

  if(t == 0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld%ld", &N, &a, &b, &K);
   ^
./Main.c:69:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &P[i]);
     ^