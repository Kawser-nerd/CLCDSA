#include <stdio.h>

#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int N, H, A, B, C, D, E, i, j, n, h, ans = inf;
	scanf("%lld%lld%lld%lld%lld%lld%lld", &N, &H, &A, &B, &C, &D, &E);
	for(i = 0; i <= N; i++){
		n = N - i;
		h = H + B * i;
		j = max((E * n + D + E - h) / (D + E), 0);
		ans = min(ans, A * i + C * j);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld%lld", &N, &H, &A, &B, &C, &D, &E);
  ^