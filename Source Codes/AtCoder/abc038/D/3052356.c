#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_BOX_MAX		100000									// ????
#define D_SEGT_CNT		131072									// ????????????(2?17?)

// ????? - ???
typedef struct Box {
	int miW;													// ?
	int miH;													// ??
} Box;

// ????
static Box sz1Box[D_BOX_MAX];									// ?
static int siBCnt;												// ??
static int si1SegT[D_SEGT_CNT * 2];								// ????????[??] = ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ???? - ???
int
fSortFncH(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Box *lzpVal1 = (Box *)pzpVal1;
	Box *lzpVal2 = (Box *)pzpVal2;

	// ????
	if (lzpVal1->miH > lzpVal2->miH) {
		return(1);
	}
	else if (lzpVal1->miH < lzpVal2->miH) {
		return(-1);
	}

	// ???
	if (lzpVal1->miW > lzpVal2->miW) {
		return(-1);
	}
	else if (lzpVal1->miW < lzpVal2->miW) {
		return(1);
	}

	return 0;
}

// ????? - ??? - ????
int
fSortFncW(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Box *lzpVal1 = (Box *)pzpVal1;
	Box *lzpVal2 = (Box *)pzpVal2;

	// ???
	if (lzpVal1->miW > lzpVal2->miW) {
		return(1);
	}
	else if (lzpVal1->miW < lzpVal2->miW) {
		return(-1);
	}

	// ????
	if (lzpVal1->miH > lzpVal2->miH) {
		return(-1);
	}
	else if (lzpVal1->miH < lzpVal2->miH) {
		return(1);
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
		int liVal = fSegTGet(piNNo * 2 + 1, liCenter + 1, piNowE, piGetS, piGetE);
		if (liRet < liVal) {
			liRet = liVal;
		}
	}

	return liRet;
}

// ???????? - ??
int
fSegTUp(
	int piUpNo					// <I> ???? 0?D_SEGT_CNT-1
	, int piVal					// <I> ???
)
{
	// ???
	int liCNo1 = D_SEGT_CNT + piUpNo;
	int liCNo2;
	if (liCNo1 % 2 == 0) {
		liCNo2 = liCNo1 + 1;
	}
	else {
		liCNo2 = liCNo1 - 1;
	}

	// ??
	si1SegT[liCNo1] = piVal;

	// ????
	while (1) {

		// ???
		int liPNo = liCNo1 / 2;
		if (liPNo < 1) {
			break;
		}

		// ??
		if (si1SegT[liCNo1] > si1SegT[liCNo2]) {
			si1SegT[liPNo] = si1SegT[liCNo1];
		}
		else {
			si1SegT[liPNo] = si1SegT[liCNo2];
		}

		// ?????
		liCNo1 = liPNo;
		if (liCNo1 % 2 == 0) {
			liCNo2 = liCNo1 + 1;
		}
		else {
			liCNo2 = liCNo1 - 1;
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
	memset(si1SegT, 0, sizeof(si1SegT));						// ????????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siBCnt);

	// ???
	for (i = 0; i < siBCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Box[i].miW, &sz1Box[i].miH);
	}

	// ??? - ????
	qsort(sz1Box, siBCnt, sizeof(Box), fSortFncH);

	// ???0?siBCnt-1???
	for (i = 0; i < siBCnt; i++) {
		sz1Box[i].miH = i;
	}

	// ??? - ???
	qsort(sz1Box, siBCnt, sizeof(Box), fSortFncW);

	// ?????
	int liMax = 0;
	for (i = 0; i < siBCnt; i++) {

		// ???????? - ??(????)
		int liCnt = fSegTGet(1, 0, D_SEGT_CNT - 1, 0, sz1Box[i].miH) + 1;
		if (liMax < liCnt) {
			liMax = liCnt;
		}

		// ???????? - ??
		fSegTUp(sz1Box[i].miH, liCnt);
	}

	// ?????
	sprintf(lc1Out, "%d\n", liMax);

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
./Main.c:198:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:207:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^