#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		100										// ?????
#define D_COLOR_BLACK	'#'										// ?
#define D_COLOR_WHITE	'.'										// ?

// ????
static int siH;													// ??
static int siW;													// ?
static char sc2Img[D_SIZE_MAX][D_SIZE_MAX];						// ??
static char sc2ImgR[D_SIZE_MAX][D_SIZE_MAX];					// ??(???)
static char sc2ImgW[D_SIZE_MAX][D_SIZE_MAX];					// ??(???)

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?????
int
fGetCCntOne(
	char *pcpImg				// <I> ??
	, int piX					// <I> ??X
	, int piY					// <I> ??Y
	, int *pipBCnt				// <O> ??
	, int *pipWCnt				// <O> ??
)
{
	// ??????
	if (piX < 0 || siW <= piX) {
		return 0;
	}
	if (piY < 0 || siH <= piY) {
		return 0;
	}

	// ??
	int liNo = piY * D_SIZE_MAX + piX;

	// ????
	if (pcpImg[liNo] == D_COLOR_BLACK) {
		(*pipBCnt)++;
	}
	else {
		(*pipWCnt)++;
	}

	return 0;
}

// ?????
int
fGetCCnt(
	char *pcpImg				// <I> ??
	, int piX					// <I> ??X 0?
	, int piY					// <I> ??Y 0?
	, int *pipBCnt				// <O> ??
	, int *pipWCnt				// <O> ??
)
{
	// ???
	*pipBCnt = 0;
	*pipWCnt = 0;

	// ????????
	fGetCCntOne(pcpImg, piX + 1, piY, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX - 1, piY, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX, piY + 1, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX, piY - 1, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX + 1, piY + 1, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX + 1, piY - 1, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX - 1, piY + 1, pipBCnt, pipWCnt);
	fGetCCntOne(pcpImg, piX - 1, piY - 1, pipBCnt, pipWCnt);

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(sc2Img, 0, sizeof(sc2Img));							// ??
	memset(sc2ImgR, 0, sizeof(sc2ImgR));						// ??(???)
	memset(sc2ImgW, 0, sizeof(sc2ImgW));						// ??(???)

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ????
	for (i = 0; i < siH; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		memcpy(sc2Img[i], lc1Buf, siW);
	}

	// ???
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {

			// ????
			if (sc2Img[i][j] == D_COLOR_WHITE) {			// ?
				sc2ImgR[i][j] = D_COLOR_WHITE;					// ?
				continue;
			}

			// ???
			int liBCnt, liWCnt;
			fGetCCnt(sc2Img[0], j, i, &liBCnt, &liWCnt);
			if (liWCnt == 0) {								// ???
				sc2ImgR[i][j] = D_COLOR_BLACK;					// ?
			}
			else {											// ???
				sc2ImgR[i][j] = D_COLOR_WHITE;					// ?
			}
		}
	}

	// ???
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {

			// ????
			if (sc2ImgR[i][j] == D_COLOR_BLACK) {			// ?
				sc2ImgW[i][j] = D_COLOR_BLACK;					// ?
				continue;
			}

			// ???
			int liBCnt, liWCnt;
			fGetCCnt(sc2ImgR[0], j, i, &liBCnt, &liWCnt);
			if (liBCnt > 0) {								// ???
				sc2ImgW[i][j] = D_COLOR_BLACK;					// ?
			}
			else {											// ???
				sc2ImgW[i][j] = D_COLOR_WHITE;					// ?
			}
		}
	}

	// ??
	int liOut = 0;
	if (memcmp(sc2Img, sc2ImgW, sizeof(sc2Img))) {		// ???
		sprintf(lc1Out, "impossible\n");
	}
	else {												// ??
		sprintf(lc1Out, "possible\n");
		liOut = 1;
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

	// ??
	if (liOut) {
		for (i = 0; i < siH; i++) {
			sprintf(lc1Out, "%s\n", sc2ImgR[i]);
#ifdef D_TEST
			fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
			if (strcmp(lc1Buf, lc1Out)) {
				siRes = -1;
			}
#else
			printf("%s", lc1Out);
#endif
		}
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
./Main.c:112:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:121:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^