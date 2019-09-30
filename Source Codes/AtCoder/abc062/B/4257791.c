#include <stdio.h>

int main(void){
  int H,W;
  scanf("%d%d",&H,&W);

  char a[H+2][W+2];
  char s[W];
  for(int i = 0;i < H+2;i++){
    for(int j = 0;j < W+2;j++){
      a[i][j] = '#';
    }
  }

  for(int i = 0;i < H;i++){
    scanf("%s",s);
    for(int j = 0;j < W;j++){
      a[i+1][j+1] = s[j];
    }
  }

  for(int i = 0;i < H+2;i++){
    for(int j = 0;j < W+2;j++){
      printf("%c",a[i][j]);
    }
    printf("\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^