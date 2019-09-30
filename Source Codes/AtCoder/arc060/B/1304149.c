#include <stdio.h>

#define lli long long int

lli digit_sum(lli b, lli n){
	if(n < b){
		return n;
	}
	else{
		return digit_sum(b, n / b) + n % b;
	}
}

int main(){
	lli n, s, b, p;
	scanf("%lld%lld", &n, &s);
	if(n < s){
		printf("-1\n");
		return 0;
	}
	if(n == s){
		printf("%lld\n", n + 1);
		return 0;
	}
	for(b = 2; b * b <= n; b++){
		if(digit_sum(b, n) == s){
			printf("%lld\n", b);
			return 0;
		}
	}
	for(p = b - 1; p >= 1; p--){
		b = (n - s) / p + 1;
		if(b != 1){
			if(digit_sum(b, n) == s){
				printf("%lld\n", b);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n, &s);
  ^