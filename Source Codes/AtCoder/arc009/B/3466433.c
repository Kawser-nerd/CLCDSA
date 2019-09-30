#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_NUM_MAX		777										// ?????
#define D_NUM_LEN		9										// ?????

// ????? - ????
typedef struct Num {
	char mc1Num[D_NUM_LEN + 5];									// ??
	int miChg;													// ??????
} Num;

// ????
static FILE *szpFpI;											// ??
static char sc1Chg[10];											// ??????
static Num sz1Num[D_NUM_MAX];									// ??
static int siNCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ????????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Num *lzpVal1 = (Num *)pzpVal1;
	Num *lzpVal2 = (Num *)pzpVal2;

	// ????????
	if (lzpVal1->miChg > lzpVal2->miChg) {
		return(1);
	}
	else if (lzpVal1->miChg < lzpVal2->miChg) {
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
	int i, j;
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

	// ?????? - ??
	for (i = 0; i < 10; i++) {
		int liNo;
		fscanf(szpFpI, "%d", &liNo);
		sc1Chg[liNo] = i + '0';
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siNCnt);

	// ?? - ??
	for (i = 0; i < siNCnt; i++) {
		fgets(sz1Num[i].mc1Num, sizeof(sz1Num[i].mc1Num), szpFpI);
		
		// ??
		for (j = 0; ; j++) {
			int liNo = sz1Num[i].mc1Num[j] - '0';
			if (0 <= liNo && liNo <= 9) {
				lc1Buf[j] = sc1Chg[liNo];
			}
			else {
				sz1Num[i].mc1Num[j] = '\0';
				lc1Buf[j] = '\0';
				sscanf(lc1Buf, "%d", &sz1Num[i].miChg);
				break;
			}
		}
	}

	// ?? - ???
	qsort(sz1Num, siNCnt, sizeof(Num), fSortFnc);

	// ?? - ??
	for (i = 0; i < siNCnt; i++) {
		sprintf(lc1Out, "%s\n", sz1Num[i].mc1Num);
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
./Main.c:74:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liNo);
   ^
./Main.c:77:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:80:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:85:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sz1Num[i].mc1Num, sizeof(sz1Num[i].mc1Num), szpFpI);
   ^