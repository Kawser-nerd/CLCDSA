#include <iostream>
using namespace std;

const long long mod = 1000000007;

struct Matrix {
	long long a[3][3];
};

Matrix Mul(Matrix A, Matrix B) {
	Matrix C; for (int i = 0; i < 9; i++) C.a[i / 3][i % 3] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				C.a[i][j] += A.a[i][k] * B.a[k][j];
				C.a[i][j] %= mod;
			}
		}
	}
	return C;
}

Matrix Power(Matrix A, long long K) {
	Matrix V, W = A; for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) { if (i == j) V.a[i][j] = 1; else V.a[i][j] = 0; } }

	for (int i = 0; i < 32; i++) {
		if ((K / (1LL << i)) % 2 == 1) { V = Mul(V, W); }
		W = Mul(W, W);
	}
	return V;
}

long long N, M, X[1 << 17], A, B, C;
Matrix Base;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> X[i];
	X[M + 1] = N + 1;

	A = 0; B = 1; C = 1;
	Base.a[0][0] = 1; Base.a[0][1] = 0; Base.a[0][2] = 1;
	Base.a[1][0] = 1; Base.a[1][1] = 1; Base.a[1][2] = 1;
	Base.a[2][0] = 1; Base.a[2][1] = 2; Base.a[2][2] = 2;
	for (int i = 0; i <= M; i++) {
		Matrix G = Power(Base, X[i + 1] - X[i] - 1);
		long long CA = G.a[0][0] * A + G.a[0][1] * B + G.a[0][2] * C; CA %= mod;
		long long CB = G.a[1][0] * A + G.a[1][1] * B + G.a[1][2] * C; CB %= mod;
		long long CC = G.a[2][0] * A + G.a[2][1] * B + G.a[2][2] * C; CC %= mod;
		A = CA; B = CB; C = CC; if (i == M) break;

		long long EA = 1LL * A + 0LL * B + 1LL * C; EA %= mod;
		long long EB = 0LL * A + 1LL * B + 0LL * C; EB %= mod;
		long long EC = 0LL * A + 2LL * B + 1LL * C; EC %= mod;
		A = EA; B = EB; C = EC;
	}
	cout << A << endl;
	return 0;
}