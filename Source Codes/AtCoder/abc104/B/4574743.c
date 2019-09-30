#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main(void){
  char s[100];
  scanf("%s",s);
  int i,n=strlen(s);
  if(s[0]!='A'){
    puts("WA");
    return 0;
  }
  int cnt=0;
  for(i=1;i<n;i++){
    if(isupper(s[i])){
      if(i==1||i==n-1||s[i]!='C'){
        puts("WA");
        return 0;
      }
      cnt++;
    }
  }
  if(cnt!=1)puts("WA");
  else puts("AC");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^