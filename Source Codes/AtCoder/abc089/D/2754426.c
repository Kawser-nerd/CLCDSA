#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_POS_MAX		90000									// ?????

// ????? - ????
typedef struct Pos {
	int miX, miY;												// ??
} Pos;

// ????
static Pos sz1Pos[D_POS_MAX + 5];								// ????
static int si1Sum[D_POS_MAX + 5];								// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????????
	int liH, liW, liMv;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &liH, &liW, &liMv);

	// ??????
	for (i = 1; i <= liH; i++) {
		for (j = 1; j <= liW; j++) {
			int liNo;
#ifdef D_TEST
			fscanf(szpFpT, "%d", &liNo);
#else
			fscanf(stdin, "%d", &liNo);
#endif
			sz1Pos[liNo].miX = j;
			sz1Pos[liNo].miY = i;
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ?????
	for (i = 1; i <= liMv; i++) {

		// ????
		si1Sum[i] = 0;

		// ????
		int liFNo = i;
		int liTNo;
		while (1) {
			liTNo = liFNo + liMv;
			if (liTNo > D_POS_MAX) {
				break;
			}
			si1Sum[liTNo] = si1Sum[liFNo] + abs(sz1Pos[liTNo].miX - sz1Pos[liFNo].miX) + abs(sz1Pos[liTNo].miY - sz1Pos[liFNo].miY);
			liFNo = liTNo;
		}
	}

	// ??????
	int liQCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liQCnt);

	// ????????
	for (i = 0; i < liQCnt; i++) {

		// ?????
		int liFNo, liTNo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liFNo, &liTNo);

		// ????
		int liSum = si1Sum[liTNo] - si1Sum[liFNo];

		// ????
		sprintf(lc1Out, "%d\n", liSum);
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
./Main.c:49:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:60:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &liNo);
    ^
./Main.c:68:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:96:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:108:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^