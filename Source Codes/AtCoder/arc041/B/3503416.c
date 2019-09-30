#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		500										// ???????

// ????
static FILE *szpFpI;											// ??
static int siH, siW;											// ???
static char sc2Now[D_SIZE_MAX][D_SIZE_MAX + 5];					// ????
static char sc2First[D_SIZE_MAX][D_SIZE_MAX + 5];				// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??????
int
fMove(
	int piCx					// <I> ??????X
	, int piCy					// <I> ??????Y
	, int piAx					// <I> ??????X
	, int piAy					// <I> ??????Y
)
{
	// ??????
	int liCnt = sc2Now[piCy][piCx];
	if (liCnt < 1) {							// ??
		return 0;
	}
	sc2Now[piCy][piCx] = 0;

	// ???? - ??
	piCx += piAx;
	piCy += piAy;
	sc2First[piCy][piCx] += liCnt;

	// ???? - ??
	sc2Now[piCy + piAy][piCx + piAx] -= liCnt;
	sc2Now[piCy + piAx][piCx + piAy] -= liCnt;
	sc2Now[piCy - piAx][piCx - piAy] -= liCnt;

	return 0;
}

// ??????????
int
fOutSide(
	int piOffset				// <I> ?????????? 0?
)
{
	int i;

	// ?????
	for (i = piOffset; i < siW - piOffset; i++) {
		fMove(i, piOffset, 0, 1);
		fMove(i, siH - 1 - piOffset, 0, -1);
	}

	// ?????
	for (i = piOffset; i < siH - piOffset; i++) {
		fMove(piOffset, i, 1, 0);
		fMove(siW - 1 - piOffset, i, -1, 0);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sc2First, 0, sizeof(sc2First));						// ????

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
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ???? - ??
	for (i = 0; i < siH; i++) {
		fgets(sc2Now[i], sizeof(sc2Now[i]), szpFpI);
	}

	// ???? - ???
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			sc2Now[i][j] -= '0';
		}
	}

	// ???????????
	int liOCnt;
	if (siH < siW) {
		liOCnt = (siH - 1) / 2;
	}
	else {
		liOCnt = (siW - 1) / 2;
	}

	// ??????????
	for (i = 0; i < liOCnt; i++) {
		fOutSide(i);
	}

	// ???? - ???
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			sc2First[i][j] += '0';
		}
	}

	// ??
	for (i = 0; i < siH; i++) {
		sprintf(lc1Out, "%s\n", sc2First[i]);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

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
./Main.c:99:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:104:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Now[i], sizeof(sc2Now[i]), szpFpI);
   ^