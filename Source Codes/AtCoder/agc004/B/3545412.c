#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SLIME_MAX		2000									// ???????

// ????
static FILE *szpFpI;											// ??
static int siSCnt;												// ?????
static int siMagic;												// ????
static long long sl2Time[D_SLIME_MAX + 5][D_SLIME_MAX];			// ????[????][????]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???????
long long
fGetLtl(
	long long plVal1			// <I> ??
	, long long plVal2			// <I> ??
)
{
	if (plVal1 < plVal2) {
		return plVal1;
	}
	else {
		return plVal2;
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

	// ?????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSCnt, &siMagic);

	// ????[????][??0] - ??
	for (i = 1; i <= siSCnt; i++) {
		fscanf(szpFpI, "%lld", &sl2Time[i][0]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ????[????][????] - ???
	int liSNo, liMCnt;
	for (liSNo = 1; liSNo <= siSCnt; liSNo++) {
		for (liMCnt = 1; liMCnt < siSCnt; liMCnt++) {

			// ??????
			int liCNo = (liSNo - liMCnt - 1 + siSCnt) % siSCnt + 1;

			// ???????????
			sl2Time[liSNo][liMCnt] = fGetLtl(sl2Time[liSNo][liMCnt - 1], sl2Time[liCNo][0]);
		}
	}

	// ???? - ??
	long long llMin = LLONG_MAX;
	for (liMCnt = 0; liMCnt < siSCnt; liMCnt++) {
		long long llSum = (long long)siMagic * (long long)liMCnt;
		for (liSNo = 1; liSNo <= siSCnt; liSNo++) {
			llSum += sl2Time[liSNo][liMCnt];
		}

		// ???? - ??
		if (llMin > llSum) {
			llMin = llSum;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llMin);

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ??????
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
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
./Main.c:59:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:64:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%lld", &sl2Time[i][0]);
   ^
./Main.c:66:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^