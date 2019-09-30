#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TOWN_MAX		100000									// ????
#define D_ROAD_MAX		100000									// ?????
#define D_WAY_CNT		2										// ???
#define D_WAY_GO		0										// ?? - ??
#define D_WAY_BACK		1										// ?? - ??

// ????? - ???
typedef struct Town {
	int miMoney;												// ??
	int mi1TSum[D_WAY_CNT];										// ?????????
	int miRSNo;													// ?? - ?? 0?
	int miRENo;													// ?? - ?? 0?
} Town;

// ????? - ????
typedef struct Road {
	int mi1TNo[D_WAY_CNT];										// ? 1?
	int miTime;													// ??
} Road;

// ????? - ?????
typedef struct Heap {
	int miTNo;													// ? 1?
	int miTSum;													// ?????????
} Heap;

// ????
static Town sz1Town[D_TOWN_MAX + 5];							// ?
static int siTCnt;												// ??
static Road sz1Road[D_ROAD_MAX];								// ??
static int siRCnt;												// ???
static int siTime;												// ????
static Heap sz1Heap[D_ROAD_MAX];								// ???
static int siHCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ???? - ?(??)??
int
fSortFncG(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Road *lzpVal1 = (Road *)pzpVal1;
	Road *lzpVal2 = (Road *)pzpVal2;

	// ?(??)??
	if (lzpVal1->mi1TNo[D_WAY_GO] > lzpVal2->mi1TNo[D_WAY_GO]) {
		return(1);
	}
	else if (lzpVal1->mi1TNo[D_WAY_GO] < lzpVal2->mi1TNo[D_WAY_GO]) {
		return(-1);
	}

	return 0;
}

// ????? - ???? - ?(??)??
int
fSortFncB(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Road *lzpVal1 = (Road *)pzpVal1;
	Road *lzpVal2 = (Road *)pzpVal2;

	// ?(??)??
	if (lzpVal1->mi1TNo[D_WAY_BACK] > lzpVal2->mi1TNo[D_WAY_BACK]) {
		return(1);
	}
	else if (lzpVal1->mi1TNo[D_WAY_BACK] < lzpVal2->mi1TNo[D_WAY_BACK]) {
		return(-1);
	}

	return 0;
}

// ??? - ????????
// ????[>=0]:?????????? [-1]:????
int
fHeapChk(
	int piPNo					// <I> ?????? 0?
)
{
	// ???
	int liMNo = piPNo;

	// ??????
	int liCNo = piPNo * 2 + 1;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].miTSum > sz1Heap[liCNo].miTSum) {
			liMNo = liCNo;
		}
	}

	// ??????
	liCNo = piPNo * 2 + 2;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].miTSum > sz1Heap[liCNo].miTSum) {
			liMNo = liCNo;
		}
	}

	// ??????????????
	if (piPNo == liMNo) {
		return -1;
	}

	// ????
	Heap lzWork;
	memcpy(&lzWork, &sz1Heap[liMNo], sizeof(Heap));
	memcpy(&sz1Heap[liMNo], &sz1Heap[piPNo], sizeof(Heap));
	memcpy(&sz1Heap[piPNo], &lzWork, sizeof(Heap));

	return liMNo;
}

// ??? - ?????
int
fHeapEnqueue(
	int piTNo					// <I> ? 1?
	, int piTSum				// <I> ?????????
)
{
	int liRet;

	// ?????
	sz1Heap[siHCnt].miTNo = piTNo;
	sz1Heap[siHCnt].miTSum = piTSum;
	siHCnt++;

	// ????????
	int liNo = siHCnt - 1;
	while (1) {

		// ??????
		liNo = (liNo - 1) / 2;

		// ????????
		liRet = fHeapChk(liNo);
		if (liRet < 0) {
			break;
		}
	}

	return 0;
}

// ??? - ?????
int
fHeapDequeue(
	Heap *pzpRet				// <O> ???
)
{
	// ????
	if (siHCnt < 1) {
		return -1;
	}

	// ??
	memcpy(pzpRet, &sz1Heap[0], sizeof(Heap));
	siHCnt--;

	// ????
	if (siHCnt < 1) {
		return 0;
	}

	// ??????
	memcpy(&sz1Heap[0], &sz1Heap[siHCnt], sizeof(Heap));

	// ????????
	int liNo = 0;
	while (liNo >= 0) {
		liNo = fHeapChk(liNo);
	}

	return 0;
}

// ????????? - ??? - ??????
int
fSetTSumOne(
	int piWay					// <I> ??
	, int piTNo					// <I> ? 1?
	, int piTime				// <I> ?????????
)
{
	// ????????? - ????
	if (siTime < piTime) {
		return 0;
	}
	if (sz1Town[piTNo].mi1TSum[piWay] <= piTime) {
		return 0;
	}

	// ????????? - ???
	sz1Town[piTNo].mi1TSum[piWay] = piTime;

	// ????
	int liWayO;
	if (piWay == D_WAY_GO) {
		liWayO = D_WAY_BACK;
	}
	else {
		liWayO = D_WAY_GO;
	}

	// ????
	int liRNo;
	for (liRNo = sz1Town[piTNo].miRSNo; liRNo <= sz1Town[piTNo].miRENo; liRNo++) {
		fHeapEnqueue(sz1Road[liRNo].mi1TNo[liWayO], piTime + sz1Road[liRNo].miTime);
	}

	return 0;
}

// ????????? - ???
int
fSetTSum(
	int piWay					// <I> ??
)
{
	int i, liRet;

	// ? - ???
	for (i = 1; i <= siTCnt; i++) {
		sz1Town[i].mi1TSum[piWay] = INT_MAX;		// ?????????
		sz1Town[i].miRSNo = -1;						// ?? - ??
		sz1Town[i].miRENo = -2;						// ?? - ??
	}

	// ?? - ???
	if (piWay == D_WAY_GO) {
		qsort(sz1Road, siRCnt, sizeof(Road), fSortFncG);
	}
	else {
		qsort(sz1Road, siRCnt, sizeof(Road), fSortFncB);
	}

	// ? - ??????
	for (i = 0; i < siRCnt; i++) {
		Town *lzpTown = &sz1Town[sz1Road[i].mi1TNo[piWay]];

		// ?? - ??
		if (lzpTown->miRSNo < 0) {
			lzpTown->miRSNo = i;
		}

		// ?? - ??
		lzpTown->miRENo = i;
	}

	// ??? - ???
	siHCnt = 0;
	Heap lzHeap;
	lzHeap.miTNo = 1;
	lzHeap.miTSum = 0;

	// ???
	while (1) {

		// ??????
		fSetTSumOne(piWay, lzHeap.miTNo, lzHeap.miTSum);

		// ?????
		liRet = fHeapDequeue(&lzHeap);
		if (liRet != 0) {
			break;
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

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siTCnt, &siRCnt, &siTime);

	// ?? - ??
	for (i = 1; i <= siTCnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &sz1Town[i].miMoney);
#else
		fscanf(stdin, "%d", &sz1Town[i].miMoney);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ?? - ??
	for (i = 0; i < siRCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &sz1Road[i].mi1TNo[D_WAY_GO], &sz1Road[i].mi1TNo[D_WAY_BACK], &sz1Road[i].miTime);
	}

	// ????????? - ???
	fSetTSum(D_WAY_GO);
	fSetTSum(D_WAY_BACK);

	// ??????????
	long long llMax = 0;
	for (i = 1; i <= siTCnt; i++) {

		// ?????????????
		if (sz1Town[i].mi1TSum[D_WAY_GO] == INT_MAX) {
			continue;
		}
		if (sz1Town[i].mi1TSum[D_WAY_BACK] == INT_MAX) {
			continue;
		}

		// ????
		int liTime = siTime - sz1Town[i].mi1TSum[D_WAY_GO] - sz1Town[i].mi1TSum[D_WAY_BACK];
		if (liTime < 1) {
			continue;
		}

		// ????
		long long llMoney = (long long)sz1Town[i].miMoney * (long long)liTime;
		if (llMax < llMoney) {
			llMax = llMoney;
		}
	}

	// ?????
	sprintf(lc1Out, "%lld\n", llMax);

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
./Main.c:312:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:321:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &sz1Town[i].miMoney);
   ^
./Main.c:327:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:335:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^