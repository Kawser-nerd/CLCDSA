#include<stdio.h>
#include<string.h>
int main(){
  char s[100001];
  scanf("%s",s);
  int i,n=strlen(s);
  long long ans=0;
  for(i=0;i<n;i++){
    ans+=n-1;
    if(s[i]=='U'){
      ans+=i;
    }else {
      ans+=n-1-i;
    }
  }
  printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^