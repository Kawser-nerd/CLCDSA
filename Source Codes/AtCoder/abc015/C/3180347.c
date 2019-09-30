#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_QUIZ_MAX		5										// ?????
#define D_SEL_MAX		5										// ??????

// ????
static FILE *szpFpI;											// ??
static int si2Ans[D_QUIZ_MAX][D_SEL_MAX];						// ??
static int siQCnt;												// ???
static int siSCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??????
int
fChkAns(
	int piQNo					// <I> ?? 0?
	, int piXor					// <I> XOR
)
{
	int i, liRet;

	// ??????
	if (piQNo >= siQCnt) {
		if (piXor == 0) {
			return -1;
		}
		else {
			return 0;
		}
	}

	// ????????
	for (i = 0; i < siSCnt; i++) {
		liRet = fChkAns(piQNo + 1, piXor ^ si2Ans[piQNo][i]);
		if (liRet != 0) {
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
	int i, j;
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

	// ???????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siQCnt, &siSCnt);

	// ?? - ??
	for (i = 0; i < siQCnt; i++) {
		for (j = 0; j < siSCnt; j++) {
			fscanf(szpFpI, "%d", &si2Ans[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// ??????
	int liRet = fChkAns(0, 0);

	// ?? - ???
	if (liRet == 0) {
		sprintf(lc1Out, "Nothing\n");
	}
	else {
		sprintf(lc1Out, "Found\n");
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
./Main.c:75:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:81:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(szpFpI, "%d", &si2Ans[i][j]);
    ^
./Main.c:83:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^