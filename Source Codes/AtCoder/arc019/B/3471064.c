#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CHAR_MAX		300000									// ?????

// ????
static FILE *szpFpI;											// ??
static char sc1Name[D_CHAR_MAX + 5];							// ??
static int siCCnt;												// ???

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

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???

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

	// ?? - ??
	fgets(sc1Name, sizeof(sc1Name), szpFpI);

	// ???
	siCCnt = fCutCrLf(sc1Name);

	// ?????? - ??
	int liPCnt = 0;
	for (i = 0; i < siCCnt / 2; i++) {
		int liNo = siCCnt - 1 - i;
		if (sc1Name[i] != sc1Name[liNo]) {
			liPCnt++;
		}
	}

	// ????? - ??
	int liCnt = 0;
	for (i = 0; i < siCCnt / 2; i++) {
		int liNo = siCCnt - 1 - i;
		if (sc1Name[i] == sc1Name[liNo]) {		// ??
			liCnt += 50;
		}
		else {									// ???
			if (liPCnt > 1) {						// ??????????
				liCnt += 50;
			}
			else {									// ??????????
				liCnt += 48;
			}
		}
	}

	// ??????
	if (siCCnt % 2 == 1) {
		if (liPCnt > 0) {						// ??????????
			liCnt += 25;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:64:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1Name, sizeof(sc1Name), szpFpI);
  ^