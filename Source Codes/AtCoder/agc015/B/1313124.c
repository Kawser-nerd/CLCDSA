#include <stdio.h>
int main(void)
{
  char s[100002];
  long long int num=0;
  int i=0,you=0;
  scanf("%s",s);
  while(s[you]!='\0'){you++;}you--;
  while(s[i]!='\0'){
    if(s[i]=='U'){
      num+=(you-i)+(i*2);
    }else if(s[i]=='D'){
      num+=i+((you-i)*2);
    }
  i++;
  }
printf("%lld",num);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^