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
#define D_EDGE_MAX		(D_VTX_MAX * D_VTX_MAX)					// ????

// ????? - ???
typedef struct Edge {
	int miVNo;													// ?????
	struct Edge *mzpNext;										// ?????
} Edge;

// ????? - ????
typedef struct Vtx {
	Edge *mzpEdge;												// ?
	int miDone;													// ??????
} Vtx;

// ????
static FILE *szpFpI;											// ??
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ??
static int siVCnt;												// ???
static Edge sz1Edge[D_EDGE_MAX * 2];							// ?
static int siECnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????????
int
fIsTree(
	int piVNo					// <I> ?? 1?
	, int piPNo					// <I> ??????
)
{
	int liRet;

	// ??????
	if (sz1Vtx[piVNo].miDone != D_OFF) {
		return -1;
	}
	sz1Vtx[piVNo].miDone = D_ON;

	// ?????
	Edge *lzpEdge = sz1Vtx[piVNo].mzpEdge;
	while (lzpEdge != NULL) {

		// ?????????
		if (lzpEdge->miVNo != piPNo) {
			liRet = fIsTree(lzpEdge->miVNo, piVNo);
			if (liRet != 0) {
				return -1;
			}
		}

		// ?????
		lzpEdge = lzpEdge->mzpNext;
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

	// ??? - ???
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// ??
	siECnt = 0;													// ??

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

	// ?????? - ??
	int liECnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siVCnt, &liECnt);

	// ? - ??
	for (i = 0; i < liECnt; i++) {
		int liVNo1, liVNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVNo1, &liVNo2);

		// ? - ??
		sz1Edge[siECnt].miVNo = liVNo2;
		sz1Edge[siECnt].mzpNext = sz1Vtx[liVNo1].mzpEdge;
		sz1Vtx[liVNo1].mzpEdge = &sz1Edge[siECnt];
		siECnt++;
		sz1Edge[siECnt].miVNo = liVNo1;
		sz1Edge[siECnt].mzpNext = sz1Vtx[liVNo2].mzpEdge;
		sz1Vtx[liVNo2].mzpEdge = &sz1Edge[siECnt];
		siECnt++;
	}

	// ???? - ??
	int liCnt = 0;
	for (i = 1; i <= siVCnt; i++) {
		if (sz1Vtx[i].miDone == D_OFF) {	// ???
			liRet = fIsTree(i, 0);
			if (liRet == 0) {
				liCnt++;
			}
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:99:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:105:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^