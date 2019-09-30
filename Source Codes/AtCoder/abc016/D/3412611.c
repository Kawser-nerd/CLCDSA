#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		100										// ?????
#define D_DIF			0.000001								// ?????

// ????? - ????
typedef struct Vtx {
	int miX, miY;												// ??
} Vtx;

// ????
static FILE *szpFpI;											// ??
static int siSx, siSy;											// ?? - ??
static int siEx, siEy;											// ?? - ??
static Vtx sz1Vtx[D_VTX_MAX + 5];								// ??
static int siVCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????????????
int
fChkCrs(
	int piVNo					// <I> ?? 0?
)
{
	// ????
	double ldBx1 = (double)siEx - (double)siSx;
	double ldBy1 = (double)siEy - (double)siSy;
	double ldBx2 = (double)sz1Vtx[piVNo + 1].miX - (double)sz1Vtx[piVNo].miX;
	double ldBy2 = (double)sz1Vtx[piVNo + 1].miY - (double)sz1Vtx[piVNo].miY;
	double ldKx = (double)sz1Vtx[piVNo].miX - (double)siSx;
	double ldKy = (double)sz1Vtx[piVNo].miY - (double)siSy;

	// ??????????
	double ldVal = ldBx2 * ldBy1 - ldBy2 * ldBx1;
	if (-D_DIF <= ldVal && ldVal <= D_DIF) {
		return -1;
	}

	// ????????
	double ldP1 = (ldBx2 * ldKy - ldBy2 * ldKx) / ldVal;
	double ldP2 = (ldBx1 * ldKy - ldBy1 * ldKx) / ldVal;

	// ????????
	if (ldP1 < -D_DIF) {
		return -1;
	}
	if (1.0 + D_DIF < ldP1) {
		return -1;
	}
	if (ldP2 < -D_DIF) {
		return -1;
	}
	if (1.0 + D_DIF < ldP2) {
		return -1;
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

	// ?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d", &siSx, &siSy, &siEx, &siEy);

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siVCnt);

	// ?? - ??
	for (i = 0; i < siVCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Vtx[i].miX, &sz1Vtx[i].miY);
	}

	// ?? - ??????
	memcpy(&sz1Vtx[siVCnt], sz1Vtx, sizeof(Vtx));

	// ??? - ??
	int liCnt = 0;
	for (i = 0; i < siVCnt; i++) {
		liRet = fChkCrs(i);
		if (liRet == 0) {
			liCnt++;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt / 2 + 1);

	// ?? - ??
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
./Main.c:92:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:96:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:101:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^