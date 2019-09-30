#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CRS_MAX		100000									// ??????

// ????
static FILE *szpFpI;											// ??
static int si1Crs[D_CRS_MAX + 5];								// ??????(??)
static int siCCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??????(??) - ??
int
fGetCNo(
	int piCNo					// <I> ??? 1?
)
{
	// ???????
	if (si1Crs[piCNo] == piCNo) {
		return piCNo;
	}

	// ??
	si1Crs[piCNo] = fGetCNo(si1Crs[piCNo]);

	return si1Crs[piCNo];
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

	// ???????? - ??
	int liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siCCnt, &liRCnt);

	// ??????(??) - ???
	for (i = 1; i <= siCCnt; i++) {
		si1Crs[i] = i;
	}

	// ?? - ??
	for (i = 0; i < liRCnt; i++) {
		int liCNo1, liCNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liCNo1, &liCNo2);

		// ??????(??) - ??
		int liPNo1 = fGetCNo(liCNo1);
		int liPNo2 = fGetCNo(liCNo2);

		// ??????(??) - ??
		if (liPNo1 != liPNo2) {				// ???
			si1Crs[liPNo2] = liPNo1;
		}
	}

	// ??????(??)?? - ??
	int liCnt = 0;
	for (i = 1; i <= siCCnt; i++) {
		if (si1Crs[i] == i) {
			liCnt++;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt - 1);

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
./Main.c:61:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:72:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^