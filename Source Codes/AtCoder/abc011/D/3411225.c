#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static int siJCnt;												// ?????
static int siLen;												// ??
static int siX;													// ?????X
static int siY;													// ?????Y

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??
double
fDiv(
	double *pdpRate				// <IO> ??
	, int *pipXPCnt				// <IO> ????? - X+
	, int *pipXMCnt				// <IO> ????? - X-
	, int *pipYPCnt				// <IO> ????? - Y+
	, int *pipYMCnt				// <IO> ????? - Y-
	, int *pipAllCnt			// <IO> ??????
)
{
	if (*pipXPCnt > 1) {
		*pdpRate /= (double)*pipXPCnt;
		(*pipXPCnt)--;
		return 1;
	}
	if (*pipXMCnt > 1) {
		*pdpRate /= (double)*pipXMCnt;
		(*pipXMCnt)--;
		return 1;
	}
	if (*pipYPCnt > 1) {
		*pdpRate /= (double)*pipYPCnt;
		(*pipYPCnt)--;
		return 1;
	}
	if (*pipYMCnt > 1) {
		*pdpRate /= (double)*pipYMCnt;
		(*pipYMCnt)--;
		return 1;
	}
	if (*pipAllCnt > 0) {
		*pdpRate /= 4.0;
		(*pipAllCnt)--;
		return 1;
	}

	return 0;
}

// ?? - ??
//		??????? = siJCnt! / piXPCnt! / piXMCnt! / piYPCnt! / piYMCnt!
//		?????? = 4?siJCnt?
double
fGetRate(
	int piXPCnt					// <I> ????? - X+
	, int piXMCnt				// <I> ????? - X-
	, int piYPCnt				// <I> ????? - Y+
	, int piYMCnt				// <I> ????? - Y-
)
{
	// ???????
	int liSum = siJCnt;

	// ??????
	int liAllCnt = siJCnt;

	// ??
	double ldRate = 1.0;
	while (liSum > 1) {
		ldRate *= (double)liSum;
		liSum--;

		// ??
		while (ldRate > 1.0) {
			fDiv(&ldRate, &piXPCnt, &piXMCnt, &piYPCnt, &piYMCnt, &liAllCnt);
		}
	}
	
	// ??
	while (fDiv(&ldRate, &piXPCnt, &piXMCnt, &piYPCnt, &piYMCnt, &liAllCnt)) {
	}

	return ldRate;
}

// ??
double
fCalc(
)
{
	// ??????? - X
	if (siX % siLen != 0) {
		return 0.0;
	}
	int liXPCnt = siX / siLen;

	// ??????? - Y
	if (siY % siLen != 0) {
		return 0.0;
	}
	int liYPCnt = siY / siLen;

	// ??????? - ??
	int liSum = liXPCnt + liYPCnt;

	// ????????
	if (siJCnt < liSum) {
		return 0.0;
	}
	if ((siJCnt - liSum) % 2 != 0) {
		return 0.0;
	}

	// ??
	double ldRate = 0.0;
	int liXMCnt = 0;
	while (liXPCnt + liXMCnt <= siJCnt - liYPCnt) {

		// ??????? - Y
		int liYSCnt = siJCnt - liYPCnt - liXPCnt - liXMCnt;

		// ?? - ??
		ldRate += fGetRate(liXPCnt, liXMCnt, liYPCnt + liYSCnt / 2, liYSCnt / 2);

		// ???????
		liXPCnt++;
		liXMCnt++;
	}

	return ldRate;
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

	// ???????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siJCnt, &siLen);

	// ????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siX, &siY);
	siX = abs(siX);
	siY = abs(siY);

	// ??
	double ldRate = fCalc();

	// ?? - ???
	sprintf(lc1Out, "%.15lf\n", ldRate);

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
./Main.c:164:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:168:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^