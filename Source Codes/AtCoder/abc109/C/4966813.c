#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long int
ll GCD(ll x,ll y){
	return y==0?x:GCD(y,x%y);
}
int compare_longlong(const void *a, const void *b) {long long *A = (long long *)a;long long *B = (long long *)b;if (*A > *B) return 1;if (*A < *B) return -1;return 0;}
int main(void){
	int n;
	ll X;
	scanf("%d%lld",&n,&X);
	ll x[n+1],ans;
	for(int i=0;i<n;i++)scanf("%lld",&x[i]);
	x[n]=X;
	qsort(x,n+1,sizeof(ll),compare_longlong);
	ans = x[1]-x[0];
	for(int i=1;i<n;i++){
		ll tmp = x[i+1]-x[i];
		ans = GCD(ans,tmp);
	}
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&n,&X);
  ^
./Main.c:15:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<n;i++)scanf("%lld",&x[i]);
                      ^