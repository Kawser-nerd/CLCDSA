#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		50										// ???????

// ????
static FILE *szpFpI;											// ??
static int siSize;												// ?????
static int si2Dlcs[D_SIZE_MAX + 5][D_SIZE_MAX + 5];				// ????[Y][X]
static int si2DSum[D_SIZE_MAX + 5][D_SIZE_MAX + 5];				// ??????[Y][X]
static int si1DMax[D_SIZE_MAX * D_SIZE_MAX + 5];				// ??????[??]

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
	int i, j, k, l;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1DMax, 0, sizeof(si1DMax));						// ??????

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

	// ????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siSize);

	// ???? - ??
	for (i = 1; i <= siSize; i++) {
		for (j = 1; j <= siSize; j++) {
			fscanf(szpFpI, "%d", &si2Dlcs[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ?????? - ??? - ???
	for (i = 1; i <= siSize; i++) {

		// ???
		si2DSum[i][1] = si2Dlcs[i][1];

		// ?????
		for (j = 2; j <= siSize; j++) {
			si2DSum[i][j] = si2DSum[i][j - 1] + si2Dlcs[i][j];
		}
	}

	// ?????? - ??? - ???
	for (i = 2; i <= siSize; i++) {
		for (j = 1; j <= siSize; j++) {
			si2DSum[i][j] += si2DSum[i - 1][j];
		}
	}

	// ?????? - ???
	for (i = 1; i <= siSize; i++) {
		for (j = 1; j <= siSize; j++) {
			for (k = 1; k <= i; k++) {
				for (l = 1; l <= j; l++) {

					// ????
					int liDlcs = si2DSum[i][j];
					if (k > 1) {
						liDlcs -= si2DSum[k - 1][j];
					}
					if (l > 1) {
						liDlcs -= si2DSum[i][l - 1];
					}
					if (k > 1 && l > 1) {
						liDlcs += si2DSum[k - 1][l - 1];
					}

					// ??
					int liCnt = (i - k + 1) * (j - l + 1);

					// ??
					if (si1DMax[liCnt] < liDlcs) {
						si1DMax[liCnt] = liDlcs;
					}
				}
			}
		}
	}

	// ?????? - ??
	int liDlcs = si1DMax[1];
	for (i = 2; i <= siSize * siSize; i++) {
		if (si1DMax[i] < liDlcs) {
			si1DMax[i] = liDlcs;
		}
		else {
			liDlcs = si1DMax[i];
		}
	}

	// ??? - ??
	int liHCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liHCnt);

	// ??(??) - ??
	for (i = 0; i < liHCnt; i++) {
		int liCnt;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &liCnt);

		// ?? - ???
		sprintf(lc1Out, "%d\n", si1DMax[liCnt]);

		// ?? - ??
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
./Main.c:48:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:54:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(szpFpI, "%d", &si2Dlcs[i][j]);
    ^
./Main.c:56:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:121:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:127:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^