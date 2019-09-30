#include <stdio.h>
#include <stdlib.h>
#define int long long

int GCD(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return GCD(b, a % b);
	}
}

signed main(){
	int T, t, A, B, C, D, k, i;
	scanf("%lld", &T);
	for(t = 0; t < T; t++){
		scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
		if(A < B || B > D){
			printf("No\n");
			continue;
		}
		if(C >= B){
			printf("Yes\n");
			continue;
		}
/*		int f = 0;
		for(i = 0; i < 2; i++){
			k = (A - C + B - 1) / B;
			A = A - k * B;
			a[i] = A;
			if(A < 0){
				printf("No\n");
				f = 1;
				break;
			}
			A += D;
		}
		if(f == 1){
			continue;
		}
		if(a[0] == a[1]){
			printf("Yes\n");
		}
		else if(a[0] < a[1]){

		}
		printf("Yes\n");
*/

		int g = GCD(B, D);
		int s1 = (A - B) / g + 1;
		int s2 = (A - C - 1) / g;
		if(s1 <= s2){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &T);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
   ^