#include <stdio.h>
int main(void){
int x,a,b,count;
  scanf("%d %d %d",&x,&a,&b);
  x=x-a;
  for(;;){
    x=x-b;
  if(x<0){break;}
  count++;
}
printf("%d",x+b);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&x,&a,&b);
   ^