#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		50										// ?????

// ????? - ????
typedef struct Vtx {
	int miX;													// ???
	int miY;													// ???
} Vtx;

// ????
static Vtx sz1Vtx[D_VTX_MAX];									// ????
static int siVCnt;												// ?????
static int siNCnt;												// ?????
static long long slMin;											// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?????
int
fSortFncX(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Vtx *lzpVal1 = (Vtx *)pzpVal1;
	Vtx *lzpVal2 = (Vtx *)pzpVal2;

	// ?????
	if (lzpVal1->miX > lzpVal2->miX) {
		return(1);
	}
	else if (lzpVal1->miX < lzpVal2->miX) {
		return(-1);
	}

	return 0;
}

// ????? - int??
int
fSortFncI(
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

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, k;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	slMin = LLONG_MAX;											// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siVCnt, &siNCnt);

	// ??????
	for (i = 0; i < siVCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Vtx[i].miX, &sz1Vtx[i].miY);
	}

	// ???????
	qsort(sz1Vtx, siVCnt, sizeof(Vtx), fSortFncX);

	// ?????
	for (i = 0; i < siVCnt - siNCnt + 1; i++) {
		for (j = i + siNCnt - 1; j < siVCnt; j++) {

			// ??????
			int liYCnt = j - i + 1;
			int li1Y[D_VTX_MAX];
			for (k = 0; k < liYCnt; k++) {
				li1Y[k] = sz1Vtx[i + k].miY;
			}

			// ???????
			qsort(li1Y, liYCnt, sizeof(int), fSortFncI);
			
			// ?????
			for (k = 0; k < liYCnt - siNCnt + 1; k++) {

				// ??
				long long llArea = (long long)(sz1Vtx[j].miX - sz1Vtx[i].miX) * (long long)(li1Y[k + siNCnt - 1] - li1Y[k]);
				if (slMin > llArea) {
					slMin = llArea;
				}
			}
		}
	}

	// ?????
	sprintf(lc1Out, "%lld\n", slMin);

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
./Main.c:96:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:105:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^