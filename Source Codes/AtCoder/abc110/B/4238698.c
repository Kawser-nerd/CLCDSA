#include <stdio.h>

int main(void){
  int N,M,X,Y;
  scanf("%d%d%d%d",&N,&M,&X,&Y);
  int x,y;
  int max = -101;
  int min = 101;

  for(int i = 0;i < N;i++){
    scanf("%d",&x);
    if(max < x){
      max = x;
    }
  }
  for(int i = 0;i < M;i++){
    scanf("%d",&y);
    if(min > y){
      min = y;
    }
  }

  for(int Z = min;Z > max;Z--){
    if(X == Z || Y == Z) continue;
    if(max < min && Z > max && X < Z && Z <= Y){
      printf("No War\n");
      return 0;
    }
  }

  printf("War\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&N,&M,&X,&Y);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y);
     ^