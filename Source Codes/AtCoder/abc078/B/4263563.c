#include<stdio.h>
int main(){
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  printf("%d",(x-z)/(y+z));
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&y,&z);
   ^