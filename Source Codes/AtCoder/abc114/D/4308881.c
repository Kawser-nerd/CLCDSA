#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_PRM_MAX		100										// ????????

// ????
static FILE *szpFpI;											// ??
static int si1Prm[D_PRM_MAX];									// ?????
static char sc1PWork[D_PRM_MAX + 5];							// ???????????
static int siPCnt;												// ??????
static int si1PCnt[D_PRM_MAX];									// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????????
int
fMakePrm(
	int piMax					// <I> ???
)
{
	// ???
	siPCnt = 0;
	memset(sc1PWork, D_OFF, sizeof(sc1PWork));

	// ???
	int liNow = 2;

	// ???
	int liLimit = (int)sqrt((double)piMax);

	// ?? - ??
	while (1) {

		// ?????
		while (sc1PWork[liNow] != D_OFF) {
			liNow++;
		}

		// ??????
		if (liNow > liLimit) {
			break;
		}

		// ????? - ??
		si1Prm[siPCnt] = liNow;
		siPCnt++;

		// ????????????
		int liVal = liNow;
		while (liVal <= piMax) {
			sc1PWork[liVal] = D_ON;
			liVal += liNow;
		}
	}

	// ????????
	while (liNow <= piMax) {
		if (sc1PWork[liNow] == D_OFF) {
			si1Prm[siPCnt] = liNow;
			siPCnt++;
		}
		liNow++;
	}

	return 0;
}

// ????? - ??
int
fGetCntK(
	int piCond1					// <I> ???
	, int piCond2				// <I> ???
	, int *pipCnt				// <O> ???
)
{
	int i;

	// ???
	pipCnt[0] = 0;
	pipCnt[1] = 0;

	// ????? - ??
	for (i = 0; i < siPCnt; i++) {
		if (si1PCnt[i] >= piCond1 - 1) {
			pipCnt[0]++;
		}
		else if (si1PCnt[i] >= piCond2 - 1) {
			pipCnt[1]++;
		}
	}

	return 0;
}

// ?????? - ??
int
fGetCnt(
)
{
	// 5 * 5 * 3
	int li1Cnt[2];
	fGetCntK(5, 3, li1Cnt);
	int liSum = li1Cnt[0] * (li1Cnt[0] - 1) / 2 * (li1Cnt[0] - 2 + li1Cnt[1]);

	// 15 * 5
	fGetCntK(15, 5, li1Cnt);
	liSum += li1Cnt[0] * (li1Cnt[0] - 1 + li1Cnt[1]);

	// 25 * 3
	fGetCntK(25, 3, li1Cnt);
	liSum += li1Cnt[0] * (li1Cnt[0] - 1 + li1Cnt[1]);

	// 75
	fGetCntK(75, 75, li1Cnt);
	liSum += li1Cnt[0];

	return liSum;
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
	memset(si1PCnt, 0, sizeof(si1PCnt));						// ????

	// ????? - ??
	fMakePrm(D_PRM_MAX);

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

	// ?? - ??
	int liN;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liN);

	// ???? - ???
	for (i = 2; i <= liN; i++) {

		// ?????
		int liVal = i;
		for (j = 0; j < siPCnt; j++) {
			while (liVal % si1Prm[j] == 0) {
				liVal /= si1Prm[j];
				si1PCnt[j]++;
			}
			if (liVal == 1) {
				break;
			}
		}
	}

	// ?????? - ??
	int liCnt = fGetCnt();

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
./Main.c:160:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^