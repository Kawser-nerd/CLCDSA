#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_NORM_MAX		1000									// ??????
#define D_WAY_CNT		2										// ???
#define D_WAY_X			0										// ?? - X
#define D_WAY_Y			1										// ?? - Y
#define D_TRY_CNT		100										// ????

// ????
static FILE *szpFpI;											// ??
static int siNCnt;												// ????
static int si2Pos[D_WAY_CNT][D_NORM_MAX];						// ??[??][???]
static int si1Cost[D_NORM_MAX];									// ???[???]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?? - ??
double
fGetTime(
	int piWNo					// <I> ??
	, double pdPos				// <I> ??
)
{
	int i;

	// ???? - ??
	double ldMax = DBL_MIN;
	for (i = 0; i < siNCnt; i++) {
		double ldLen = fabs(pdPos - (double)si2Pos[piWNo][i]) * (double)si1Cost[i];
		if (ldMax < ldLen) {
			ldMax = ldLen;
		}
	}

	return ldMax;
}

// ???? - ??
double
fGetTimeMin(
	int piWNo					// <I> ??
	, double pdPosS				// <I> ???? - ??
	, double pdPosE				// <I> ???? - ??
)
{
	int i;

	// ??
	double ldTimeS, ldTimeE;
	for (i = 0; i < D_TRY_CNT; i++) {

		// ??
		double ldSep = (pdPosE - pdPosS) / 3.0;

		// ??????
		double ldPosS = pdPosS + ldSep;
		double ldPosE = pdPosE - ldSep;

		// ?? - ??
		ldTimeS = fGetTime(piWNo, ldPosS);
		ldTimeE = fGetTime(piWNo, ldPosE);

		// ?? - ??
		if (ldTimeS < ldTimeE) {
			pdPosE = ldPosE;
		}
		else if (ldTimeS > ldTimeE) {
			pdPosS = ldPosS;
		}
		else {
			pdPosS = ldPosS;
			pdPosE = ldPosE;
		}
	}

	return (ldTimeS + ldTimeE) / 2.0;
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

	// ???? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siNCnt);

	// ?????????????? - ??
	int li1Max[D_WAY_CNT], li1Min[D_WAY_CNT];
	li1Max[D_WAY_X] = INT_MIN;
	li1Max[D_WAY_Y] = INT_MIN;
	li1Min[D_WAY_X] = INT_MAX;
	li1Min[D_WAY_Y] = INT_MAX;
	for (i = 0; i < siNCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d", &si2Pos[D_WAY_X][i], &si2Pos[D_WAY_Y][i], &si1Cost[i]);

		// ??????? - ??
		for (j = 0; j < D_WAY_CNT; j++) {
			if (li1Max[j] < si2Pos[j][i]) {
				li1Max[j] = si2Pos[j][i];
			}
			if (li1Min[j] > si2Pos[j][i]) {
				li1Min[j] = si2Pos[j][i];
			}
		}
	}

	// ???? - ??
	double ldMinX = fGetTimeMin(D_WAY_X, (double)li1Min[D_WAY_X], (double)li1Max[D_WAY_X]);
	double ldMinY = fGetTimeMin(D_WAY_Y, (double)li1Min[D_WAY_Y], (double)li1Max[D_WAY_Y]);

	// ?? - ???
	if (ldMinX < ldMinY) {
		sprintf(lc1Out, "%.5lf\n", ldMinY);
	}
	else {
		sprintf(lc1Out, "%.5lf\n", ldMinX);
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
./Main.c:111:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:121:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^