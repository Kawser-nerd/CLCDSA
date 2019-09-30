#include <stdio.h>
#include <stdlib.h>
#define int long long

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int f(int k, int A){
	if(k < A){
		return k;
	}
	else{
		return k + 1;
	}
}

int can_make(int x, int A, int B){
	int k, ans = 0;
	k = min(x, max(1, x / 2));
	ans = max(ans, f(k, A) * f(x - k + 1, B));
	k = min(x, max(1, x / 2 + 1));
	ans = max(ans, f(k, A) * f(x - k + 1, B));
	k = min(x, max(1, x / 2 + 2));
	ans = max(ans, f(k, A) * f(x - k + 1, B));
	if(ans < A * B){
		return 1;
	}
	else{
		return 0;
	}
}

signed main(){
	int Q, A, B, q;
	scanf("%lld", &Q);
	int *ans = (int *)malloc(sizeof(int) * Q);
	for(q = 0; q < Q; q++){
		scanf("%lld%lld", &A, &B);
		int l = 0, h, r = 3000000010;
		while(r - l > 1){
			h = (l + r) / 2;
			if(can_make(h, A, B) == 1){
				l = h;
			}
			else{
				r = h;
			}
		}
		ans[q] = l;
	}
	for(q = 0; q < Q; q++){
		printf("%lld\n", ans[q]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &Q);
  ^
./Main.c:43:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &A, &B);
   ^