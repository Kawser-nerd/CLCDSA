#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static int siLen;												// ??
static int siSpdR;												// ?? - ??
static int siSpdW;												// ?? - ??
static int siStart;												// ????
static int siGoal;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?? - ??
double
fGetTime(
	int piWay					// <I> ?? 1 or -1
)
{
	// ??
	int liLen = (siGoal - siStart) * piWay;
	if (liLen < 0) {
		liLen += siLen;
	}

	// ??
	int liSpd = siSpdW + siSpdR * piWay;
	if (liSpd <= 0) {
		return (double)INT_MAX;
	}

	// ??
	double ldTime = (double)liLen / (double)liSpd;

	return ldTime;
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

	// ? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d%d", &siLen, &siSpdR, &siSpdW, &siStart, &siGoal);

	// ?? - ??
	double ldTime1 = fGetTime(1);
	double ldTime2 = fGetTime(-1);

	// ?? - ???
	if (ldTime1 < ldTime2) {
		sprintf(lc1Out, "%.10lf\n", ldTime1);
	}
	else {
		sprintf(lc1Out, "%.10lf\n", ldTime2);
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
./Main.c:66:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^