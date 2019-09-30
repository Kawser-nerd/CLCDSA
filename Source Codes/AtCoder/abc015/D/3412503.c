#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CNT_MAX		50										// ????
#define D_IMP_MAX		(100 * D_CNT_MAX)						// ?????

// ????? - ????
typedef struct Img {
	int miW;													// ?
	int miImp;													// ???
	double mdImpW;												// ???/?
} Img;

// ????
static FILE *szpFpI;											// ??
static int siW;													// ?
static int siPCnt;												// ?????
static Img sz1Img[D_CNT_MAX];									// ??
static int siICnt;												// ???
static int si3W[D_CNT_MAX][D_CNT_MAX + 5][D_IMP_MAX + 5];		// ???[???][?????][???]
static int siImp;												// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ???/???
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Img *lzpVal1 = (Img *)pzpVal1;
	Img *lzpVal2 = (Img *)pzpVal2;

	// ???/???
	if (lzpVal1->mdImpW > lzpVal2->mdImpW) {
		return(-1);
	}
	else if (lzpVal1->mdImpW < lzpVal2->mdImpW) {
		return(1);
	}

	return 0;
}

// ????? - ???
int
fSetImp(
	int piINo					// <I> ?? 0?
	, int piW					// <I> ???
	, int piPCnt				// <I> ?????
	, int piImp					// <I> ?????
)
{
	// ??? - ????
	if (piW > siW) {
		return 0;
	}

	// ????? - ????
	if (piPCnt > siPCnt) {
		return 0;
	}

	// ????? - ??
	if (siImp < piImp) {
		siImp = piImp;
	}

	// ?? - ????
	if (piINo >= siICnt) {
		return 0;
	}

	// ????? - ??
	if (piPCnt > 0) {
		if (si3W[piINo][piPCnt][piImp] <= piW) {
			return 0;
		}
	}
	si3W[piINo][piPCnt][piImp] = piW;

	// ??????
	fSetImp(piINo + 1, piW + sz1Img[piINo].miW, piPCnt + 1, piImp + sz1Img[piINo].miImp);

	// ??????
	fSetImp(piINo + 1, piW, piPCnt, piImp);

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

	// ??? - ???
	siImp = 0;													// ?????

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

	// ? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siW);

	// ????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siICnt, &siPCnt);

	// ?? - ??
	for (i = 0; i < siICnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Img[i].miW, &sz1Img[i].miImp);

		// ???/?
		sz1Img[i].mdImpW = (double)sz1Img[i].miImp / (double)sz1Img[i].miW;
	}

	// ?? - ???
	qsort(sz1Img, siICnt, sizeof(Img), fSortFnc);

	// ??? - ???
	for (i = 0; i < D_CNT_MAX; i++) {
		for (j = 0; j <= D_CNT_MAX; j++) {
			for (k = 0; k <= D_IMP_MAX; k++) {
				si3W[i][j][k] = INT_MAX;
			}
		}
	}

	// ????? - ???
	fSetImp(0, 0, 0, 0);

	// ?? - ???
	sprintf(lc1Out, "%d\n", siImp);

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
./Main.c:125:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:129:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:134:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^