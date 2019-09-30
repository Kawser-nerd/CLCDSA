#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

void run(void){
  char *s=(char *)malloc(sizeof(char)*200001);
  scanf("%s",s);
  int n=strlen(s);
  int64 ans=1;
  int cnt[26]={};
  int i;
  for(i=0;i<n;i++){
    ans+=i-cnt[s[i]-'a'];
    cnt[s[i]-'a']++;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^