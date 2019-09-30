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

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

signed main(){
	int A, B, D;
	scanf("%lld%lld%lld", &A, &B, &M);
	D = gcd(A, B);
	matrix_2x2 U, V, X, Y;
	X.a = MOD(10);
	X.b = 1;
	X.c = 0;
	X.d = 1;
	Y.a = power(10, D);
	Y.b = 1;
	Y.c = 0;
	Y.d = 1;
	U = matpow_2x2(X, A - 1);
	V = matpow_2x2(Y, B / D - 1);
	int ans = MOD((U.a + U. b) * (V.a + V.b));
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &A, &B, &M);
  ^