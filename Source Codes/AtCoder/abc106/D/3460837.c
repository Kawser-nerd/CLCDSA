#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STN_MAX		500										// ????

// ????
static FILE *szpFpI;											// ??
static int siSCnt;												// ??
static int si2Trn[D_STN_MAX + 5][D_STN_MAX + 5];				// ???[???][???]

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
	memset(si2Trn, 0, sizeof(si2Trn));							// ???[???][???]

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

	// ?????????? - ??
	int liTCnt, liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siSCnt, &liTCnt, &liQCnt);

	// ?? - ??
	for (i = 0; i < liTCnt; i++) {
		int liSNo1, liSNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liSNo1, &liSNo2);

		// ??????? - ???
		si2Trn[1][liSNo2]++;
		si2Trn[liSNo1 + 1][liSNo2]--;
	}

	// ????????? - ???
	for (i = 1; i <= siSCnt; i++) {
		for (j = 2; j <= siSCnt; j++) {
			si2Trn[j][i] += si2Trn[j - 1][i];
		}
	}

	// ????????? - ???
	for (i = 1; i <= siSCnt; i++) {
		for (j = 2; j <= siSCnt; j++) {
			si2Trn[i][j] += si2Trn[i][j - 1];
		}
	}

	// ?? - ??
	for (i = 0; i < liQCnt; i++) {
		int liSNo1, liSNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liSNo1, &liSNo2);

		// ?? - ???
		sprintf(lc1Out, "%d\n", si2Trn[liSNo1][liSNo2]);

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
./Main.c:47:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:53:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:78:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^