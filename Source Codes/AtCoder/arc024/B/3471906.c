#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TREE_MAX		100000									// ????

// ????
static FILE *szpFpI;											// ??
static int si1Tree[D_TREE_MAX];									// ?
static int siTCnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?? - ??
int
fGetDCnt(
)
{
	int i;

	// ?????? - ??
	int liSNo = -1;
	for (i = 1; i < siTCnt; i++) {
		if (si1Tree[i] != si1Tree[i - 1]) {
			liSNo = i;
			break;
		}
	}
	if (liSNo < 0) {
		return -1;
	}

	// ??????? - ??
	int liENo = liSNo - 1;
	int liMax = 0;
	int liLen = 1;
	while (liSNo != liENo) {

		// ???
		int liNNo;
		if (liSNo < siTCnt - 1) {
			liNNo = liSNo + 1;
		}
		else {
			liNNo = 0;
		}

		// ??????
		if (si1Tree[liSNo] == si1Tree[liNNo]) {
			liLen++;
			if (liMax < liLen) {
				liMax = liLen;
			}
		}
		else {
			liLen = 1;
		}

		// ????
		liSNo = liNNo;
	}

	return (liMax + 1) / 2;
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

	// ?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siTCnt);

	// ? - ??
	for (i = 0; i < siTCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &si1Tree[i]);
	}

	// ?? - ??
	int liDCnt = fGetDCnt();

	// ?? - ???
	sprintf(lc1Out, "%d\n", liDCnt);

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
./Main.c:95:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:100:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^