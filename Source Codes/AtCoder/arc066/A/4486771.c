#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long N, i, t = 0, ans = 1;

  scanf("%lld", &N);

  long long A[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &A[i]);
  }

  if(N % 2 == 1){
    long long c[(N / 2) + 1];
    for(i = 0; i <= N / 2; i++){
      c[i] = 0;
    }
    for(i = 0; i < N; i++){
      if(A[i] % 2 == 1){
	printf("0\n");
	t = 1;
	break;
      }else{
	c[A[i] / 2]++;
	if(A[i] == 0 && c[0] > 1){
	  printf("0\n");
	  t = 1;
	  break;
	}else if(c[A[i] / 2] > 2){
	  printf("0\n");
	  t = 1;
	  break;
	}
      }
    }
    if(t == 0){
      for(i = 0; i < N / 2; i++){
	ans = (ans * 2) % 1000000007;
      }
      printf("%lld\n", ans);
    }
  }else{
    long long d[(N / 2)];
    for(i = 0; i < N / 2; i++){
      d[i] = 0;
    }
    for(i = 0; i < N; i++){
      if(A[i] % 2 == 0){
	printf("0\n");
	t = 1;
	break;
      }else{
	d[A[i] / 2]++;
	if(d[A[i] / 2] > 2){
	  printf("0\n");
	  t = 1;
	  break;
	}
      }
    }
    if(t == 0){
      for(i = 0; i < N / 2; i++){
	ans = (ans * 2) % 1000000007;
      }
      printf("%lld\n", ans);
    }
  }
	
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &A[i]);
     ^