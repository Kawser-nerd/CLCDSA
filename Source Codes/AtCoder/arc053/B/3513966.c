#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STR_MAX		100000									// ?????
#define D_CHAR_CNT		26										// ?????

// ????
static FILE *szpFpI;											// ??
static char sc1Str[D_STR_MAX + 5];								// ???
static int si1CCnt[D_CHAR_CNT];									// ??[??]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1CCnt, 0, sizeof(si1CCnt));						// ??[??]

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

	// ??? - ??
	fgets(sc1Str, sizeof(sc1Str), szpFpI);

	// ??[??] - ???
	for (i = 0; ; i++) {
		int liNo = sc1Str[i] - 'a';
		if (liNo < 0 || 26 <= liNo) {
			break;
		}
		else {
			si1CCnt[liNo]++;
		}
	}

	// ????????????????? - ??
	int liOKCnt = 0;
	int liNGCnt = 0;
	for (i = 0; i < D_CHAR_CNT; i++) {
		if (si1CCnt[i] % 2 == 0) {
			liOKCnt += si1CCnt[i];
		}
		else {
			liOKCnt += si1CCnt[i] - 1;
			liNGCnt++;
		}
	}

	// ?????
	int liMax;
	if (liNGCnt > 1) {
		liMax = (liOKCnt / 2 / liNGCnt) * 2 + 1;
	}
	else {
		liMax = liOKCnt + liNGCnt;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liMax);

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
./Main.c:47:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1Str, sizeof(sc1Str), szpFpI);
  ^