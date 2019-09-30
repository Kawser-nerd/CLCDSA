#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	long long int n, k, i, j, p, q, ans=0;
	scanf("%lld%lld", &n, &k);
	// k=0
	if(k==0){
		printf("%lld\n", n*n);
	}
	else{
		// k>0
		// a<b
		for(i=n; i>k; i--){
			ans+=i-k;
		}
		// printf("%lld\n", ans);
		// a>b
		for(i=n-k; i>k; i--){
			p=n%i;
			q=n/i;
			if(p>=k && q==0){
				ans+=p-k+1;
			}
			else if(p>=k){
				ans+=(i-k)*(q-1)+p-k+1;
			}
			else{
				ans+=(i-k)*(q-1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &k);
  ^