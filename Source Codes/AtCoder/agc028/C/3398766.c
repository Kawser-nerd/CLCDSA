#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int i;
	int val;
}pair;

signed compair(const void *a, const void *b){
	int sub = ((pair *)a)->val - ((pair *)b)->val;
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

int min(int a, int b){
	return a <= b ? a : b;
}
/*
signed main(){
	int N, i, j, now, ans;
	scanf("%lld", &N);
	pair *A = (pair *)malloc(sizeof(pair) * N);
	pair *B = (pair *)malloc(sizeof(pair) * N);
	for(i = 0; i < N; i++){
		A[i].i = i;
		B[i].i = i;
		scanf("%lld%lld", &A[i].val, &B[i].val);
	}
	qsort(A, N, sizeof(pair), compair);
	qsort(B, N, sizeof(pair), compair);
	int *is_used = (int *)malloc(sizeof(int) * N);
	int *Apos = (int *)malloc(sizeof(int) * N);
	int *Bpos = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		is_used[i] = 0;
		Apos[A[i].i] = i;
		Bpos[B[i].i] = i;
	}
	now = A[N - 1].i;
	is_used[now] = 1;
	j = 0;
	ans = 0;
	while(1){
		printf("now = %lld\n", now);
		while(j < N && is_used[B[j].i] == 1){
			j++;
		}
		printf("j = %lld\n", j);
		if(j == N){
			ans += min(A[Apos[now]].val, B[N - 1].val);
			printf("%lld\n", ans);
			return 0;
		}
		ans += min(A[Apos[now]].val, B[j].val);
		now = B[j].i;
		is_used[now] = 1;
	}
}
*/

signed main(){
	int N, i, Asum = 0, Bsum = 0;
	scanf("%lld", &N);
	pair *ps = (pair *)malloc(sizeof(pair) * (2 * N));
	int *is_used = (int *)malloc(sizeof(int) * N);
	int *vs = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		is_used[i] = 0;
		vs[i] = -1;
		ps[2 * i].i = i;
		ps[2 * i + 1].i = i;
		scanf("%lld%lld", &ps[2 * i].val, &ps[2 * i + 1].val);
		Asum += ps[2 * i].val;
		Bsum += ps[2 * i + 1].val;
	}
	qsort(ps, 2 * N, sizeof(pair), compair);
	int f = 0, now = 0, ans = 0;
	for(i = 0; i < 2 * N; i++){
		ans += ps[i].val;
		vs[ps[i].i] = ps[i].val;
		is_used[ps[i].i]++;
		now++;
		if(is_used[ps[i].i] == 2){
			f = 1;
		}
/*		if(f == 1 || now < N - 1){
			ans += ps[i].val;
			is_used[ps[i].i]++;
			now++;
			if(is_used[ps[i].i] == 2){
				f = 1;
			}
		}
		else{
			if(is_used[ps[i].i] == 1){
				ans += ps[i].val;
				is_used[ps[i].i]++;
				now++;
				f = 1;
			}
		}
*/		if(now == N){
			if(f == 0){
				if(ps[i].i != ps[i + 1].i){
					ans = ans - ps[i].val + ps[i + 1].val;
				}
				else{
					ans = min(ans - ps[i - 1].val + ps[i + 1].val, ans - ps[i].val + ps[i + 2].val);
				}
/*				int ans_sub = ans;
				ans = min(Asum, Bsum);
				for(i++; i < 2 * N; i++){
					ans = min(ans, ans_sub - vs[ps[i].i] + ps[i].val);
				}
*/			}
			printf("%lld\n", min(min(Asum, Bsum), ans));
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:71:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &ps[2 * i].val, &ps[2 * i + 1].val);
   ^