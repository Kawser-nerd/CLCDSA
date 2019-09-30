#include <stdio.h>
int main(void){
  char s[100010];
  int n;
  scanf("%d %s",&n,s);
  long long int i,cnt[100]={0},sum=1;
  for(i=0;i<n;i++) {
    int num=s[i]-'a';
    cnt[num]++;
  }
  for(i=0;i<26;i++) sum=(sum*(cnt[i]+1))%1000000007;
  printf("%lld\n",sum-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %s",&n,s);
   ^