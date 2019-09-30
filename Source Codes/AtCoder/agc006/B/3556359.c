#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_NUM_MAX		200000									// ?????

// ????
static FILE *szpFpI;											// ??
static int siSCnt;												// ??
static int siTop;												// ?????
static int si1Num[D_NUM_MAX];									// ??
static int siNCnt;												// ???
static int si1Set[D_NUM_MAX + 5];								// ????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ? - ???
int
fSetVal(
	int piNo					// <I> ????? 0?
	, int piVal					// <I> ? 1?
)
{
	// ???
	si1Num[piNo] = piVal;

	// ????????
	si1Set[piVal] = D_ON;

	return 0;
}

// ??
int
fJudge(
)
{
	int i;

	// ???
	siNCnt = 2 * siSCnt - 1;

	// ??????
	if (siTop == 1 || siTop == siNCnt) {
		return -1;
	}

	// ?? - ??? - ???
	if (siSCnt == 2) {						// ??
		fSetVal(0, 1);
		fSetVal(1, 2);
		fSetVal(2, 3);
	}
	else if (siTop == 2) {					// ??? = 2	x x x ... 3 1 2 4 x x x ...
		fSetVal(siSCnt - 3, 3);
		fSetVal(siSCnt - 2, 1);
		fSetVal(siSCnt - 1, 2);
		fSetVal(siSCnt, 4);
	}
	else {									// ???		x x x ... ? ? Top ? x x x ...
		fSetVal(siSCnt - 3, siTop - 1);
		fSetVal(siSCnt - 2, siTop + 1);
		fSetVal(siSCnt - 1, siTop);
		fSetVal(siSCnt, siTop - 2);
	}

	// ?? - ??? - ???
	int liVal = 1;
	for (i = 0; i < siNCnt; i++) {
		if (si1Num[i] >= 1) {			// ????
			continue;
		}

		// ????
		while (si1Set[liVal] == D_ON) {
			liVal++;
		}

		// ???
		fSetVal(i, liVal);
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
	memset(si1Num, D_OFF, sizeof(si1Num));						// ??
	memset(si1Set, D_OFF, sizeof(si1Set));						// ????????

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

	// ???????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSCnt, &siTop);

	// ??
	int liRet = fJudge();
	if (liRet == 0) {
		sprintf(lc1Out, "Yes\n");
	}
	else {
		sprintf(lc1Out, "No\n");
	}

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// Yes - ??
	if (liRet == 0) {
		for (i = 0; i < siNCnt; i++) {
			sprintf(lc1Out, "%d\n", si1Num[i]);
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
./Main.c:121:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^