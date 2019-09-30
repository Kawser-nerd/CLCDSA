#include <stdio.h>
int main(void){
	long long int h1,w1,h2,w2;
	scanf("%lld%lld%lld%lld",&h1,&w1,&h2,&w2);
	if(h1==h2 || h1==w2 || w1==h2 || w1==w2) printf("YES\n");
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&h1,&w1,&h2,&w2);
  ^