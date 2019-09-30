#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MASS_NONE'.'										// ?????????
#define D_MASS_PAINT	 'o'										// ??????

// ????
static FILE *szpFpI;											// ??

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

	// ?????? - ??
	int liMCnt, liRange;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liMCnt, &liRange);

	// ?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?? - ??
	int liPos = 0;
	int liTime = 0;
	while (1) {

		// ???????????
		int liNo = -1;
		for (i = liPos; i < liMCnt; i++) {
			if (lc1Buf[i] == D_MASS_NONE) {
				liNo = i;
				break;
			}
		}
		if (liNo < 0) {
			break;
		}

		// ???????????????
		for (i = liMCnt - 1; i > liNo; i--) {
			if (lc1Buf[i] == D_MASS_NONE) {
				if (liNo + liRange - 1 >= i) {
					liNo = i;
					break;
				}
			}
		}

		// ????
		int liMove = liNo - liPos - liRange + 1;

		// ??
		if (liMove > 0) {
			liPos += liMove;
			liTime += liMove;
		}

		// ??
		for (i = 0; i < liRange; i++) {
			lc1Buf[liPos + i] = D_MASS_PAINT;
		}
		liTime++;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liTime);

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
} ./Main.c:9:20: warning: ISO C99 requires whitespace after the macro name
 #define D_MASS_NONE'.'          // ?????????
                    ^
./Main.c: In function ‘fMain’:
./Main.c:43:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:47:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^