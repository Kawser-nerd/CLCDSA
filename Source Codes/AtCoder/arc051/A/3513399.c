#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static int siCx, siCy;											// ?? - ????
static int siR;													// ?? - ??
static int siSx, siSy;											// ???? - ????
static int siEx, siEy;											// ???? - ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????????
int
fRInB(
)
{
	// ??
	if (siCx - siR < siSx) {
		return -1;
	}

	// ??
	if (siCy - siR < siSy) {
		return -1;
	}

	// ??
	if (siCx + siR > siEx) {
		return -1;
	}

	// ??
	if (siCy + siR > siEy) {
		return -1;
	}

	return 0;
}

// ??????????? - ???
int
fBInROne(
	int piX						// <I> ??X
	, int piY					// <I> ??Y
)
{
	// ??
	double ldX = (double)(siCx - piX);
	double ldY = (double)(siCy - piY);
	double ldLen = sqrt(ldX * ldX + ldY * ldY);

	// ?????
	if (ldLen > (double)siR) {
		return -1;
	}

	return 0;
}

// ???????????
int
fBInR(
)
{
	int liRet;

	// ????
	liRet = fBInROne(siSx, siSy);
	if (liRet != 0) {
		return -1;
	}

	// ????
	liRet = fBInROne(siEx, siSy);
	if (liRet != 0) {
		return -1;
	}

	// ????
	liRet = fBInROne(siEx, siEy);
	if (liRet != 0) {
		return -1;
	}

	// ????
	liRet = fBInROne(siSx, siEy);
	if (liRet != 0) {
		return -1;
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int liRet;
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
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siCx, &siCy, &siR);

	// ???? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d", &siSx, &siSy, &siEx, &siEy);

	// ?????????
	liRet = fRInB();
	if (liRet == 0) {
		sprintf(lc1Out, "NO\n");
	}
	else {
		sprintf(lc1Out, "YES\n");
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ???????????
	liRet = fBInR();
	if (liRet == 0) {
		sprintf(lc1Out, "NO\n");
	}
	else {
		sprintf(lc1Out, "YES\n");
	}
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
./Main.c:124:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:128:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^