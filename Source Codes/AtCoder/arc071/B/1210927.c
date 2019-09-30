#include <stdio.h>
#define MOD 1000000007LL

int main(void) {
	int n,m;
	long long int x[100000],y[100000];

	scanf("%d %d",&n,&m);
	for (int i = 0;i < n;i++) {
		scanf("%lld",&x[i]);
	}
	for (int i = 0;i < m;i++) {
		scanf("%lld",&y[i]);
	}
	
	long long int sumx = 0LL;
	long long int tmp;
	for (int i = 0;i < n-1;i++) {
		tmp = (x[i+1]-x[i])*(i+1);
		tmp %= MOD;
		tmp *= (n-1-i);
		tmp %= MOD;
		sumx += tmp;
		sumx %= MOD;
	}
	long long int sumy = 0L;
	for (int i = 0;i < m-1;i++) {
		tmp = (y[i+1]-y[i])*(i+1);
		tmp %= MOD;
		tmp *= (m-1-i);
		tmp %= MOD;
		sumy += tmp;
		sumy %= MOD;
	}
	printf("%lld\n", (sumx*sumy)%MOD);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&x[i]);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&y[i]);
   ^