#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MASS_MAX		50										// ???????
#define D_MASS_WHITE	'.'										// ?? - ?
#define D_MASS_BLACK	'#'										// ?? - ?
#define D_STACK_KIND	2										// ??????
#define D_STACK_NO1		0										// ?????
#define D_STACK_NO2		1										// ?????

// ????? - ????
typedef struct Pos {
	int miX, miY;												// ?? 0?
} Pos;

// ????
static int siH;													// ??
static int siW;													// ?
static char sc2Mass[D_MASS_MAX][D_MASS_MAX + 5];				// ??
static int si2Len[D_MASS_MAX][D_MASS_MAX + 5];					// ????
static Pos sz2Pos[D_STACK_KIND][D_MASS_MAX * 2];				// ???????????
static int si1PCnt[D_STACK_KIND];								// ????????????
static int siFNo;												// ?????? - ?
static int siTNo;												// ?????? - ?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ??????? - ???
int
fSetLenOne(
	int piX						// <I> ??X 0?
	, int piY					// <I> ??Y 0?
	, int piLen					// <I> ????
)
{
	// ??????
	if (piX < 0 || siW <= piX) {
		return 0;
	}
	if (piY < 0 || siH <= piY) {
		return 0;
	}

	// ????????
	if (sc2Mass[piY][piX] != D_MASS_WHITE) {	// ???
		return 0;
	}

	// ????????
	if (piLen >= si2Len[piY][piX]) {			// ?????
		return 0;
	}

	// ???????
	si2Len[piY][piX] = piLen;

	// ????
	sz2Pos[siTNo][si1PCnt[siTNo]].miX = piX;
	sz2Pos[siTNo][si1PCnt[siTNo]].miY = piY;
	si1PCnt[siTNo]++;

	return 0;
}

// ???????
int
fSetLen(
)
{
	int i, j, liLen;

	// ???????
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			si2Len[i][j] = INT_MAX;
		}
	}

	// ??????
	siFNo = D_STACK_NO1;
	siTNo = D_STACK_NO2;
	memset(si1PCnt, 0, sizeof(si1PCnt));
	fSetLenOne(0, 0, 0);

	for (liLen = 1; ; liLen++) {

		// ??????
		if (siFNo == D_STACK_NO1) {
			siFNo = D_STACK_NO2;
			siTNo = D_STACK_NO1;
		}
		else {
			siFNo = D_STACK_NO1;
			siTNo = D_STACK_NO2;
		}

		// ?????(?)
		si1PCnt[siTNo] = 0;

		// ?????(?)????
		for (i = 0; i < si1PCnt[siFNo]; i++) {
			int liX = sz2Pos[siFNo][i].miX;
			int liY = sz2Pos[siFNo][i].miY;
			fSetLenOne(liX + 1, liY, liLen);	// ?
			fSetLenOne(liX - 1, liY, liLen);	// ?
			fSetLenOne(liX, liY + 1, liLen);	// ?
			fSetLenOne(liX, liY - 1, liLen);	// ?
		}

		// ??????
		if (si2Len[siH - 1][siW - 1] != INT_MAX) {
			return 0;
		}

		// ???????
		if (si1PCnt[siTNo] < 1) {
			return -1;
		}
	}

	return 0;
}

// ????????
int
fSetBlack(
	int piX						// <I> ??X 0?
	, int piY					// <I> ??Y 0?
	, int piLen					// <I> ????
)
{
	int liRet;

	// ??????
	if (piX < 0 || siW <= piX) {
		return -1;
	}
	if (piY < 0 || siH <= piY) {
		return -1;
	}

	// ????????
	if (piLen != si2Len[piY][piX]) {	// ??????
		return -1;
	}

	// ??
	sc2Mass[piY][piX] = D_MASS_BLACK;

	// ??????
	if (piX == 0) {
		if (piY == 0) {
			return 0;
		}
	}

	// ??
	liRet = fSetBlack(piX + 1, piY, piLen - 1);
	if (liRet == 0) {
		return 0;
	}

	// ??
	liRet = fSetBlack(piX - 1, piY, piLen - 1);
	if (liRet == 0) {
		return 0;
	}

	// ??
	liRet = fSetBlack(piX, piY + 1, piLen - 1);
	if (liRet == 0) {
		return 0;
	}

	// ??
	liRet = fSetBlack(piX, piY - 1, piLen - 1);
	if (liRet == 0) {
		return 0;
	}

	return -1;
}

// ?????
int
fGetScore(
)
{
	int i, j, liRet;

	// ???????
	liRet = fSetLen();
	if (liRet != 0) {
		return -1;
	}

	// ????????
	fSetBlack(siW - 1, siH - 1, si2Len[siH - 1][siW - 1]);

	// ???????
	int liCnt = 0;
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			if (sc2Mass[i][j] == D_MASS_WHITE) {
				liCnt++;
			}
		}
	}

	return liCnt;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siH, &siW);
	
	// ????
	for (i = 0; i < siH; i++) {
#ifdef D_TEST
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpT);
#else
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), stdin);
#endif
	}

	// ?????
	int liScore = fGetScore();

	// ?????
	sprintf(lc1Out, "%d\n", liScore);

	// ????
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
	fclose(szpFpT);
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
./Main.c:244:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:253:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Mass[i], sizeof(sc2Mass[i]), stdin);
   ^