#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_HUMAN_MAX		100000									// ????

// ????
static FILE *szpFpI;											// ??
static int si1Age[D_HUMAN_MAX + 5];								// ??[??]
static int si1Ord[D_HUMAN_MAX + 5];								// ??[??]
static int siHCnt;												// ??
static int siK;													// K??

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
	memset(si1Ord, 0, sizeof(si1Ord));							// ??[??]

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

	// ???K?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siHCnt, &siK);

	// ??[??] - ??
	for (i = 1; i <= siHCnt; i++) {
		fscanf(szpFpI, "%d", &si1Age[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ????? - ???
	int liAge = 0;
	int liNo;
	for (liNo = 1; liNo <= siK; liNo++) {
		si1Ord[si1Age[liNo]] = liNo;
		if (liAge < si1Age[liNo]) {
			liAge = si1Age[liNo];
		}
	}

	// ??
	sprintf(lc1Out, "%d\n", si1Ord[liAge]);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ??? - ??
	for ( ; liNo <= siHCnt; liNo++) {

		// ????
		si1Ord[si1Age[liNo]] = liNo;

		// ??????
		if (liAge > si1Age[liNo]) {

			// ????
			do {
				liAge--;
			} while (si1Ord[liAge] == 0);
		}

		// ??
		sprintf(lc1Out, "%d\n", si1Ord[liAge]);
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
./Main.c:48:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:53:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1Age[i]);
   ^
./Main.c:55:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^