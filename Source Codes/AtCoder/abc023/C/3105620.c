#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		100000									// ?????

// ????? - ????
typedef struct Pos {
	int miRow, miCol;											// ???
} Pos;

// ????
static Pos sz1Pos[D_ARRAY_MAX];									// ????
static int siPCnt;												// ?????
static int si1Row[D_ARRAY_MAX + 5];								// ???
static int siRCnt;												// ??
static int si1Col[D_ARRAY_MAX + 5];								// ???
static int siCCnt;												// ??
static int siNeed;												// ???
static int si1RSum[D_ARRAY_MAX + 5];							// ???????
static int si1CSum[D_ARRAY_MAX + 5];							// ???????

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
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(si1Row, 0, sizeof(si1Row));							// ???
	memset(si1Col, 0, sizeof(si1Col));							// ???
	memset(si1RSum, 0, sizeof(si1RSum));						// ???????
	memset(si1CSum, 0, sizeof(si1CSum));						// ???????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siRCnt, &siCCnt, &siNeed);

	// ????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siPCnt);

	// ???? - ??
	for (i = 0; i < siPCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Pos[i].miRow, &sz1Pos[i].miCol);

		// ????
		si1Row[sz1Pos[i].miRow]++;
		si1Col[sz1Pos[i].miCol]++;
	}

	// ??????? - ???
	for (i = 1; i <= siRCnt; i++) {
		si1RSum[si1Row[i]]++;
	}

	// ??????? - ???
	for (i = 1; i <= siCCnt; i++) {
		si1CSum[si1Col[i]]++;
	}

	// ???????
	long long llSum = 0;
	for (i = 0; i <= siNeed; i++) {
		llSum += (long long)si1RSum[i] * (long long)si1CSum[siNeed - i];
	}

	// ???????
	for (i = 0; i < siPCnt; i++) {

		// ???????
		int liCnt = si1Row[sz1Pos[i].miRow] + si1Col[sz1Pos[i].miCol];
		if (liCnt == siNeed) {
			llSum--;
		}
		else if (liCnt == siNeed + 1) {
			llSum++;
		}
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
./Main.c:61:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:69:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:78:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^