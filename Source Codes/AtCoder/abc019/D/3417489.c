#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ??
int
fGetLen(
	int piNo1					// <I> ??? 1?
	, int piNo2					// <I> ??? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ??
	sprintf(lc1Out, "? %d %d\n", piNo1, piNo2);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
	fflush(stdout);
#endif

	// ??
	int liLen;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liLen);

	return liLen;
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

	// ??? - ??
	int liVCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liVCnt);

	// ????
	int liNo1 = 1;
	int liNo2 = 2;

	// ?????
	int liLen = fGetLen(liNo1, liNo2);

	// ???????????
	for (i = 3; i <= liVCnt; i++) {
		int liLen1 = fGetLen(liNo1, i);
		int liLen2 = fGetLen(liNo2, i);

		// ?????????
		if (liLen1 >= liLen && liLen1 >= liLen2) {
			liNo2 = i;
			liLen = liLen1;
		}
		else if (liLen2 >= liLen && liLen2 >= liLen1) {
			liNo1 = i;
			liLen = liLen2;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "! %d\n", liLen);

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
	fflush(stdout);
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
} ./Main.c: In function ‘fGetLen’:
./Main.c:40:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c: In function ‘fMain’:
./Main.c:68:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^