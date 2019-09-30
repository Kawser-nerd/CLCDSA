#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_SIZE			100										// ????
#define D_MASS_SEA		'x'										// ?? - ?
#define D_MASS_LAND		'o'										// ?? - ?

// ????
static FILE *szpFpI;											// ??
static char sc2Ild[D_SIZE][D_SIZE + 5];							// ?
static int si2Done[D_SIZE][D_SIZE];								// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ???
int
fSetDone(
	int piX						// <I> ??X
	, int piY					// <I> ??Y
)
{
	// ??????
	if (piX < 0 || D_SIZE <= piX) {
		return 0;
	}
	if (piY < 0 || D_SIZE <= piY) {
		return 0;
	}

	// ???
	if (sc2Ild[piX][piY] != D_MASS_LAND) {
		return 0;
	}

	// ?????
	if (si2Done[piX][piY] != D_OFF) {
		return 0;
	}
	si2Done[piX][piY] = D_ON;

	// ?????
	fSetDone(piX + 1, piY);
	fSetDone(piX - 1, piY);
	fSetDone(piX, piY + 1);
	fSetDone(piX, piY - 1);

	return 0;
}

// ?????????
int
fIsAllDone(
)
{
	int i, j;

	for (i = 0; i < D_SIZE; i++) {
		for (j = 0; j < D_SIZE; j++) {
			if (sc2Ild[i][j] == D_MASS_LAND) {		// ?
				if (si2Done[i][j] != D_ON) {			// ??
					return -1;
				}
			}
		}
	}

	return 0;
}

// ??
int
fJudge(
)
{
	int i, j, liRet;

	// ????????
	for (i = 0; i < D_SIZE; i++) {
		for (j = 0; j < D_SIZE; j++) {
			if (sc2Ild[i][j] == D_MASS_LAND) {		// ?
				continue;
			}

			// ??????
			sc2Ild[i][j] = D_MASS_LAND;

			// ????? - ???
			memset(si2Done, D_OFF, sizeof(si2Done));

			// ????? - ???
			fSetDone(i, j);

			// ?????????
			liRet = fIsAllDone();
			if (liRet == 0) {
				return 0;
			}

			// ????
			sc2Ild[i][j] = D_MASS_SEA;
		}
	}

	return -1;
}

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

	// ? - ??
	for (i = 0; i < D_SIZE; i++) {
		fgets(sc2Ild[i], sizeof(sc2Ild[i]), szpFpI);
	}

	// ??
	int liRet = fJudge();

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "YES\n");
	}
	else {
		sprintf(lc1Out, "NO\n");
	}

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
./Main.c:140:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Ild[i], sizeof(sc2Ild[i]), szpFpI);
   ^