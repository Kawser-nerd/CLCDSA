#include <stdio.h>

#define int long long int

int MOD(int a){
	return a % (int)(1e9 + 7);
}

int fact(int n){
	int i, ans = 1;
	for(i = 1; i <= n; i++){
		ans = MOD(i * ans);
	}
	return ans;
}

signed main(){
	int N, M;
	scanf("%lld%lld", &N, &M);
	if(N > M + 1 || M > N + 1){
		printf("0\n");
	}
	else if(N == M){
		printf("%lld\n", MOD(2 * fact(N) * fact(M)));
	}
	else{
		printf("%lld\n", MOD(fact(N) * fact(M)));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^