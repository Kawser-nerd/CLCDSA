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
static int siSLen;												// ??????
static int siCCnt;												// ?????
static char sc1Str[1024];										// ?????
static int si1Cnt[D_CHAR_CNT];									// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????????
int
fChkMake(
	int piCNo					// <I> ???? 0?
	, int piCCnt				// <I> ???
	, int *pipCnt				// <I> ?????
)
{
	int i;

	for (i = piCNo; i < siSLen; i++) {

		// ??????
		int liCNo = sc1Str[i] - 'a';

		// ??????
		if (pipCnt[liCNo] > 0) {			// ??
			pipCnt[liCNo]--;
		}
		else {								// ??
			piCCnt++;
		}
	}

	// ?????????
	if (piCCnt > siCCnt) {
		return -1;
	}

	return 0;
}

// ???? - ??
int
fGetChar(
	int piCNo					// <I> ???? 0?
	, int piCCnt				// <I> ???
)
{
	int i, liRet;

	for (i = 0; i < D_CHAR_CNT; i++) {

		// ??????
		if (si1Cnt[i] < 1) {
			continue;
		}

		// ????
		if (sc1Str[piCNo] == 'a' + i) {		// ??
			return i;
		}

		// ???
		int liCCnt = piCCnt + 1;
		if (liCCnt > siCCnt) {
			continue;
		}

		// ????? - ???
		int li1Cnt[D_CHAR_CNT];
		memcpy(li1Cnt, si1Cnt, sizeof(li1Cnt));
		li1Cnt[i]--;

		// ????????
		liRet = fChkMake(piCNo + 1, liCCnt, li1Cnt);
		if (liRet == 0) {
			return i;
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

	// ???????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSLen, &siCCnt);

	// ????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%s", sc1Str);

	// ????? - ??
	memset(si1Cnt, 0, sizeof(si1Cnt));
	for (i = 0; i < siSLen; i++) {
		si1Cnt[sc1Str[i] - 'a']++;
	}

	// ????????
	int liCCnt = 0;
	for (i = 0; i < siSLen; i++) {

		// ???? - ??
		int liCNo = fGetChar(i, liCCnt);

		// ???
		lc1Out[i] = 'a' + liCNo;
		si1Cnt[liCNo]--;

		// ????
		if (sc1Str[i] != lc1Out[i]) {		// ??
			liCCnt++;
		}
	}

	// ??
	lc1Out[siSLen] = '\n';
	lc1Out[siSLen + 1] = '\0';

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
./Main.c:119:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:123:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^