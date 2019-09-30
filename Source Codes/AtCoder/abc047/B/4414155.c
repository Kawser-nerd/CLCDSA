#include<stdio.h>

int main(void){
  int w,h,n;
  scanf("%d",&w);
  scanf("%d",&h);
  scanf("%d",&n);
  int point[h][w];
  int x[n];
  int y[n];
  int a[n];
  int s = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      point[i][j] = 0;
    }
  }
  for(int i = 0;i < n;i++){
    scanf("%d",&x[i]);
    scanf("%d",&y[i]);
    scanf("%d",&a[i]);
  }
  for(int i = 0;i < n;i++){
    if(a[i] == 1){
      for(int j = 0;j < h;j++){
        for(int k = 0;k < x[i];k++){
          point[j][k] = 1;
        }
      }
    }else if(a[i] == 2){
      for(int j = 0;j < h;j++){
        for(int k = x[i];k < w;k++){
          point[j][k] = 1;
        }
      }
    }else if(a[i] == 3){
      for(int j = 0;j < y[i];j++){
        for(int k = 0;k < w;k++){
          point[j][k] = 1;
        }
      }
    }else if(a[i] == 4){
      for(int j = y[i];j < h;j++){
        for(int k = 0;k < w;k++){
          point[j][k] = 1;
        }
      }
    }
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(point[i][j] == 0){
        s++;
      }
    }
  }
  printf("%d",s);
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&w);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&h);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&y[i]);
     ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^