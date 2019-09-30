#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_HUMAN_MAX		100000									// ????
#define D_RATE_MAX		100000									// ?????
#define D_HAND_CNT		3										// ???????
#define D_HAND_G		1										// ??
#define D_HAND_C		2										// ???
#define D_HAND_P		3										// ??

// ????? - ???
typedef struct Human {
	int miRate;													// ???
	int miHand;													// ?????
} Human;

// ????? - ????
typedef struct HSum {
	int mi1Hand[D_HAND_CNT + 5];								// ?????
	int miDSum;													// ????
	int miUSum;													// ????
} HSum;

// ????
static FILE *szpFpI;											// ??
static Human sz1Human[D_HUMAN_MAX];								// ?
static int siHCnt;												// ??
static HSum sz1HSum[D_RATE_MAX + 5];							// ??[???]

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
	memset(sz1HSum, 0, sizeof(sz1HSum));						// ??[???]

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
	sscanf(lc1Buf, "%d", &siHCnt);

	// ? - ??
	for (i = 0; i < siHCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Human[i].miRate, &sz1Human[i].miHand);

		// ??[???] - ????? - ??
		sz1HSum[sz1Human[i].miRate].mi1Hand[sz1Human[i].miHand]++;
	}

	// ??[???] - ???? - ???
	for (i = 1; i <= D_RATE_MAX; i++) {
		sz1HSum[i].miDSum = sz1HSum[i - 1].miDSum;
		for (j = 1; j <= D_HAND_CNT; j++) {
			sz1HSum[i].miDSum += sz1HSum[i - 1].mi1Hand[j];
		}
	}

	// ??[???] - ???? - ???
	for (i = D_RATE_MAX; i >= 1; i--) {
		sz1HSum[i].miUSum = sz1HSum[i + 1].miUSum;
		for (j = 1; j <= D_HAND_CNT; j++) {
			sz1HSum[i].miUSum += sz1HSum[i + 1].mi1Hand[j];
		}
	}

	// ?? - ??
	for (i = 0; i < siHCnt; i++) {
		Human *lzpHuman = &sz1Human[i];
		HSum *lzpHSum = &sz1HSum[lzpHuman->miRate];

		// ???
		int liWin = lzpHSum->miDSum;
		int liLose = lzpHSum->miUSum;
		int liDraw = -1;
		switch (lzpHuman->miHand) {
		case D_HAND_G:
			liWin += lzpHSum->mi1Hand[D_HAND_C];
			liLose += lzpHSum->mi1Hand[D_HAND_P];
			liDraw += lzpHSum->mi1Hand[D_HAND_G];
			break;

		case D_HAND_C:
			liWin += lzpHSum->mi1Hand[D_HAND_P];
			liLose += lzpHSum->mi1Hand[D_HAND_G];
			liDraw += lzpHSum->mi1Hand[D_HAND_C];
			break;

		case D_HAND_P:
			liWin += lzpHSum->mi1Hand[D_HAND_G];
			liLose += lzpHSum->mi1Hand[D_HAND_C];
			liDraw += lzpHSum->mi1Hand[D_HAND_P];
			break;
		}

		// ??
		sprintf(lc1Out, "%d %d %d\n", liWin, liLose, liDraw);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

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
./Main.c:65:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:70:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^