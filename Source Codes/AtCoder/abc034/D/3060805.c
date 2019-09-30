#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_WATER_MAX		1000									// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????? - ??
	int liWCnt, liUCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liWCnt, &liUCnt);

	// ??????????? - ??
	long double ld1Water[D_WATER_MAX], ld1Cct[D_WATER_MAX];
	long double ldMax = 0;
	int liNo;
	for (i = 0; i < liWCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%Lf%Lf", &ld1Water[i], &ld1Cct[i]);

		// ????
		if (ldMax < ld1Cct[i]) {
			ldMax = ld1Cct[i];
			liNo = i;
		}
	}

	// ???
	long double ldWater = ld1Water[liNo];
	long double ldSalt = ldWater * ld1Cct[liNo] / (long double)100.0;
	liWCnt--;
	ld1Water[liNo] = ld1Water[liWCnt];
	ld1Cct[liNo] = ld1Cct[liWCnt];

	// ????????????
	for (i = 1; i < liUCnt; i++) {

		// ?????????????
		ldMax = 0;
		for (j = 0; j < liWCnt; j++) {
			long double ldWater2 = ldWater + ld1Water[j];
			long double ldSalt2 = ldSalt + ld1Water[j] * ld1Cct[j] / (long double)100.0;
			long double ldCct2 = ldSalt2 / ldWater2;
			if (ldMax < ldCct2) {
				ldMax = ldCct2;
				liNo = j;
			}
		}

		// ??????
		ldWater += ld1Water[liNo];
		ldSalt += ld1Water[liNo] * ld1Cct[liNo] / (long double)100.0;

		// ??????
		liWCnt--;
		ld1Water[liNo] = ld1Water[liWCnt];
		ld1Cct[liNo] = ld1Cct[liWCnt];
	}

	// ?????
	sprintf(lc1Out, "%.9Lf\n", ldSalt / ldWater * (long double)100.0);

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
./Main.c:40:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:52:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^