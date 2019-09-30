#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		100000									// ?????

// ????
static FILE *szpFpI;											// ??
static int si1A[D_ARRAY_MAX + 5];								// ??A
static int siACnt;												// ??A?
static int si1B[D_ARRAY_MAX + 5];								// ??B
static int siBCnt;												// ??B?

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
	int i;
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
	sscanf(lc1Buf, "%d%d", &siACnt, &siBCnt);

	// ??A - ??
	for (i = 0; i < siACnt; i++) {
		fscanf(szpFpI, "%d", &si1A[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??B - ??
	for (i = 0; i < siBCnt; i++) {
		fscanf(szpFpI, "%d", &si1B[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?? - ???
	qsort(si1A, siACnt, sizeof(int), fSortFnc);
	qsort(si1B, siBCnt, sizeof(int), fSortFnc);

	// ?? - ???
	si1A[siACnt] = INT_MAX;
	si1B[siBCnt] = INT_MAX;

	// And??Or? - ??
	int liAndCnt = 0;
	int liOrCnt = 0;
	int liANo = 0;
	int liBNo = 0;
	while (liANo < siACnt || liBNo < siBCnt) {

		// ??
		if (si1A[liANo] < si1B[liBNo]) {
			liANo++;
		}
		else if (si1A[liANo] > si1B[liBNo]) {
			liBNo++;
		}
		else {
			liAndCnt++;
			liANo++;
			liBNo++;
		}
		liOrCnt++;
	}

	// Jaccard
	double ldJac = (double)liAndCnt / (double)liOrCnt;

	// ?? - ???
	sprintf(lc1Out, "%.10lf\n", ldJac);

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
./Main.c:66:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:71:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1A[i]);
   ^
./Main.c:73:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:77:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1B[i]);
   ^
./Main.c:79:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^