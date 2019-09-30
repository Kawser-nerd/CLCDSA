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

// ????? - ???
typedef struct Edge {
	int miVNo;													// ????
	struct Edge *mzpNext;										// ?????
} Edge;

// ????? - ????
typedef struct Vtx {
	int miJewel;												// ????
	Edge *mzpEdge;												// ???
	int miH;													// ?? 1?
	int miDone;													// ??????
} Vtx;

// ????
static FILE *szpFpI;											// ??
static Vtx sz1Vtx[D_VTX_MAX];									// ??
static int siVCnt;												// ???
static Edge sz1Edge[D_VTX_MAX * 2];								// ?
static int siECnt;												// ??

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
)
{
	sz1Edge[siECnt].miVNo = piVTNo;
	sz1Edge[siECnt].mzpNext = sz1Vtx[piVFNo].mzpEdge;
	sz1Vtx[piVFNo].mzpEdge = &sz1Edge[siECnt];
	siECnt++;

	return 0;
}

// ?? - ???
int
fSetH(
	int piFNo					// <I> ?? 0?
	, int piH					// <I> ?? 1?
)
{
	// ????
	if (sz1Vtx[piFNo].miH > 0) {
		return 0;
	}

	// ???
	sz1Vtx[piFNo].miH = piH;

	// ?????
	Edge *lzpEdge = sz1Vtx[piFNo].mzpEdge;
	while (lzpEdge != NULL) {

		// ???
		fSetH(lzpEdge->miVNo, piH + 1);

		// ????
		lzpEdge = lzpEdge->mzpNext;
	}

	return 0;
}

// ??????? - ??
int
fGetVNo(
	int piSNo					// <I> ????
)
{
	int i;

	for (i = piSNo; i < siVCnt; i++) {

		// ??????
		if (sz1Vtx[i].miDone != D_OFF) {
			continue;
		}
		sz1Vtx[i].miDone = D_ON;

		// ????
		if (sz1Vtx[i].miJewel == D_ON) {
			return i;
		}
	}

	return -1;
}

// ???????????????
int
fGetUpH(
	int piFNo					// <I> ?? 0?
)
{
	// ?????
	Edge *lzpEdge = sz1Vtx[piFNo].mzpEdge;
	while (lzpEdge != NULL) {
		int liVNo = lzpEdge->miVNo;

		// ??
		if (sz1Vtx[liVNo].miH + 1 == sz1Vtx[piFNo].miH) {
			sz1Vtx[liVNo].miJewel = D_ON;						// ?????
			sz1Vtx[liVNo].miDone = D_ON;						// ??????
			return liVNo;
		}

		// ????
		lzpEdge = lzpEdge->mzpNext;
	}

	return 0;
}

// ??? - ??
int
fGetJCnt(
	int piFNo					// <I> ?? 0?
)
{
	// ??????
	if (sz1Vtx[piFNo].miDone != D_OFF) {
		return 0;
	}
	sz1Vtx[piFNo].miDone = D_ON;

	// ????
	if (sz1Vtx[piFNo].miJewel != D_ON) {	// ??
		return 0;
	}

	// ???
	int liJCnt = 1;

	// ?????
	Edge *lzpEdge = sz1Vtx[piFNo].mzpEdge;
	while (lzpEdge != NULL) {

		// ???
		liJCnt += fGetJCnt(lzpEdge->miVNo);

		// ????
		lzpEdge = lzpEdge->mzpNext;
	}

	return liJCnt;
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

	// ???????? - ??
	int liSNo;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siVCnt, &liSNo);
	liSNo--;

	// ???? - ??
	for (i = 0; i < siVCnt; i++) {
		fscanf(szpFpI, "%d", &sz1Vtx[i].miJewel);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ???? - ?????
	sz1Vtx[liSNo].miJewel = D_ON;

	// ? - ??
	int liNo = 0;
	for (i = 0; i < siVCnt - 1; i++) {
		int liVNo1, liVNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVNo1, &liVNo2);
		liVNo1--;
		liVNo2--;

		// ? - ??
		fAddEdge(liVNo1, liVNo2);
		fAddEdge(liVNo2, liVNo1);
	}

	// ?? - ???
	fSetH(0, 1);

	// ??????? - ??
	int liVNo1 = fGetVNo(0);

	// ???????
	liSNo = liVNo1 + 1;
	while (1) {
		int liVNo2 = fGetVNo(liSNo);
		if (liVNo2 < 0) {						// ??
			break;
		}
		liSNo = liVNo2 + 1;

		// ?????????????
		while (1) {
			if (sz1Vtx[liVNo1].miH < sz1Vtx[liVNo2].miH) {
				liVNo2 = fGetUpH(liVNo2);
			}
			else if (sz1Vtx[liVNo1].miH > sz1Vtx[liVNo2].miH) {
				liVNo1 = fGetUpH(liVNo1);
			}
			else if (liVNo1 != liVNo2) {
				liVNo1 = fGetUpH(liVNo1);
				liVNo2 = fGetUpH(liVNo2);
			}
			else {
				break;
			}
		}
	}

	// ?????? - ???
	for (i = 0; i < siVCnt; i++) {
		sz1Vtx[i].miDone = D_OFF;
	}

	// ??? - ??
	int liJCnt = fGetJCnt(liVNo1);

	// ?? - ???
	sprintf(lc1Out, "%d\n", (liJCnt - 1) * 2);

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
./Main.c:194:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:200:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &sz1Vtx[i].miJewel);
   ^
./Main.c:202:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:211:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^