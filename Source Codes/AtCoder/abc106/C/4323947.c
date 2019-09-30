#include<stdio.h>
#include<string.h>
int main(){
  char s[111];
  long long i,k;
  scanf("%s%lld",s,&k);
  for(i=0;i<strlen(s);i++){
    if(s[i]!='1') break;
  }
  if(k<=i) puts("1");
  else printf("%c",s[i]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%lld",s,&k);
   ^