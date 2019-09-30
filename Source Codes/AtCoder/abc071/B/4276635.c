#include<stdio.h>
#include<string.h>
int main(){
  char s[100000];
  int i;
  scanf("%s",s);
  for(i=97;i<124;i++){
    if(strchr(s,i)==0) break;
  }
  if(i==123)puts("None");
  else printf("%c",i);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^