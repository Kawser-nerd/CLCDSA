#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int n,len,i,j;
  char s[101000],t[101000];
  scanf("%d %s %s",&n,s,t);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(s[i+j]-t[j])break;
    }
    if(s[i+j]==0)break;
  }
  printf("%d",n+i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %s %s",&n,s,t);
   ^