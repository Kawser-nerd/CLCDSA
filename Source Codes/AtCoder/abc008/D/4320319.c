#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MCN_MAX		30											// ?????
#define D_POS_MAX		D_MCN_MAX * 3 + 5							// ?????

// ????? - ????
typedef struct Mcn {
	int miX, miY;													// ??
} Mcn;

// ????
static FILE *szpFpI;												// ??
static int siW;														// ?
static int siH;														// ??
static Mcn sz1Mcn[D_MCN_MAX];										// ??
static int siMCnt;													// ???
static int si1X[D_POS_MAX];											// X?????
static int siXCnt;													// X??????
static int si1Y[D_POS_MAX];											// Y?????
static int siYCnt;													// Y??????
static int si4Max[D_POS_MAX][D_POS_MAX][D_POS_MAX][D_POS_MAX];		// ????[????X][????Y][????X][????Y]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - int??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	int *lipVal1 = (int *)pzpVal1;
	int *lipVal2 = (int *)pzpVal2;

	// int??
	if (*lipVal1 > *lipVal2) {
		return 1;
	}
	else if (*lipVal1 < *lipVal2) {
		return -1;
	}

	return 0;
}

// ????? - ??
int
fAddLst(
	int piVal					// <I> ?
	, int *pipLst				// <I> ???
	, int *pipCnt				// <I> ????
	, int piLimit				// <I> ??
)
{
	// ??????
	if (piVal < 1 || piLimit < piVal) {
		return 0;
	}

	// ??
	pipLst[*pipCnt] = piVal;
	(*pipCnt)++;

	return 0;
}

// ????? - ??
int
fMakeLst(
	int piX						// <I> [1]:X [-1]:Y
)
{
	int i, j;

	// ?????
	int *lipLst, *lipCnt, liLimit;
	if (piX == 1) {
		lipLst = si1X;
		lipCnt = &siXCnt;
		liLimit = siW;
	}
	else {
		lipLst = si1Y;
		lipCnt = &siYCnt;
		liLimit = siH;
	}

	// ???????? - ??
	*lipCnt = 0;
	for (i = 0; i < siMCnt; i++) {
		int liVal;
		if (piX == 1) {
			liVal = sz1Mcn[i].miX;
		}
		else {
			liVal = sz1Mcn[i].miY;
		}
		fAddLst(liVal, lipLst, lipCnt, liLimit);
		fAddLst(liVal + 1, lipLst, lipCnt, liLimit);
		fAddLst(liVal - 1, lipLst, lipCnt, liLimit);
	}

	// ??????? - ??
	fAddLst(1, lipLst, lipCnt, liLimit);
	fAddLst(liLimit, lipLst, lipCnt, liLimit);

	// ????? - ???
	qsort(lipLst, *lipCnt, sizeof(int), fSortFnc);

	// ???????
	int liCnt = 1;
	for (int liFNo = 1; liFNo < *lipCnt; liFNo++) {
		if (lipLst[liFNo] != lipLst[liCnt - 1]) {
			lipLst[liCnt] = lipLst[liFNo];
			liCnt++;
		}
	}
	*lipCnt = liCnt;

	// ????? - ??
	for (i = 0; i < siMCnt; i++) {
		int *lipPos;
		if (piX == 1) {
			lipPos = &sz1Mcn[i].miX;
		}
		else {
			lipPos = &sz1Mcn[i].miY;
		}

		// ??
		for (j = 0; j < *lipCnt; j++) {
			if (*lipPos == lipLst[j]) {
				*lipPos = j;
			}
		}
	}

	return 0;
}

// ??? - ??
int
fGetMax(
	int piSx					// <I> ????X
	, int piSy					// <I> ????Y
	, int piEx					// <I> ????X
	, int piEy					// <I> ????Y
)
{
	int i;

	// ??????
	if (piEx < 0 || siXCnt <= piSx) {
		return 0;
	}
	if (piEy < 0 || siYCnt <= piSy) {
		return 0;
	}

	// ???
	if (si4Max[piSx][piSy][piEx][piEy] >= 0) {
		return si4Max[piSx][piSy][piEx][piEy];
	}

	// ??? - ??
	int liMax = 0;
	for (i = 0; i < siMCnt; i++) {

		// ??????????
		if (sz1Mcn[i].miX < piSx || piEx < sz1Mcn[i].miX) {
			continue;
		}
		if (sz1Mcn[i].miY < piSy || piEy < sz1Mcn[i].miY) {
			continue;
		}

		// ????????
		int liCnt = si1X[piEx] - si1X[piSx] + si1Y[piEy] - si1Y[piSy] + 1;

		// ???
		liCnt += fGetMax(sz1Mcn[i].miX + 1, sz1Mcn[i].miY + 1, piEx,  piEy);
		liCnt += fGetMax(sz1Mcn[i].miX + 1, piSy, piEx, sz1Mcn[i].miY - 1);
		liCnt += fGetMax(piSx, sz1Mcn[i].miY + 1, sz1Mcn[i].miX - 1,  piEy);
		liCnt += fGetMax(piSx, piSy, sz1Mcn[i].miX - 1, sz1Mcn[i].miY - 1);

		// ??? - ??
		if (liMax < liCnt) {
			liMax = liCnt;
		}
	}

	// ???
	si4Max[piSx][piSy][piEx][piEy] = liMax;

	return si4Max[piSx][piSy][piEx][piEy];
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si4Max, -1, sizeof(si4Max));							// ????

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
	sscanf(lc1Buf, "%d%d", &siW, &siH);

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siMCnt);

	// ?? - ??
	for (i = 0; i < siMCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Mcn[i].miX, &sz1Mcn[i].miY);
	}

	// ????? - ??
	fMakeLst(1);
	fMakeLst(-1);

	// ??? - ??
	int liMax = fGetMax(0, 0, siXCnt - 1, siYCnt - 1);

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
./Main.c:232:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:236:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:241:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^