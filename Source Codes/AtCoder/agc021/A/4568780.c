#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  char s[20];
  scanf("%s",s);
  int l=strlen(s),ans=l*9+s[0]-57,sum=0;
  for(int i=0;i<l;i++){
    sum+=s[i]-48;
  }
  if(sum!=ans) ans--;
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^