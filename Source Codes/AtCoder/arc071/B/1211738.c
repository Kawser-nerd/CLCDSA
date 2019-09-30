#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000
#define M 100000
#define Q 1000000007

typedef long long int ll;

ll add_mod(ll x, ll y, ll q){
	ll ret;

	ret = x + y;
	if(ret >= q) ret -= q;
	if(ret < 0) ret += q;

	return ret;
}

ll mul_mod(ll x, ll y, ll q){
	ll ret;

	if(x < 0) x+=q;
	if(y < 0) y+=q;
	ret = x * y;
	if(ret > 0) ret%=q;

	return ret;
}

ll x[N], y[M];

int main(void){
	int n, m;
	int i;
	ll ret, tmpx=0, tmpy=0;

	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%lld", &x[i]);
	for(i=0; i<m; i++) scanf("%lld", &y[i]);
	
	for(i=0; i<n; i++)
		tmpx = add_mod(tmpx, mul_mod(add_mod(2*i, 1-n, Q), x[i], Q), Q);
	for(i=0; i<m; i++)
		tmpy = add_mod(tmpy, mul_mod(add_mod(2*i, 1-m, Q), y[i], Q), Q);
	ret = mul_mod(tmpx, tmpy, Q);
	
	printf("%lld\n", ret);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:40:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0; i<n; i++) scanf("%lld", &x[i]);
                     ^
./Main.c:41:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0; i<m; i++) scanf("%lld", &y[i]);
                     ^