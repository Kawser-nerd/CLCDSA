#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_VTX_MAX		1000									// ?????
#define D_EDGE_MAX		2000									// ????

// ????? - ????
typedef struct Vtx {
	long long mlScore;											// ???
	int miInf;													// ?????
} Vtx;

// ????? - ???
typedef struct Edge {
	int miVFNo;													// ?? - ? 1?
	int miVTNo;													// ?? - ? 1?
	int miScore;												// ???
} Edge;

// ????
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ??
static int siVCnt;												// ???
static Edge sz1Edge[D_EDGE_MAX];								// ?
static int siECnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ???? - ?????????
int
fUpVtx(
	int piInf					// <I> ???????? [1]?? [0]??
)
{
	int i, j;

	// ?????? - ??(????????????????? - ??????)
	for (i = 0; i < siVCnt; i++) {
		for (j = 0; j < siECnt; j++) {

			// ??(?)
			Vtx *lzpVtxF = &sz1Vtx[sz1Edge[j].miVFNo];

			// ????
			if (lzpVtxF->mlScore == LLONG_MIN) {
				continue;
			}

			// ???
			long long llSocre = lzpVtxF->mlScore + (long long)sz1Edge[j].miScore;

			// ??(?)
			Vtx *lzpVtxT = &sz1Vtx[sz1Edge[j].miVTNo];
			if (lzpVtxT->mlScore < llSocre) {
				lzpVtxT->mlScore = llSocre;

				if (piInf == D_ON) {
					lzpVtxT->miInf = D_ON;
				}
			}
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
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// ??

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siVCnt, &siECnt);

	// ???
	for (i = 0; i < siECnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &sz1Edge[i].miVFNo, &sz1Edge[i].miVTNo, &sz1Edge[i].miScore);
	}

	// ?????? - ???
	sz1Vtx[1].mlScore = 0;
	for (i = 2; i <= siVCnt; i++) {
		sz1Vtx[i].mlScore = LLONG_MIN;
	}

	// ?????? - ??
	fUpVtx(D_OFF);

	// ????????????(??????????)
	fUpVtx(D_ON);

	// ?????
	if (sz1Vtx[siVCnt].miInf == D_ON) {
		sprintf(lc1Out, "inf\n");
	}
	else {
		sprintf(lc1Out, "%lld\n", sz1Vtx[siVCnt].mlScore);
	}

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
./Main.c:102:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:111:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^