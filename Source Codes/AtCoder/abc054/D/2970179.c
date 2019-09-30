#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ITM_MAX		40												// ?????
#define D_WEIGHT_MAX	10												// ?????
#define D_WEIGHT_RNG	(D_ITM_MAX * D_WEIGHT_MAX)						// ??????

// ????? - ????
typedef struct Itm {
	int miA;															// A????
	int miB;															// B????
	int miVal;															// ??
} Itm;

// ????
static Itm sz1Itm[D_ITM_MAX];											// ??
static int siICnt;														// ???
static int siMinA;														// ??? - A
static int siMinB;														// ??? - B
static int si3Val[D_ITM_MAX + 5][D_WEIGHT_RNG + 5][D_WEIGHT_RNG + 5];	// ???[????][A????][B????]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?? - ?????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Itm *lzpVal1 = (Itm *)pzpVal1;
	Itm *lzpVal2 = (Itm *)pzpVal2;

	// ???
	double ldVal1 = (lzpVal1->miA + lzpVal1->miB) / lzpVal1->miVal;
	double ldVal2 = (lzpVal2->miA + lzpVal2->miB) / lzpVal2->miVal;

	// ?????
	if (ldVal1 > ldVal2) {
		return(-1);
	}
	else if (ldVal1 < ldVal2) {
		return(1);
	}

	return 0;
}

// ??????
int
fSetVal(
	int piINo					// <I> ?? 0?
	, int piA					// <I> A????
	, int piB					// <I> B????
	, int piVal					// <I> ??
)
{
	// ???
	if (si3Val[piINo][piA][piB] > 0) {
		if (si3Val[piINo][piA][piB] <= piVal) {
			return 0;
		}
	}
	si3Val[piINo][piA][piB] = piVal;

	// ??????
	if (piINo >= siICnt) {
		return 0;
	}

	// ?????
	Itm *lzpItm = &sz1Itm[piINo];

	// ???????
	fSetVal(piINo + 1, piA + lzpItm->miA, piB + lzpItm->miB, piVal + lzpItm->miVal);	// ??
	fSetVal(piINo + 1, piA, piB, piVal);												// ??

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

	// ??????
	memset(si3Val, 0, sizeof(si3Val));							// ???

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????(A,B)??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siICnt, &siMinA, &siMinB);

	// ????
	for (i = 0; i < siICnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &sz1Itm[i].miA, &sz1Itm[i].miB, &sz1Itm[i].miVal);
	}

	// ?? - ???
	qsort(sz1Itm, siICnt, sizeof(Itm), fSortFnc);

	// ??????
	fSetVal(0, 0, 0, 0);

	// ???????
	int liMin = INT_MAX;
	for (i = 1; i <= siICnt; i++) {
		int liA = siMinA;
		int liB = siMinB;
		while (1) {

			// ??????????
			if (liA > D_WEIGHT_RNG) {
				break;
			}
			if (liB > D_WEIGHT_RNG) {
				break;
			}

			// ????????
			if (si3Val[i][liA][liB] > 0) {
				if (liMin > si3Val[i][liA][liB]) {
					liMin = si3Val[i][liA][liB];
				}
			}

			// ?????
			liA += siMinA;
			liB += siMinB;
		}
	}

	// ?????
	if (liMin == INT_MAX) {
		sprintf(lc1Out, "-1\n");
	}
	else {
		sprintf(lc1Out, "%d\n", liMin);
	}

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
./Main.c:115:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:124:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^