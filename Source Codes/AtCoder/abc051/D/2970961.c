#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_VTX_MAX		100										// ?????
#define D_EDGE_MAX		1000									// ????

// ????? - ????
typedef struct Vtx {
	int miESNo;													// ??? - ??
	int miEENo;													// ??? - ??
	int miLen;													// ???????????
} Vtx;

// ????? - ???
typedef struct Edge {
	int miENNo;													// ??? 0?
	int miVFNo;													// ?? - ?
	int miVTNo;													// ?? - ?
	int miLen;													// ??
	int miUse;													// ?????????
} Edge;

// ????
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ??
static int siVCnt;												// ???
static Edge sz1EdgeN[D_EDGE_MAX];								// ???
static int siENCnt;												// ????
static Edge sz1EdgeD[D_EDGE_MAX * 2];							// ???
static int siEDCnt;												// ????
static Edge sz1Heap[D_EDGE_MAX * 2];							// ???
static int siHCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ? - ??(?)??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Edge *lzpVal1 = (Edge *)pzpVal1;
	Edge *lzpVal2 = (Edge *)pzpVal2;

	// ??(?)??
	if (lzpVal1->miVFNo > lzpVal2->miVFNo) {
		return(1);
	}
	else if (lzpVal1->miVFNo < lzpVal2->miVFNo) {
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
	Edge lzWork;
	memcpy(&lzWork, &sz1Heap[liMNo], sizeof(Edge));
	memcpy(&sz1Heap[liMNo], &sz1Heap[piPNo], sizeof(Edge));
	memcpy(&sz1Heap[piPNo], &lzWork, sizeof(Edge));

	return liMNo;
}

// ??? - ?????
int
fHeapEnqueue(
	Edge *pzpEdge				// <I> ?
	, int piAdd					// <I> ????
)
{
	int liRet;

	// ?????
	memcpy(&sz1Heap[siHCnt], pzpEdge, sizeof(Edge));
	sz1Heap[siHCnt].miLen += piAdd;
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
	Edge *pzpRet				// <O> ???
)
{
	// ????
	if (siHCnt < 1) {
		return -1;
	}

	// ??
	memcpy(pzpRet, &sz1Heap[0], sizeof(Edge));
	siHCnt--;

	// ????
	if (siHCnt < 1) {
		return 0;
	}

	// ??????
	memcpy(&sz1Heap[0], &sz1Heap[siHCnt], sizeof(Edge));

	// ????????
	int liNo = 0;
	while (liNo >= 0) {
		liNo = fHeapChk(liNo);
	}

	return 0;
}

// ????????????? - ???????????
int
fSetUseLen(
	int piVNo					// <I> ?? 1?
	, int piLen					// <I> ?? 1?
)
{
	int i, liRet;

	// ????
	Vtx *lzpVtx = &sz1Vtx[piVNo];

	// ??
	if (lzpVtx->miLen > 0) {
		return -1;
	}
	lzpVtx->miLen = piLen;

	// ??????
	for (i = lzpVtx->miESNo; i <= lzpVtx->miEENo; i++) {
		fHeapEnqueue(&sz1EdgeD[i], piLen);
	}

	while (1) {

		// ???????
		Edge lzEdge;
		liRet = fHeapDequeue(&lzEdge);
		if (liRet != 0) {
			break;
		}

		// ?????
		liRet = fSetUseLen(lzEdge.miVTNo, lzEdge.miLen);
		if (liRet == 0) {
			sz1EdgeN[lzEdge.miENNo].miUse = D_ON;		// ?????
		}
	}

	return 0;
}

// ?????????????
int
fSetUse(
	int piVNo					// <I> ?? 1?
)
{
	int i;

	// ??????????? - ???
	for (i = 1; i <= siVCnt; i++) {
		sz1Vtx[i].miLen = 0;
	}

	// ????
	siHCnt = 0;

	// ??????????? - ???
	fSetUseLen(piVNo, 1);

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
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// ??
	memset(sz1EdgeN, 0, sizeof(sz1EdgeN));						// ???
	siEDCnt = 0;												// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siVCnt, &siENCnt);

	// ?????
	for (i = 0; i < siENCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &sz1EdgeN[i].miVFNo, &sz1EdgeN[i].miVTNo, &sz1EdgeN[i].miLen);
		sz1EdgeN[i].miENNo = i;
	}

	// ??? - ???
	for (i = 0; i < siENCnt; i++) {
		sz1EdgeD[siEDCnt].miENNo = sz1EdgeN[i].miENNo;
		sz1EdgeD[siEDCnt].miVFNo = sz1EdgeN[i].miVFNo;
		sz1EdgeD[siEDCnt].miVTNo = sz1EdgeN[i].miVTNo;
		sz1EdgeD[siEDCnt].miLen = sz1EdgeN[i].miLen;
		siEDCnt++;

		sz1EdgeD[siEDCnt].miENNo = sz1EdgeN[i].miENNo;
		sz1EdgeD[siEDCnt].miVFNo = sz1EdgeN[i].miVTNo;
		sz1EdgeD[siEDCnt].miVTNo = sz1EdgeN[i].miVFNo;
		sz1EdgeD[siEDCnt].miLen = sz1EdgeN[i].miLen;
		siEDCnt++;
	}

	// ??? - ???
	qsort(sz1EdgeD, siEDCnt, sizeof(Edge), fSortFnc);

	// ?????? - ???
	for (i = 1; i <= siVCnt; i++) {
		sz1Vtx[i].miESNo = -1;
	}

	// ?????? - ???
	for (i = 0; i < siEDCnt; i++) {
		Vtx *lzpVtx = &sz1Vtx[sz1EdgeD[i].miVFNo];

		// ??? - ??
		if (lzpVtx->miESNo < 0) {
			lzpVtx->miESNo = i;
		}

		// ??? - ??
		lzpVtx->miEENo = i;
	}

	// ?????????????
	for (i = 1; i <= siVCnt; i++) {
		fSetUse(i);
	}

	// ????????
	int liCnt = 0;
	for (i = 0; i < siENCnt; i++) {
		if (sz1EdgeN[i].miUse == D_OFF) {
			liCnt++;
		}
	}

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
./Main.c:261:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:270:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^