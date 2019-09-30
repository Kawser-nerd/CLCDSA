#include<stdio.h>

int main(void){
  int c[3][3];
  int i,j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      scanf("%d",&c[i][j]);
    }
  }
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      if(!(c[i][j]-c[i][j+1]==c[i+1][j]-c[i+1][j+1])){
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&c[i][j]);
       ^