#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ITM_MAX		50										// ?????

// ????? - ????
typedef struct Itm {
	long long mlVal;											// ??
	int miCnt;													// ?
} Itm;

// ????
static Itm sz1Itm[D_ITM_MAX];									// ??
static int siICnt;												// ???
static int siISMin;												// ????? - ??
static int siISMax;												// ????? - ??
static long long sl2Comb[D_ITM_MAX + 5][D_ITM_MAX + 5];			// ??????[n][m] = nCm

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Itm *lzpVal1 = (Itm *)pzpVal1;
	Itm *lzpVal2 = (Itm *)pzpVal2;

	// ????
	if (lzpVal1->mlVal > lzpVal2->mlVal) {
		return(-1);
	}
	else if (lzpVal1->mlVal < lzpVal2->mlVal) {
		return(1);
	}

	return 0;
}

// ?? - ????
int
fSetCnt(
)
{
	int i;

	// ????
	int liNo = 0;
	for (i = 1; i < siICnt; i++) {
		if (sz1Itm[i].mlVal == sz1Itm[liNo].mlVal) {	// ??
			sz1Itm[liNo].miCnt++;
		}
		else {											// ???
			liNo++;
			sz1Itm[liNo].mlVal = sz1Itm[i].mlVal;
		}
	}

	// ?????
	siICnt = liNo;

	return 0;
}

// ?????????
int
fMakeComb(
)
{
	int i, j;

	for (i = 0; i <= siICnt; ++i) {
		for (j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				sl2Comb[i][j] = 1;
			}
			else {
				sl2Comb[i][j] = sl2Comb[i - 1][j - 1] + sl2Comb[i - 1][j];
			}
		}
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siICnt, &siISMin, &siISMax);

	// ????
	for (i = 0; i < siICnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%lld", &sz1Itm[i].mlVal);
#else
		fscanf(stdin, "%lld", &sz1Itm[i].mlVal);
#endif
		sz1Itm[i].miCnt = 1;
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ?? - ???
	qsort(sz1Itm, siICnt, sizeof(Itm), fSortFnc);

	// ???? - ??
	long long llSum = 0;
	for (i = 0; i < siISMin; i++) {
		llSum += sz1Itm[i].mlVal;
	}
	double ldAvg = (double)llSum / (double)siISMin;

	// ???? - ??
	sprintf(lc1Out, "%.6lf\n", ldAvg);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ?????????
	fMakeComb();

	// ?? - ????
	fSetCnt();

	long long llPtn = 0;

	// ??????????????
	if (sz1Itm[0].miCnt <= siISMin) {			// ?????

		// ???????
		int liCnt = siISMin - sz1Itm[0].miCnt;		// ??
		int liNo = 1;
		while (liCnt >= sz1Itm[liNo].miCnt) {
			liCnt -= sz1Itm[liNo].miCnt;
			liNo++;
		}

		// ?????
		llPtn = sl2Comb[sz1Itm[liNo].miCnt][liCnt];
	}
	else {										// ?????

		// ???
		int liCnt = 0;
		if (siISMax < sz1Itm[0].miCnt) {
			liCnt = siISMax;
		}
		else {
			liCnt = sz1Itm[0].miCnt;
		}

		// ???????
		for (i = siISMin; i <= siISMax; i++) {
			llPtn += sl2Comb[sz1Itm[0].miCnt][i];
		}
	}

	// ????????
	sprintf(lc1Out, "%lld\n", llPtn);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ???????????
#ifdef D_TEST
	fclose(szpFpT);
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
./Main.c:119:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:128:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%lld", &sz1Itm[i].mlVal);
   ^
./Main.c:135:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^