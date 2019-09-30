#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_RAIN_MAX		30000									// ????
#define D_RAIN_START	0										// ? - ??
#define D_RAIN_END		1										// ? - ??

// ????? - ???
typedef struct Rain {
	int miType;													// ?? or ??
	int miHhMm;													// ??
} Rain;

// ????
static FILE *szpFpI;											// ??
static Rain sz1Rain[D_RAIN_MAX * 2];							// ?
static int siRCnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ???? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Rain *lzpVal1 = (Rain *)pzpVal1;
	Rain *lzpVal2 = (Rain *)pzpVal2;

	// ????
	if (lzpVal1->miHhMm > lzpVal2->miHhMm) {
		return(1);
	}
	else if (lzpVal1->miHhMm < lzpVal2->miHhMm) {
		return(-1);
	}

	// ????
	if (lzpVal1->miType > lzpVal2->miType) {
		return(1);
	}
	else if (lzpVal1->miType < lzpVal2->miType) {
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
	siRCnt = 0;													// ??

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

	// ?? - ??
	int liLCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liLCnt);

	// ? - ??
	for (i = 0; i < liLCnt; i++) {
		int liHhMm1, liHhMm2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d-%d", &liHhMm1, &liHhMm2);

		// ??
		liHhMm1 = (liHhMm1 / 5) * 5;
		liHhMm2 = ((liHhMm2 + 4) / 5) * 5;
		if (liHhMm2 % 100 == 60) {
			liHhMm2 = (liHhMm2 / 100 + 1) * 100;
		}

		// ? - ???
		sz1Rain[siRCnt].miType = D_RAIN_START;
		sz1Rain[siRCnt].miHhMm = liHhMm1;
		siRCnt++;
		sz1Rain[siRCnt].miType = D_RAIN_END;
		sz1Rain[siRCnt].miHhMm = liHhMm2;
		siRCnt++;
	}

	// ? - ???
	qsort(sz1Rain, siRCnt, sizeof(Rain), fSortFnc);

	// ? - ??
	int liRCnt = 0;
	for (i = 0; i < siRCnt; i++) {
		if (sz1Rain[i].miType == D_RAIN_START) {				// ??
			liRCnt++;
			if (liRCnt == 1) {										// ??
				sprintf(lc1Out, "%04d-", sz1Rain[i].miHhMm);
			}
		}
		else {													// ??
			liRCnt--;
			if (liRCnt == 0) {										// ??
				sprintf(lc1Buf, "%04d\n", sz1Rain[i].miHhMm);
				strcat(lc1Out, lc1Buf);

				// ?? - ??
#ifdef D_TEST
				fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
				if (strcmp(lc1Buf, lc1Out)) {
					siRes = -1;
				}
#else
				printf("%s", lc1Out);
#endif
			}
		}
	}

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
./Main.c:84:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:90:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^