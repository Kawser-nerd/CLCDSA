#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
  char s[5];
  scanf("%s",s);
  int a,b,c,d,i;
  a=s[0]-'0';
  b=s[1]-'0';
  c=s[2]-'0';
  d=s[3]-'0';
  if(a+b+c+d==7) printf("%d+%d+%d+%d=7",a,b,c,d);
  else if(a+b+c-d==7) printf("%d+%d+%d-%d=7",a,b,c,d);
  else if(a+b-c+d==7) printf("%d+%d-%d+%d=7",a,b,c,d);
  else if(a+b-c-d==7) printf("%d+%d-%d-%d=7",a,b,c,d);
  else if(a-b+c+d==7) printf("%d-%d+%d+%d=7",a,b,c,d);
  else if(a-b+c-d==7) printf("%d-%d+%d-%d=7",a,b,c,d);
  else if(a-b-c+d==7) printf("%d-%d-%d+%d=7",a,b,c,d);
  else if(a-b-c-d==7) printf("%d-%d-%d-%d=7",a,b,c,d);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^