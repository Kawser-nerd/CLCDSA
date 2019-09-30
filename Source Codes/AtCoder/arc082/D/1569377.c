#include <stdio.h>
#include <stdlib.h>
#define int long long

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
//	srand(1);
	int X, K, Q, i;
	scanf("%lld%lld", &X, &K);
	int *r = (int *)malloc(sizeof(int) * (K + 1));
	r[0] = 0;
	for(i = 1; i <= K; i++){
		scanf("%lld", &r[i]);
//		r[i] = r[i - 1] + rand() % 10000;
	}
	scanf("%lld", &Q);
	int *t = (int *)malloc(sizeof(int) * Q);
	int *a = (int *)malloc(sizeof(int) * Q);
	for(i = 0; i < Q; i++){
		scanf("%lld%lld", &t[i], &a[i]);
//		t[i] = rand() % 15000;
//		a[i] = rand() % (X + 1);
	}
/*	for(i = 0; i <= K; i++){
		printf("r[%lld] = %lld\n", i, r[i]);
	}
	for(i = 0; i < Q; i++){
		printf("t[%lld] = %lld, a[%lld] = %lld\n", i, t[i], i, a[i]);
	}
*/	int *termsd = (int *)malloc(sizeof(int) * (K + 1));
	int *termsu = (int *)malloc(sizeof(int) * (K + 1));
	int *Ad = (int *)malloc(sizeof(int) * (K + 1));
	int *An = (int *)malloc(sizeof(int) * (K + 1));
	int *Au = (int *)malloc(sizeof(int) * (K + 1));
	termsd[0] = 0;
	termsu[0] = X;
	Ad[0] = 0;
	An[0] = 0;
	Au[0] = X;
	for(i = 1; i <= K; i++){
		if(i % 2 == 1){
			Ad[i] = min(X, max(0, Ad[i - 1] + r[i - 1] - r[i]));
			An[i] = An[i - 1] + r[i - 1] - r[i];
			Au[i] = min(X, max(0, Au[i - 1] + r[i - 1] - r[i]));
			termsd[i] = max(termsd[i - 1], -An[i]);
			termsu[i] = min(termsu[i - 1], X - An[i]);
		}
		else{
			Ad[i] = min(X, max(0, Ad[i - 1] - r[i - 1] + r[i]));
			An[i] = An[i - 1] - r[i - 1] + r[i];
			Au[i] = min(X, max(0, Au[i - 1] - r[i - 1] + r[i]));
			termsd[i] = max(termsd[i - 1], -An[i]);
			termsu[i] = min(termsu[i - 1], X - An[i]);
		}
	}
/*	for(i = 0; i <= K; i++){
		printf("Ad[%lld] = %lld\n", i, Ad[i]);
	}
	for(i = 0; i <= K; i++){
		printf("An[%lld] = %lld\n", i, An[i]);
	}
	for(i = 0; i <= K; i++){
		printf("Au[%lld] = %lld\n", i, Au[i]);
	}
	for(i = 0; i <= K; i++){
		printf("termsd[%lld] = %lld\n", i, termsd[i]);
	}
	for(i = 0; i <= K; i++){
		printf("termsu[%lld] = %lld\n", i, termsu[i]);
	}
*/	int left, half, right;
	int ans1, ans2, j;
	for(i = 0; i < Q; i++){
//		printf("i = %lld: ", i);
		left = 0;
		right = K + 1;
		while(right - left > 1){
			half = (left + right) / 2;
			if(r[half] < t[i]){
				left = half;
			}
			else{
				right = half;
			}
		}
//		printf("left = %lld\n", left);
		if(left % 2 == 0){
			if(a[i] <= termsd[left]){
				ans1 = max(0, Ad[left] + r[left] - t[i]);
			}
			else if(a[i] < termsu[left]){
				ans1 = max(0, a[i] + An[left] + r[left] - t[i]);
			}
			else{
				ans1 = max(0, Au[left] + r[left] - t[i]);
			}
		}
		else{
			if(a[i] <= termsd[left]){
				ans1 = min(X, Ad[left] - r[left] + t[i]);
			}
			else if(a[i] < termsu[left]){
				ans1 = min(X, a[i] + An[left] - r[left] + t[i]);
			}
			else{
				ans1 = min(X, Au[left] - r[left] + t[i]);
			}
		}
		printf("%lld\n", ans1);
/*		ans2 = a[i];
		for(j = 1; r[j] <= t[i] && j <= K; j++){
			if(j % 2 == 1){
				ans2 = max(0, ans2 + r[j - 1] - r[j]);
			}
			else{
				ans2 = min(X, ans2 - r[j - 1] + r[j]);
			}
		}
		if(j % 2 == 1){
			ans2 = max(0, ans2 + r[j - 1] - t[i]);
		}
		else{
			ans2 = min(X, ans2 - r[j - 1] + t[i]);
		}
		printf("%lld\n", ans2);
*/	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &X, &K);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &r[i]);
   ^
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &Q);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &t[i], &a[i]);
   ^