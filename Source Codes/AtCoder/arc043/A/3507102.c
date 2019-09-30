#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static int siCnt;												// ??
static int siAvg;												// ??
static int siDF;												// ?
static int siMax;												// ???
static int siMin;												// ???
static long long slSum;											// ??
static double sdMVal;											// ???
static double sdAVal;											// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??
int
fCalc(
)
{
	// ????
	int liDF = siMax - siMin;
	if (liDF == 0) {
		return -1;
	}

	// ???
	sdMVal = (double)siDF / (double)liDF;

	// ???
	double ldAvg = (double)slSum * sdMVal / (double)siCnt;

	// ???
	sdAVal = (double)siAvg - ldAvg;

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
	siMax = INT_MIN;											// ???
	siMin = INT_MAX;											// ???
	slSum = 0;													// ??

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

	// ??????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siCnt, &siAvg, &siDF);

	// ?????????? - ??
	for (i = 0; i < siCnt; i++) {

		// ?? - ??
		int liVal;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &liVal);

		// ???
		if (siMax < liVal) {
			siMax = liVal;
		}

		// ???
		if (siMin > liVal) {
			siMin = liVal;
		}

		// ??
		slSum += (long long)liVal;
	}

	// ??
	int liRet = fCalc();

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "%.8lf %.8lf\n", sdMVal, sdAVal);
	}
	else {
		sprintf(lc1Out, "-1\n");
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
./Main.c:74:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:82:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^