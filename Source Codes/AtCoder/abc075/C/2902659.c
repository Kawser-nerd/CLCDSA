#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_VTX_MAX		50										// ?????

// ????? - ????
typedef struct Vtx {
	int mi1Vtx[D_VTX_MAX + 5];									// ????
	int miVCnt;													// ?????
	int miChk;													// ????????
} Vtx;

// ????? - ???
typedef struct Edge {
	int miVNo1;													// ???
	int miVNo2;													// ???
} Edge;

// ????
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ????
static int siVCnt;												// ?????
static Edge sz1Edge[D_VTX_MAX];									// ???
static int siECnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ???? - ???
int
fVtxEdgeAdd(
	int piVNo1					// <I> ???
	, int piVNo2				// <I> ???
)
{
	// ?????
	Vtx *lzpVtx = &sz1Vtx[piVNo1];

	// ????
	lzpVtx->mi1Vtx[lzpVtx->miVCnt] = piVNo2;

	// ?????
	lzpVtx->miVCnt++;

	return 0;
}

// ???? - ???
int
fVtxEdgeDel(
	int piVNo1					// <I> ???
	, int piVNo2				// <I> ???
)
{
	int i;

	// ?????
	Vtx *lzpVtx = &sz1Vtx[piVNo1];

	// ?????
	lzpVtx->miVCnt--;
	if (lzpVtx->miVCnt < 1) {
		return 0;
	}

	// ??????
	int liNo;
	for (i = 0; i <= lzpVtx->miVCnt; i++) {
		if (lzpVtx->mi1Vtx[i] == piVNo2) {
			liNo = i;
			break;
		}
	}
	if (liNo >= lzpVtx->miVCnt) {		// ?????
		return 0;
	}

	// ???? - ?????????
	lzpVtx->mi1Vtx[liNo] = lzpVtx->mi1Vtx[lzpVtx->miVCnt];

	return 0;
}

// ???? - ??????
int
fVtxConvChk(
	int piVNo1					// <I> ???
	, int piVNo2				// <I> ???
)
{
	int i, liRet;

	// ??????
	if (piVNo1 == piVNo2) {
		return 0;
	}

	// ?????
	Vtx *lzpVtx = &sz1Vtx[piVNo1];

	// ????????
	if (lzpVtx->miChk != D_OFF) {
		return -1;
	}
	lzpVtx->miChk = D_ON;

	// ???????
	for (i = 0; i < lzpVtx->miVCnt; i++) {
		liRet = fVtxConvChk(lzpVtx->mi1Vtx[i], piVNo2);
		if (liRet == 0) {
			return 0;
		}
	}

	return -1;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(sz1Vtx, D_OFF, sizeof(sz1Vtx));						// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siVCnt, &siECnt);

	// ?????
	for (i = 0; i < siECnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Edge[i].miVNo1, &sz1Edge[i].miVNo2);

		// ???? - ???
		fVtxEdgeAdd(sz1Edge[i].miVNo1, sz1Edge[i].miVNo2);
		fVtxEdgeAdd(sz1Edge[i].miVNo2, sz1Edge[i].miVNo1);
	}

	// ?????
	int liCnt = 0;
	for (i = 0; i < siECnt; i++) {

		// ???? - ???
		fVtxEdgeDel(sz1Edge[i].miVNo1, sz1Edge[i].miVNo2);
		fVtxEdgeDel(sz1Edge[i].miVNo2, sz1Edge[i].miVNo1);

		// ???? - ???????????
		for (j = 1; j <= siVCnt; j++) {
			sz1Vtx[j].miChk = D_OFF;
		}

		// ???? - ??????
		liRet = fVtxConvChk(sz1Edge[i].miVNo1, sz1Edge[i].miVNo2);
		if (liRet != 0) {												// ???
			liCnt++;
		}

		// ???? - ???
		fVtxEdgeAdd(sz1Edge[i].miVNo1, sz1Edge[i].miVNo2);
		fVtxEdgeAdd(sz1Edge[i].miVNo2, sz1Edge[i].miVNo1);
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
./Main.c:152:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:161:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^