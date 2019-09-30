#include<stdio.h>
#include<string.h>

typedef unsigned nat;
typedef nat bool;

#define false 0
#define true 1

typedef unsigned char nat8;
typedef nat8 bool8;
typedef unsigned short nat16;

typedef bool8 matrix_t;
typedef bool8 malted_t;
typedef bool8 kill_t;
typedef nat16 wm_t;

#define M_MAX 2048
#define N_MAX 2048

#define NONE ((wm_t)(-1))

nat m, n;
matrix_t A[M_MAX][N_MAX];
wm_t WM[M_MAX];
malted_t MALTED[N_MAX];
kill_t KR[M_MAX], KC[N_MAX];

bool batch();

int main() {
	nat tc, cs;
	nat i, j, k;
	nat x, y;
	nat t;

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u%u", &n, &m);

		for (i = 0; i != m; ++i) {
			memset(A[i], 0, n*sizeof(matrix_t));
			scanf("%u", &t);
			WM[i] = NONE;
			for (k = 0; k != t; ++k) {
				scanf("%u%u", &x, &y);
				--x;
				if (y)
					WM[i] = x;
				else
					A[i][x] = true;
			}
		}

		memset(KR, 0, m*sizeof(kill_t));
		memset(KC, 0, n*sizeof(kill_t));
		memset(MALTED, 0, n*sizeof(malted_t));

		printf("Case #%u:", cs+1);
		if (batch()) {
			for (i = 0; i != n; ++i)
				printf(" %c", MALTED[i] ? '1' : '0');
			putchar('\n');
		}
		else
			puts(" IMPOSSIBLE");
	}

	return 0;
}

bool line_is_null(nat);

bool batch() {
	nat i;
	nat nl;
	nat malte;

	for (i = 0; i != m; ++i)
		if (!KR[i] && line_is_null(i)) {
			nl = i;
			break;
		}
	if (i == m)
		return true;

	if (WM[nl] == NONE)
		return false;

	malte = WM[nl];
	MALTED[malte] = true;

	for (i = 0; i != m; ++i)
		if (!KR[i] && WM[i] == malte)
			KR[i] = true;

	KC[malte] = true;

	return batch();
}

bool line_is_null(nat i) {
	nat j;

	for (j = 0; j != n; ++j)
		if (!KC[j] && A[i][j] != 0)
			return false;
	return true;
}


