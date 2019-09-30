#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		500										// ?????
#define D_MASS_WHITE	'o'										// ?? - ?

// ????
static FILE *szpFpI;											// ??
static char sc2Rect[D_SIZE_MAX][D_SIZE_MAX + 5];				// ???
static int siRCnt;												// ??
static int siCCnt;												// ??
static int si2Size[D_SIZE_MAX][D_SIZE_MAX];						// ???

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

	// ??????K - ??
	int liK;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siRCnt, &siCCnt, &liK);

	// ??? - ??
	for (i = 0; i < siRCnt; i++) {
		fgets(sc2Rect[i], sizeof(sc2Rect[i]), szpFpI);
	}

	// ??? - ????? - ???
	int liSize;
	for (i = 0; i < siRCnt; i++) {
		liSize = 0;
		for (j = 0; j < siCCnt; j++) {
			if (sc2Rect[i][j] == D_MASS_WHITE) {		// ???
				liSize++;
			}
			else {										// ???
				liSize = 0;
			}
			si2Size[i][j] = liSize;
		}
	}

	// ??? - ???? - ???
	for (i = 0; i < siRCnt; i++) {
		liSize = 0;
		for (j = siCCnt - 1; j >= 0; j--) {
			if (sc2Rect[i][j] == D_MASS_WHITE) {		// ???
				liSize++;
			}
			else {										// ???
				liSize = 0;
			}
			if (si2Size[i][j] > liSize) {
				si2Size[i][j] = liSize;
			}
		}
	}

	// ??? - ???? - ???
	for (i = 0; i < siCCnt; i++) {

		// ???
		if (si2Size[0][i] > 1) {
			si2Size[0][i] = 1;
		}

		// ?????
		for (j = 1; j < siRCnt; j++) {
			liSize = si2Size[j - 1][i] + 1;				// ????? = ?? + 1
			if (si2Size[j][i] > liSize) {
				si2Size[j][i] = liSize;
			}
		}
	}

	// ??? - ???? - ???
	for (i = 0; i < siCCnt; i++) {

		// ???
		if (si2Size[siRCnt - 1][i] > 1) {
			si2Size[siRCnt - 1][i] = 1;
		}

		// ???????
		for (j = siRCnt - 2; j >= 0; j--) {
			liSize = si2Size[j + 1][i] + 1;				// ????? = ?? + 1
			if (si2Size[j][i] > liSize) {
				si2Size[j][i] = liSize;
			}
		}
	}

	// ?? - ??
	int liCnt = 0;
	for (i = 0; i < siRCnt; i++) {
		for (j = 0; j < siCCnt; j++) {
			if (si2Size[i][j] >= liK) {
				liCnt++;
			}
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:47:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:52:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Rect[i], sizeof(sc2Rect[i]), szpFpI);
   ^