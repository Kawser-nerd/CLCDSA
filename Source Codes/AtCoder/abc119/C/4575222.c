#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MAKE_CNT		3										// ???
#define D_CNT_MAX		8										// ????

// ????? - ????
typedef struct Sel {
	int mi1Len[D_CNT_MAX];										// ??
	int miSCnt;													// ???
} Sel;

// ????
static FILE *szpFpI;											// ??
static int siBCnt;												// ??
static int si1Make[D_MAKE_CNT];									// ??????
static int si1Len[D_CNT_MAX];									// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ????
int
fConv(
	Sel *pzpSel				// <I> ????
	, int piNo				// <I> ????
	, int piMake			// <I> ??????
	, int piSum				// <I> ??????
	, int piCCnt			// <I> ???
	, int *pipMin			// <O> ??MP
)
{
	// ????
	if (piNo == pzpSel->miSCnt) {

		if (piCCnt == 0) {		// ????
			return 0;
		}

		// MP
		int liMP = abs(piSum - piMake) + (piCCnt - 1) * 10;

		// ??MP - ??
		if (*pipMin > liMP) {
			*pipMin = liMP;
		}

		return 0;
	}

	// ????
	fConv(pzpSel, piNo + 1, piMake, piSum + pzpSel->mi1Len[piNo], piCCnt + 1, pipMin);

	// ????
	fConv(pzpSel, piNo + 1, piMake, piSum, piCCnt, pipMin);

	return 0;
}

// ??MP - ???
int
fSetMp(
	Sel *pzpSel				// <I> ????
	, int *pipMin			// <O> ??MP
)
{
	int i;

	int liMP = 0;
	for (i = 0; i < D_MAKE_CNT; i++) {

		// ????
		int liMin = INT_MAX;
		fConv(&pzpSel[i], 0, si1Make[i], 0, 0, &liMin);
		if (liMin == INT_MAX) {								// ???
			return 0;
		}

		// MP
		liMP += liMin;
	}

	// ??MP - ??
	if (*pipMin > liMP) {
		*pipMin = liMP;
	}

	return 0;
}

// ????
int
fDiv(
	int piDCnt				// <I> ???
	, Sel *pzpSel			// <I> ????
	, int *pipMin			// <O> ??MP
)
{
	int i;

	// ????
	if (piDCnt == siBCnt) {
		fSetMp(pzpSel, pipMin);			// ??MP - ???
		return 0;
	}

	// ??
	for (i = 0; i < D_MAKE_CNT; i++) {
		pzpSel[i].mi1Len[pzpSel[i].miSCnt] = si1Len[piDCnt];
		pzpSel[i].miSCnt++;

		// ???
		fDiv(piDCnt + 1, pzpSel, pipMin);

		// ???????
		pzpSel[i].miSCnt--;
	}

	return 0;
}

// ?????
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// ????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d", &siBCnt, &si1Make[0], &si1Make[1], &si1Make[2]);

	// ???? - ??
	for (i = 0; i < siBCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &si1Len[i]);
	}

	// ????
	Sel lz1Sel[D_MAKE_CNT];
	memset(lz1Sel, 0, sizeof(lz1Sel));
	int liMin = INT_MAX;
	fDiv(0, lz1Sel, &liMin);

	return liMin;
}

// ????
int
fOne(
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????
	int liRet = fMain();

	// ?? - ???
	sprintf(lc1Out, "%d\n", liRet);

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// ???????
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne(0);
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:141:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:146:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^