#include<stdio.h>
#include<string.h>
int main(void){
  int i,a='a'-'A';
  char s[13];
  scanf("%s",s);
  if(('a'<=s[0]) && (s[0]<='z')) s[0]-=a;
  for(i=1;i<strlen(s);i++){
    if(('A'<=s[i]) && (s[i]<='Z')) s[i]+=a;
  }
  printf("%s\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^