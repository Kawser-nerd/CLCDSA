#include<stdio.h>

char s[50][51];
int H, W, a[50][50] = {0}, i, j;

int main(){
  
  scanf("%d %d", &H, &W);
  
  for (i = 0; i < H; i++){
    scanf("%s", s[i]);
  }
  
  for (i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      if(s[i][j] == '#'){
        if(i > 0 && j > 0)         a[i - 1][j - 1]++;
        if(j > 0)                  a[i][j - 1]++;
        if(i < H - 1 && j > 0)     a[i + 1][j - 1]++;
        if(i > 0)                  a[i - 1][j]++;
                                   a[i][j] = 9;
        if(i < H - 1)              a[i + 1][j]++;
        if(i > 0 && j < W - 1)     a[i - 1][j + 1]++;
        if(j < W - 1)              a[i][j + 1]++;
        if(i < H - 1 && j < W - 1) a[i + 1][j + 1]++;
      }
    }
  }
  
  for (i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      if(a[i][j] < 9){
        printf("%d", a[i][j]);
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^