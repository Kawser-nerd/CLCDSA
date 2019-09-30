#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MAX_SIZE		50										// ?????
#define D_MASS_BLACK	'#'										// ???

// ????
static int siH;													// ??
static int siW;													// ?
static char sc2Mass[D_MAX_SIZE][D_MAX_SIZE + 5];				// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fChkMassBlack(
	int piRow					// <I> ? 0?
	, int piCol					// <I> ? 0?
)
{
	// ??????
	if (piRow < 0 || siH <= piRow) {
		return -1;
	}
	if (piCol < 0 || siW <= piCol) {
		return -1;
	}

	// ?????
	if (sc2Mass[piRow][piCol] == D_MASS_BLACK) {	// ???
		return 0;
	}

	return -1;
}

// ????
int
fChkMass(
)
{
	int i, j, liRet;

	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {

			// ?????
			if (sc2Mass[i][j] != D_MASS_BLACK) {	// ?????
				continue;
			}

			// ???
			liRet = fChkMassBlack(i, j + 1);
			if (liRet == 0) {						// ???
				continue;
			}

			// ???
			liRet = fChkMassBlack(i, j - 1);
			if (liRet == 0) {						// ???
				continue;
			}

			// ???
			liRet = fChkMassBlack(i + 1, j);
			if (liRet == 0) {						// ???
				continue;
			}

			// ???
			liRet = fChkMassBlack(i - 1, j);
			if (liRet == 0) {						// ???
				continue;
			}

			// ?????
			return -1;
		}
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ????
	for (i = 0; i < siH; i++) {
#ifdef D_TEST
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpT);
#else
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), stdin);
#endif
	}

	// ????
	liRet = fChkMass();

	// ?????
	if (liRet == 0) {
		sprintf(lc1Out, "Yes\n");
	}
	else {
		sprintf(lc1Out, "No\n");
	}

	// ????
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
./Main.c:115:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:124:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Mass[i], sizeof(sc2Mass[i]), stdin);
   ^