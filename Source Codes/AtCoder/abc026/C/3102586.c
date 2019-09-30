#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SYAIN_MAX		20										// ?????

// ????? - ????
typedef struct Syain {
	int mi1Buka[D_SYAIN_MAX];									// ??
	int miBCnt;													// ???
	int miSal;													// ??
} Syain;

// ????
static Syain sz1Syain[D_SYAIN_MAX + 5];							// ??
static int siSCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(sz1Syain, 0, sizeof(sz1Syain));						// ??

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siSCnt);

	// ?? - ??
	for (i = 2; i <= siSCnt; i++) {
		int liNo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d", &liNo);

		// ?? - ??
		Syain *lzpSyain = &sz1Syain[liNo];
		lzpSyain->mi1Buka[lzpSyain->miBCnt] = i;
		(lzpSyain->miBCnt)++;
	}

	// ?????
	for (i = siSCnt; i >= 1; i--) {
		Syain *lzpSyain = &sz1Syain[i];

		// ?????
		int liMin = 0;
		int liMax = 0;
		for (j = 0; j < lzpSyain->miBCnt; j++) {
			int liBNo = lzpSyain->mi1Buka[j];

			if (liMin == 0 || liMin > sz1Syain[liBNo].miSal) {
				liMin = sz1Syain[liBNo].miSal;
			}
			if (liMax == 0 || liMax < sz1Syain[liBNo].miSal) {
				liMax = sz1Syain[liBNo].miSal;
			}
		}

		// ?????
		lzpSyain->miSal = liMin + liMax + 1;
	}

	// ?????
	sprintf(lc1Out, "%d\n", sz1Syain[1].miSal);

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
./Main.c:53:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:63:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^