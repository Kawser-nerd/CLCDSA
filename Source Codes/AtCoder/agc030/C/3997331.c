#include <stdio.h>

int main(void){
  int K;
  scanf("%d",&K);
  int N = (K+1)/2;
  if(N%2 == 1){
    N++;
  }
  if(K == 1){
    printf("1\n1\n");
    return 0;
  }
  int data[N][N];

  for(int r = 0;r<N;r++){
    for(int c = 0;c<N;c++){
      if(r%2 == 0){
        data[r][c] = (r-c+N)%N;
      }else{
        data[r][c] = N+(r-c+N)%N;
      }
      if(data[r][c]>=K){
        data[r][c] -= N;
      }
    }
  }

  printf("%d\n",N);
  for(int r = 0;r<N;r++){
    for(int c = 0;c<N;c++){
      printf("%d",data[r][c]+1);
      if(c != N-1){
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&K);
   ^