#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_QUIZ_MAX		100005									// ?????
#define D_SEL_CNT		4										// ?????

// ????
static FILE *szpFpI;											// ??
static int siQCnt;												// ???
static int si1Lv[D_QUIZ_MAX];									// ???
static long long sl2Ptn[D_SEL_CNT][D_QUIZ_MAX];					// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - int??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	int *lipVal1 = (int *)pzpVal1;
	int *lipVal2 = (int *)pzpVal2;

	// ??
	if (*lipVal1 > *lipVal2) {
		return(1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(-1);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
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

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siQCnt);

	// ??? - ??
	for (i = 0; i < siQCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &si1Lv[i]);
	}

	// ??? - ???
	qsort(si1Lv, siQCnt, sizeof(int), fSortFnc);

	// ????? - ??? - ???
	sl2Ptn[D_SEL_CNT - 1][siQCnt] = 0;
	for (i = siQCnt - 1; i >= 0; i--) {
		sl2Ptn[D_SEL_CNT - 1][i] = sl2Ptn[D_SEL_CNT - 1][i + 1] + 1;
	}

	// ????? - ??? - ?????
	for (i = D_SEL_CNT - 2; i >= 0; i--) {
		int liNo = siQCnt - 1;

		sl2Ptn[i][siQCnt] = 0;
		for (j = siQCnt - 1; j >= 0; j--) {

			// ???????????
			while (si1Lv[j] * 2 <= si1Lv[liNo]) {
				liNo--;
			}

			// ????? - ???
			sl2Ptn[i][j] = sl2Ptn[i][j + 1] + sl2Ptn[i + 1][liNo + 1];
			sl2Ptn[i][j] %= D_MOD;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", sl2Ptn[0][0]);

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
./Main.c:67:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:72:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^