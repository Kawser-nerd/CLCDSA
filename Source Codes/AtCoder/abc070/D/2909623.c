#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		100000									// ?????

// ????? - ???
typedef struct Edge {
	int miVFNo;													// ?? - ? 1?
	int miVTNo;													// ?? - ? 1?
	int miLen;													// ??
} Edge;

// ????? - ????
typedef struct Vtx {
	int miESNo;													// ? - ?? 0?
	int miEENo;													// ? - ?? 0?
	long long mlLen;											// ???????????
} Vtx;

// ????? - ?????
typedef struct Heap {
	int miVNo;													// ?? 1?
	long long mlLen;											// ????
} Heap;

// ????
static Edge sz1Edge[D_VTX_MAX * 2];								// ?
static int siECnt;												// ??
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ??
static int siVCnt;												// ???
static Heap sz1Heap[D_VTX_MAX * 2];								// ???
static int siHCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ? - ??
int
fEdgeAdd(
	int piVFNo					// <I> ?? - ? 1?
	, int piVTNo				// <I> ?? - ? 1?
	, int piLen					// <I> ??
)
{
	// ?????
	Edge *lzpEdge = &sz1Edge[siECnt];

	// ???
	lzpEdge->miVFNo = piVFNo;
	lzpEdge->miVTNo = piVTNo;
	lzpEdge->miLen = piLen;

	// ??
	siECnt++;

	return 0;
}

// ? - ????? - ??(?)??
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
		if (sz1Heap[liMNo].mlLen > sz1Heap[liCNo].mlLen) {
			liMNo = liCNo;
		}
	}

	// ??????
	liCNo = piPNo * 2 + 2;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].mlLen > sz1Heap[liCNo].mlLen) {
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
	int piVNo					// <I> ?? 1?
	, long long plLen			// <I> ????
)
{
	int liRet;

	// ?????
	sz1Heap[siHCnt].miVNo = piVNo;
	sz1Heap[siHCnt].mlLen = plLen;
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

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siECnt = 0;													// ??
	siHCnt = 0;													// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siVCnt);

	// ?? - ???
	for (i = 1; i <= siVCnt; i++) {
		sz1Vtx[i].miESNo = -1;									// ? - ?? 0?
		sz1Vtx[i].mlLen = -1;									// ???????????
	}

	// ???
	for (i = 0; i < siVCnt - 1; i++) {
		int liNo1, liNo2, liLen;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &liNo1, &liNo2, &liLen);

		// ? - ??
		fEdgeAdd(liNo1, liNo2, liLen);
		fEdgeAdd(liNo2, liNo1, liLen);
	}

	// ? - ???
	qsort(sz1Edge, siECnt, sizeof(Edge), fSortFnc);

	// ?? - ????
	for (i = 0; i < siECnt; i++) {

		// ?????
		Vtx *lzpVtx = &sz1Vtx[sz1Edge[i].miVFNo];

		// ? - ??
		if (lzpVtx->miESNo < 0) {		// ??
			lzpVtx->miESNo = i;
		}

		// ? - ??
		lzpVtx->miEENo = i;
	}

	// ???????????
	int liQCnt, liKNo;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liQCnt, &liKNo);

	// ???????????????
	fHeapEnqueue(liKNo, 0);				// ?????
	while (1) {

		// ?????
		Heap lzHeap;
		liRet = fHeapDequeue(&lzHeap);
		if (liRet != 0) {
			break;
		}

		// ?????
		Vtx *lzpVtx = &sz1Vtx[lzHeap.miVNo];

		// ???????????
		if (lzpVtx->mlLen >= 0) {
			continue;
		}
		lzpVtx->mlLen = lzHeap.mlLen;

		// ?????(?????)
		for (i = lzpVtx->miESNo; i <= lzpVtx->miEENo; i++) {
			fHeapEnqueue(sz1Edge[i].miVTNo, lzpVtx->mlLen + (long long)sz1Edge[i].miLen);
		}
	}

	// ????????
	for (i = 0; i < liQCnt; i++) {

		// ?????
		int liVFNo, liVTNo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liVFNo, &liVTNo);

		// ??
		long long llLen = sz1Vtx[liVFNo].mlLen + sz1Vtx[liVTNo].mlLen;

		// ????
		sprintf(lc1Out, "%lld\n", llLen);
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
./Main.c:217:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:233:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:265:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:303:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^