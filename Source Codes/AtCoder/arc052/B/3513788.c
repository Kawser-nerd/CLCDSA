#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_X_MAX			20000									// ??X?
#define M_PI			3.1415926535897932384626433832795		// ???
#define D_SEGT_CNT		32768									// ????????????

// ????
static FILE *szpFpI;											// ??
static double sd1SegT[D_SEGT_CNT * 2];							// ????????(??[X])

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????????(??[X]) - ???????
int
fSegTSetP(
)
{
	int i;

	// ????????
	int liPNo1 = D_SEGT_CNT / 2;
	int liPNo2 = D_SEGT_CNT - 1;

	// ??
	while (liPNo1 > 0) {
		for (i = liPNo1; i <= liPNo2; i++) {

			// ???
			int liCNo1 = i * 2;
			int liCNo2 = liCNo1 + 1;

			// ???
			sd1SegT[i] = sd1SegT[liCNo1] + sd1SegT[liCNo2];
		}

		// ???????
		liPNo2 = liPNo1 - 1;
		liPNo1 /= 2;
	}

	return 0;
}

// ????????(??[X]) - ??
double
fSegTGet(
	int piNNo					// <I> ???? 1?
	, int piNowS				// <I> ???? - ?? 0?D_SEGT_CNT-1
	, int piNowE				// <I> ???? - ?? 0?D_SEGT_CNT-1
	, int piGetS				// <I> ???? - ?? 0?D_SEGT_CNT-1
	, int piGetE				// <I> ???? - ?? 0?D_SEGT_CNT-1
)
{
	// ??????
	if (piGetS <= piNowS && piNowE <= piGetE) {
		return sd1SegT[piNNo];
	}

	// ????
	int liCenter = (piNowS + piNowE) / 2;

	double ldRet = 0.0;

	// ??
	if (piGetS <= liCenter) {
		ldRet = fSegTGet(piNNo * 2, piNowS, liCenter, piGetS, piGetE);
	}

	// ??
	if (piGetE >= liCenter + 1) {
		ldRet += fSegTGet(piNNo * 2 + 1, liCenter + 1, piNowE, piGetS, piGetE);
	}

	return ldRet;
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
	memset(sd1SegT, 0, sizeof(sd1SegT));						// ????????(??[X])

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

	// ???????? - ??
	int liCCnt, liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liCCnt, &liQCnt);

	// ?? - ??
	for (i = 0; i < liCCnt; i++) {
		int liX, liR, liH;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d", &liX, &liR, &liH);

		// ???????
		double ldVolBack = 0.0;
		for (j = 1; j <= liH; j++) {

			// ??
			double ldR = (double)liR * (double)j / (double)liH;

			// ??
			double ldVol = ldR * ldR * M_PI * (double)j / 3.0;

			// ????????(??[X])
			sd1SegT[D_SEGT_CNT + liX + liH - j] += ldVol - ldVolBack;

			// ??????
			ldVolBack = ldVol;
		}
	}

	// ????????(??[X]) - ???????
	fSegTSetP();

	// ??? - ??
	for (i = 0; i < liQCnt; i++) {
		int liSx, liEx;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liSx, &liEx);

		// ??
		double ldVol;
		if (liSx < liEx) {
			ldVol = fSegTGet(1, 0, D_SEGT_CNT - 1, liSx, liEx - 1);
		}
		else {
			ldVol = 0.0;
		}

		// ?? - ???
		sprintf(lc1Out, "%.6lf\n", ldVol);

		// ?? - ??
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
} ./Main.c:10:0: warning: "M_PI" redefined
 #define M_PI   3.1415926535897932384626433832795  // ???
 ^
In file included from ./Main.c:2:0:
/usr/include/math.h:372:0: note: this is the location of the previous definition
 # define M_PI  3.14159265358979323846 /* pi */
 ^
./Main.c: In function ‘fMain’:
./Main.c:112:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:118:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:145:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^