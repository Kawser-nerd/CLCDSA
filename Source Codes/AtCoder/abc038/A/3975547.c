#include <stdio.h>
int main(void){
  char s[50];
  int i;
  scanf("%s",s);
  for(i=0;i<=50;i++){
    if(s[i]=='\0') break;
  }
  if(s[i-1]=='T') printf("YES");
  else printf("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^