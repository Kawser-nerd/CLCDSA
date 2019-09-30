#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_GRD_SIZE		4										// ???????

// ????
static FILE *szpFpI;											// ??
static int si2Grd[D_GRD_SIZE][D_GRD_SIZE];						// ????[?][?]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??
int
fJudge(
)
{
	int i, j;

	for (i = 0; i < D_GRD_SIZE; i++) {
		for (j = 0; j < D_GRD_SIZE; j++) {

			// ?????
			if (j < D_GRD_SIZE - 1) {
				if (si2Grd[i][j] == si2Grd[i][j + 1]) {
					return 0;
				}
			}

			// ?????
			if (i < D_GRD_SIZE - 1) {
				if (si2Grd[i][j] == si2Grd[i + 1][j]) {
					return 0;
				}
			}
		}
	}

	return -1;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
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

	// ???? - ??
	for (i = 0; i < D_GRD_SIZE; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d%d", &si2Grd[i][0], &si2Grd[i][1], &si2Grd[i][2], &si2Grd[i][3]);
	}

	// ??
	int liRet = fJudge();

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "CONTINUE\n");
	}
	else {
		sprintf(lc1Out, "GAMEOVER\n");
	}

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
./Main.c:72:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^