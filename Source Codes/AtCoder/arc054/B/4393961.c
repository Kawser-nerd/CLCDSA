#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TRY_CNT		200										// ????

// ????
static FILE *szpFpI;											// ??
static double sdYear;											// ????
static double sdMin;											// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? - ??
double
fGetNTime(
	double pdTime				// <I> ????
)
{
	// ????
	double ldTime = pdTime + sdYear / pow(2.0, pdTime / 1.5);

	// ???? - ??
	if (sdMin > ldTime) {
		sdMin = ldTime;
	}

	return ldTime;
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
	sdMin = DBL_MAX;											// ????

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

	// ???? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lf", &sdYear);

	// ??????
	double ldTimeS = 0.0;
	double ldTimeE = sdYear;

	// ??
	for (i = 0; i < D_TRY_CNT; i++) {

		// ??
		double ldSep = (ldTimeE - ldTimeS) / 3.0;

		// ??????
		double ldCTime1 = ldTimeS + ldSep;
		double ldCTime2 = ldTimeE - ldSep;

		// ???? - ??
		double ldNTime1 = fGetNTime(ldCTime1);
		double ldNTime2 = fGetNTime(ldCTime2);

		// ?????
		if (ldNTime1 < ldNTime2) {
			ldTimeE = ldCTime2;
		}
		else {
			ldTimeS = ldCTime1;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%.9lf\n", sdMin);

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
./Main.c:64:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^