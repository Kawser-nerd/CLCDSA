#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_DAY_CNT		7										// ??

// ????
static FILE *szpFpI;											// ??
static int si1Des[D_DAY_CNT + 5];								// ??
static int si1Jun[D_DAY_CNT + 5];								// ?????

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
	memset(si1Des, 0, sizeof(si1Des));							// ??
	memset(si1Jun, 0, sizeof(si1Jun));							// ?????

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

	// ?? - ??
	for (i = 1; i <= D_DAY_CNT; i++) {
		fscanf(szpFpI, "%d", &si1Des[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ????? - ??
	for (i = 1; i <= D_DAY_CNT; i++) {
		fscanf(szpFpI, "%d", &si1Jun[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??? - ??
	int liMax = 0;
	for (i = 1; i <= D_DAY_CNT; i++) {
		if (si1Des[i] > si1Jun[i]) {
			liMax += si1Des[i];
		}
		else {
			liMax += si1Jun[i];
		}
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
./Main.c:48:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1Des[i]);
   ^
./Main.c:50:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:54:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &si1Jun[i]);
   ^
./Main.c:56:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^