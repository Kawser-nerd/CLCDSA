#include <stdio.h>
#define int long long

int f(int N){
	int ans = 0;
	while(1){
		ans ^= N;
		if(N % 4 == 0){
			return ans;
		}
		N--;
	}
}

signed main(){
	int A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", f(A) ^ f(B) ^ A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &A, &B);
  ^