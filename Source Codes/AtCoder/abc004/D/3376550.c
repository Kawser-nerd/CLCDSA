#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_COLOR_CNT		3										// ????
#define D_COLOR_R		0										// ? - ?
#define D_COLOR_G		1										// ? - ?
#define D_COLOR_B		2										// ? - ?
#define D_MARBLE_MAX	300										// ???????
#define D_BOX_LEN		100										// ????

// ????
static FILE *szpFpI;											// ??
static int si1MCnt[D_COLOR_CNT];								// ?????
static int si2Ptn[D_COLOR_CNT][D_MARBLE_MAX];					// ????(????)[?][???]
static int siMin;												// ??????

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
	siMin = INT_MAX;											// ??????

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
	sscanf(lc1Buf, "%d%d%d", &si1MCnt[D_COLOR_R], &si1MCnt[D_COLOR_G], &si1MCnt[D_COLOR_B]);

	// ????(????) - ???
	for (i = 0; i < D_COLOR_CNT; i++) {
		for (j = 0; j < si1MCnt[i]; j++) {

			// ???? - ???
			si2Ptn[i][j] = j * (j + 1) / 2;

			// ???
			int liCnt = si1MCnt[i] - 1 - j;

			// ???? - ???
			si2Ptn[i][j] += liCnt * (liCnt + 1) / 2;
		}
	}

	// ??????????
	for (i = -D_MARBLE_MAX; i <= D_MARBLE_MAX; i++) {

		// ???????
		int liSum;
		if (i < 0) {
			liSum = si1MCnt[D_COLOR_G] * (-i) + si2Ptn[D_COLOR_G][0];			// ????
		}
		else if (i < si1MCnt[D_COLOR_G]) {
			liSum = si2Ptn[D_COLOR_G][i];
		}
		else {
			liSum = si1MCnt[D_COLOR_G] * i + si2Ptn[D_COLOR_G][0];				// ????
		}

		// ?????
		int liCnt = i + si1MCnt[D_COLOR_B] - D_BOX_LEN;
		if (liCnt < 0) {
			liCnt = 0;
		}

		// ???????
		int liMin = si2Ptn[D_COLOR_B][0];
		if (liCnt >= si1MCnt[D_COLOR_B]) {
			liMin += si1MCnt[D_COLOR_B] * (liCnt - si1MCnt[D_COLOR_B] + 1);		// ????
		}
		else {
			for (j = liCnt; j < si1MCnt[D_COLOR_B]; j++) {
				if (liMin > si2Ptn[D_COLOR_B][j]) {
					liMin = si2Ptn[D_COLOR_B][j];
				}
			}
		}
		liSum += liMin;

		// ?????
		liCnt = i - si1MCnt[D_COLOR_G] + D_BOX_LEN;
		if (liCnt >= si1MCnt[D_COLOR_R]) {
			liCnt = si1MCnt[D_COLOR_R] - 1;
		}

		// ???????
		liMin = si2Ptn[D_COLOR_R][0];
		if (liCnt < 0) {
			liMin += si1MCnt[D_COLOR_R] * (-liCnt);								// ????
		}
		else {
			for (j = liCnt; j >= 0; j--) {
				if (liMin > si2Ptn[D_COLOR_R][j]) {
					liMin = si2Ptn[D_COLOR_R][j];
				}
			}
		}
		liSum += liMin;

		// ?????? - ??
		if (siMin > liSum) {
			siMin = liSum;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", siMin);

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
./Main.c:52:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^