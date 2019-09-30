#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_AMD_SIZE		20										// ?????????

// ????
static FILE *szpFpI;											// ??
static char sc2Amd[D_AMD_SIZE + 5][D_AMD_SIZE + 5];				// ?????

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
	memset(sc2Amd, 0, sizeof(sc2Amd));							// ?????

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

	// ????? - ??
	int liCnt, liLen;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liCnt, &liLen);

	// ????? - ??
	for (i = 1; i <= liLen + 1; i++) {
		fgets(&sc2Amd[i][1], sizeof(sc2Amd[i]) - 1, szpFpI);
	}

	// ???? - ??
	int liX;
	for (i = 1; ; i++) {
		if (sc2Amd[liLen + 1][i] == 'o') {
			liX = i;
			break;
		}
	}
	int liY = liLen;

	// ??????
	while (1) {

		// ??????
		if (liY == 0) {
			break;
		}

		// ??
		if (sc2Amd[liY][liX - 1] == '-') {
			liX -= 2;
		}
		else if (sc2Amd[liY][liX + 1] == '-') {
			liX += 2;
		}
		liY--;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liX / 2 + 1);

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
./Main.c:46:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:51:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(&sc2Amd[i][1], sizeof(sc2Amd[i]) - 1, szpFpI);
   ^