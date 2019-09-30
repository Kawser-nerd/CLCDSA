#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STD_MAX		100000									// ?????

// ????? - ????
typedef struct Std {
	int miNo;													// ????
	int miH;													// ??
} Std;

// ????
static Std sz1Std[D_STD_MAX];									// ??
static int siSCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Std *lzpVal1 = (Std *)pzpVal1;
	Std *lzpVal2 = (Std *)pzpVal2;

	// ????
	if (lzpVal1->miH > lzpVal2->miH) {
		return(-1);
	}
	else if (lzpVal1->miH < lzpVal2->miH) {
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
	sscanf(lc1Buf, "%d", &siSCnt);

	// ????
	for (i = 0; i < siSCnt; i++) {
		sz1Std[i].miNo = i + 1;
#ifdef D_TEST
		fscanf(szpFpT, "%d", &sz1Std[i].miH);
#else
		fscanf(stdin, "%d", &sz1Std[i].miH);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ???
	qsort(sz1Std, siSCnt, sizeof(Std), fSortFnc);

	// ??
	for (i = 0; i < siSCnt; i++) {
		sprintf(lc1Out, "%d\n", sz1Std[i].miNo);
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
./Main.c:70:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:80:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &sz1Std[i].miH);
   ^
./Main.c:86:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^