#include <stdio.h>
#include <stdlib.h>

int main(void){
  int H,W;
  scanf("%d%d",&H,&W);
  char data[H][W];
  char sample[W];
  int gyou[H];
  int retu[W];

  for(int i = 0;i < W;i++){
    retu[i] = 0;
  }

  for(int i = 0;i < H;i++){
    scanf("%s",sample);
    gyou[i] = 0;
    for(int j = 0;j < W;j++){
      if(sample[j] == '#'){
        retu[j] = 1;
        gyou[i] = 1;
      }
      data[i][j] = sample[j];
    }
  }

  int flag;
  for(int i = 0;i < H;i++){
    flag = 0;
    for(int j = 0;j < W;j++){
      if(retu[j] && gyou[i]){
        printf("%c",data[i][j]);
        flag = 1;
      }
    }
    if(flag){
      printf("\n");
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",sample);
     ^