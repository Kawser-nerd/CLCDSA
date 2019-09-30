#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_HYO_SIZE		9										// ????

// ????
static FILE *szpFpI;											// ??
static int siNx, siNy;											// ????
static int siMx, siMy;											// ????
static char sc2Hyo[D_HYO_SIZE][D_HYO_SIZE + 5];					// ?

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

	// ????????? - ??
	char lc1Move[128];
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%s", &siNx, &siNy, lc1Move);
	siNx--;
	siNy--;

	// ????
	siMx = 0;
	siMy = 0;
	for (i = 0; i < 2; i++) {
		switch (lc1Move[i]) {
		case 'R':		siMx = 1;		break;
		case 'L':		siMx = -1;		break;
		case 'D':		siMy = 1;		break;
		case 'U':		siMy = -1;		break;
		}
	}

	// ? - ??
	for (i = 0; i < D_HYO_SIZE; i++) {
		fgets(sc2Hyo[i], sizeof(sc2Hyo[i]), szpFpI);
	}

	// ?? - ??
	for (i = 0; i < 4; i++) {
		lc1Out[i] = sc2Hyo[siNy][siNx];

		// ??????
		if (siMx > 0) {
			if (siNx >= D_HYO_SIZE - 1) {
				siMx = -1;
			}
		}
		else if (siMx < 0) {
			if (siNx <= 0) {
				siMx = 1;
			}
		}
		if (siMy > 0) {
			if (siNy >= D_HYO_SIZE - 1) {
				siMy = -1;
			}
		}
		else if (siMy < 0) {
			if (siNy <= 0) {
				siMy = 1;
			}
		}

		// ??
		siNx += siMx;
		siNy += siMy;
	}
	lc1Out[4] = '\n';
	lc1Out[5] = '\0';

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
./Main.c:45:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:64:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Hyo[i], sizeof(sc2Hyo[i]), szpFpI);
   ^