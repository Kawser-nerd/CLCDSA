#include <stdio.h>
int main(void){
int a,b;
  scanf("%d %d",&a,&b);
  
  if((a==1||a==3||a==5||a==7||a==8||a==10||a==12)&&(b==1||b==3||b==5||b==7||b==8||b==10||b==12))
  {printf("Yes"); return 0;}
  if((a==4||a==6||a==9||a==11)&&(b==4||b==6||b==9||b==11))
    {printf("Yes");return 0;}
  if(a==2&&b==2)
  {printf("Yes");return 0;}
  printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^