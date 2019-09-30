#include <stdio.h>
#define ll long long int
int main(void){
	int n,i;
	scanf("%d",&n);
	char s[n][21];
	ll p[n],sum=0;
	for(i=0;i<n;i++){
		scanf("%s %lld",s[i],&p[i]);
		sum+=p[i];
	}
	for(i=0;i<n;i++){
		if(sum*0.5 < p[i]){
			printf("%s\n",s[i]);
			return 0;
		}
	}
	printf("atcoder\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %lld",s[i],&p[i]);
   ^