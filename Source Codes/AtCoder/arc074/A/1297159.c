#include <stdio.h>

long long int max(long long int a, long long int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

long long int min(long long int a, long long int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

long long int max3(long long int a, long long int b, long long int c){
	return max(max(a, b), c);
}

long long int min3(long long int a, long long int b, long long int c){
	return min(min(a, b), c);
}

long long int min4(long long int a, long long int b, long long int c, long long int d){
	return min(min3(a, b, c), d);
}

long long int main(){
	long long int H, W;
	scanf("%lld%lld", &H, &W);
	if(H % 3 == 0 || W % 3 == 0){
		printf("0\n");
		return 0;
	}
	long long int ans;
	long long int W1 = W / 3, W2 = 1 + (W - 1) / 3, H1 = H / 2, H2 = 1 + (H - 1) / 2;
	long long int h1 = H / 3, h2 = 1 + (H - 1) / 3, w1 = W / 2, w2 = 1 + (W - 1) / 2;
	ans = min3(min4(
		  max3(H * W1, (W - W1) * H1, (W - W1) * H2) - min3(H * W1, (W - W1) * H1, (W - W1) * H2)
		, max3(H * W2, (W - W2) * H1, (W - W2) * H2) - min3(H * W2, (W - W2) * H1, (W - W2) * H2)
		, max3(W * h1, (H - h1) * w1, (H - h1) * w2) - min3(W * h1, (H - h1) * w1, (H - h1) * w2)
		, max3(W * h2, (H - h2) * w1, (H - h2) * w2) - min3(W * h2, (H - h2) * w1, (H - h2) * w2)
		), H * (W2 - W1), W * (h2 - h1));
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &H, &W);
  ^