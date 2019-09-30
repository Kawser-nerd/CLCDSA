#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_COLOR_MAX		30										// ????
#define D_GRID_MAX		500										// ?????????
#define D_COLOR_GRP		3										// ????????

// ????
static int siCCnt;												// ??
static int si2Grp[D_GRID_MAX * 2][D_COLOR_MAX + 5];				// ??????(?????)
static int siGCnt;												// ???????
static int siMin;												// ????????
static int si1NGColor[D_COLOR_MAX + 5];							// ?????
static int si1SelColor[D_COLOR_GRP];							// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ???????????
int
fSetMin(
	int piGNo					// <I> ???????? 0?
	, int piSum					// <I> ?????
)
{
	int i;

	// ??????
	if (piGNo >= siGCnt) {

		// ????????
		if (siMin > piSum) {
			siMin = piSum;
		}

		return 0;
	}

	// ????
	if (piGNo < D_COLOR_GRP) {				// ???????
		for (i = 1; i <= siCCnt; i++) {

			// ?????
			if (si1NGColor[i] != D_OFF) {
				continue;
			}
			si1NGColor[i] = D_ON;
			si1SelColor[piGNo] = i;				// ???

			// ???
			fSetMin(piGNo + 1, piSum + si2Grp[piGNo][i]);

			// ?????
			si1NGColor[i] = D_OFF;
		}
	}
	else {									// ???????

		// ???
		int liColor = si1SelColor[piGNo % D_COLOR_GRP];

		// ???
		fSetMin(piGNo + 1, piSum + si2Grp[piGNo][liColor]);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, k;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(si2Grp, 0, sizeof(si2Grp));							// ????????????
	siMin = INT_MAX;											// ????????
	memset(si1NGColor, D_OFF, sizeof(si1NGColor));				// ?????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????????
	int liGSize;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liGSize, &siCCnt);

	// ?????
	int li2Icp[D_COLOR_MAX + 5][D_COLOR_MAX + 5];
	for (i = 1; i <= siCCnt; i++) {
		for (j = 1; j <= siCCnt; j++) {
#ifdef D_TEST
			fscanf(szpFpT, "%d", &li2Icp[i][j]);
#else
			fscanf(stdin, "%d", &li2Icp[i][j]);
#endif
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ???????????????????????
	for (i = 0; i < liGSize; i++) {
		for (j = 0; j < liGSize; j++) {
			int liColor;
#ifdef D_TEST
			fscanf(szpFpT, "%d", &liColor);
#else
			fscanf(stdin, "%d", &liColor);
#endif

			// ?????????
			int *lipGrp = si2Grp[i + j];

			// ????????
			for (k = 1; k <= siCCnt; k++) {
				lipGrp[k] += li2Icp[liColor][k];
			}
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ???????
	siGCnt = liGSize * 2 - 1;

	// ???????????
	fSetMin(0, 0);

	// ?????
	sprintf(lc1Out, "%d\n", siMin);

	// ????
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
./Main.c:107:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:118:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &li2Icp[i][j]);
    ^
./Main.c:124:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:135:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &liColor);
    ^
./Main.c:149:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^