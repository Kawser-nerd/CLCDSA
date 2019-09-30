#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CHAR_MAX		200005									// ?????
#define D_CHAR_CNT		26										// ?????

// ????
static FILE *szpFpI;											// ??
static char sc1StrFrom[D_CHAR_MAX];								// ??? - ?
static char sc1StrTo[D_CHAR_MAX];								// ??? - ?
static int siSCnt;												// ????
static char sc1ChgFrom[D_CHAR_CNT];								// ???? - ?
static char sc1ChgTo[D_CHAR_CNT];								// ???? - ?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
// ???????
int
fCutCrLf(
	char *pcpStr				// <I> ???
)
{
	int i;

	for (i = 0; pcpStr[i] != '\0'; i++) {
		if (pcpStr[i] == '\n') {
			pcpStr[i] = '\0';
			break;
		}
	}

	return i;
}

// ??
int
fJudge(
)
{
	int i;

	// ???????
	for (i = 0; i < siSCnt; i++) {
		int liFNo = sc1StrFrom[i] - 'a';
		int liTNo = sc1StrTo[i] - 'a';

		// ???? - ?
		if (sc1ChgFrom[liFNo] == 0) {				// ??
			sc1ChgFrom[liFNo] = liTNo;
		}
		else if (sc1ChgFrom[liFNo] != liTNo) {		// ???
			return -1;
		}

		// ???? - ?
		if (sc1ChgTo[liTNo] == 0) {					// ??
			sc1ChgTo[liTNo] = liFNo;
		}
		else if (sc1ChgTo[liTNo] != liFNo) {		// ???
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
	int liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sc1ChgFrom, 0, sizeof(sc1ChgFrom));					// ???? - ?
	memset(sc1ChgTo, 0, sizeof(sc1ChgTo));						// ???? - ?

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
	fgets(sc1StrFrom, sizeof(sc1StrFrom), szpFpI);
	fgets(sc1StrTo, sizeof(sc1StrTo), szpFpI);

	// ?????
	siSCnt = fCutCrLf(sc1StrFrom);

	// ??
	liRet = fJudge();

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "Yes\n");
	}
	else {
		sprintf(lc1Out, "No\n");
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
./Main.c:102:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1StrFrom, sizeof(sc1StrFrom), szpFpI);
  ^
./Main.c:103:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1StrTo, sizeof(sc1StrTo), szpFpI);
  ^