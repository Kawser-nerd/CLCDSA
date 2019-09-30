#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		10										// ?????

// ????
static int si1Array[D_ARRAY_MAX];								// ??
static int siACnt;												// ???
static int si1Sum[D_ARRAY_MAX];									// ??
static int siSCnt;												// ???

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
	if (*lipVal1 > *lipVal2) {
		return(-1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(1);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, k;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siSCnt = 0;													// ???

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d%d%d", &si1Array[0], &si1Array[1], &si1Array[2], &si1Array[3], &si1Array[4]);

	// ?????
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 4; j++) {
			for (k = j + 1; k < 5; k++) {
				si1Sum[siSCnt] = si1Array[i] + si1Array[j] + si1Array[k];
				siSCnt++;
			}
		}
	}

	// ?? - ???
	qsort(si1Sum, siSCnt, sizeof(int), fSortFnc);

	// ???????
	int liFNo = 1;
	int liTNo = 0;
	for ( ; liFNo < siSCnt; liFNo++) {
		if (si1Sum[liTNo] != si1Sum[liFNo]) {
			liTNo++;
			si1Sum[liTNo] = si1Sum[liFNo];
		}
	}
	siSCnt = liTNo;

	// ?????
	sprintf(lc1Out, "%d\n", si1Sum[2]);

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
./Main.c:69:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^