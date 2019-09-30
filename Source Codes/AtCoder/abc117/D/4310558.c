#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_BIT_MAX		64										// ??????

// ????
static FILE *szpFpI;											// ??
static long long slK;											// K
static int si1KOn[D_BIT_MAX];									// K?1??[???]
static int si1KOff[D_BIT_MAX];									// K?0??[???]
static int siKNo;												// K???????
static int si1SumOn[D_BIT_MAX];									// 1????[???]
static int si1SumOff[D_BIT_MAX];								// 0????[???]
static int siSumNo;												// ?????????
static long long slMax;											// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????
int
fBit(
	long long plVal				// <I> ?
	, int piMin					// <I> ??????
	, int *pipOn				// <O> 1??
	, int *pipOff				// <O> 0??
	, int *pipNo				// <O> ??????
)
{
	int liNo = 0;
	long long llDiv = 2;
	while (plVal > 0 || liNo < piMin) {
		if (plVal % llDiv == 0) {			// 0
			pipOff[liNo]++;
		}
		else {								// 1
			pipOn[liNo]++;
		}

		// ??????
		plVal /= 2;
		liNo++;
	}

	// ?????? - ??
	if (*pipNo < liNo) {
		*pipNo = liNo;
	}

	return 0;
}

// K - ??
int
fSelK(
	int piNo					// <I> ??? 0?
	, long long plK				// <I> K
	, long long plSum			// <I> ??
)
{
	int liRet, liRVal;

	// ????
	if (piNo < 0) {

		// ??? - ??
		if (slMax < plSum) {
			slMax = plSum;
		}

		return 0;
	}

	// ???????
	long long llVal = (long long)1 << piNo;

	// 0???? > 1????
	liRVal = 0;
	if (si1SumOff[piNo] > si1SumOn[piNo]) {

		// ??
		if (plK + llVal <= slK) {
			liRVal = fSelK(piNo - 1, plK + llVal, plSum + llVal * si1SumOff[piNo]);
		}
		else {
			liRVal = -1;
		}
	}

	// 0???? <= 1???? or ????
	if (si1SumOff[piNo] <= si1SumOn[piNo] || liRVal != 0) {
		liRet = fSelK(piNo - 1, plK, plSum + llVal * si1SumOn[piNo]);
		if (liRet != 0) {
			liRVal = -1;
		}
	}

	return liRVal;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1KOn, 0, sizeof(si1KOn));							// K?1??[???]
	memset(si1KOff, 0, sizeof(si1KOff));						// K?0??[???]
	siKNo = 0;													// K???????
	memset(si1SumOn, 0, sizeof(si1SumOn));						// 1????[???]
	memset(si1SumOff, 0, sizeof(si1SumOff));					// 0????[???]
	siSumNo = 0;												// ?????????
	slMax = 0;													// ???

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

	// ????K - ??
	int liACnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%lld", &liACnt, &slK);

	// K - ????
	fBit(slK, 0, si1KOn, si1KOff, &siKNo);

	// ?? - ??
	for (i = 0; i < liACnt; i++) {
		long long llVal;
		fscanf(szpFpI, "%lld", &llVal);

		// ? - ????
		fBit(llVal, siKNo, si1SumOn, si1SumOff, &siSumNo);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ????
	int liNo;
	if (siKNo < siSumNo) {
		liNo = siSumNo;
	}
	else {
		liNo = siKNo;
	}

	// K - ??
	fSelK(liNo, 0, 0);

	// ?? - ???
	sprintf(lc1Out, "%lld\n", slMax);

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
./Main.c:141:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:150:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%lld", &llVal);
   ^
./Main.c:155:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^