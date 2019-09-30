#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  if(N == 1){
    printf("0\n");
    return 0;
  }

  int C[N],F[N];
  long S[N];

  for(int i = 0;i < N-1;i++){
    scanf("%d%ld%d",&C[i],&S[i],&F[i]);
  }

  for(int i = 0;i < N-1;i++){
    long time = S[i]+C[i];
    for(int j = i+1;j < N-1;j++){
      if(time < S[j]){
        time = S[j];
      }else if(time%F[j] != 0){
        time = time+F[j]-(time%F[j]);
      }
      time += C[j];
    }
    printf("%ld\n",time);
  }

  printf("0\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%ld%d",&C[i],&S[i],&F[i]);
     ^