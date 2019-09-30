#include<stdio.h>

int main(){
  int N, a, b, K, P[100], C[100] = {0}, i;
  
  scanf("%d", &N);
  scanf("%d %d", &a, &b);
  C[a - 1] = C[b - 1] = 1;
  scanf("%d", &K);
  for (i = 0; i < K; i++){
    scanf("%d", &P[i]);
  }
  for (i = 0; i < K; i++){
    if(C[P[i] - 1] == 1){
      break;
    }
    C[P[i] - 1] = 1;
  }
  
  if(i == K){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &K);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &P[i]);
     ^