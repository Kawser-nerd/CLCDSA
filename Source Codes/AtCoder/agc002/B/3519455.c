#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_BOX_MAX		100000									// ????

// ????? - ???
typedef struct Box {
	int miRed;													// ????
	int miCnt;													// ????
} Box;

// ????
static FILE *szpFpI;											// ??
static Box sz1Box[D_BOX_MAX + 5];								// ?
static int siBCnt;												// ??

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

	// ?????? - ??
	int liMCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siBCnt, &liMCnt);

	// ? - ???
	sz1Box[1].miRed = D_ON;
	sz1Box[1].miCnt = 1;
	for (i = 2; i <= siBCnt; i++) {
		sz1Box[i].miRed = D_OFF;
		sz1Box[i].miCnt = 1;
	}

	// ?? - ??
	for (i = 0; i < liMCnt; i++) {
		int liFNo, liTNo;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liFNo, &liTNo);

		// ???
		sz1Box[liTNo].miCnt++;
		if (sz1Box[liFNo].miRed == D_ON) {
			sz1Box[liTNo].miRed = D_ON;
		}

		// ???
		sz1Box[liFNo].miCnt--;
		if (sz1Box[liFNo].miCnt == 0) {
			sz1Box[liFNo].miRed = D_OFF;
		}
	}

	// ?? - ??
	int liCnt = 0;
	for (i = 1; i <= siBCnt; i++) {
		if (sz1Box[i].miRed == D_ON) {
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
./Main.c:52:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:66:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^