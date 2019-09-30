#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_NUM_CNT		6										// ???
#define D_NUM_KIND		10										// ????

// ????
static FILE *szpFpI;											// ??
static int si1Num[D_NUM_KIND];									// ??

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
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1Num, 0, sizeof(si1Num));							// ??

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
	for (i = 0; i < D_NUM_CNT; i++) {
		int liNo;
		fscanf(szpFpI, "%d", &liNo);
		si1Num[liNo]++;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?????? - ??
	int liBNo;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liBNo);

	// ???? - ??
	for (i = 0; i < D_NUM_CNT; i++) {
		int liNo;
		fscanf(szpFpI, "%d", &liNo);
		si1Num[liNo]++;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??? - ??
	int liCnt = 0;
	for (i = 0; i < D_NUM_KIND; i++) {
		if (si1Num[i] == 2) {
			liCnt++;
		}
	}

	// ?? - ??
	int liLank = 0;
	switch (liCnt) {
	case 6:
		liLank = 1;
		break;

	case 5:
		if (si1Num[liBNo] == 1) {
			liLank = 2;
		}
		else {
			liLank = 3;
		}
		break;

	case 4:
		liLank = 4;
		break;

	case 3:
		liLank = 5;
		break;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liLank);

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
./Main.c:48:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liNo);
   ^
./Main.c:51:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:55:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:61:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liNo);
   ^
./Main.c:64:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^