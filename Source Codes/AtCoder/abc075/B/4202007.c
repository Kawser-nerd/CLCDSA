#include <stdio.h>

int main(void){
  int H,W;
  scanf("%d%d",&H,&W);

  char data[H+2][W+2];
  char ans[H+2][W+2];
  char sample[W];

  for(int i = 0;i < H+2;i++){
    for(int j = 0;j < W+2;j++){
      data[i][j] = '.';
      ans[i][j] = '#';
    }
  }
  for(int i = 1;i < H+1;i++){
    scanf("%s",sample);
    for(int j = 0;j < W;j++){
      data[i][j+1] = sample[j];
    }
  }

  for(int i = 1;i < H+1;i++){
    for(int j = 1;j < W+1;j++){
      if(data[i][j] != '#'){
        int counter = 0;
        if(data[i-1][j-1] == '#')
          counter++;
        if(data[i-1][j] == '#')
          counter++;
        if(data[i-1][j+1] == '#')
          counter++;
        if(data[i][j-1] == '#')
          counter++;
        if(data[i][j+1] == '#')
          counter++;
        if(data[i+1][j-1] == '#')
          counter++;
        if(data[i+1][j] == '#')
          counter++;
        if(data[i+1][j+1] == '#')
          counter++;
        ans[i][j] = counter;
      }
    }
  }


  for(int i = 1;i < H+1;i++){
    for(int j = 1;j < W+1;j++){
      if(ans[i][j] == '#')
        printf("#");
      else
        printf("%d",ans[i][j]);
    }
    printf("\n");
  }


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",sample);
     ^