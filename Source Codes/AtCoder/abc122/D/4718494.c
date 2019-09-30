#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MOD			1000000007										// ??(10?9?+7)
#define D_LEN_MAX		105												// ??????
#define D_CHAR_KIND		4												// ?????

// ????
static FILE *szpFpI;													// ??
static int siLen;														// ????
static int si4Ptn[D_LEN_MAX][D_CHAR_KIND][D_CHAR_KIND][D_CHAR_KIND];	// ?????[???][????][????][????]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ??
int
fOut(
	char *pcpLine				// <I> ??
)
{
	char lc1Buf[1024];

#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// NG???? - ???
int
fClearNG(
	int piNo					// <I> ???
)
{
	si4Ptn[piNo][0][2][1] = 0;				// AGC
	si4Ptn[piNo][0][1][2] = 0;				// ACG
	si4Ptn[piNo][2][0][1] = 0;				// GAC

	return 0;
}

// ?????
int
fMain(
)
{
	int i, j, k, l, m;
	char lc1Buf[1024];

	// ???? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siLen);

	// ????? - ??? - ????
	for (i = 0; i < D_CHAR_KIND; i++) {
		for (j = 0; j < D_CHAR_KIND; j++) {
			for (k = 0; k < D_CHAR_KIND; k++) {
				si4Ptn[3][i][j][k] = 1;
			}
		}
	}
	fClearNG(3);				// NG???? - ???

	// ????? - ??? - ??????
	for (i = 4; i <= siLen; i++) {

		// ???
		for (j = 0; j < D_CHAR_KIND; j++) {
			for (k = 0; k < D_CHAR_KIND; k++) {
				for (l = 0; l < D_CHAR_KIND; l++) {
					for (m = 0; m < D_CHAR_KIND; m++) {
						si4Ptn[i][j][k][l] += si4Ptn[i - 1][m][j][k];
						si4Ptn[i][j][k][l] %= D_MOD;
					}
				}
			}
		}

		// ??
		si4Ptn[i][2][2][1] -= si4Ptn[i - 1][0][2][2];		// AGGC (GGC - AGG)
		if (si4Ptn[i][2][2][1] < 0) {
			si4Ptn[i][2][2][1] += D_MOD;
		}
		si4Ptn[i][3][2][1] -= si4Ptn[i - 1][0][3][2];		// ATGC (TGC - ATG)
		if (si4Ptn[i][3][2][1] < 0) {
			si4Ptn[i][3][2][1] += D_MOD;
		}
		si4Ptn[i][2][3][1] -= si4Ptn[i - 1][0][2][3];		// AGTC (GTC - AGT)
		if (si4Ptn[i][2][3][1] < 0) {
			si4Ptn[i][2][3][1] += D_MOD;
		}

		// NG???? - ???
		fClearNG(i);
	}

	// ??????? - ??
	int liSum = 0;
	for (i = 0; i < D_CHAR_KIND; i++) {
		for (j = 0; j < D_CHAR_KIND; j++) {
			for (k = 0; k < D_CHAR_KIND; k++) {
				liSum += si4Ptn[siLen][i][j][k];
				liSum %= D_MOD;
			}
		}
	}

	return liSum;
}

// ????
int
fOne(
)
{
	int liRet;
	char lc1Buf[1024];

	// ??? - ???
	memset(si4Ptn, 0, sizeof(si4Ptn));							// ?????

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????
	liRet = fMain();

	// ?? - ???
	sprintf(lc1Buf, "%d\n", liRet);

	// ?? - ??
	fOut(lc1Buf);

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// ???????
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne();
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:68:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^