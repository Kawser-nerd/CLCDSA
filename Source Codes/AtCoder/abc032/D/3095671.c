#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ITM_MAX		200										// ?????
#define D_DP_COND		1000									// DP??
#define D_DP_RNG		(D_ITM_MAX * D_DP_COND)					// DP??
#define D_MATCH_KIND	2										// ????????
#define D_MATCH_NO1		0										// ?????????
#define D_MATCH_NO2		1										// ?????????
#define D_MATCH_MAX		70000									// ????????

// ????? - ????
typedef struct Itm {
	long long mlVal;											// ??
	long long mlWeight;											// ??
} Itm;

// ????
static Itm sz1Itm[D_ITM_MAX];									// ??
static int siICnt;												// ???
static long long slCap;											// ????
static long long slMax;											// ????
static long long sl1Dp[D_DP_RNG + 5];							// DP
static Itm sz2Match[D_MATCH_KIND][D_MATCH_MAX];					// ????????
static int si1MCnt[D_MATCH_KIND];								// ?????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?????
int
fSortFncC(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Itm *lzpVal1 = (Itm *)pzpVal1;
	Itm *lzpVal2 = (Itm *)pzpVal2;

	// ???
	double ldVal1 = (double)lzpVal1->mlVal / (double)lzpVal1->mlWeight;
	double ldVal2 = (double)lzpVal2->mlVal / (double)lzpVal2->mlWeight;

	// ?????
	if (ldVal1 > ldVal2) {
		return(1);
	}
	else if (ldVal1 < ldVal2) {
		return(-1);
	}

	return 0;
}

// ????? - ????
int
fSortFncW(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Itm *lzpVal1 = (Itm *)pzpVal1;
	Itm *lzpVal2 = (Itm *)pzpVal2;

	// ????
	if (lzpVal1->mlWeight > lzpVal2->mlWeight) {
		return(1);
	}
	else if (lzpVal1->mlWeight < lzpVal2->mlWeight) {
		return(-1);
	}

	return 0;
}

// ??????? - ??
int
fSetVMaxVal(
)
{
	int i, j;

	// DP - ???
	sl1Dp[0] = 0;
	for (i = 1; i <= D_DP_RNG; i++) {
		sl1Dp[i] = LLONG_MAX;
	}

	// ?????
	for (i = 0; i < siICnt; i++) {

		// DP - ??
		for (j = D_DP_RNG - (int)sz1Itm[i].mlVal; j >= 0; j--) {

			// ???
			if (sl1Dp[j] == LLONG_MAX) {
				continue;
			}

			// ????
			long long llWSum = sl1Dp[j] + sz1Itm[i].mlWeight;
			if (llWSum > slCap) {
				continue;
			}

			// ????
			int liTNo = j + (int)sz1Itm[i].mlVal;
			if (sl1Dp[liTNo] > llWSum) {
				sl1Dp[liTNo] = llWSum;
			}
		}
	}

	// ????
	for (i = D_DP_RNG; i > 0; i--) {
		if (sl1Dp[i] != LLONG_MAX) {
			slMax = i;
			break;
		}
	}

	return 0;
}

// ??????? - ??
int
fSetVMaxWeight(
)
{
	int i, j;

	// DP - ???
	memset(sl1Dp, 0, sizeof(sl1Dp));

	// ?????
	for (i = 0; i < siICnt; i++) {

		// DP - ??
		for (j = (int)slCap - (int)sz1Itm[i].mlWeight; j >= 0; j--) {

			// ????
			long long llVSum = sl1Dp[j] + sz1Itm[i].mlVal;

			// ????
			int liTNo = j + (int)sz1Itm[i].mlWeight;
			if (sl1Dp[liTNo] < llVSum) {
				sl1Dp[liTNo] = llVSum;
			}
		}
	}

	// ????
	for (i = (int)slCap; i > 0; i--) {
		if (slMax < sl1Dp[i]) {
			slMax = sl1Dp[i];
		}
	}

	return 0;
}

// ??????? - ????? - ?????
int
fSetVMaxMatchLst(
	int piMNo					// <I> ???????
	, int piINo					// <I> ?? 0?
	, int piINoE				// <I> ???? 1?
	, long long plVSum			// <I> ????
	, long long plWSum			// <I> ????
)
{
	// ???
	sz2Match[piMNo][si1MCnt[piMNo]].mlVal = plVSum;
	sz2Match[piMNo][si1MCnt[piMNo]].mlWeight = plWSum;
	si1MCnt[piMNo]++;

	// ????????
	if (piINo > piINoE) {
		return 0;
	}

	// ??
	fSetVMaxMatchLst(piMNo, piINo + 1, piINoE, plVSum + sz1Itm[piINo].mlVal, plWSum + sz1Itm[piINo].mlWeight);
	fSetVMaxMatchLst(piMNo, piINo + 1, piINoE, plVSum, plWSum);

	return 0;
}

// ??????? - ?????
int
fSetVMaxMatch(
)
{
	int i;

	// ????
	int li1SNo[D_MATCH_KIND], li1ENo[D_MATCH_KIND];
	li1SNo[D_MATCH_NO1] = 0;
	li1ENo[D_MATCH_NO1] = siICnt / 2 - 1;
	li1SNo[D_MATCH_NO2] = li1ENo[D_MATCH_NO1] + 1;
	li1ENo[D_MATCH_NO2] = siICnt - 1;

	// ?????
	for (i = 0; i < D_MATCH_KIND; i++) {
		fSetVMaxMatchLst(i, li1SNo[i], li1ENo[i], 0, 0);

		// ??? - ????
		qsort(sz2Match[i], si1MCnt[i], sizeof(Itm), fSortFncW);

		// ????????
		int liFNo = 1;
		int liTNo = 0;
		for (; liFNo < si1MCnt[i]; liFNo++) {
			if (sz2Match[i][liTNo].mlVal < sz2Match[i][liFNo].mlVal) {
				liTNo++;
				sz2Match[i][liTNo].mlVal = sz2Match[i][liFNo].mlVal;
				sz2Match[i][liTNo].mlWeight = sz2Match[i][liFNo].mlWeight;
			}
		}
		si1MCnt[i] = liTNo + 1;
	}

	// ?????
	int liNo1 = 0;
	int liNo2 = si1MCnt[D_MATCH_NO2] - 1;
	while (1) {

		// ????
		long long llWSum = sz2Match[D_MATCH_NO1][liNo1].mlWeight + sz2Match[D_MATCH_NO2][liNo2].mlWeight;

		// ????????
		if (llWSum > slCap) {

			// ??
			if (liNo2 > 0) {
				liNo2--;
				continue;
			}
			else {
				return 0;
			}
		}

		// ????
		long long llVSum = sz2Match[D_MATCH_NO1][liNo1].mlVal + sz2Match[D_MATCH_NO2][liNo2].mlVal;

		// ????
		if (slMax < llVSum) {
			slMax = llVSum;
		}

		// ??
		if (liNo1 < si1MCnt[D_MATCH_NO1] - 1) {
			liNo1++;
		}
		else {
			return 0;
		}
	}

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
	slMax = 0;													// ????
	memset(si1MCnt, 0, sizeof(si1MCnt));						// ??????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%lld", &siICnt, &slCap);

	// ???????????? - ??
	long long llVMax = 0;
	long long llWMax = 0;
	for (i = 0; i < siICnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%lld%lld", &sz1Itm[i].mlVal, &sz1Itm[i].mlWeight);

		// ????
		if (llVMax < sz1Itm[i].mlVal) {
			llVMax = sz1Itm[i].mlVal;
		}

		// ????
		if (llWMax < sz1Itm[i].mlWeight) {
			llWMax = sz1Itm[i].mlWeight;
		}
	}

	// ?? - ??? - ?????
	qsort(sz1Itm, siICnt, sizeof(Itm), fSortFncC);

	// ???????
	if (llVMax <= D_DP_COND) {									// ??
		fSetVMaxVal();
	}
	else if (llWMax <= D_DP_COND) {								// ??
		fSetVMaxWeight();
	}
	else if (siICnt == 1) {										// ????
		if (sz1Itm[0].mlWeight <= slCap) {
			slMax = sz1Itm[0].mlVal;
		}
	}
	else {														// ?????
		fSetVMaxMatch();
	}

	// ?????
	sprintf(lc1Out, "%lld\n", slMax);

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
./Main.c:298:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:309:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^