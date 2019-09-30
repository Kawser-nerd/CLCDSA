#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int val;
	int num;
}pair;

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

int min(int a, int b){
	return a <= b ? a : b;
}

int next_pow(int n){
	int ans = 1;
	while(ans <= n){
		ans *= 2;
	}
	return ans;
}

signed main(){
	int N, i, j, ans = 0;
	scanf("%lld", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	qsort(A, N, sizeof(int), compare);
	pair *B = (pair *)malloc(sizeof(pair) * N);
	for(i = 1, j = 0, B[0].val = A[0], B[0].num = 1; i < N; i++){
		if(A[i] == A[i - 1]){
			B[j].num++;
		}
		else{
			j++;
			B[j].val = A[i];
			B[j].num = 1;
		}
	}
	N = j + 1;
	int l, h, r, k, minnum;
	for(i = N - 1; i >= 0; i--){
		if(B[i].num > 0){
			k = next_pow(B[i].val);
			l = -1;
			r = i + 1;
			while(r - l > 1){
				h = (l + r) / 2;
				if(B[h].val < k - B[i].val){
					l = h;
				}
				else{
					r = h;
				}
			}
			if(B[r].val + B[i].val == k){
				if(r == i){
					ans += B[i].num / 2;
					B[i].num %= 2;
				}
				else{
					minnum = min(B[r].num, B[i].num);
					ans += minnum;
					B[r].num -= minnum;
					B[i].num -= minnum;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^