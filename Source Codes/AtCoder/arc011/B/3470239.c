#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CHAR_CNT		26										// ?????

// ????
static FILE *szpFpI;											// ??
static char sc1Chg[D_CHAR_CNT];									// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? - ??
char
fGetChar(
	char pcChar					// <I> ??
)
{
	// ????????
	int liPos = pcChar - 'A';
	if (liPos < 0 || D_CHAR_CNT <= liPos) {
		liPos = pcChar - 'a';
		if (liPos < 0 || D_CHAR_CNT <= liPos) {
			return 0;
		}
	}

	return sc1Chg[liPos];
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[65536];

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
	memset(sc1Chg, 0, sizeof(sc1Chg));
	sc1Chg[1] = '1';						// B
	sc1Chg[2] = '1';						// C
	sc1Chg[3] = '2';						// D
	sc1Chg[5] = '4';						// F
	sc1Chg[6] = '9';						// G
	sc1Chg[7] = '8';						// H
	sc1Chg[9] = '3';						// J
	sc1Chg[10] = '8';						// K
	sc1Chg[11] = '5';						// L
	sc1Chg[12] = '7';						// M
	sc1Chg[13] = '9';						// N
	sc1Chg[15] = '7';						// P
	sc1Chg[16] = '4';						// Q
	sc1Chg[17] = '0';						// R
	sc1Chg[18] = '6';						// S
	sc1Chg[19] = '3';						// T
	sc1Chg[21] = '5';						// V
	sc1Chg[22] = '2';						// W
	sc1Chg[23] = '6';						// X
	sc1Chg[25] = '0';						// Z

	// ??? - ??
	int liCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liCnt);

	// ?? - ??
	lc1Out[0] = '\0';
	for (i = 0; i < liCnt; i++) {
		char lc1Word[128];
		fscanf(szpFpI, "%s", &lc1Word);

		// ??
		int liNo = 0;
		for (j = 0; lc1Word[j] != '\0'; j++) {

			// ???? - ??
			char lcChg = fGetChar(lc1Word[j]);

			// ???
			if (lcChg > 0) {
				lc1Buf[liNo] = lcChg;
				liNo++;
			}
		}
		lc1Buf[liNo] = '\0';

		// ????
		if (lc1Buf[0] == '\0') {
			continue;
		}

		// ?? - ???
		if (lc1Out[0] != '\0') {
			strcat(lc1Out, " ");
		}
		strcat(lc1Out, lc1Buf);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??
	strcat(lc1Out, "\n");

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
./Main.c:91:18: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[128]’ [-Wformat=]
   fscanf(szpFpI, "%s", &lc1Word);
                  ^
./Main.c:84:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:91:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%s", &lc1Word);
   ^
./Main.c:119:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^