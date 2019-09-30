#include<stdio.h>
int main(){
  int h,w;
  char c[111];
  scanf("%d%d",&h,&w);
  while(h--){
    scanf("%s",c);
    printf("%s\n%s\n",c,c);
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",c);
     ^