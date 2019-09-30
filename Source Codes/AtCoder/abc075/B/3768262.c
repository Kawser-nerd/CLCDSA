#include <stdio.h>

int main(){
  int H, W;
  char S[60][60] = {};
  int count = 0;

  scanf("%d %d", &H, &W);
  for(int i = 0; i < H; i++){
    scanf("%s", S[i]);
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(S[i][j] == '.'){
        count = 0;
        for(int k = -1; k <= 1; k++){
          for(int l = -1; l <= 1; l++){
            if(k != 0 || l != 0){
              if(i+k>=0 && i+k<H && j+l>=0 && j+l<W && S[i+k][j+l]=='#'){
                count++;
              }
            }
          }
        }
        S[i][j] = count + '0';
      }
    }
  }

  for(int i = 0; i < H; i++){
    printf("%s\n", S[i]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^