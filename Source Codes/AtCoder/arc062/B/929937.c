#include<stdio.h>
int main(){
  int g=0,p=0,i;
  char s[100010];
  scanf("%s",s);
  for(i=0;s[i];i++)s[i]-'p'?(g++):(p++);
  printf("%d\n",(g-p)/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^