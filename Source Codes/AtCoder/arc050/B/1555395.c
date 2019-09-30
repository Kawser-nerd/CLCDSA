#include <stdio.h>
#define int long long

typedef enum{
	false,
	true
}Boolean;

static int R, B, x, y;

Boolean can_make(int K){
	if((R - K) / (x - 1) + (B - K) / (y - 1) >= K && R >= K && B >= K){
		return true;
	}
	else{
		return false;
	}
}

signed main(){
	scanf("%lld%lld%lld%lld", &R, &B, &x, &y);
	int l = 0, h, r = R + B;
	while(r - l > 1){
		h = (l + r) / 2;
		if(can_make(h) == true){
			l = h;
		}
		else{
			r = h;
		}
	}
	printf("%lld\n", l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &R, &B, &x, &y);
  ^