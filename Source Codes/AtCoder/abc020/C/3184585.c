#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		10										// ?????
#define D_BLACK_MAX		(D_SIZE_MAX * 2)						// ????
#define D_MASS_START	'S'										// ?? - ????
#define D_MASS_GOAL		'G'										// ?? - ???
#define D_MASS_BLACK	'#'										// ?? - ?

// ????
static FILE *szpFpI;											// ??
static char sc2Mass[D_SIZE_MAX][D_SIZE_MAX + 5];				// ??
static int si3Len[D_SIZE_MAX][D_SIZE_MAX][D_BLACK_MAX];			// ???????
static int siH;													// ??
static int siW;													// ?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??????? - ???
int
fSetLen(
	int piX						// <I> ??X
	, int piY					// <I> ??Y
	, int piLen					// <I> ????
	, int piBCnt				// <I> ????
)
{
	// ??????
	if (piX < 0 || siW <= piX) {
		return 0;
	}
	if (piY < 0 || siH <= piY) {
		return 0;
	}

	// ????
	if (sc2Mass[piY][piX] == D_MASS_BLACK) {	// ?
		piBCnt++;
	}
	else {										// ???(?)
		piLen++;
	}

	// ????????
	if (piBCnt >= D_BLACK_MAX) {
		return 0;
	}

	// ??????
	if (si3Len[piY][piX][piBCnt] <= piLen) {
		return 0;
	}
	si3Len[piY][piX][piBCnt] = piLen;

	// ?????
	fSetLen(piX + 1, piY, piLen, piBCnt);
	fSetLen(piX - 1, piY, piLen, piBCnt);
	fSetLen(piX, piY + 1, piLen, piBCnt);
	fSetLen(piX, piY - 1, piLen, piBCnt);

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, k;
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

	// ????????? - ??
	int liTime;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siH, &siW, &liTime);

	// ?? - ??
	for (i = 0; i < siH; i++) {
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpI);
	}

	// ???????????? - ??
	int liSx, liSy, liGx, liGy;
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			switch (sc2Mass[i][j]) {
			case D_MASS_START:
				liSx = j;
				liSy = i;
				break;
			case D_MASS_GOAL:
				liGx = j;
				liGy = i;
				break;
			}
		}
	}

	// ??????? - ???
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			for (k = 0; k < D_BLACK_MAX; k++) {
				si3Len[i][j][k] = INT_MAX;
			}
		}
	}

	// ??????? - ???
	fSetLen(liSx, liSy, -1, 0);

	// ??? - ??
	int liMax = 0;
	for (i = 1; i < D_BLACK_MAX; i++) {
		int liSec = (liTime - si3Len[liGy][liGx][i]) / i;
		if (liMax < liSec) {
			liMax = liSec;
		}
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
./Main.c:95:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:100:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpI);
   ^