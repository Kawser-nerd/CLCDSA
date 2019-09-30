#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_NG_CNT		3										// NG?
#define D_TRY_CNT		100										// ????
#define D_DEL_MAX		3										// ?????

// ????
static FILE *szpFpI;											// ??
static int si1NG[D_NG_CNT];										// NG

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// NG??
int
fChkNG(
	int piVal					// <I> ?
)
{
	int i;

	for (i = 0; i < D_NG_CNT; i++) {
		if (piVal == si1NG[i]) {
			return -1;
		}
	}

	return 0;
}

// ??
int
fJudge(
	int piVal					// <I> ?
)
{
	int i, j, liRet;

	// NG??
	liRet = fChkNG(piVal);
	if (liRet != 0) {
		return -1;
	}

	// ??
	for (i = 0; i < D_TRY_CNT; i++) {

		// ??
		for (j = D_DEL_MAX; j > 0; j--) {
			liRet = fChkNG(piVal - j);
			if (liRet == 0) {
				piVal -= j;
				break;
			}
		}
	}

	// ????
	if (piVal > 0) {
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
	int i, liRet;
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
	int liVal;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liVal);

	// NG - ??
	for (i = 0; i < D_NG_CNT; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &si1NG[i]);
	}

	// ??
	liRet = fJudge(liVal);

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "YES\n");
	}
	else {
		sprintf(lc1Out, "NO\n");
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
./Main.c:97:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:102:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^