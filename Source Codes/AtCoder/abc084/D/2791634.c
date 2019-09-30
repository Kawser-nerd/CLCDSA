#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SEGT_CNT		131072									// ????????????
#define D_VAL_MAX		100000									// ???

// ????
static int si1SegT[D_SEGT_CNT * 2];								// ????????(?????)

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ???
int
fSqrt(
	int piVal					// <I> ? 1?
)
{
	int liVal;

	// ???(????)??????
	for (liVal = 1; piVal > 0; liVal++) {
		piVal -= liVal * 2 + 1;
	}

	return liVal - 1;
}

// ??????
int
fIsPrime(
	int piVal					// <I> ?
)
{
	int i;

	// ???????
	if (piVal < 2) {
		return -1;
	}

	// ??????
	int liLimit = fSqrt(piVal);

	// ????
	for (i = 2; i <= liLimit; i++) {
		if (piVal % i == 0) {
			return -1;
		}
	}

	return 0;
}

// ???????? - ???????
int
fSegTSetP(
)
{
	int i;

	// ?????
	int liPNo1 = D_SEGT_CNT / 2;
	int liPNo2 = D_SEGT_CNT - 1;

	// ??
	while (liPNo1 > 0) {
		for (i = liPNo1; i <= liPNo2; i++) {

			// ???
			int liCNo1 = i * 2;
			int liCNo2 = liCNo1 + 1;

			// ???
			si1SegT[i] = si1SegT[liCNo1] + si1SegT[liCNo2];
		}

		// ???????
		liPNo2 = liPNo1 - 1;
		liPNo1 /= 2;
	}

	return 0;
}

// ???????? - ??
int
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
		return si1SegT[piNNo];
	}

	// ????
	int liCenter = (piNowS + piNowE) / 2;

	int liRet = 0;

	// ??
	if (piGetS <= liCenter) {
		liRet = fSegTGet(piNNo * 2, piNowS, liCenter, piGetS, piGetE);
	}

	// ??
	if (piGetE >= liCenter + 1) {
		liRet += fSegTGet(piNNo * 2 + 1, liCenter + 1, piNowE, piGetS, piGetE);
	}

	return liRet;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(si1SegT, 0, sizeof(si1SegT));							// ????????(?????)

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????(?????) - ???????
	for (i = 1; i <= D_VAL_MAX; i += 2) {

		// ??????
		liRet = fIsPrime(i);
		if (liRet != 0) {
			continue;
		}

		// ??????
		liRet = fIsPrime((i + 1) / 2);
		if (liRet != 0) {
			continue;
		}

		// ???
		si1SegT[D_SEGT_CNT + i] = 1;
	}

	// ????????(?????) - ???????
	fSegTSetP();

	// ??????
	int liQCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liQCnt);

	// ????????
	for (i = 0; i < liQCnt; i++) {

		// ????
		int liSNo, liENo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liSNo, &liENo);

		// ???????
		int liCnt = fSegTGet(1, 0, D_SEGT_CNT - 1, liSNo, liENo);

		// ?????
		sprintf(lc1Out, "%d\n", liCnt);

		// ????
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
./Main.c:175:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:187:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^