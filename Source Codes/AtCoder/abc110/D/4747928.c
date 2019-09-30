#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MOD			1000000007								// ??(10?9?+7)
#define D_PRM_MAX		100										// ?????
#define D_FACT_MAX		100100									// ?????

// ????? - ????
typedef struct Prm {
	int miVal;													// ?
	int miCnt;													// ??
} Prm;

// ????
static FILE *szpFpI;											// ??
static int siN;													// N
static int siM;													// M
static Prm sz1Prm[D_PRM_MAX];									// ??
static int siPCnt;												// ???
static int si1ModFact[D_FACT_MAX];								// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
int
fDivPrm(
)
{
	int i;

	// ??
	int liLimit = (int)sqrt((double)siM);

	// ?????
	for (i = 2; i <= liLimit; i++) {

		// ????
		if (siM == 1) {
			break;
		}

		// ??
		while (siM % i == 0) {
			siM /= i;
			sz1Prm[siPCnt].miCnt++;
		}

		// ????
		if (sz1Prm[siPCnt].miCnt > 0) {
			sz1Prm[siPCnt].miVal = i;
			siPCnt++;
		}
	}

	// ????????
	if (siM != 1) {
		sz1Prm[siPCnt].miCnt = 1;
		sz1Prm[siPCnt].miVal = siM;
		siPCnt++;
	}

	return 0;
}

// ????? - ??
int
fMakeModFact(
	int piMax					// <I> ???
)
{
	int i;

	si1ModFact[0] = 1;
	si1ModFact[1] = 1;
	for (i = 2; i <= piMax; i++) {
		si1ModFact[i] = (int)((long long)si1ModFact[i - 1] * (long long)i % (long long)D_MOD);
	}

	return 0;
}

// ??? - ??
int
fGetModPower(
	int piBase					// <I> ??
	, int piIdx					// <I> ??
)
{
	// ????? - ??
	int li1Val[100];
	li1Val[0] = piBase;
	int liCnt = 1;
	int liIdx = 1;
	while (piIdx > liIdx) {
		li1Val[liCnt] = (int)((long long)li1Val[liCnt - 1] * (long long)li1Val[liCnt - 1] % (long long)D_MOD);
		liCnt++;
		liIdx += liIdx;
	}

	// ??? - ??
	int liVal = 1;
	while (piIdx > 0) {
		if (piIdx >= liIdx) {
			piIdx -= liIdx;
			liVal = (int)((long long)liVal * (long long)li1Val[liCnt - 1] % (long long)D_MOD);
		}
		liCnt--;
		liIdx /= 2;
	}

	return liVal;
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
	memset(sz1Prm, 0, sizeof(sz1Prm));							// ??
	siPCnt = 0;													// ???

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

	// N, M - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siN, &siM);

	// ?????
	fDivPrm();

	// ??????? - ??
	int liMax = 0;
	for (i = 0; i < siPCnt; i++) {
		if (liMax < sz1Prm[i].miCnt) {
			liMax = sz1Prm[i].miCnt;
		}
	}

	// ????? - ??
	fMakeModFact(siN + liMax - 1);

	// ????? - ??
	int liPtn = 1;
	for (i = 0; i < siPCnt; i++) {

		// ??
		int liSum = siN + sz1Prm[i].miCnt - 1;

		// *n!
		int liVal = si1ModFact[liSum];

		// /r!
		int liDiv = fGetModPower(si1ModFact[sz1Prm[i].miCnt], D_MOD - 2);
		liVal = (int)((long long)liVal * (long long)liDiv % (long long)D_MOD);

		// /(n-r)!
		liDiv = fGetModPower(si1ModFact[liSum - sz1Prm[i].miCnt], D_MOD - 2);
		liVal = (int)((long long)liVal * (long long)liDiv % (long long)D_MOD);

		// ????? - ??
		liPtn = (long long)liPtn * (long long)liVal % (long long)D_MOD;
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liPtn);

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
./Main.c:149:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^