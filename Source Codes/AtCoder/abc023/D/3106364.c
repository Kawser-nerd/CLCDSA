#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_BLN_MAX		100000									// ?????
#define D_UP_MAX		1000000000								// ?????

// ????? - ????
typedef struct Bln {
	int miH;													// ??
	int miUp;													// ???
} Bln;

// ????
static Bln sz1Bln[D_BLN_MAX];									// ??
static int siBCnt;												// ???
static int si1Time[D_BLN_MAX];									// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ??????
int
fGetMinChk(
	long long plH				// <I> ??
)
{
	int i;

	// ??????
	memset(si1Time, 0, sizeof(si1Time));
	for (i = 0; i < siBCnt; i++) {

		// ??????
		if (plH < (long long)sz1Bln[i].miH) {
			return -1;
		}

		// ???
		long long llSec = (plH - (long long)sz1Bln[i].miH) / (long long)sz1Bln[i].miUp;
		if (llSec >= siBCnt) {
			llSec = siBCnt - 1;
		}

		si1Time[llSec]++;
	}

	// ???????
	int liSum = 0;
	for (i = 0; i < siBCnt - 1; i++) {
		liSum += si1Time[i];
		if (liSum > i + 1) {
			return -1;
		}
	}

	return 0;
}

// ?????
long long
fGetMin(
)
{
	int liRet;

	// ???? - ???
	long long llHMin = 0;
	long long llHMax = (long long)siBCnt * (long long)D_UP_MAX;

	// ??
	long long llMin;
	while (1) {

		// ??????
		if (llHMin > llHMax) {
			break;
		}

		// ??
		long long llH = (llHMin + llHMax) / 2;

		// ??????
		liRet = fGetMinChk(llH);
		if (liRet == 0) {							// OK
			llMin = llH;								// ?????
			llHMax = llH - 1;							// ????
		}
		else {										// NG
			llHMin = llH + 1;							// ????
		}
	}

	return llMin;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siBCnt);

	// ?? - ??
	for (i = 0; i < siBCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Bln[i].miH, &sz1Bln[i].miUp);
	}

	// ?????
	long long llMin = fGetMin();

	// ?????
	sprintf(lc1Out, "%lld\n", llMin);

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
./Main.c:126:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:135:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^