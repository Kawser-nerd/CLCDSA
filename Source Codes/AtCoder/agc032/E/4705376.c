#include <stdio.h>
#include <stdlib.h>
#define inf (int)(2e9)

signed compare(const void *a, const void *b){
	int sub = *(int *)a - *(int *)b;
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int sub1(int N, int *a, int K){
	int i, ans = 0;
	for(i = 0; i < K; i++){
		ans = max(ans, a[i] + a[2 * K - 1 - i]);
	}
	return ans;
}

int sub2(int N, int *a, int L){
	int i, ans = inf;
	for(i = 0; i < L; i++){
		ans = min(ans, a[2 * N - 1 - i] + a[2 * N - 2 * L + i]);
	}
	return ans;
}

int sub3(int N, int *a, int L){
	int i, ans = 0;
	for(i = 0; i < L; i++){
		ans = max(ans, a[2 * N - 1 - i] + a[2 * N - 2 * L + i]);
	}
	return ans;
}

int can_achieve(int N, int M, int *a, int x){
//	printf("x = %d\n", x);
	int l, h, r;
	int v1, v2, v3;

	l = -1;
	r = N + 1;
	while(r - l > 1){
		h = (l + r) / 2;
		if(sub1(N, a, h) > x){
			r = h;
		}
		else{
			l = h;
		}
	}
	v1 = l;

	l = -1;
	r = N + 1;
	while(r - l > 1){
		h = (l + r) / 2;
		if(sub2(N, a, h) >= M){
			l = h;
		}
		else{
			r = h;
		}
	}
	v2 = l;

	l = 0;
	r = N + 1;
	while(r - l > 1){
		h = (l + r) / 2;
		if(sub3(N, a, h) > M + x){
			l = h;
		}
		else{
			r = h;
		}
	}
	v3 = r;
//	printf("(v1, v2, v3) = (%d, %d, %d)\n", v1, v2, v3);

	if(max(N - v1, v3) <= v2 || v1 == N){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int N, M, i;
	scanf("%d%d", &N, &M);
	int *a = (int *)malloc(sizeof(int) * (2 * N));
	for(i = 0; i < 2 * N; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, 2 * N, sizeof(int), compare);
	int l = -1, h, r = M;
	while(r - l > 1){
		h = (l + r) / 2;
		if(can_achieve(N, M, a, h) == 1){
//			printf("can_achieve(%d) = 1\n", h);
			r = h;
		}
		else{
//			printf("can_achieve(%d) = 0\n", h);
			l = h;
		}
	}
	printf("%d\n", r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:105:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:108:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^