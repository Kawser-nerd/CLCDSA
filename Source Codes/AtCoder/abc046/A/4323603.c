#include <stdio.h>
int main(void){
int a,b,c,count=3;
  scanf("%d %d %d",&a,&b,&c);
  if(a==b){count--;}
    if(a==c){count--;}
    if(b==c){count--;}
  if(count==0){count++;}
  printf("%d",count);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^