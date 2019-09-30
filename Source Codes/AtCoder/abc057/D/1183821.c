#include <stdio.h>

long long int comb(int n, int k){
	if(k == 0){
		return 1;
	}
	else{
		return (n * comb(n - 1, k - 1)) / k;
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

int main(){
	int N, A, B, i, j;
	scanf("%d%d%d", &N, &A, &B);
	double ans1 = 0;
	long long int v[N], tmp, ans2 = 0;
	for(i = 0; i < N; i++){
		scanf("%lld", &v[i]);
	}
	for(i = 1; i < N; i++){
		for(j = i; j > 0 && v[j] > v[j - 1]; j--){
			tmp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = tmp;
		}
	}
	for(i = 0; i < A; i++){
		ans1 += v[i];
	}
	ans1 /= A;
	printf("%f\n", ans1);
	int l = 0, r = A - 1;
	while(v[l] != v[A - 1]){
		l++;
	}
	while(v[r] == v[A - 1] && r < N){
		r++;
	}
	if(l == 0){
		for(i = A; i <= min(B, r); i++){
			ans2 += comb(r, i);
		}
	}
	else{
		ans2 = comb(r - l, A - l);
	}
	printf("%lld\n", ans2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &v[i]);
   ^