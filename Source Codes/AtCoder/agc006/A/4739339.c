#include<stdio.h>
#include<string.h>
int main(){
  int n,i;
  char s[111],t[111];
  scanf("%d%s%s",&n,s,t);
  for(i=0;i<n;i++){
    if(strstr(t,&s[i])==t) break;
  }
  printf("%d\n",n+i);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%s%s",&n,s,t);
   ^