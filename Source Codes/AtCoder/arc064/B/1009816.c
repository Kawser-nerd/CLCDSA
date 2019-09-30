#include<stdio.h>
#include<string.h>
int main(){
  int i,l,a,f[100010];
  char s[100010];
  scanf("%s",s);
  l=strlen(s)-1;
  if(s[0]==s[l])l++;
  printf("%s\n",l%2==0?"First":"Second");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^