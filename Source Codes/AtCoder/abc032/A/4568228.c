#include <stdio.h>
int main(void){
int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  for(;;){
  if(c%a==0&&c%b==0){printf("%d\n",c); break;}
    c++;
  }
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^