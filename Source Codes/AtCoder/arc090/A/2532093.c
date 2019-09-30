#include<stdio.h>
int main(void){
  int n ,i ,j ,total = 0, max = 0;
  scanf("%d",&n);
  int a[2][n];
  for(i = 0; i < 2;i++){
    for(j = 0; j < n ;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(i = 0; i < n; i++){         // i<=j????????
    for(j = 0; j < n; j++){
      if(i <= j){
        total += a[1][j];
      }else{
        total += a[0][j];
      }
    }
      total += a[0][i];
      max = (max > total) ? max : total;
      total = 0;
    }
    printf("%d",max);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i][j]);
       ^