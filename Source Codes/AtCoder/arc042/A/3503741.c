#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_THREAD_MAX	100000									// ???????

// ????? - ??????
typedef struct Thread {
	int miNo;													// ??????
	int miOrd;													// ??
} Thread;

// ????
static FILE *szpFpI;											// ??
static Thread sz1Thread[D_THREAD_MAX + 5];						// ????
static int siTCnt;												// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Thread *lzpVal1 = (Thread *)pzpVal1;
	Thread *lzpVal2 = (Thread *)pzpVal2;

	// ????
	if (lzpVal1->miOrd > lzpVal2->miOrd) {
		return(1);
	}
	else if (lzpVal1->miOrd < lzpVal2->miOrd) {
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

	// ??????????? - ??
	int liWCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siTCnt, &liWCnt);

	// ???? - ???
	for (i = 1; i <= siTCnt; i++) {
		sz1Thread[i].miNo = i;
		sz1Thread[i].miOrd = i;
	}

	// ???? - ??
	for (i = 0; i < liWCnt; i++) {
		int liTNo;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &liTNo);

		// ?? - ??
		sz1Thread[liTNo].miOrd = -i;
	}

	// ???? - ???
	qsort(&sz1Thread[1], siTCnt, sizeof(Thread), fSortFnc);

	// ?? - ??
	for (i = 1; i <= siTCnt; i++) {
		sprintf(lc1Out, "%d\n", sz1Thread[i].miNo);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

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
./Main.c:71:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:83:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^