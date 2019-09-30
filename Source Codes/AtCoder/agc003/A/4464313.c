#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  char s[10100];
  int n=0,so=0,w=0,e=0;
  scanf("%s",s);
  int len=strlen(s);
  for(int i=0;i<len;i++){
    if(s[i]=='N') n=1;
    else if(s[i]=='S') so=1;
    else if(s[i]=='W') w=1;
    else if(s[i]=='E') e=1;
  }
  if(so==1&&n==0) printf("No");
  else if(so==0&&n==1) printf("No");
  else if(e==0&&w==1) printf("No");
  else if(w==0&&e==1) printf("No");
  else printf("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^