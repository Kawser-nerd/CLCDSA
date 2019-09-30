#include <stdio.h>
#define N 100

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int A,B;
  scanf("%d%d",&A,&B);

  char S[N][N];
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      if(i < N/2) S[i][j] = '#';
      else S[i][j] = '.';
    }
  }

  int cnt = 0;
  for(int i = 1;i < N/2;i += 2){
    for(int j = 1;j < N-1;j += 2){
      if(++cnt < A) S[i][j] = '.';
    }
  }

  cnt = 0;
  for(int i = N/2+1;i < N;i += 2){
    for(int j = 1;j < N-1;j += 2){
      if(++cnt < B) S[i][j] = '#';
    }
  }

  printf("%d %d\n",N,N);
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      printf("%c",S[i][j]);
    }
    printf("\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&A,&B);
   ^