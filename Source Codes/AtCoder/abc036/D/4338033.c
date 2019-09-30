#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_ILD_MAX		100000									// ????
#define D_BRD_MAX		200000									// ????

// ????? - ???
typedef struct Brd {
	int miINo;													// ? 0?
	struct Brd *mzpNext;										// ???
} Brd;

// ????? - ???
typedef struct Ild {
	Brd *mzpBrd;												// ?
	int miDone;													// ??????
} Ild;

// ????
static FILE *szpFpI;											// ??
static Brd sz1Brd[D_BRD_MAX];									// ?
static int siBCnt;												// ??
static Ild sz1Ild[D_ILD_MAX];									// ?
static int siICnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ? - ??
int
fAddBrd(
	int piIFNo					// <I> ? - ? 0?
	, int piITNo				// <I> ? - ? 0?
)
{
	Brd *lzpBrd = &sz1Brd[siBCnt];
	lzpBrd->miINo = piITNo;
	lzpBrd->mzpNext = sz1Ild[piIFNo].mzpBrd;
	sz1Ild[piIFNo].mzpBrd = lzpBrd;
	siBCnt++;

	return 0;
}

// ????? - ??
int
fGetPtn(
	int piINo					// <I> ? 0?
	, long long *plpWCnt		// <O> ?????????
	, long long *plpBCnt		// <O> ?????????
)
{
	int liRet;

	// ??????
	if (sz1Ild[piINo].miDone != D_OFF) {
		return -1;
	}
	sz1Ild[piINo].miDone = D_ON;

	// ???
	*plpWCnt = 1;
	*plpBCnt = 1;

	// ??
	Brd *lzpBrd = sz1Ild[piINo].mzpBrd;
	while (lzpBrd != NULL) {

		// ???
		long long llWCnt, llBCnt;
		liRet = fGetPtn(lzpBrd->miINo, &llWCnt, &llBCnt);
		
		// ????? - ??
		if (liRet == 0) {
			*plpWCnt *= llWCnt + llBCnt;
			*plpWCnt %= D_MOD;
			*plpBCnt *= llWCnt;
			*plpBCnt %= D_MOD;
		}

		// ????
		lzpBrd = lzpBrd->mzpNext;
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

	// ??????
	memset(sz1Ild, 0, sizeof(sz1Ild));							// ?
	siBCnt = 0;													// ??

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
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siICnt);

	// ? - ??
	for (i = 0; i < siICnt - 1; i++) {
		int liINo1, liINo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liINo1, &liINo2);
		liINo1--;
		liINo2--;

		// ? - ??
		fAddBrd(liINo1, liINo2);
		fAddBrd(liINo2, liINo1);
	}

	// ????? - ??
	long long llWCnt, llBCnt;
	fGetPtn(0, &llWCnt, &llBCnt);
	llWCnt += llBCnt;
	llWCnt %= D_MOD;

	// ?????
	sprintf(lc1Out, "%lld\n", llWCnt);

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
./Main.c:124:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:130:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^