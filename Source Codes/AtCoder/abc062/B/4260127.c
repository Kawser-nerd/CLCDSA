#include <stdio.h>
int main(void){
  int h,w,i,j;
  char a[101][101];
  char b[103][103];
  scanf("%d %d",&h,&w);
  for(i=0;i<h+2;i++){
    for(j=0;j<w+2;j++){
      b[i][j]='#';
    }
  }
  for(i=0;i<h;i++){
    scanf("%s",a[i]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      b[i+1][j+1]=a[i][j];
    }
  }
  for(i=0;i<h+2;i++){
    for(j=0;j<w+2;j++){
      printf("%c",b[i][j]);
    }
    printf("\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a[i]);
     ^