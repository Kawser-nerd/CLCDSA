#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_HEIGHT_MAX	100000									// ?????
#define D_WIDTH_MAX		200000									// ?????
#define D_SEGT_CNT		262144									// ????????????

// ????
static FILE *szpFpI;											// ??
static int siHCnt;												// ???
static int si1Width[D_WIDTH_MAX];								// ??
static int siWCnt;												// ???
static int siDCnt;												// ????
static int si1One[D_HEIGHT_MAX];								// ???????????
static int si1Move[D_HEIGHT_MAX];								// ????????????
static long long sl1SegT[D_SEGT_CNT * 2];						// ????????(???[?????])
static int si1SNo[D_HEIGHT_MAX];								// ???????????
static int si1LCnt[D_HEIGHT_MAX];								// ?????????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???????? - ???????
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
			sl1SegT[i] = sl1SegT[liCNo1] + sl1SegT[liCNo2];
		}

		// ???????
		liPNo2 = liPNo1 - 1;
		liPNo1 /= 2;
	}

	return 0;
}

// ???????? - ??
long long
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
		return sl1SegT[piNNo];
	}

	// ????
	int liCenter = (piNowS + piNowE) / 2;

	long long llRet = 0;

	// ??
	if (piGetS <= liCenter) {
		llRet = fSegTGet(piNNo * 2, piNowS, liCenter, piGetS, piGetE);
	}

	// ??
	if (piGetE >= liCenter + 1) {
		llRet += fSegTGet(piNNo * 2 + 1, liCenter + 1, piNowE, piGetS, piGetE);
	}

	return llRet;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liWork;
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

	// ???????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siHCnt, &siWCnt, &siDCnt);

	// ?? - ??
	for (i = 0; i < siWCnt; i++) {
		fscanf(szpFpI, "%d", &si1Width[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??????????? - ???
	for (i = 0; i < siHCnt; i++) {
		si1One[i] = i;
	}

	// ??????????? - ???
	for (i = 0; i < siWCnt; i++) {
		liWork = si1One[si1Width[i]];
		si1One[si1Width[i]] = si1One[si1Width[i] - 1];
		si1One[si1Width[i] - 1] = liWork;
	}

	// ???????????? - ???
	for (i = 0; i < siHCnt; i++) {
		int liNo = si1One[i];
		si1Move[liNo] = (i - liNo + siHCnt) % siHCnt;
	}

	// ??????????? - ???
	memset(si1SNo, 0, sizeof(si1SNo));

	// ???????? - ???????
	int liSNo = D_SEGT_CNT;
	for (i = 0; i < siHCnt; i++) {

		// ?????????
		if (si1SNo[i] > 0) {
			continue;
		}

		// ????????
		int liNow = i;
		int liCnt = 0;
		do {

			// ???
			si1SNo[liNow] = liSNo;							// ???????????
			sl1SegT[liSNo] = si1Move[liNow];				// ???????? - ????

			// ??
			liNow = (liNow + si1Move[liNow]) % siHCnt;
			liSNo++;
			liCnt++;
		} while (liNow != i);

		// ?????????????
		liNow = i;
		do {
			si1LCnt[liNow] = liCnt;
			liNow = (liNow + si1Move[liNow]) % siHCnt;		// ??
		} while (liNow != i);

		// ??????
		memcpy(&sl1SegT[liSNo], &sl1SegT[liSNo - liCnt], sizeof(long long) * liCnt);
		liSNo += liCnt;
	}

	// ???????? - ???????
	fSegTSetP();

	// ??
	for (i = 0; i < siHCnt; i++) {

		// ???
		int liMCnt = siDCnt % si1LCnt[i];

		// ??? - ??
		long long llMove = 0;
		if (liMCnt > 0) {
			int liNo = si1SNo[i] - D_SEGT_CNT;
			llMove = fSegTGet(1, 0, D_SEGT_CNT - 1, liNo, liNo + liMCnt - 1);
		}

		// ??
		long long llPos = ((long long)i + llMove) % (long long)siHCnt + 1;

		// ?? - ???
		sprintf(lc1Out, "%lld\n", llPos);

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
./Main.c:116:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:121:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1Width[i]);
   ^
./Main.c:123:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^