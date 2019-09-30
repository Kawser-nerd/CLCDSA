#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		105										// ?????

// ????? - ?????
typedef struct Choco {
	int miBCnt;													// ?????
	int miWCnt;													// ?????
} Choco;

// ????
static FILE *szpFpI;											// ??
static int siW, siH;											// ????
static Choco sz2Choco[D_SIZE_MAX][D_SIZE_MAX];					// ???
static Choco sz2Sum[D_SIZE_MAX][D_SIZE_MAX];					// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sz2Choco, 0, sizeof(sz2Choco));						// ???
	memset(sz2Sum, 0, sizeof(sz2Sum));							// ?????

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

	// ???? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ??? - ??
	for (i = 1; i <= siH; i++) {
		for (j = 1; j <= siW; j++) {
			if ((i + j) % 2 == 0) {
				fscanf(szpFpI, "%d", &sz2Choco[j][i].miBCnt);
			}
			else {
				fscanf(szpFpI, "%d", &sz2Choco[j][i].miWCnt);
			}
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ????? - ??? - ???????
	for (i = 1; i <= siH; i++) {
		for (j = 1; j <= siW; j++) {
			sz2Sum[j][i].miBCnt += sz2Sum[j - 1][i].miBCnt + sz2Choco[j][i].miBCnt;
			sz2Sum[j][i].miWCnt += sz2Sum[j - 1][i].miWCnt + sz2Choco[j][i].miWCnt;
		}
	}
	for (i = 1; i <= siW; i++) {
		for (j = 1; j <= siH; j++) {
			sz2Sum[i][j].miBCnt += sz2Sum[i][j - 1].miBCnt;
			sz2Sum[i][j].miWCnt += sz2Sum[i][j - 1].miWCnt;
		}
	}

	// ?????? - ??
	int liMax = 0;
	for (int liSx = 1; liSx <= siW; liSx++) {
		for (int liSy = 1; liSy <= siH; liSy++) {
			for (int liEx = liSx; liEx <= siW; liEx++) {
				for (int liEy = liSy; liEy <= siH; liEy++) {

					// ??????????
					int liBSum = sz2Sum[liEx][liEy].miBCnt - sz2Sum[liSx - 1][liEy].miBCnt - sz2Sum[liEx][liSy - 1].miBCnt + sz2Sum[liSx - 1][liSy - 1].miBCnt;
					int liWSum = sz2Sum[liEx][liEy].miWCnt - sz2Sum[liSx - 1][liEy].miWCnt - sz2Sum[liEx][liSy - 1].miWCnt + sz2Sum[liSx - 1][liSy - 1].miWCnt;
					if (liBSum != liWSum) {
						continue;
					}

					// ????
					int liCnt = (liEx - liSx + 1) * (liEy - liSy + 1);

					// ?????? - ??
					if (liMax < liCnt) {
						liMax = liCnt;
					}
				}
			}
		}
	}

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
./Main.c:55:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:62:5: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
     fscanf(szpFpI, "%d", &sz2Choco[j][i].miBCnt);
     ^
./Main.c:65:5: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
     fscanf(szpFpI, "%d", &sz2Choco[j][i].miWCnt);
     ^
./Main.c:68:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^