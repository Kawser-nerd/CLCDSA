#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_BIT_MAX		40										// ??????

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ?????? - ??
int
fGetCnt(
	long long plVal				// <I> ?
	, long long *plpCnt			// <O> ??
)
{
	int i;

	long long llVal = 1;
	long long llVal2 = 2;
	for (i = 0; i < D_BIT_MAX; i++) {

		// ?
		plpCnt[i] = plVal / llVal2 * llVal;

		// ??
		long long llMod = plVal % llVal2;
		if (llMod >= llVal) {
			plpCnt[i] += llMod - llVal + 1;
		}

		// ???
		llVal = llVal2;
		llVal2 *= 2;
	}

	return 0;
}

// ?????
long long
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// ?? - ??
	long long llValS, llValE;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%lld", &llValS, &llValE);

	// ?????? - ??
	long long ll1CntE[D_BIT_MAX];
	fGetCnt(llValE, ll1CntE);

	// ?????? - ??
	if (llValS > 0) {
		long long ll1CntS[D_BIT_MAX];
		fGetCnt(llValS - 1, ll1CntS);

		for (i = 0; i < D_BIT_MAX; i++) {
			ll1CntE[i] -= ll1CntS[i];
		}
	}

	// ????????
	long long llSum = 0;
	long long llVal = 1;
	for (i = 0; i < D_BIT_MAX; i++) {
		if (ll1CntE[i] % 2 == 1) {
			llSum += llVal;
		}

		// ???
		llVal *= 2;
	}

	return llSum;
}

// ????
int
fOne(
)
{
	long long llRet;
	char lc1Buf[1024], lc1Out[1024];

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????
	llRet = fMain();

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llRet);

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// ???????
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne(0);
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:62:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^