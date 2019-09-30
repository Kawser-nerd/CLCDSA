#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int T, N, M, i, j;
  int k = 0, t = 0;

  scanf("%d%d", &T, &N);

  int A[N];

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &M);

  int B[M];

  for(i = 0; i < M; i++){
    scanf("%d", &B[i]);
  }


  if(N < M){
    t = 1;
  }else{for(i = 0; i < M; i++){
    for(j = k; j < N; j++){
      if(((B[i] - A[j]) >= 0) && ((B[i] - A[j]) <= T)){
	k = j + 1;
	break;
      }else if(A[j] > B[i] || j == N - 1){
	t = 1;
	break;
      }
    }
    if(t == 1){
      break;
    }
  }
  }

  if(t == 1){
    printf("no\n");
  }else{
    printf("yes\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &T, &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &A[i]);
     ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &M);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &B[i]);
     ^