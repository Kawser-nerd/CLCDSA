#include<stdio.h>
#include<string.h>
int main(){
  int i;
  char s[100001];
  scanf("%s",s);
  for(i=0;i<strlen(s);i+=2){
    printf("%c",s[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^