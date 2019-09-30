#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_LV_MAX		55										// ?????

// ????
static FILE *szpFpI;											// ??
static int siLV;												// ???
static long long sl1ACnt[D_LV_MAX];								// ??[???]
static long long sl1PCnt[D_LV_MAX];								// ??????[???]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????? - ??
long long
fGetPCnt(
	int piLV					// <I> ???
	, long long plCnt			// <I> ??
)
{
	// ?? >= ??
	if (plCnt >= sl1ACnt[piLV]) {

		// ???
		if (sl1PCnt[piLV] > 0) {
			return sl1PCnt[piLV];
		}

		// ???
		if (piLV == 0) {
			sl1PCnt[piLV] = 1;
		}
		else {
			sl1PCnt[piLV] = fGetPCnt(piLV - 1, plCnt) * 2 + 1;		// ???
		}

		return sl1PCnt[piLV];
	}

	long long llSum = 0;

	// ?????
	if (plCnt > 0) {
		llSum = fGetPCnt(piLV - 1, plCnt - 1);
	}

	// ???
	long long llMdl = sl1ACnt[piLV] / 2 + 1;
	if (plCnt >= llMdl) {
		llSum++;
	}

	// ?????
	if (plCnt > llMdl) {
		llSum += fGetPCnt(piLV - 1, plCnt - llMdl);
	}

	return llSum;
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
	memset(sl1PCnt, 0, sizeof(sl1PCnt));						// ??????[???]

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
	long long llCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%lld", &siLV, &llCnt);

	// ?? - ???
	sl1ACnt[0] = 1;
	for (i = 1; i <= siLV; i++) {
		sl1ACnt[i] = sl1ACnt[i - 1] * 2 + 3;
	}

	// ?????? - ??
	long long llPCnt = fGetPCnt(siLV, llCnt);

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llPCnt);

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
./Main.c:96:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^