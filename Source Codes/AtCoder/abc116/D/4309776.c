#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SUSHI_MAX		100005									// ?????

// ????? - ????
typedef struct Sushi {
	int miType;													// ??
	int miVal;													// ????
} Sushi;

// ????
static FILE *szpFpI;											// ??
static Sushi sz1Sushi[D_SUSHI_MAX];								// ??
static int siSCnt;												// ???
static int siECnt;												// ???
static int si1ECnt[D_SUSHI_MAX];								// ???[??]
static int siTCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ??????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Sushi *lzpVal1 = (Sushi *)pzpVal1;
	Sushi *lzpVal2 = (Sushi *)pzpVal2;

	// ??????
	if (lzpVal1->miVal > lzpVal2->miVal) {
		return -1;
	}
	else if (lzpVal1->miVal < lzpVal2->miVal) {
		return 1;
	}

	return 0;
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
	memset(si1ECnt, 0, sizeof(si1ECnt));						// ???[??]
	siTCnt = 0;													// ???

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

	// ??????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siSCnt, &siECnt);

	// ?? - ??
	for (i = 0; i < siSCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Sushi[i].miType, &sz1Sushi[i].miVal);
	}

	// ?? - ???
	qsort(sz1Sushi, siSCnt, sizeof(Sushi), fSortFnc);

	// ??? - ???
	long long llMax = 0;
	for (i = 0; i < siECnt; i++) {
		llMax += sz1Sushi[i].miVal;

		// ???
		if (si1ECnt[sz1Sushi[i].miType] == 0) {
			siTCnt++;
		}
		si1ECnt[sz1Sushi[i].miType]++;
	}
	llMax += (long long)siTCnt * (long long)siTCnt;

	// ??? - ??
	long long llVal = llMax;
	int liSNo = siECnt - 1;
	int liENo = liSNo;
	while (1) {

		// ?????? - ??
		while (liSNo >= 0) {
			if (si1ECnt[sz1Sushi[liSNo].miType] > 1) {
				break;
			}
			else {
				liSNo--;
			}
		}
		if (liSNo < 0) {
			break;
		}

		// ????? - ??
		while (liENo < siSCnt) {
			if (si1ECnt[sz1Sushi[liENo].miType] == 0) {
				break;
			}
			else {
				liENo++;
			}
		}
		if (liENo >= siSCnt) {
			break;
		}

		// ???? - ??
		llVal -= sz1Sushi[liSNo].miVal;
		llVal += sz1Sushi[liENo].miVal;

		// ??? - ??
		si1ECnt[sz1Sushi[liSNo].miType]--;
		llVal -= (long long)siTCnt * (long long)siTCnt;
		siTCnt++;
		si1ECnt[sz1Sushi[liENo].miType]++;
		llVal += (long long)siTCnt * (long long)siTCnt;

		// ?? - ??
		liSNo--;
		liENo++;

		// ??? - ??
		if (llMax < llVal) {
			llMax = llVal;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llMax);

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
./Main.c:78:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:83:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^