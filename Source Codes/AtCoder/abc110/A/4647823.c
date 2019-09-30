#include <stdio.h>
int main(){
  int a,b,c,d;
  scanf("%d%d%d",&a,&b,&c);
  if(a>=b){
    if(c>=a) d=c*10+a+b;
    else d=a*10+b+c;
  }
  else{
    if(c>=b) d=c*10+b+a;
    else d=b*10+a+c;
  }
  printf("%d",d);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^