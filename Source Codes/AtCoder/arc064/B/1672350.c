#include<stdio.h>
int main(){
  int i;
  char s[100010];
  scanf("%s",s);
  for(i=0;s[i];i++);
  if(s[0]==s[i-1])i++;
  printf("%s\n",i%2?"First":"Second");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^