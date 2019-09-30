#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_WOMAN_MAX		18										// ?????
#define D_MAN_MAX		18										// ?????
#define D_CHOKO_MAX		(D_WOMAN_MAX * D_MAN_MAX)				// ??????

// ????? - ????????
typedef struct Choco {
	int miWNo;													// ???? 0?
	int miMNo;													// ???? 0?
	int miHappy;												// ???
} Choco;

// ????
static FILE *szpFpI;											// ??
static int siWCnt;												// ???
static int siMCnt;												// ???
static int siGWCnt;												// ???????
static int siGMCnt;												// ???????
static int siCCnt;												// ???????
static Choco sz1Choco[D_CHOKO_MAX];								// ??????
static int siMax;												// ?????

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

	// ??
	if (*lipVal1 > *lipVal2) {
		return(-1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(1);
	}

	return 0;
}

// ????? - ???
int
fSetMax(
	int *pipWSel				// <I> ??????
	, int piWSCnt				// <I> ???????
)
{
	int i;

	// ??????
	if (piWSCnt != siGWCnt) {
		return 0;
	}

	// ???[??] - ???
	int li1Happy[D_MAN_MAX];
	memset(li1Happy, 0, sizeof(li1Happy));

	// ???[??] - ???
	for (i = 0; i < siCCnt; i++) {

		// ?????
		if (pipWSel[sz1Choco[i].miWNo] != D_ON) {
			continue;
		}

		// ???[??] - ??
		li1Happy[sz1Choco[i].miMNo] += sz1Choco[i].miHappy;
	}

	// ???[??] - ???
	qsort(li1Happy, siMCnt, sizeof(int), fSortFnc);

	// ?????
	int liSum = 0;
	for (i = 0; i < siGMCnt; i++) {
		liSum += li1Happy[i];
	}

	// ????? - ??
	if (siMax < liSum) {
		siMax = liSum;
	}

	return 0;
}

// ?????
int
fSelWoman(
	int piWNo					// <I> ???? 0?
	, int *pipWSel				// <I> ??????
	, int piWSCnt				// <I> ???????
)
{
	// ???????????
	if (piWNo == siWCnt) {
		fSetMax(pipWSel, piWSCnt);				// ????? - ???
		return 0;
	}

	// ???????
	pipWSel[piWNo] = D_ON;
	fSelWoman(piWNo + 1, pipWSel, piWSCnt + 1);
	pipWSel[piWNo] = D_OFF;

	// ???????
	fSelWoman(piWNo + 1, pipWSel, piWSCnt);

	return 0;
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
	siMax = 0;													// ?????

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

	// ??????????????????????????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d%d", &siWCnt, &siMCnt, &siGWCnt, &siGMCnt, &siCCnt);

	// ?????? - ??
	for (i = 0; i < siCCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d", &sz1Choco[i].miWNo, &sz1Choco[i].miMNo, &sz1Choco[i].miHappy);
		sz1Choco[i].miWNo--;
		sz1Choco[i].miMNo--;
	}

	// ?????
	int li1WSel[D_WOMAN_MAX];
	memset(li1WSel, D_OFF, sizeof(li1WSel));
	fSelWoman(0, li1WSel, 0);

	// ?? - ???
	sprintf(lc1Out, "%d\n", siMax);

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
./Main.c:155:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:160:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^