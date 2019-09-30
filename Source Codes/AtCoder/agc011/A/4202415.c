#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SENTINEL 10000000000

void merge(long long A[], long long left, long long mid, long long right){
  long long n1, n2, i, j, k;
  long long *L,*R;
  
  n1 = mid-left;
  n2 = right-mid;
  
  L = (long long*)malloc(sizeof(long long) *(n1 + 1));
  R = (long long*)malloc(sizeof(long long) *(n2 + 1));
  
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

void mergeSort(long long A[], long long left, long long right){
  long long mid;
  
  if(left + 1 < right){
    mid=(left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
 
int main(void){
 
  long long N, C, K, i, s, ans = 1, k;

  scanf("%lld%lld%lld", &N, &C, &K);

  long long T[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &T[i]);
  }

  mergeSort(T, 0, N);

  for(i = 0; i < N; i++){
    if(i == 0){
      s = T[i];
      k = 0;
    }else{
      if(T[i] > s + K){
	s = T[i];
	k = i;
	ans++;
      }else if(i - k + 1 > C){
	s = T[i];
	k = i;
	ans++;
      }
    }	
  }

  printf("%lld\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &N, &C, &K);
   ^
./Main.c:66:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &T[i]);
     ^