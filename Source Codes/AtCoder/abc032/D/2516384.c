#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

typedef struct {
	int v;
	int w;
}pair;

signed compare(const void *a, const void *b){
	pair A = *(pair *)a, B = *(pair *)b;
	if(A.w < B.w){
		return -1;
	}
	else if(A.w > B.w){
		return 1;
	}
	else if(A.v < B.v){
		return 1;
	}
	else if(A.v > B.v){
		return -1;
	}
	else{
		return 0;
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int solve1(int N, int W, int *v, int *w){
//	printf("solve1\n");
	int N1 = N / 2, N2 = (N + 1) / 2, lvvN1 = (int)1 << N1, lvvN2 = (int)1 << N2, i, j;
	pair *vw1 = (pair *)malloc(sizeof(pair) * lvvN1);
	for(i = 0; i < lvvN1; i++){
		vw1[i].v = 0;
		vw1[i].w = 0;
		for(j = 0; j < N1; j++){
			if((i & ((int)1 << j)) != 0){
				vw1[i].v += v[j];
				vw1[i].w += w[j];
			}
		}
	}
	qsort(vw1, lvvN1, sizeof(pair), compare);
	for(i = 1, j = 1; j < lvvN1; j++){
		if(vw1[i - 1].v < vw1[j].v){
			vw1[i] = vw1[j];
			i++;
		}
	}
	lvvN1 = i;
	pair *vw2 = (pair *)malloc(sizeof(pair) * lvvN2);
	for(i = 0; i < lvvN2; i++){
		vw2[i].v = 0;
		vw2[i].w = 0;
		for(j = 0; j < N2; j++){
			if((i & ((int)1 << j)) != 0){
				vw2[i].v += v[N1 + j];
				vw2[i].w += w[N1 + j];
			}
		}
	}
	qsort(vw2, lvvN2, sizeof(pair), compare);
	for(i = 1, j = 1; j < lvvN2; j++){
		if(vw2[i - 1].v < vw2[j].v){
			vw2[i] = vw2[j];
			i++;
		}
	}
	lvvN2 = i;
/*	for(i = 0; i < (1 << N1); i++){
		printf("v1[%lld] = (%lld, %lld)\n", i, vw1[i].v, vw1[i].w);
	}
	printf("\n");
	for(i = 0; i < (1 << N2); i++){
		printf("v2[%lld] = (%lld, %lld)\n", i, vw2[i].v, vw2[i].w);
	}
	printf("\n");
*/	int l, h, r, ans = 0;
	for(i = 0; i < lvvN1; i++){
//		printf("i = %lld\n", i);
		if(vw1[i].w > W){
			continue;
		}
		l = -1;
		r = lvvN2;
		while(r - l > 1){
//			printf("(l, r) = (%lld, %lld)\n", l, r);
			h = (l + r) / 2;
			if(vw1[i].w + vw2[h].w <= W){
				l = h;
			}
			else{
				r = h;
			}
		}
		ans = max(ans, vw1[i].v + vw2[l].v);
	}
	return ans;
}

int solve2(int N, int W, int *v, int *w){
//	printf("solve2\n");
	int i, j, vsum = 0, wsum = 0;
	for(i = 0; i < N; i++){
		vsum += v[i];
		wsum += w[i];
	}
	if(wsum <= W){
		return vsum;
	}
	else{
		int *dp = (int *)malloc(sizeof(int) * (W + 1));
		for(i = 0; i <= W; i++){
			dp[i] = 0;
		}
		for(i = 0; i < N; i++){
//			printf("i = %lld\n", i);
			for(j = W; j >= w[i]; j--){
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		return dp[W];
	}
}

int solve3(int N, int W, int *v, int *w){
//	printf("solve3\n");
	int i, j, vsum = 0, ans = 0;
	for(i = 0; i < N; i++){
		vsum += v[i];
	}
	int *dp = (int *)malloc(sizeof(int) * (vsum + 1));
	for(i = 0; i <= vsum; i++){
		dp[i] = inf;
	}
	dp[0] = 0;
	for(i = 0; i < N; i++){
		for(j = vsum; j >= v[i]; j--){
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
			if(dp[j] <= W){
				ans = max(ans, j);
			}
		}
	}
	return ans;
}

signed main(){
	int N, W, i, ans;
	scanf("%lld%lld", &N, &W);
	int *v = (int *)malloc(sizeof(int) * N);
	int *w = (int *)malloc(sizeof(int) * N);
	int f1 = 1, f2 = 1;
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &v[i], &w[i]);
		if(v[i] > 1000){
			f2 = 0;
		}
		if(w[i] > 1000){
			f1 = 0;
		}
	}
	if(N <= 30){
		ans = solve1(N, W, v, w);
	}
	else if(f1 == 1){
		ans = solve2(N, W, v, w);
	}
	else{
		ans = solve3(N, W, v, w);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:159:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &W);
  ^
./Main.c:164:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &v[i], &w[i]);
   ^