#include<stdio.h>
#include<string.h>
int main(){
  char o[55],e[55];
  scanf("%s%s",o,e);
  for(int i=0;i<strlen(o)+strlen(e);i++){
    if(i%2==0) printf("%c",o[i/2]);
    else printf("%c",e[i/2]);
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",o,e);
   ^