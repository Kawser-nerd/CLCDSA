#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_PAPER_MAX		100										// ??????
#define D_COL_CNT		10										// ????

// ????
static FILE *szpFpI;											// ??

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
	int i, j, k;
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

	// ??????? - ??
	int liPCnt, liCost;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liPCnt, &liCost);

	// ??? - ??
	int li1Paper[D_PAPER_MAX];
	for (i = 0; i < liPCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &li1Paper[i]);
	}

	// ?????? - ??
	int liMin = INT_MAX;
	for (i = 1; i <= D_COL_CNT; i++) {
		for (j = 1; j <= D_COL_CNT; j++) {
			if (i == j) {
				continue;
			}

			// ???? - ??
			int liCCnt = 0;
			for (k = 0; k < liPCnt; k++) {
				if (k % 2 == 0) {				// ????
					if (li1Paper[k] != i) {			// ???
						liCCnt++;
					}
				}
				else {							// ????
					if (li1Paper[k] != j) {			// ???
						liCCnt++;
					}
				}
			}

			// ?????? - ??
			if (liMin > liCCnt) {
				liMin = liCCnt;
			}
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCost * liMin);

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
./Main.c:43:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:49:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^