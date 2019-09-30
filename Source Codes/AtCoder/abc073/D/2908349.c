#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_TOWN_MAX		200										// ????
#define D_VISIT_MAX		8										// ??????

// ????? - ???
typedef struct Town {
	int mi1TNo[D_TOWN_MAX];										// ??? 1?
	int mi1Len[D_TOWN_MAX];										// ????????
	int miTCnt;													// ????
	int miMin;													// ???????????
} Town;

// ????? - ?????
typedef struct Heap {
	int miTNo;													// ??? 1?
	int miLen;													// ??????????
} Heap;

// ????
static Town sz1Town[D_TOWN_MAX + 5];							// ???
static int siTCnt;												// ????
static int si1Visit[D_VISIT_MAX];								// ???
static int siVCnt;												// ????
static Heap sz1Heap[D_TOWN_MAX * D_TOWN_MAX];					// ???
static int siHCnt;												// ????
static int si2Min[D_VISIT_MAX + 5][D_VISIT_MAX + 5];			// ?????????
static int siMin;												// ????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????????
int
fSetTown(
	int piTNo1					// <I> ???? 1?
	, int piTNo2				// <I> ???? 1?
	, int piLen					// <I> ??
)
{
	// ?????
	Town *lzpTown = &sz1Town[piTNo1];

	// ???
	lzpTown->mi1TNo[lzpTown->miTCnt] = piTNo2;		// ???
	lzpTown->mi1Len[lzpTown->miTCnt] = piLen;		// ????????
	lzpTown->miTCnt++;								// ????
	
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
		if (sz1Heap[liMNo].miLen > sz1Heap[liCNo].miLen) {
			liMNo = liCNo;
		}
	}

	// ??????
	liCNo = piPNo * 2 + 2;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].miLen > sz1Heap[liCNo].miLen) {
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
	int piTNo					// <I> ??? 1?
	, int piLen					// <I> ??????????
)
{
	int liRet;

	// ?????
	sz1Heap[siHCnt].miTNo = piTNo;
	sz1Heap[siHCnt].miLen = piLen;
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

// ???????????????
int
fSetTownMin(
)
{
	int i, liRet;

	while (1) {

		// ?????
		Heap lzHeap;
		liRet = fHeapDequeue(&lzHeap);
		if (liRet != 0) {
			break;
		}

		// ?????
		Town *lzpTown = &sz1Town[lzHeap.miTNo];

		// ??????????
		if (lzpTown->miMin >= 0) {
			continue;
		}

		// ???
		lzpTown->miMin = lzHeap.miLen;

		// ?????
		for (i = 0; i < lzpTown->miTCnt; i++) {
			fHeapEnqueue(lzpTown->mi1TNo[i], lzpTown->miMin + lzpTown->mi1Len[i]);
		}
	}

	return 0;
}

// ?????????????
int
fSetVisit(
	int piVNo					// <I> ??? 0?
)
{
	int i;

	// ???????????????
	for (i = 1; i <= siTCnt; i++) {
		sz1Town[i].miMin = -1;
	}

	// ???????????????
	fHeapEnqueue(si1Visit[piVNo], 0);		// ?????
	fSetTownMin();

	// ?????????????
	for (i = 0; i < siVCnt; i++) {
		if (i != piVNo) {
			si2Min[piVNo][i] = sz1Town[si1Visit[i]].miMin;
		}
	}

	return 0;
}

// ????????????
int
fSetMin(
	int piVNo					// <I> ????
	, int *pipVNo				// <I> ????
	, int piVCnt				// <I> ?????
	, int piLen					// <I> ??
)
{
	int i;

	// ???????
	if (pipVNo[piVNo] != D_OFF) {
		return 0;
	}

	// ????
	if (piVCnt == siVCnt - 1) {

		// ??????????
		if (siMin > piLen) {
			siMin = piLen;
		}

		return 0;
	}

	// ??
	pipVNo[piVNo] = D_ON;

	// ????
	for (i = 0; i < siVCnt; i++) {
		fSetMin(i, pipVNo, piVCnt + 1, piLen + si2Min[piVNo][i]);
	}

	// ????
	pipVNo[piVNo] = D_OFF;

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
	memset(sz1Town, 0, sizeof(sz1Town));						// ???
	siHCnt = 0;													// ????
	siMin = INT_MAX;											// ????????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????????????
	int liRCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siTCnt, &liRCnt, &siVCnt);

	// ?????
	for (i = 0; i < siVCnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &si1Visit[i]);
#else
		fscanf(stdin, "%d", &si1Visit[i]);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ????
	for (i = 0; i < liRCnt; i++) {
		int liTNo1, liTNo2, liLen;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &liTNo1, &liTNo2, &liLen);

		// ?????????
		fSetTown(liTNo1, liTNo2, liLen);
		fSetTown(liTNo2, liTNo1, liLen);
	}

	// ?????????????
	for (i = 0; i < siVCnt; i++) {
		fSetVisit(i);
	}

	// ????????????
	int li1VNo[D_VISIT_MAX];
	memset(li1VNo, D_OFF, sizeof(li1VNo));
	for (i = 0; i < siVCnt; i++) {
		fSetMin(i, li1VNo, 0, 0);
	}

	// ?????
	sprintf(lc1Out, "%d\n", siMin);

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
./Main.c:307:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &si1Visit[i]);
   ^
./Main.c:313:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:322:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^