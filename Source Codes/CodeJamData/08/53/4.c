#include<stdio.h>

typedef unsigned nat;
typedef unsigned bool;

#define false 0
#define true 1

#define M_SIZE 16
#define N_SIZE 16
#define S_SIZE (1u << 11u)

nat P[S_SIZE][N_SIZE];
bool A[M_SIZE][N_SIZE];

int main() {
	nat tc, cs;
	nat i, j, k;
	nat r, s;
	nat m, n;
	char ch;
	bool ok;
	nat setmx;
	nat x;
	nat card;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u", &m, &n);
		for (i = 0; i != m; ++i)
			for (j = 0; j != n; ++j) {
				scanf(" %c", &ch);
				A[i][j] = ch == '.';
			}

		setmx = 1u << m;
		for (s = 0; s != setmx; ++s)
			P[s][n] = 0;

		for (k = n; k != 0;) {
			--k;
			for (r = 0; r != setmx; ++r) {
				P[r][k] = 0;
				for (s = 0; s != setmx; ++s) {
					ok = true;
					card = 0;
					for (i = 0; i != m; ++i)
						if ((1u << i) & s) {
							++card;
							if (!A[i][k] ||
									(i != 0 && ((1u << (i-1)) & r)) ||
									((1u << i) & r) ||
									(i != m-1 && ((1u << (i+1)) & r))
							   ) {
								ok = false;
								break;
							}
						}
					if (!ok)
						continue;

					x = card + P[s][k+1];
					if (x > P[r][k])
						P[r][k] = x;
				}
			}
		}

		printf("Case #%u: %u\n", cs+1, P[0][0]);
		fflush(stdout);
	}

	return 0;
}


