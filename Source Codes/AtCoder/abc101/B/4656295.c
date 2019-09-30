#include <stdio.h>
#include <stdlib.h>
int main(void){
char s[15];
  int sum;
  int count;
  int a;
  scanf("%s",s);
  for(count=0;s[count]!='\0';count++){
 sum=sum+(s[count]-'0');
  }
  a=atoi(s);
  if(a%sum==0){printf("Yes");}
  else {printf("No");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^