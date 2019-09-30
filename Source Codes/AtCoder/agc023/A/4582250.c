#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int compare_long(const void *a, const void *b) {long *A = (long *)a;long *B = (long *)b;if (*A > *B) return 1;if (*A < *B) return -1;return 0;}
ll sum(ll n){
	if(n<0)return 0;
	ll i,s=0;
	for(i=1;i<=n;i++){s+=i;}
	return s;
}
int main(void){
	ll n,a,i;
	scanf("%lld",&n);
	ll s[n+1];
	s[0] = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		s[i+1] = s[i] + a;
	}
	qsort(s, n+1, sizeof(ll), compare_long);
	ll ans=0,b=s[0],count=0;
	for(i=1;i<n;i++){
		if(b == s[i]) count++;
		else{
			ans += sum(count);
			count = 0;
			b = s[i];
		}
	}
	if(b==s[n]) ans += sum(++count);
	
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^