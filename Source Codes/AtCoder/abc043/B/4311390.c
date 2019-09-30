#include<stdio.h>
#include<string.h>
int main(){
  char s[11],ans[11]={};
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='B') ans[strlen(ans)-1]='\0';
    else ans[strlen(ans)]=s[i];
  }
  printf("%s",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^