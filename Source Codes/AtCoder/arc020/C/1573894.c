#include <stdio.h>
#include <stdlib.h>
#define int long long

int M;

typedef struct {
	int a;
	int b;
	int c;
	int d;
}matrix_2x2;

int MOD(int a){
	if(a >= 0){
		return a % M;
	}
	else{
		return M + a % M;
	}
}

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else if(n % 2 == 0){
		return power(MOD(a * a), n / 2);
	}
	else{
		return MOD(a * power(a, n - 1));
	}
}

matrix_2x2 matmul_2x2(matrix_2x2 A, matrix_2x2 B){
	matrix_2x2 ans;
	ans.a = MOD(A.a * B.a + A.b * B.c);
	ans.b = MOD(A.a * B.b + A.b * B.d);
	ans.c = MOD(A.c * B.a + A.d * B.c);
	ans.d = MOD(A.c * B.b + A.d * B.d);
	return ans;
}

matrix_2x2 matpow_2x2(matrix_2x2 A, int n){
	if(n == 0){
		matrix_2x2 ans;
		ans.a = 1;
		ans.b = 0;
		ans.c = 0;
		ans.d = 1;
		return ans;
	}
	else if(n % 2 == 0){
		return matpow_2x2(matmul_2x2(A, A), n / 2);
	}
	else{
		return matmul_2x2(A, matpow_2x2(A, n - 1));
	}
}

signed main(){
	int N, i, lovk, ans = 0;
	scanf("%lld", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	int *L = (int *)malloc(sizeof(int) * N);
	int *a_digit = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &a[i], &L[i]);
		for(lovk = 1; lovk <= a[i]; lovk *= 10){}
		a_digit[i] = lovk;
	}
	matrix_2x2 X, Y;
	scanf("%lld", &M);
	for(i = 0; i < N; i++){
		X.a = MOD(a_digit[i]);
		X.b = MOD(a[i]);
		X.c = 0;
		X.d = 1;
		Y = matpow_2x2(X, L[i]);
		ans = MOD(ans * Y.a + Y.b);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &a[i], &L[i]);
   ^
./Main.c:73:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &M);
  ^