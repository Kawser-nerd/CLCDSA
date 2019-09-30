#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 1000000007 //10^9+7
#define ll long long int

int main(void){
	ll n,i,ans=1;
	char s[100001];
	scanf("%lld %s",&n,s);
	int alph[26]={0};
	for(i=0;i<n;i++)alph[s[i]-'a']++;
	for(i=0;i<26;i++){
		ans *= (alph[i]+1);
		ans = ans%NUM;
	}
	ans = (ans-1)%NUM;
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %s",&n,s);
  ^