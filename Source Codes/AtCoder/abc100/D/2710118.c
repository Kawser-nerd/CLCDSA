#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CAKE_MAX		1000									// ??????

// ????? - ???
typedef struct Cake {
	long long mlBty;											// ???
	long long mlDlc;											// ????
	long long mlPpr;											// ???
} Cake;

// ????
static Cake sz1Cake[D_CAKE_MAX];								// ???
static int siCCnt;												// ????
static int siSCnt;												// ???
static long long slSortBty;										// ????? - ???
static long long slSortDlc;										// ????? - ????
static long long slSortPpr;										// ????? - ???

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
	Cake *lzpVal1 = (Cake *)pzpVal1;
	Cake *lzpVal2 = (Cake *)pzpVal2;

	// ??
	long long llSum1 = lzpVal1->mlBty * slSortBty + lzpVal1->mlDlc * slSortDlc + lzpVal1->mlPpr * slSortPpr;
	long long llSum2 = lzpVal2->mlBty * slSortBty + lzpVal2->mlDlc * slSortDlc + lzpVal2->mlPpr * slSortPpr;

	// ????
	if (llSum1 > llSum2) {
		return(-1);
	}
	else if (llSum1 < llSum2) {
		return(1);
	}

	return 0;
}

// ?????
long long
fUpMax(
	long long plMax				// <I> ?????
	, int piBty					// <I> ????? - ???
	, int piDlc					// <I> ????? - ????
	, int piPpr					// <I> ????? - ???
)
{
	int i;

	// ?????
	slSortBty = piBty;
	slSortDlc = piDlc;
	slSortPpr = piPpr;

	// ???
	qsort(sz1Cake, siCCnt, sizeof(Cake), fSortFnc);

	// ???
	long long llBty = 0;
	long long llDlc = 0;
	long long llPpr = 0;
	for (i = 0; i < siSCnt; i++) {
		llBty += sz1Cake[i].mlBty;
		llDlc += sz1Cake[i].mlDlc;
		llPpr += sz1Cake[i].mlPpr;
	}

	// ???
	long long llSum = llabs(llBty) + llabs(llDlc) + llabs(llPpr);
	if (llSum < plMax) {
		return plMax;
	}
	else {
		return llSum;
	}
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

	// ??????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siCCnt, &siSCnt);

	// ?????
	for (i = 0; i < siCCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%lld%lld%lld", &sz1Cake[i].mlBty, &sz1Cake[i].mlDlc, &sz1Cake[i].mlPpr);
	}

	// ???
	long long llMax = 0;
	llMax = fUpMax(llMax, 1, 1, 1);
	llMax = fUpMax(llMax, 1, 1, -1);
	llMax = fUpMax(llMax, 1, -1, 1);
	llMax = fUpMax(llMax, 1, -1, -1);
	llMax = fUpMax(llMax, -1, 1, 1);
	llMax = fUpMax(llMax, -1, 1, -1);
	llMax = fUpMax(llMax, -1, -1, 1);
	llMax = fUpMax(llMax, -1, -1, -1);

	// ?????
	sprintf(lc1Out, "%lld\n", llMax);

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
./Main.c:118:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:127:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^