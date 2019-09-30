#include<stdio.h>

typedef unsigned nat;

#define N_MAX 17
#define S_MAX (1u << N_MAX)

nat A[S_MAX];
char P[S_MAX][N_MAX];
char B[16][16];
nat C[N_MAX], W[N_MAX];

void gensubsets(nat* A, nat n) {
	nat k, i, l/*l*/;

	C[0] = 1;
	W[0] = 0;
	for (k = 0; k != n; ++k) {
		C[k+1] = (n-k)*C[k]/(k+1);
		W[k+1] = W[k] + C[k];
	}

	l = 1u << n;
	for (i = 0; i != l; ++i)
		A[W[__builtin_popcount(i)]++] = i;
}

int main() {
	nat tc, cs;
	nat rows, cols, n;
	nat i, j, k, a , b;
	char ch;
	nat king;
	nat S, p, w;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u", &rows, &cols);
		n = rows*cols;

		for (i = 0; i != rows; ++i) {
			for (j = 0; j != cols; ++j) {
				scanf(" %c", &ch);
				if (ch == 'K')
					king = cols*i  +j;
				B[i][j] = ch;
			}
		}

		gensubsets(A, n);

		for (i = 0; i != n; ++i)
			P[(1u << n)-1][i] = 1;

		for (k = 1u << n; k != 0;) {
			--k;
			for (w = 0; w != n; ++w) {
				S = A[k];
				i = w/cols;
				j = w%cols;
				P[S][w] = 0;

#define doit(a0, b0) \
				a = a0; \
				b = b0; \
				if (a < rows && b < cols && B[a][b] != '#' && !((1u << (p = cols*a+b)) & S)) { \
					if (!P[S | (1u << p)][p]) { \
						P[S][w] = 1; \
					} \
				}

				doit(i-1, j-1);
				doit(i-1, j+0);
				doit(i-1, j+1);
				doit(i+0, j-1);
				doit(i+0, j+1);
				doit(i+1, j-1);
				doit(i+1, j+0);
				doit(i+1, j+1);
			}
		}

		printf("Case #%u: %c\n", cs+1, P[1u << king][king] ? 'A' : 'B');
	}

	return 0;
}


