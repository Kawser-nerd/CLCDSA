#include <stdio.h>

int main(void)
{
  char s[4];
  scanf("%s",s);
  int i,sum=0;
  for(i=0;i<=3;i++){if(s[i]=='+'){sum++;}
                    else{sum--;}}
    printf("%d",sum);
  return 0;} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^