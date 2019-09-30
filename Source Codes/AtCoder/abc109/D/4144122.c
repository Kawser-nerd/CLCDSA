#include <stdio.h>

int main(void){
  int H,W;
  int counter = 0;
  scanf("%d%d",&H,&W);
  int ans[4][H*W];

  int data[H][W];
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      scanf("%d",&data[i][j]);
    }
  }


  for(int i = 0;i < H;i++){
    if(i%2 == 0){
      for(int j = 0;j < W;j++){
        if(i == H-1 && j == W-1){
          break;
        }
        if(data[i][j]%2 != 0){
          if(j == W-1){
            ans[0][counter] = i+1;
            ans[1][counter] = j+1;
            ans[2][counter] = i+2;
            ans[3][counter] = j+1;
            data[i+1][j]++;
            counter++;
          }else{
            ans[0][counter] = i+1;
            ans[1][counter] = j+1;
            ans[2][counter] = i+1;
            ans[3][counter] = j+2;
            data[i][j+1]++;
            counter++;
          }
        }
      }
    }else{
      for(int j = W-1;j >= 0;j--){
        if(i == H-1 && j==0){
          break;
        }
        if(data[i][j]%2 != 0){
          if(j == 0){
            ans[0][counter] = i+1;
            ans[1][counter] = j+1;
            ans[2][counter] = i+2;
            ans[3][counter] = j+1;
            data[i+1][j]++;
            counter++;
          }else{
            ans[0][counter] = i+1;
            ans[1][counter] = j+1;
            ans[2][counter] = i+1;
            ans[3][counter] = j+0;
            data[i][j-1]++;
            counter++;
          }
        }
      }
    }
  }

  printf("%d\n",counter);
  for(int i = 0;i < counter;i++){
    printf("%d %d %d %d\n",ans[0][i],ans[1][i],ans[2][i],ans[3][i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&data[i][j]);
       ^