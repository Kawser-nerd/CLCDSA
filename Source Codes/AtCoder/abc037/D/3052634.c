#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_MASS_SIZE		1000									// ???????
#define D_MASS_MAX		1000000									// ?????
#define D_MOD			1000000007								// ??

// ????? - ????
typedef struct Mass {
	int miX, miY;												// ??
	int miVal;													// ?
	long long mlCnt;											// ???
} Mass;

// ????
static int siH;													// ??
static int siW;													// ?
static Mass sz2Mass[D_MASS_SIZE][D_MASS_SIZE];					// ??[X][Y]
static Mass *szp1Mass[D_MASS_MAX];								// ????????
static int siMCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ???
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Mass **lzppVal1 = (Mass **)pzpVal1;
	Mass **lzppVal2 = (Mass **)pzpVal2;

	// ???
	if ((*lzppVal1)->miVal > (*lzppVal2)->miVal) {
		return(1);
	}
	else if ((*lzppVal1)->miVal < (*lzppVal2)->miVal) {
		return(-1);
	}

	return 0;
}

// ??
int
fMove(
	int piNo					// <I> ???? 0?
	, int piX					// <I> X????
	, int piY					// <I> Y????
)
{
	// ??X
	int liX = szp1Mass[piNo]->miX + piX;
	if (liX < 0 || siW <= liX) {
		return 0;
	}

	// ??Y
	int liY = szp1Mass[piNo]->miY + piY;
	if (liY < 0 || siH <= liY) {
		return 0;
	}

	// ?????????
	if (sz2Mass[liX][liY].miVal <= szp1Mass[piNo]->miVal) {
		return 0;
	}

	// ?????
	sz2Mass[liX][liY].mlCnt += szp1Mass[piNo]->mlCnt;
	sz2Mass[liX][liY].mlCnt %= (long long)D_MOD;

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siMCnt = 0;													// ???

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ????
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
#ifdef D_TEST
			fscanf(szpFpT, "%d", &sz2Mass[j][i].miVal);
#else
			fscanf(stdin, "%d", &sz2Mass[j][i].miVal);
#endif
			sz2Mass[j][i].miX = j;								// ??X
			sz2Mass[j][i].miY = i;								// ??Y
			sz2Mass[j][i].mlCnt = 1;							// ???
			szp1Mass[siMCnt] = &sz2Mass[j][i];					// ????????
			siMCnt++;											// ???
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ???
	qsort(szp1Mass, siMCnt, sizeof(Mass *), fSortFnc);

	// ????
	long long llSum = 0;
	for (i = 0; i < siMCnt; i++) {

		// ????
		llSum += szp1Mass[i]->mlCnt;
		llSum %= (long long)D_MOD;

		// ??
		fMove(i, 1, 0);
		fMove(i, -1, 0);
		fMove(i, 0, 1);
		fMove(i, 0, -1);
	}

	// ?????
	sprintf(lc1Out, "%lld\n", llSum);

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
./Main.c:111:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:121:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &sz2Mass[j][i].miVal);
    ^
./Main.c:132:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^