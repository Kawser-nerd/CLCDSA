#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TMP_MAX		60										// ????

// ????
static FILE *szpFpI;											// ??
static int si1Cnt[D_TMP_MAX];									// ?????[??]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????[??] - ???
int
fSetCnt(
	int piTmp					// <I> ??
	, int piCnt					// <I> ??
)
{
	// ?????????
	if (piTmp < 1 || D_TMP_MAX <= piTmp) {
		return 0;
	}

	// ??????
	if (si1Cnt[piTmp] <= piCnt) {
		return 0;
	}
	si1Cnt[piTmp] = piCnt;

	// ?????
	piCnt++;
	fSetCnt(piTmp + 10, piCnt);
	fSetCnt(piTmp - 10, piCnt);
	fSetCnt(piTmp + 5, piCnt);
	fSetCnt(piTmp - 5, piCnt);
	fSetCnt(piTmp + 1, piCnt);
	fSetCnt(piTmp - 1, piCnt);

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

	// ????????? - ??
	int liStart, liEnd;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liStart, &liEnd);
	liStart += 10;
	liEnd += 10;

	// ?????[??] - ???
	for (i = 1; i < D_TMP_MAX; i++) {
		si1Cnt[i] = INT_MAX;
	}

	// ?????[??] - ???
	fSetCnt(liStart, 0);
	
	// ?? - ???
	sprintf(lc1Out, "%d\n", si1Cnt[liEnd]);

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
./Main.c:73:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^