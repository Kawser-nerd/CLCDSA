#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static int si2Holiday[15][40];									// ??[?][?]

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
	memset(si2Holiday, 0, sizeof(si2Holiday));					// ??[?][?]

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

	// ??? - ??
	int liCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liCnt);

	// ?? - ??
	for (i = 0; i < liCnt; i++) {
		int liM, liD;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d/%d", &liM, &liD);

		// ??[?][?] - ???
		si2Holiday[liM][liD] = 1;
	}

	// ???????
	int liNM = 1;
	int liND = 1;
	int liLen = 0;
	int liMax = 0;
	for (i = 0; liNM < 13; i++) {

		// ??
		int liLD;
		switch (liNM) {
		case 2:
			liLD = 29;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			liLD = 30;
			break;
		default:
			liLD = 31;
			break;
		}

		// ??
		int liTM, liTD;
		if (liND < liLD) {
			liTM = liNM;
			liTD = liND + 1;
		}
		else {
			liTM = liNM + 1;
			liTD = 1;
		}

		// ??
		if (i % 7 == 0 || i % 7 == 6) {
			si2Holiday[liNM][liND]++;
		}

		// ?????
		if (si2Holiday[liNM][liND] > 1) {								// ??
			si2Holiday[liTM][liTD] += si2Holiday[liNM][liND] - 1;			// ???
		}

		// ??
		if (si2Holiday[liNM][liND] > 0) {								// ??
			liLen++;
			if (liMax < liLen) {
				liMax = liLen;
			}
		}
		else {															// ??
			liLen = 0;
		}

		// ???
		liNM = liTM;
		liND = liTD;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liMax);

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