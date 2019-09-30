#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_HUMAN_MAX		12										// ????

// ????
static FILE *szpFpI;											// ??
static int siHCnt;												// ??
static int si2Frd[D_HUMAN_MAX + 5][D_HUMAN_MAX + 5];			// ??????
static int siMax;												// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????? - ???
int
fSetMax(
	int piHNo					// <I> ? 1?
	, int *pipGrp				// <I> ??
	, int piGCnt				// <I> ????
)
{
	int i;

	// ??????
	if (piHNo > siHCnt) {
		if (siMax < piGCnt) {
			siMax = piGCnt;
		}
		return 0;
	}

	// ????
	fSetMax(piHNo + 1, pipGrp, piGCnt);			// ???

	// ????????
	for (i = 0; i < piGCnt; i++) {
		if (si2Frd[piHNo][pipGrp[i]] != D_ON) {
			return 0;
		}
	}

	// ????
	pipGrp[piGCnt] = piHNo;
	fSetMax(piHNo + 1, pipGrp, piGCnt + 1);		// ???

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si2Frd, D_OFF, sizeof(si2Frd));						// ??????
	siMax = 0;													// ??????

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
	int liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siHCnt, &liRCnt);

	// ?????? - ???
	for (i = 1; i <= siHCnt; i++) {
		si2Frd[i][i] = D_ON;
	}

	// ?? - ??
	for (i = 0; i < liRCnt; i++) {
		int liNo1, liNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liNo1, &liNo2);

		// ?????? - ??
		si2Frd[liNo1][liNo2] = D_ON;
		si2Frd[liNo2][liNo1] = D_ON;
	}

	// ?????? - ???
	int li1Grp[D_HUMAN_MAX];
	fSetMax(1, li1Grp, 0);

	// ?? - ???
	sprintf(lc1Out, "%d\n", siMax);

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
./Main.c:86:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:97:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^