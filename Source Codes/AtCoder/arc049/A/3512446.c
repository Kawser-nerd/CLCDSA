#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_INS_CNT		4										// ????

// ????
static FILE *szpFpI;											// ??

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
	char lc1Str[1024];
	fgets(lc1Str, sizeof(lc1Str), szpFpI);

	// ????
	int liSCnt = fCutCrLf(lc1Str);

	// ???? - ??
	int li1Ins[D_INS_CNT + 5];
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d%d", &li1Ins[0], &li1Ins[1], &li1Ins[2], &li1Ins[3]);
	li1Ins[1] += 1;
	li1Ins[2] += 2;
	li1Ins[3] += 3;
	li1Ins[4] = -1;

	// ????? - ???
	int liSNo = 0;
	int liINo = 0;
	int liNNo = 0;
	while (liSNo < liSCnt || liINo < D_INS_CNT) {
		if (liNNo == li1Ins[liINo]) {
			lc1Out[liNNo] = '"';
			liINo++;
		}
		else {
			lc1Out[liNNo] = lc1Str[liSNo];
			liSNo++;
		}
		liNNo++;
	}
	lc1Out[liNNo] = '\n';
	lc1Out[liNNo + 1] = '\0';

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
./Main.c:60:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Str, sizeof(lc1Str), szpFpI);
  ^
./Main.c:67:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^