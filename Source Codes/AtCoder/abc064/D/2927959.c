#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CHAR_MAX		100										// ?????
#define D_CHAR_SP		'('										// ???
#define D_CHAR_EP		')'										// ???

// ????
static char sc1Out[D_CHAR_MAX * 2 + 5];							// ????
static int siBNo;												// ????? - ?
static int siANo;												// ????? - ?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????????? - ?
int
fAddCharB(
	char pcChar					// <I> ????
)
{
	siBNo--;
	sc1Out[siBNo] = pcChar;

	return 0;
}

// ????????? - ?
int
fAddCharA(
	char pcChar					// <I> ????
)
{
	sc1Out[siANo] = pcChar;
	siANo++;

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

	// ??????
	siBNo = D_CHAR_MAX;											// ????? - ?
	siANo = D_CHAR_MAX;											// ????? - ?

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????
	int liCCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liCCnt);

	// ?????
	char lc1Str[D_CHAR_MAX + 5];
#ifdef D_TEST
	fgets(lc1Str, sizeof(lc1Str), szpFpT);
#else
	fgets(lc1Str, sizeof(lc1Str), stdin);
#endif

	// ???????
	int liSPCnt = 0;
	for (i = 0; i < liCCnt; i++) {
		if (lc1Str[i] == D_CHAR_SP) {		// ???
			fAddCharA(D_CHAR_SP);				// ????
			liSPCnt++;							// ????????
		}
		else {								// ???
			fAddCharA(D_CHAR_EP);				// ????
			if (liSPCnt > 0) {					// ??????????
				liSPCnt--;							// ????????
			}
			else {								// ??????????
				fAddCharB(D_CHAR_SP);				// ????
			}
		}
	}

	// ????????
	for (i = 0; i < liSPCnt; i++) {
		fAddCharA(D_CHAR_EP);				// ????
	}

	// ????
	fAddCharA('\0');

	// ?????
	sprintf(lc1Out, "%s\n", &sc1Out[siBNo]);

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
./Main.c:75:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:84:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Str, sizeof(lc1Str), stdin);
  ^