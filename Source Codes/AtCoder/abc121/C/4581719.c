#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STORE_MAX		100000									// ????

// ????? - ???
typedef struct Store {
	int miVal;													// ??
	int miCnt;													// ??
} Store;

// ????
static FILE *szpFpI;											// ??
static Store sz1Store[D_STORE_MAX];								// ?
static int siSCnt;												// ??
static int siNCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ????? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Store *lzpVal1 = (Store *)pzpVal1;
	Store *lzpVal2 = (Store *)pzpVal2;

	// ????
	if (lzpVal1->miVal > lzpVal2->miVal) {
		return 1;
	}
	else if (lzpVal1->miVal < lzpVal2->miVal) {
		return -1;
	}

	return 0;
}

// ?????
long long
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// ?????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSCnt, &siNCnt);

	// ? - ??
	for (i = 0; i < siSCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Store[i].miVal, &sz1Store[i].miCnt);
	}

	// ? - ???
	qsort(sz1Store, siSCnt, sizeof(Store), fSortFnc);

	// ???? - ??
	long long llMin = 0;
	for (i = 0; siNCnt > 0; i++) {

		// ????
		int liCnt;
		if (siNCnt < sz1Store[i].miCnt) {
			liCnt = siNCnt;
		}
		else {
			liCnt = sz1Store[i].miCnt;
		}

		// ??
		llMin += (long long)sz1Store[i].miVal * (long long)liCnt;
		siNCnt -= liCnt;
	}

	return llMin;
}

// ????
int
fOne(
)
{
	long long llRet;
	char lc1Buf[1024], lc1Out[1024];

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????
	llRet = fMain();

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llRet);

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// ???????
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne(0);
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:61:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:66:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^