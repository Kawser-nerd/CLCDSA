#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SEGT_CNT		262144									// ????????????(2???)

// ????? - ??????????
typedef struct SegT {
	int miNo;													// ?? 0?
	int miVal;													// ?
} SegT;

// ????
static FILE *szpFpI;											// ??
static int siNCnt;												// ???
static SegT sz1SegT[D_SEGT_CNT * 2];							// ????????

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
			if (sz1SegT[liCNo1].miVal < sz1SegT[liCNo2].miVal) {
				sz1SegT[i] = sz1SegT[liCNo1];
			}
			else {
				sz1SegT[i] = sz1SegT[liCNo2];
			}
		}

		// ???????
		liPNo2 = liPNo1 - 1;
		liPNo1 /= 2;
	}

	return 0;
}

// ???????? - ??
SegT *
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
		return &sz1SegT[piNNo];
	}

	// ????
	int liCenter = (piNowS + piNowE) / 2;

	SegT *lzpRet = NULL;

	// ??
	if (piGetS <= liCenter) {
		lzpRet = fSegTGet(piNNo * 2, piNowS, liCenter, piGetS, piGetE);
	}

	// ??
	if (piGetE >= liCenter + 1) {
		SegT *lzpRet2 = fSegTGet(piNNo * 2 + 1, liCenter + 1, piNowE, piGetS, piGetE);
		if (lzpRet == NULL) {
			lzpRet = lzpRet2;
		}
		else {
			if (lzpRet->miVal > lzpRet2->miVal) {
				lzpRet = lzpRet2;
			}
		}
	}

	return lzpRet;
}

// ?????
long long
fGetSum(
	int piGetS					// <I> ???? - ?? 0?D_SEGT_CNT-1
	, int piGetE				// <I> ???? - ?? 0?D_SEGT_CNT-1
)
{
	// ??????? - ??
	SegT *lzpSegT = fSegTGet(1, 0, D_SEGT_CNT - 1, piGetS, piGetE);

	// ??????
	long long llH = piGetE - piGetS + 1;

	// ??????
	long long llSum = llH * (llH + 1) / 2 * (long long)lzpSegT->miVal;

	// ?????????
	llH = lzpSegT->miNo - piGetS;
	if (llH > 0) {

		// ??(?????????)???
		llSum -= llH * (llH + 1) / 2 * (long long)lzpSegT->miVal;

		// ?????????
		llSum += fGetSum(piGetS, lzpSegT->miNo - 1);
	}

	// ?????????
	llH = piGetE - lzpSegT->miNo;
	if (llH > 0) {

		// ??(?????????)???
		llSum -= llH * (llH + 1) / 2 * (long long)lzpSegT->miVal;

		// ?????????
		llSum += fGetSum(lzpSegT->miNo + 1, piGetE);
	}

	return llSum;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
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

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siNCnt);

	// ?? - ??
	for (i = 0; i < siNCnt; i++) {
		fscanf(szpFpI, "%d", &sz1SegT[D_SEGT_CNT + i].miVal);
		sz1SegT[D_SEGT_CNT + i].miNo = i;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ???????? - ???????
	fSegTSetP();

	// ?????
	long long llSum = fGetSum(0, siNCnt - 1);

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llSum);

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
./Main.c:167:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:172:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &sz1SegT[D_SEGT_CNT + i].miVal);
   ^
./Main.c:175:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^