#include <stdio.h>
int main(void){
	long long int n,i,p[1000],v=0;
	char s[1000][21];
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%s%lld",s[i],&p[i]);
		v+=p[i];
	}
	for(i=0;i<n;i++){
		if(p[i]>v/2){
			printf("%s\n",s[i]);
			return 0;
		}
	}
	printf("atcoder\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%lld",s[i],&p[i]);
   ^