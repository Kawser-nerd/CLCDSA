#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		100000									// ?????

// ????? - ???
typedef struct Val {
	int miNo;													// ??????
	int miVal;													// ?
	int miPVal;													// ???
} Val;

// ????
static Val sz1Array[D_ARRAY_MAX];								// ??
static int siACnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ???
int
fSortFncV(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Val *lzpVal1 = (Val *)pzpVal1;
	Val *lzpVal2 = (Val *)pzpVal2;

	// ???
	if (lzpVal1->miVal > lzpVal2->miVal) {
		return(1);
	}
	else if (lzpVal1->miVal < lzpVal2->miVal) {
		return(-1);
	}

	return 0;
}

// ????? - ????
int
fSortFncN(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Val *lzpVal1 = (Val *)pzpVal1;
	Val *lzpVal2 = (Val *)pzpVal2;

	// ????
	if (lzpVal1->miNo > lzpVal2->miNo) {
		return(1);
	}
	else if (lzpVal1->miNo < lzpVal2->miNo) {
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

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siACnt);

	// ????
	for (i = 0; i < siACnt; i++) {
		sz1Array[i].miNo = i;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d", &sz1Array[i].miVal);
	}

	// ??? - ???
	qsort(sz1Array, siACnt, sizeof(Val), fSortFncV);

	// ???????
	sz1Array[0].miPVal = 0;
	for (i = 1; i < siACnt; i++) {
		if (sz1Array[i].miVal == sz1Array[i - 1].miVal) {		// ??????
			sz1Array[i].miPVal = sz1Array[i - 1].miPVal;
		}
		else {													// ???????
			sz1Array[i].miPVal = sz1Array[i - 1].miPVal + 1;
		}
	}

	// ??? - ????
	qsort(sz1Array, siACnt, sizeof(Val), fSortFncN);

	// ????
	for (i = 0; i < siACnt; i++) {
		sprintf(lc1Out, "%d\n", sz1Array[i].miPVal);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif

	}

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
./Main.c:92:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:102:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^