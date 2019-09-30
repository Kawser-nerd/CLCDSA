#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_KAT_MAX		100000									// ????

// ????
static int siKCnt;												// ??
static int siNeed;												// ??????
static int siShake;												// ????????
static int si1Throw[D_KAT_MAX];									// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
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
	if (*lipVal1 >  *lipVal2) {
		return(-1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(1);
	}

	return 0;
}

// ????
int
fGetCnt(
)
{
	int i;

	// ??????
	for (i = 0; i < siKCnt; i++) {
		if (si1Throw[i] <= siShake) {	// ????????
			break;
		}

		// ????
		siNeed -= si1Throw[i];

		// ???????
		if (siNeed <= 0) {
			return i + 1;
		}
	}

	// ????
	int liCnt = (siNeed + siShake - 1) / siShake;

	return liCnt + i;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siShake = 0;												// ????????

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
	sscanf(lc1Buf, "%d%d", &siKCnt, &siNeed);

	// ?????????????????
	for (i = 0; i < siKCnt; i++) {
		int liVal;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liVal, &si1Throw[i]);

		// ????????
		if (siShake < liVal) {
			siShake = liVal;
		}
	}

	// ?????? - ???
	qsort(si1Throw, siKCnt, sizeof(int), fSortFnc);

	// ????
	int liCnt = fGetCnt();

	// ?????
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:97:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:107:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^