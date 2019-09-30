#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STORE_MAX		100										// ????
#define D_PTN_CNT		10										// ?????

// ????
static int siSCnt;												// ??
static int si2Open[D_STORE_MAX][D_PTN_CNT];						// ????
static int si2Money[D_STORE_MAX][D_PTN_CNT + 1];				// ????
static int siMax;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ??????
int
fSetMax(
	int piPCnt					// <I> ???????????
	, int *pipPtn				// <I> ??????
)
{
	int i, j;

	// ??????
	if (piPCnt == D_PTN_CNT) {

		// ??????????
		for (i = 0; i < D_PTN_CNT; i++) {
			if (pipPtn[i] == 1) {
				break;
			}
		}
		if (i == D_PTN_CNT) {				// ????
			return 0;
		}

		// ????
		int liSum = 0;
		for (i = 0; i < siSCnt; i++) {

			// ?????
			int liMatch = 0;
			for (j = 0; j < D_PTN_CNT; j++) {
				if (pipPtn[j] == 1) {
					if (si2Open[i][j] == 1) {
						liMatch++;
					}
				}
			}

			// ????
			liSum += si2Money[i][liMatch];
		}

		// ?????
		if (siMax < liSum) {
			siMax = liSum;
		}

		return 0;
	}

	// ????
	pipPtn[piPCnt] = 1;
	fSetMax(piPCnt + 1, pipPtn);

	// ????
	pipPtn[piPCnt] = 0;
	fSetMax(piPCnt + 1, pipPtn);

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
	siMax = INT_MIN;											// ???

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siSCnt);

	// ??????
	for (i = 0; i < siSCnt; i++) {
		for (j = 0; j < D_PTN_CNT; j++) {
#ifdef D_TEST
			fscanf(szpFpT, "%d", &si2Open[i][j]);
#else
			fscanf(stdin, "%d", &si2Open[i][j]);
#endif
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ??????
	for (i = 0; i < siSCnt; i++) {
		for (j = 0; j < D_PTN_CNT + 1; j++) {
#ifdef D_TEST
			fscanf(szpFpT, "%d", &si2Money[i][j]);
#else
			fscanf(stdin, "%d", &si2Money[i][j]);
#endif
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ??????
	int li1Ptn[D_PTN_CNT];
	fSetMax(0, li1Ptn);

	// ?????
	sprintf(lc1Out, "%d\n", siMax);

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
./Main.c:108:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:118:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &si2Open[i][j]);
    ^
./Main.c:124:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:134:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &si2Money[i][j]);
    ^
./Main.c:140:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^