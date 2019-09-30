#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_SIZE_MAX		500										// ?????
#define D_OPE_MAX		(D_SIZE_MAX * D_SIZE_MAX / 2)			// ??????

// ????? - ????
typedef struct Ope {
	int miFy, miFx;												// ???
	int miTy, miTx;												// ???
} Ope;

// ????
static FILE *szpFpI;											// ??
static int siH, siW;											// ????
static int si2Coin[D_SIZE_MAX + 5][D_SIZE_MAX + 5];				// ????
static Ope sz1Ope[D_OPE_MAX];									// ??
static int siOCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??
int
fMove(
	int piDsp					// <I> ??
	, Ope *pzpOpe				// <I> ??
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ????
	int liNx = pzpOpe->miFx;
	int liNy = pzpOpe->miFy;

	// ??
	int liCnt = 0;
	while (liNx != pzpOpe->miTx || liNy != pzpOpe->miTy) {

		// ???
		int liTx = liNx;
		int liTy = liNy;
		if (liNy % 2 == 1) {			// ???
			if (liNx < siW) {
				liTx++;
			}
			else {
				liTy++;
			}
		}
		else {							// ???
			if (liNx > 1) {
				liTx--;
			}
			else {
				liTy++;
			}
		}

		// ??
		if (piDsp == D_ON) {
			sprintf(lc1Out, "%d %d %d %d\n", liNy, liNx, liTy, liTx);
#ifdef D_TEST
			fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
			if (strcmp(lc1Buf, lc1Out)) {
				siRes = -1;
			}
#else
			printf("%s", lc1Out);
#endif
		}

		// ??
		liNx = liTx;
		liNy = liTy;
		liCnt++;
	}

	return liCnt;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	siOCnt = 0;													// ???

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
			fscanf(szpFpI, "%d", &si2Coin[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ?? - ???
	int liFrom = D_OFF;
	int liOSum = 0;
	for (i = 1; i <= siH; i++) {

		// ???? - ???
		int liSNo, liENo, liAdd;
		if (i % 2 == 1) {					// ???
			liSNo = 1;
			liENo = siW + 1;
			liAdd = 1;
		}
		else {								// ???
			liSNo = siW;
			liENo = 0;
			liAdd = -1;
		}

		// ?? - ??
		for (j = liSNo; j != liENo; j += liAdd) {

			// ???? - ????
			if (si2Coin[i][j] % 2 == 0) {		// ??
				continue;
			}

			// ??? - ??????
			if (liFrom == D_OFF) {				// ??
				liFrom = D_ON;
				sz1Ope[siOCnt].miFy = i;
				sz1Ope[siOCnt].miFx = j;
				continue;
			}
			liFrom = D_OFF;

			// ??? - ???
			sz1Ope[siOCnt].miTy = i;
			sz1Ope[siOCnt].miTx = j;
			siOCnt++;

			// ?????
			liOSum += fMove(D_OFF, &sz1Ope[siOCnt - 1]);
		}
	}

	// ????? - ??
	sprintf(lc1Out, "%d\n", liOSum);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ?? - ??
	for (i = 0; i < siOCnt; i++) {
		fMove(D_ON, &sz1Ope[i]);
	}

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
./Main.c:116:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:122:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(szpFpI, "%d", &si2Coin[i][j]);
    ^
./Main.c:124:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^