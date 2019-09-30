#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_LEN_MAX		100005									// ????
#define D_POW_MAX		70										// ?????????

// ????
static FILE *szpFpI;											// ??
static int si1VCnt[D_LEN_MAX];									// ???[??]
static int siVCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??? - ??
long long
fGetPow(
	long long plVal				// <I> ?
	, long long plCnt			// <I> ?? 1?
)
{
	int i;

	// ?????? - ???
	long long ll1Val[D_POW_MAX];
	long long ll1Cnt[D_POW_MAX];
	ll1Val[0] = plVal;
	ll1Cnt[0] = 1;
	int liLCnt = 1;

	// ?????? - ??
	while (ll1Cnt[liLCnt - 1] < plCnt) {
		ll1Val[liLCnt] = ll1Val[liLCnt - 1] * ll1Val[liLCnt - 1];
		ll1Val[liLCnt] %= D_MOD;
		ll1Cnt[liLCnt] = ll1Cnt[liLCnt - 1] * 2;
		liLCnt++;
	}

	// ??? - ??
	long long llVal = 1;
	for (i = liLCnt - 1; i >= 0; i--) {
		if (plCnt >= ll1Cnt[i]) {
			plCnt -= ll1Cnt[i];
			llVal *= ll1Val[i];
			llVal %= D_MOD;
		}
	}

	return llVal;
}

// ????? - ??
int
fGetPtn(
)
{
	int i;
	char lc1Buf[1024];

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siVCnt);

	// ???
	int liLen;
	fscanf(szpFpI, "%d", &liLen);
	if (liLen != 0) {
		return 0;
	}
	si1VCnt[0] = 1;

	// ???[??]?????????? - ??
	int liMCnt = 0;
	int liMLen = 0;
	for (i = 1; i < siVCnt; i++) {
		fscanf(szpFpI, "%d", &liLen);
		si1VCnt[liLen]++;

		// ???? - ??
		if (liMCnt < si1VCnt[liLen]) {
			liMCnt = si1VCnt[liLen];
		}

		// ???? - ??
		if (liMLen < liLen) {
			liMLen = liLen;
		}
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	if (si1VCnt[0] != 1) {
		return 0;
	}

	// ????? - ??
	long long llSum = 1;
	for (i = 1; i <= liMLen; i++) {
		if (si1VCnt[i] < 1) {
			return 0;
		}

		// ???????????
		long long llPtn = fGetPow(2, si1VCnt[i - 1]) - (long long)1;		// ????
		llSum *= fGetPow(llPtn, si1VCnt[i]);
		llSum %= D_MOD;

		// ???????????
		if (si1VCnt[i] > 1) {
			llSum *= fGetPow(2, (long long)si1VCnt[i] * (long long)(si1VCnt[i] - 1) / (long long)2);
			llSum %= D_MOD;
		}
	}

	return (int)llSum;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1VCnt, 0, sizeof(si1VCnt));						// ???[??]

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

	// ????? - ??
	int liPCnt = fGetPtn();

	// ?? - ???
	sprintf(lc1Out, "%d\n", liPCnt);

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
} ./Main.c: In function ‘fGetPtn’:
./Main.c:70:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:75:2: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
  fscanf(szpFpI, "%d", &liLen);
  ^
./Main.c:85:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liLen);
   ^
./Main.c:98:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^