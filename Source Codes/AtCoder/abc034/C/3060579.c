#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_PRM_MAX		20000									// ?????
#define D_MOD			1000000007								// ??

// ????? - ????
typedef struct Prm {
	int miVal;													// ?
	int miCnt;													// ?
} Prm;

// ????
static Prm sz1Prm[D_PRM_MAX];									// ??
static int siPCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ???
int
fChgPrm(
	int piSVal					// <I> ??? 2?
	, int piEVal				// <I> ???
	, int piAdd					// <I> ??? 1 or -1
)
{
	int i;

	for (i = piSVal; i <= piEVal; i++) {
		int liVal = i;
		int liPNo = 0;
		while (liVal > 1 && liPNo < siPCnt) {
			if (liVal % sz1Prm[liPNo].miVal == 0) {
				liVal /= sz1Prm[liPNo].miVal;
				sz1Prm[liPNo].miCnt += piAdd;
			}
			else {
				liPNo++;
			}
		}
		if (liVal > 1) {
			sz1Prm[siPCnt].miVal = liVal;
			sz1Prm[siPCnt].miCnt = piAdd;
			siPCnt++;
		}
	}

	return 0;
}

// nCr??
long long
fGetComb(
	int piN						// <I> n
	, int piR					// <I> r
)
{
	int i, j;

	// r???
	int liHalf = piN / 2;
	if (piR > liHalf) {
		piR = piN - piR;
	}

	// r????
	siPCnt = 0;
	fChgPrm(2, piR, -1);

	// n????
	fChgPrm(piN - piR + 1, piN, 1);

	// ?????
	long long llRet = 1;
	for (i = 0; i < siPCnt; i++) {
		for (j = 0; j < sz1Prm[i].miCnt; j++) {
			llRet *= (long long)sz1Prm[i].miVal;
			llRet %= (long long)D_MOD;
		}
	}

	return llRet;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???? - ??
	int liW, liH;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liW, &liH);

	// nCr??
	long long llRet = fGetComb(liW + liH - 2, liW - 1);

	// ?????
	sprintf(lc1Out, "%lld\n", llRet);

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
./Main.c:116:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^