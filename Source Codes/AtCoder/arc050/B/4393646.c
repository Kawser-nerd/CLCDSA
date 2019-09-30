#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??
static long long slRCnt;										// ??????
static long long slBCnt;										// ??????
static long long slRUse;										// ???????????
static long long slBUse;										// ???????????
static long long slMax;											// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? - ??
long long
fGetCnt(
	long long plRMake			// <I> ??????????
)
{
	// ???????
	long long llRCnt = slRCnt - slRUse * plRMake;

	// ???????
	long long llBCnt = slBCnt - plRMake;

	// ??????????
	long long llBMake = llBCnt / slBUse;
	if (llBMake > llRCnt) {
		llBMake = llRCnt;
	}

	// ????
	long long llSum = plRMake + llBMake;

	// ???? - ??
	if (slMax < llSum) {
		slMax = llSum;
	}

	return llSum;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	slMax = 0;													// ????

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
	sscanf(lc1Buf, "%lld%lld", &slRCnt, &slBCnt);

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%lld", &slRUse, &slBUse);

	// ???????????
	long long llRMin = 0;
	long long llRMax = slRCnt / slRUse;
	if (llRMax > slBCnt) {
		llRMax = slBCnt;
	}

	// ?????
	while (1) {

		// ??
		long long llSep = (llRMax - llRMin) / 3;
		if (llSep < 1) {
			while (llRMin <= llRMax) {
				fGetCnt(llRMin);
				llRMin++;
			}
			break;
		}

		// ??????
		long long llRCnt1 = llRMin + llSep;
		long long llRCnt2 = llRMax - llSep;

		// ???? - ??
		long long llSum1 = fGetCnt(llRCnt1);
		long long llSum2 = fGetCnt(llRCnt2);

		// ?????
		if (llSum1 < llSum2) {
			llRMin = llRCnt1;
		}
		else if (llSum1 > llSum2) {
			llRMax = llRCnt2;
		}
		else {
			llRMin = llRCnt1;
			llRMax = llRCnt2;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", slMax);

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
./Main.c:74:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:78:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^