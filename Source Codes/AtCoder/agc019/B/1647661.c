#include<stdio.h>
int main(){
  long long a,i,b[30]={};
  char s[200010];
  scanf("%s",s);
  for(i=0;s[i];i++)b[s[i]-'a']++;
  a=i*(i-1)/2;
  for(i=0;i<26;i++)a-=b[i]*(b[i]-1)/2;
  printf("%lld\n",a+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^