#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_DIGIT_CNT		19										// ??????
#define D_NG_NUM1		4										// NG??
#define D_NG_NUM2		9										// NG??

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// OK???
int
fGetOKCnt(
	long long plVal				// <I> ?
	, int piDigit				// <I> ?
	, long long *plpRet			// <O> OK?
)
{
	int i;

	// ????OK??
	long long llDiv = 1;
	long long llOK = 1;
	for (i = 1; i < piDigit; i++) {
		llDiv *= 10;
		llOK *= 8;
	}

	// ???????
	long long llNum = plVal / llDiv;

	// ??????
	int liNum = (int)(llNum % 10);

	// OK? - ??????
	int liRet = 0;
	if (piDigit == 1) {
		if (liNum < D_NG_NUM1) {
			*plpRet = liNum + 1;
		}
		else if (liNum < D_NG_NUM2) {
			*plpRet = liNum;
		}
		else {
			*plpRet = liNum - 1;
		}
	}
	else {
		if (liNum < D_NG_NUM1) {
			*plpRet = liNum;
		}
		else if (liNum == D_NG_NUM1) {
			*plpRet = liNum;
			liRet = -1;
		}
		else if (liNum < D_NG_NUM2) {
			*plpRet = liNum - 1;
		}
		else {
			*plpRet = liNum - 1;
			liRet = -1;
		}
		*plpRet *= llOK;
	}

	return liRet;
}

// NG???
long long
fGetNGCnt(
	long long plVal				// <I> ?
)
{
	int i, liRet;

	// OK? - ??
	long long llOK = 0;
	for (i = D_DIGIT_CNT; i >= 1; i--) {
		long long llVal;
		liRet = fGetOKCnt(plVal, i, &llVal);
		llOK += llVal;
		if (liRet != 0) {
			break;
		}
	}

	return plVal - llOK;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
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

	// ?? - ??
	long long llValS, llValE;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%lld", &llValS, &llValE);

	// NG???
	llValS = fGetNGCnt(llValS - 1);
	llValE = fGetNGCnt(llValE);

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llValE - llValS);

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
./Main.c:123:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^