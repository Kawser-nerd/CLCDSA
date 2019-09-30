#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_VTX_MAX		105										// ?????
#define D_EDGE_MAX		(D_VTX_MAX * D_VTX_MAX)					// ????

// ????? - ???
typedef struct Edge {
	int miCap;													// ??
	int miVNo;													// ?????
	struct Edge *mzpRev;										// ?????
	struct Edge *mzpNext;										// ???(????)
} Edge;

// ????? - ????
typedef struct Vtx {
	Edge *mzpEdge;												// ?
	int miDone;													// ??????
} Vtx;

// ????
static FILE *szpFpI;											// ??
static Edge sz1Edge[D_EDGE_MAX];								// ?
static int siECnt;												// ??
static Vtx sz1Vtx[D_VTX_MAX];									// ??
static int siVCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ? - ??
int
fAddEdge(
	int piVFNo					// <I> ?? - ? 0?
	, int piVTNo				// <I> ?? - ? 0?
	, int piEdge				// <I> ??
)
{
	// ??(?)?
	Edge *lzpFrom = &sz1Edge[siECnt];
	siECnt++;
	lzpFrom->miCap = piEdge;
	lzpFrom->miVNo = piVTNo;
	lzpFrom->mzpNext = sz1Vtx[piVFNo].mzpEdge;
	sz1Vtx[piVFNo].mzpEdge = lzpFrom;

	// ??(?)?
	Edge *lzpTo = &sz1Edge[siECnt];
	siECnt++;
	lzpTo->miCap = piEdge;
	lzpTo->miVNo = piVFNo;
	lzpTo->mzpNext = sz1Vtx[piVTNo].mzpEdge;
	sz1Vtx[piVTNo].mzpEdge = lzpTo;

	// ?????
	lzpFrom->mzpRev = lzpTo;
	lzpTo->mzpRev = lzpFrom;

	return 0;
}

// ??? - ?? - ????
int
fGetMaxFlowOne(
	int piVSNo					// <I> ??
	, int piVENo				// <I> ??
	, int piFlow				// <I> ??
)
{
	// ??????
	if (sz1Vtx[piVSNo].miDone != D_OFF) {
		return 0;
	}
	sz1Vtx[piVSNo].miDone = D_ON;

	// ??????
	if (piVSNo == piVENo) {
		return piFlow;
	}

	// ??
	Edge *lzpEdge = sz1Vtx[piVSNo].mzpEdge;
	while (lzpEdge != NULL) {

		// ??
		int liFlow = lzpEdge->miCap;
		if (liFlow < 1) {											// ??
			lzpEdge = lzpEdge->mzpNext;									// ????
			continue;
		}
		if (liFlow > piFlow) {
			liFlow = piFlow;
		}

		// ???
		liFlow = fGetMaxFlowOne(lzpEdge->miVNo, piVENo, liFlow);
		if (liFlow < 1) {											// ??
			lzpEdge = lzpEdge->mzpNext;									// ????
			continue;
		}

		// ?? - ?????
		lzpEdge->miCap -= liFlow;
		lzpEdge->mzpRev->miCap += liFlow;

		return liFlow;
	}

	return 0;
}

// ??? - ??
int
fGetMaxFlow(
	int piVSNo					// <I> ??
	, int piVENo				// <I> ??
)
{
	int i;

	int liSum = 0;
	while (1) {

		// ?????? - ???
		for (i = 0; i < siVCnt; i++) {
			sz1Vtx[i].miDone = D_OFF;
		}

		// ???? - ??
		int liFlow = fGetMaxFlowOne(piVSNo, piVENo, INT_MAX);
		if (liFlow < 1) {											// ??
			break;
		}

		// ?? - ??
		liSum += liFlow;
	}

	return liSum;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sz1Edge, 0, sizeof(sz1Edge));						// ?
	siECnt = 0;													// ??
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// ??

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
	int liMCnt, liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siVCnt, &liMCnt, &liRCnt);
	siVCnt++;

	// ??? - ??
	for (i = 0; i < liMCnt; i++) {
		int liVNo;
		fscanf(szpFpI, "%d", &liVNo);

		// ? - ??
		fAddEdge(liVNo, siVCnt - 1, 1);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?? - ??
	for (i = 0; i < liRCnt; i++) {
		int liVNo1, liVNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVNo1, &liVNo2);

		// ? - ??
		fAddEdge(liVNo1, liVNo2, 1);
	}

	// ??? - ??
	int liMax = fGetMaxFlow(0, siVCnt - 1);

	// ?? - ???
	sprintf(lc1Out, "%d\n", liMax);

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
./Main.c:180:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:187:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liVNo);
   ^
./Main.c:192:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:197:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^