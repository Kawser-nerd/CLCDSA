#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SCORE_MAX		200000									// ??????

// ????? - ?????
typedef struct Score {
	int miJNo;													// ?? 1?
	int miVal;													// ???
} Score;

// ????
static FILE *szpFpI;											// ??
static int siJCnt;												// ???
static Score sz1Score[D_SCORE_MAX];								// ???
static int siSCnt;												// ????

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
	Score *lzpVal1 = (Score *)pzpVal1;
	Score *lzpVal2 = (Score *)pzpVal2;

	// ????
	if (lzpVal1->miJNo > lzpVal2->miJNo) {
		return(1);
	}
	else if (lzpVal1->miJNo < lzpVal2->miJNo) {
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

	// ??? - ???
	siSCnt = 0;													// ????

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

	// ??????? - ??
	int liDCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liDCnt, &siJCnt);

	// ????????? - ??
	long long llSum = 0;
	for (i = 0; i < liDCnt; i++) {
		int liJNo1, liJNo2, liScore;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d", &liJNo1, &liJNo2, &liScore);

		// ?????????
		sz1Score[siSCnt].miJNo = liJNo1;
		sz1Score[siSCnt].miVal = -liScore;
		siSCnt++;

		// ?????????
		sz1Score[siSCnt].miJNo = liJNo2 + 1;
		sz1Score[siSCnt].miVal = liScore;
		siSCnt++;

		// ?????
		llSum += (long long)liScore;
	}

	// ??? - ???
	qsort(sz1Score, siSCnt, sizeof(Score), fSortFnc);

	// ???????
	long long llNow = llSum;
	long long llMax = 0;
	int liSNo = 0;
	for (i = 1; i <= siJCnt; i++) {

		// ??????????
		while (liSNo < siSCnt) {
			if (sz1Score[liSNo].miJNo < i) {					// ?
			}
			else if (sz1Score[liSNo].miJNo == i) {				// ??
				llNow += (long long)sz1Score[liSNo].miVal;
			}
			else {												// ?
				break;
			}

			// ??
			liSNo++;
		}

		// ???????
		if (llMax < llNow) {
			llMax = llNow;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llMax);

	// ?? - ??
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
./Main.c:75:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:82:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^