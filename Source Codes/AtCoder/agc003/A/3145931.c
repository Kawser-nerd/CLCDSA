#include <stdio.h>
#include <string.h>
int main(void){
 int n=0,s=0,e=0,w=0,i;
 char c[1001];
 scanf("%s",c);
 for(i=0;i<strlen(c);i++){
  if(c[i]=='N') n=1;
  else if(c[i]=='S') s=1;
  else if(c[i]=='E') e=1;
  else w=1;
 }
 puts(n==s && e==w?"Yes":"No");
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",c);
  ^