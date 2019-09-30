#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CHAR_CNT		26										// ?????

// ????
static FILE *szpFpI;											// ??
static int si1Brd[D_CHAR_CNT];									// ??
static int si1Kit[D_CHAR_CNT];									// ???

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
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1Brd, 0, sizeof(si1Brd));							// ??
	memset(si1Kit, 0, sizeof(si1Kit));							// ???

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
	int liBCnt, liKCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liBCnt, &liKCnt);

	// ?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	for (i = 0; i < liBCnt; i++) {
		int liNo = lc1Buf[i] - 'A';
		si1Brd[liNo]++;
	}

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	for (i = 0; i < liKCnt; i++) {
		int liNo = lc1Buf[i] - 'A';
		si1Kit[liNo]++;
	}

	// ??? - ??
	int liMin = 0;
	for (i = 0; i < D_CHAR_CNT; i++) {

		// ???
		if (si1Brd[i] < 1) {
			continue;
		}

		// ????
		if (si1Kit[i] < 1) {
			liMin = -1;
			break;
		}

		// ???
		int liCnt = (si1Brd[i] + si1Kit[i] - 1) / si1Kit[i];
		if (liMin < liCnt) {
			liMin = liCnt;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liMin);

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
./Main.c:48:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:52:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:59:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^