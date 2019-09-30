#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int t;
	int d;
}pair;

signed compair(const void *a, const void *b){
	pair pa = *(pair *)a, pb = *(pair *)b;
	int sub = pa.d - pb.d;
	if(sub < 0){
		return 1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return -1;
	}
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, K, i, j, k;
	scanf("%lld%lld", &N, &K);
	pair *ps = (pair *)malloc(sizeof(pair) * 2 * N);
	for(i = 0; i < N; i++){
		ps[i] = (pair){i, 0};
	}
	for(i = N; i < 2 * N; i++){
		scanf("%lld%lld", &ps[i].t, &ps[i].d);
		ps[i].t--;
	}
	qsort(ps, 2 * N, sizeof(pair), compair);
	int *t_num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		t_num[i] = 0;
	}
	int *A = (int *)malloc(sizeof(int) * 2 * N);
	int *B = (int *)malloc(sizeof(int) * 2 * N);
	int sum = 0, t_count = 0;
	for(i = 0, j = 0, k = 0; i < N; i++){
		if(i < K){
			sum += ps[i].d;
			if(t_num[ps[i].t] == 0){
				t_count++;
			}
			else{
				A[j] = ps[i].d;
				j++;
			}
		}
		else{
			if(t_num[ps[i].t] == 0){
				B[k] = ps[i].d;
				k++;
			}
		}
		t_num[ps[i].t]++;
	}
	int NA = j, NB = k, ans = sum + t_count * t_count;
	for(i = 0; i < NA && i < NB; i++){
		sum -= A[NA - 1 - i];
		sum += B[i];
		t_count++;
		ans = max(ans, sum + t_count * t_count);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &ps[i].t, &ps[i].d);
   ^