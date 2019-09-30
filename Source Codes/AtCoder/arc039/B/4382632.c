#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_VAL_MAX		605										// ???

// ????
static FILE *szpFpI;											// ??
static int siSCnt;												// ???
static int siCCnt;												// ??????
static long long sl2Comb[D_VAL_MAX][D_VAL_MAX];					// ??????[n][k] = nCk

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// nCk(??????[n][k])??? - ????????
int
fMakeComb(
	int piRng					// <I> ??
)
{
	int i, j;

	for (i = 0; i <= piRng; ++i) {
		for (j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				sl2Comb[i][j] = 1;
			}
			else {
				sl2Comb[i][j] = sl2Comb[i - 1][j - 1] + sl2Comb[i - 1][j];
				sl2Comb[i][j] %= D_MOD;
			}
		}
	}

	return 0;
}

// ????? - ??
int
fGetPCnt(
)
{
	// nCk(??????[n][k])??? - ????????
	fMakeComb(siSCnt + siCCnt);

	// ??? > ??????
	if (siSCnt > siCCnt) {
		return (int)sl2Comb[siSCnt + siCCnt - 1][siCCnt];
	}

	// ?????
	int liCnt = siCCnt / siSCnt;

	// ??
	liCnt = siCCnt - siSCnt * liCnt;

	return (int)sl2Comb[siSCnt][liCnt];
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSCnt, &siCCnt);

	// ????? - ??
	int liPCnt = fGetPCnt();

	// ?? - ???
	sprintf(lc1Out, "%d\n", liPCnt);

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ??????
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
#endif

	// ???????????
#ifdef D_TEST
	fclose(szpFpI);
	fclose(szpFpA);
#endif

	// ?????
#ifdef D_TEST
	if (siRes == 0) {
		printf("OK %d\n", piTNo);
	}
	else {
		printf("NG %d\n", piTNo);
	}
#endif

	return 0;
}

int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		fMain(i);
	}
#else
	fMain(0);
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:90:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^