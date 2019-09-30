#include <stdio.h>
int main(void){
  int a,b,c,d;
  scanf("%d %d %d",&a,&b,&c);
  d=100*a+10*b+c;
    if(d%4==0){
    printf("YES");}
  else{printf("NO");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^