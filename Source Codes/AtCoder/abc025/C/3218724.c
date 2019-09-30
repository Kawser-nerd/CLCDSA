#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_BOARD_SIZE	3										// ?????
#define D_MASS_NONE		0										// ?? - ??
#define D_MASS_P1		1										// ?? - P1
#define D_MASS_P2		-1										// ?? - P2

// ????
static FILE *szpFpI;											// ??
static int si2ScoreY[D_BOARD_SIZE][D_BOARD_SIZE];				// ??(???)
static int si2ScoreX[D_BOARD_SIZE][D_BOARD_SIZE];				// ??(???)
static char sc2Mass[D_BOARD_SIZE][D_BOARD_SIZE];				// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????
int
fGetScore(
	int *pipScore1				// <O> ?? - P1
	, int *pipScore2			// <O> ?? - P2
)
{
	int i, j;

	// ???
	*pipScore1 = 0;
	*pipScore2 = 0;

	// ??(???)
	for (i = 0; i < D_BOARD_SIZE - 1; i++) {
		for (j = 0; j < D_BOARD_SIZE; j++) {
			if (sc2Mass[i][j] == sc2Mass[i + 1][j]) {		// ??
				*pipScore1 += si2ScoreY[i][j];
			}
			else {											// ???
				*pipScore2 += si2ScoreY[i][j];
			}
		}
	}

	// ??(???)
	for (i = 0; i < D_BOARD_SIZE; i++) {
		for (j = 0; j < D_BOARD_SIZE - 1; j++) {
			if (sc2Mass[i][j] == sc2Mass[i][j + 1]) {		// ??
				*pipScore1 += si2ScoreX[i][j];
			}
			else {											// ???
				*pipScore2 += si2ScoreX[i][j];
			}
		}
	}

	return 0;
}

// ??????
int
fGetBest(
	int piCnt					// <I> ???
	, char pcPlayer				// <I> P1 or P2
	, int *pipScore1			// <O> ?? - P1
	, int *pipScore2			// <O> ?? - P2
)
{
	int i, j;

	// ??????
	if (piCnt == D_BOARD_SIZE * D_BOARD_SIZE) {
		fGetScore(pipScore1, pipScore2);			// ????
		return 0;
	}

	// ??????
	int liLimit;
	if (pcPlayer == D_MASS_P1) {				// P1
		liLimit = INT_MIN;
	}
	else {										// P2
		liLimit = INT_MAX;
	}
	for (i = 0; i < D_BOARD_SIZE; i++) {
		for (j = 0; j < D_BOARD_SIZE; j++) {
			if (sc2Mass[i][j] != D_MASS_NONE) {			// ???
				continue;
			}

			// ??
			sc2Mass[i][j] = pcPlayer;

			// ????
			int liScore1, liScore2;
			fGetBest(piCnt + 1, pcPlayer * -1, &liScore1, &liScore2);
			int liDF = liScore1 - liScore2;
			if (pcPlayer == D_MASS_P1) {				// P1
				if (liLimit < liDF) {
					liLimit = liDF;
					*pipScore1 = liScore1;
					*pipScore2 = liScore2;
				}
			}
			else {										// P2
				if (liLimit > liDF) {
					liLimit = liDF;
					*pipScore1 = liScore1;
					*pipScore2 = liScore2;
				}
			}

			// ????
			sc2Mass[i][j] = D_MASS_NONE;
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
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sc2Mass, D_MASS_NONE, sizeof(sc2Mass));				// ??

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

	// ??(???) - ??
	for (i = 0; i < D_BOARD_SIZE - 1; i++) {
		for (j = 0; j < D_BOARD_SIZE; j++) {
			fscanf(szpFpI, "%d", &si2ScoreY[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ??(???) - ??
	for (i = 0; i < D_BOARD_SIZE; i++) {
		for (j = 0; j < D_BOARD_SIZE - 1; j++) {
			fscanf(szpFpI, "%d", &si2ScoreX[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ??????
	int liScore1, liScore2;
	fGetBest(0, D_MASS_P1, &liScore1, &liScore2);

	// P1 - ??
	sprintf(lc1Out, "%d\n", liScore1);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// P2 - ??
	sprintf(lc1Out, "%d\n", liScore2);
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
./Main.c:153:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(szpFpI, "%d", &si2ScoreY[i][j]);
    ^
./Main.c:155:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:161:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(szpFpI, "%d", &si2ScoreX[i][j]);
    ^
./Main.c:163:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^