#include <stdio.h>
int main(void){
int a,b;
  scanf("%d %d",&a,&b);
  if(a==1&&b!=1){printf("Alice");return 0;}
  if(b==1&&a!=1){printf("Bob");return 0;}
  if(a==1&&b==1){printf("Draw");return 0;}
  if(a>b){printf("Alice");return 0;}
  if(a<b){printf("Bob");return 0;}
  if(a==b){printf("Draw");return 0;}
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^