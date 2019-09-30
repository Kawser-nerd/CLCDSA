#include <stdio.h>
#define ll long long int
int main(void){
	int n,ans=0;
	ll k,l,r,P=1;
	scanf("%d %lld",&n,&k);
	ll s[n],i;
	for(i=0;i<n;i++){
		scanf("%lld",&s[i]);
		if(s[i] == 0){
			printf("%d\n",n);
			return 0;
		}
	}
	l = 0;
	r = 0;
	while(l<n){
		while(P*s[r] <= k && r<n){
			P *= s[r];
			r++;
		}
		if(l<r){
			if(P<=k && ans <(r-l))  ans = r-l;
			P /= s[l];
			l++;
		}else{
			l++;
			r++;
		}
	}
	
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld",&n,&k);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&s[i]);
   ^