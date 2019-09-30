#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_WATER_MAX		1000									// ??????
#define D_CHK_CNT		100										// ??????????

// ????
static int siWCnt;												// ????
static int siUCnt;												// ???
static double sd1Water[D_WATER_MAX];							// ???
static double sd1Cct[D_WATER_MAX];								// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - double??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	double *ldpVal1 = (double *)pzpVal1;
	double *ldpVal2 = (double *)pzpVal2;

	// double??
	if (*ldpVal1 > *ldpVal2) {
		return(-1);
	}
	else if (*ldpVal1 < *ldpVal2) {
		return(1);
	}

	return 0;
}

// ?????????
int
fChkMake(
	double pdCct				// <I> ??
)
{
	int i;

	// ?????????
	double ld1Salt[D_WATER_MAX];
	for (i = 0; i < siWCnt; i++) {
		ld1Salt[i] = sd1Water[i] * (sd1Cct[i] - pdCct) / 100.0;
	}

	// ??????
	qsort(ld1Salt, siWCnt, sizeof(double), fSortFnc);

	// ????
	double ldSum = 0.0;
	for (i = 0; i < siUCnt; i++) {
		ldSum += ld1Salt[i];
	}

	// ?????????
	if (ldSum < 0.0) {
		return -1;
	}
	else {
		return 0;
	}
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siWCnt, &siUCnt);

	// ?????? - ??
	for (i = 0; i < siWCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%lf%lf", &sd1Water[i], &sd1Cct[i]);
	}

	// ??????????
	double ldOK = 0.0;
	double ldNG = 100.0;

	// ????????
	double ldCct;
	for (i = 0; i < D_CHK_CNT; i++) {
		ldCct = (ldOK + ldNG) / 2.0;
		liRet = fChkMake(ldCct);
		if (liRet == 0) {					// OK
			ldOK = ldCct;
		}
		else {								// NG
			ldNG = ldCct;
		}
	}

	// ?????
	sprintf(lc1Out, "%.9lf\n", ldCct);

	// ????
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
./Main.c:99:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:108:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^