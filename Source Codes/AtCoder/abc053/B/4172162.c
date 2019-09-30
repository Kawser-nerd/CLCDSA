#include <stdio.h>
int main(void){
  int n=0,i,a,z;
  char s[200000];
  scanf("%s",s);
  while(s[n]!='\0')n++;
  for(i=0;i<n;i++){
    if(s[i]=='A'){
      a=i;break;
    }
  }
  for(i=n;i>=0;i--){
    if(s[i]=='Z'){
      z=i;break;
    }
  }
  printf("%d",z-a+1);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^