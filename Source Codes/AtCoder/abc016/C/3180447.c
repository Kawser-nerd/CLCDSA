#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_USER_MAX		10										// ??????

// ????
static FILE *szpFpI;											// ??
static int si2Frd[D_USER_MAX + 5][D_USER_MAX + 5];				// ????
static int siUCnt;												// ????

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

	// ??? - ???
	memset(si2Frd, D_OFF, sizeof(si2Frd));						// ????

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
	int liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siUCnt, &liRCnt);

	// ???? - ??
	for (i = 0; i < liRCnt; i++) {
		int liUNo1, liUNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liUNo1, &liUNo2);
		si2Frd[liUNo1][liUNo2] = D_ON;
		si2Frd[liUNo2][liUNo1] = D_ON;
	}

	// ????????
	for (i = 1; i <= siUCnt; i++) {
		int li1Frd[D_USER_MAX + 5];
		memset(li1Frd, D_OFF, sizeof(li1Frd));

		// ?????????
		for (j = 1; j <= siUCnt; j++) {
			if (si2Frd[i][j] != D_ON) {		// ??????
				continue;
			}

			// ?????????
			for (k = 1; k <= siUCnt; k++) {
				if (si2Frd[j][k] == D_ON) {		// ??
					li1Frd[k] = D_ON;
				}
			}
		}

		// ??????
		for (j = 1; j <= siUCnt; j++) {
			if (si2Frd[i][j] == D_ON) {		// ??
				li1Frd[j] = D_OFF;
			}
		}

		// ??????
		li1Frd[i] = D_OFF;

		// ????????
		int liCnt = 0;
		for (j = 1; j <= siUCnt; j++) {
			if (li1Frd[j] == D_ON) {		// ?????
				liCnt++;
			}
		}

		// ?? - ???
		sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:49:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:55:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^