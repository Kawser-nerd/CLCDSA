#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TV_MAX		100000									// ????????
#define D_CH_MAX		30										// ????????

// ????? - ????
typedef struct Time {
	int miTime;													// ??
	int miType;													// ??? [0]:?? [1]:??
} Time;

// ????
static int si2Time[D_CH_MAX][D_TV_MAX * 2];						// ????????
static int si1TCnt[D_CH_MAX];									// ?????????
static Time sz1Time[D_TV_MAX * 2];								// ???
static int siTCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - int??
int
fSortFncInt(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	int *lipVal1 = (int *)pzpVal1;
	int *lipVal2 = (int *)pzpVal2;

	// ??
	if (*lipVal1 >  *lipVal2) {
		return(1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(-1);
	}

	return 0;
}

// ????? - ???? - ?????
int
fSortFncTime(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Time *lzpVal1 = (Time *)pzpVal1;
	Time *lzpVal2 = (Time *)pzpVal2;

	// ????
	if (lzpVal1->miTime > lzpVal2->miTime) {
		return(1);
	}
	else if (lzpVal1->miTime < lzpVal2->miTime) {
		return(-1);
	}

	// ?????
	if (lzpVal1->miType > lzpVal2->miType) {
		return(-1);
	}
	else if (lzpVal1->miType < lzpVal2->miType) {
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
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(si1TCnt, 0, sizeof(si1TCnt));						// ?????????
	siTCnt = 0;													// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????????????
	int liTCnt, liCCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liTCnt, &liCCnt);

	// ???????
	for (i = 0; i < liTCnt; i++) {
		int liStart, liEnd, liCh;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &liStart, &liEnd, &liCh);
		liCh--;

		// ???????? - ???
		si2Time[liCh][si1TCnt[liCh]] = liStart;
		si1TCnt[liCh]++;
		si2Time[liCh][si1TCnt[liCh]] = liEnd;
		si1TCnt[liCh]++;
	}

	// ???????? - ???
	for (i = 0; i < liCCnt; i++) {
		qsort(si2Time[i], si1TCnt[i], sizeof(int), fSortFncInt);
	}

	// ??? - ???
	for (i = 0; i < liCCnt; i++) {

		// ?????
		int liType = 0;										// ????

		// ??????????
		for (j = 0; j < si1TCnt[i]; j++) {
			if (liType == 0) {									// ????
				sz1Time[siTCnt].miType = 0;
				sz1Time[siTCnt].miTime = si2Time[i][j] * 2 - 1;
			}
			else {												// ????

				// ??????
				if (j < si1TCnt[i] - 1) {
					if (si2Time[i][j] == si2Time[i][j + 1]) {			// ?????????
						j++;												// ???????????
						continue;
					}
				}

				sz1Time[siTCnt].miType = 1;
				sz1Time[siTCnt].miTime = si2Time[i][j] * 2;
			}
			siTCnt++;

			// ???????
			liType = (liType + 1) % 2;
		}
	}

	// ??? - ???
	qsort(sz1Time, siTCnt, sizeof(Time), fSortFncTime);

	// ???? - ??
	int liMax = 0;
	int liCnt = 0;
	for (i = 0; i < siTCnt; i++) {
		if (sz1Time[i].miType == 0) {						// ????
			liCnt++;

			// ??????
			if (liMax < liCnt) {
				liMax = liCnt;
			}
		}
		else {												// ????
			liCnt--;
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", liMax);

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
./Main.c:107:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:117:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^