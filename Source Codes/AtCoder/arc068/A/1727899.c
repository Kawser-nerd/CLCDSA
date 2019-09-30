#include <stdio.h>

int main(){
	long long x, ans;
	scanf("%lld", &x);
	ans = (x / 11) * 2;
	if(x % 11 == 0){
		ans--;
	}
	else if(x % 11 > 6){
		ans++;
	}
	printf("%lld\n", ans + 1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &x);
  ^