#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SEP_MAX		400000									// ??????

// ????
static int si1Sep[D_SEP_MAX + 5];								// ???
static int siSCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static FILE *szpFpT;
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
	char lc1Buf[1024];

	// ??????
	siSCnt = 0;													// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
#endif

	// ??????? - ??
	int liFCnt, liOCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liFCnt, &liOCnt);

	// ??? - ??
	for (i = 0; i < liOCnt; i++) {
		int liNo1, liNo2;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liNo1, &liNo2);
		si1Sep[siSCnt] = liNo1;
		siSCnt++;
		si1Sep[siSCnt] = liNo2 + 1;
		siSCnt++;
	}

	// ??? - ???
	qsort(si1Sep, siSCnt, sizeof(int), fSortFnc);

	// ????
	int liColor = 0;
	int liSNo = 0;
	si1Sep[siSCnt] = 0;								// ????
	for (i = 1; i <= liFCnt; i++) {

		// ???
		while (si1Sep[liSNo] == i) {					// ?????
			liColor = !liColor;								// ???
			liSNo++;										// ????????
		}

		// ??
		printf("%d", liColor);
	}

	// ??
	printf("\n");

	// ???????????
#ifdef D_TEST
	fclose(szpFpT);
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
./Main.c:64:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:74:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^