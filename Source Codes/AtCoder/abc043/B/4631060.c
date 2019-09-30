#include <stdio.h>
#include <string.h>
int main(void){
  char s[11],a[11]={'\0'};
  scanf("%s",s);
  int n=strlen(s),i;
  for(i=0;i<n;i++){
    int m=strlen(a);
    if(s[i]=='B') a[m-1]='\0';
    else a[m]=s[i];
  }
  printf("%s",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^