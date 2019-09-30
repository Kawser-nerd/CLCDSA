#include <stdio.h>

int main(void)
{int x=1,i=0;
 char s[3];
 scanf("%s",s);
 for(i;i<=2;i++)
 {if(s[i]=='a'){x*=1;}
  else if(s[i]=='b'){x*=2;}
  else{x*=3;}
 }
 if(x==6){printf("Yes");}
 else{printf("No");}
  return 0;
 } ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^