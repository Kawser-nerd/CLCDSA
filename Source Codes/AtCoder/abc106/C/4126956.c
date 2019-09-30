#include<stdio.h>

int main(){
  char s[101];long long int k,i=0;
  scanf("%s",s);
  scanf("%lld",&k);
  while(s[i] == '1')i++;
  if(i >= k) printf("1");
  else printf("%c",s[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&k);
   ^