#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_COMB_MAX		100000									// ??nCr????
#define D_PRM_MAX		10000									// ?????
#define D_MOD			1000000007								// ??

// ????? - ????
typedef struct Prm {
	int miVal;													// ?
	int miCnt;													// ?
} Prm;

// ????
static int si1Comb[D_COMB_MAX];									// nCr???
static int siCCnt;												// nCr????
static Prm sz1Prm[D_PRM_MAX];									// ??
static int siPCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

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

	// nCr???
	siCCnt = piR;
	for (i = 0; i < siCCnt; i++) {
		si1Comb[i] = piN - i;
	}

	// r????
	siPCnt = 0;
	for (i = 2; i <= piR; i++) {
		int liVal = i;
		int liPNo = 0;
		while (liVal > 1 && liPNo < siPCnt) {
			if (liVal % sz1Prm[liPNo].miVal == 0) {
				liVal /= sz1Prm[liPNo].miVal;
				sz1Prm[liPNo].miCnt++;
			}
			else {
				liPNo++;
			}
		}
		if (liVal > 1) {
			sz1Prm[siPCnt].miVal = liVal;
			sz1Prm[siPCnt].miCnt = 1;
			siPCnt++;
		}
	}

	// ?????r???
	int liNNo = 0;
	for (i = siPCnt - 1; i >= 0; i--) {
		for (j = 0; j < sz1Prm[i].miCnt; j++) {
			while (si1Comb[liNNo] % sz1Prm[i].miVal != 0) {
				if (liNNo < siCCnt - 1) {
					liNNo++;
				}
				else {
					liNNo = 0;
				}
			}
			si1Comb[liNNo] /= sz1Prm[i].miVal;
		}
	}

	// ??
	long long llRet = si1Comb[0];
	for (i = 1; i < siCCnt; i++) {
		llRet *= (long long)si1Comb[i];
		llRet %= (long long)D_MOD;
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
./Main.c:121:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^