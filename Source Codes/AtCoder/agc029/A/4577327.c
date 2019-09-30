#include <stdio.h>
#include <string.h>
#define ll long long int
int main(void){
	ll i,ans=0,b=0;
	char S[200001];
	scanf("%s",S);
	for(i=0;i<strlen(S);i++){
		if(S[i] == 'B')	b++;
		else ans += b;
	}
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^