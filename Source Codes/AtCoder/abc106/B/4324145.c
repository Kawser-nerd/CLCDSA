#include<stdio.h>

int main(){
  int n,i,p[5]={105,135,165,189,195};
  scanf("%d",&n);
  for(i=0;i<5;i++){
    if(p[i]>n) break;
  }
  printf("%d",i);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^