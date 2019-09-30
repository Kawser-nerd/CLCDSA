#include<stdio.h>
#include<string.h>

typedef unsigned nat;
typedef unsigned bool;

#define false 0
#define true 1

typedef unsigned char nat8;
typedef nat8 bool8;

typedef bool8 rock_t;
typedef unsigned short pd_t;

#define M_SIZE 128
#define N_SIZE 128
#define MOD 10007

rock_t R[M_SIZE][N_SIZE];
pd_t P[M_SIZE][N_SIZE];

int main() {
	nat tc, cs;
	nat m, n, r;
	nat i, j;
	nat x, y;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u%u", &m, &n, &r);
		--m;
		--n;
		for (i = 0; i != m; ++i)
			memset(R[i], 0, n*sizeof(rock_t));
		for (i = 0; i != r; ++i) {
			scanf("%u%u", &x, &y);
			--x;
			--y;
			R[x][y] = true;
		}

		for (i = 0; i != m; ++i)
			P[i][n] = 0;
		for (j = 0; j != n; ++j)
			P[m][j] = 0;

		P[m][n] = 1;

		for (i = m; i != 0;) {
			--i;
			for (j = n; j != 0;) {
				--j;

				if (R[i][j]) {
					P[i][j] = 0;
					continue;
				}

				x = 0;

				if (i+2 <= m && j+1 <= n)
					x = (x + P[i+2][j+1]) % MOD;
				if (i+1 <= m && j+2 <= n)
					x = (x + P[i+1][j+2]) % MOD;

				P[i][j] = x;
			}
		}

		printf("Case #%u: %u\n", cs+1, P[0][0]);
		fflush(stdout);
	}

	return 0;
}


