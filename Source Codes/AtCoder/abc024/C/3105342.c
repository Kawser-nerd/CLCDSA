#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_DAY_MAX		10000									// ????

// ????? - ????
typedef struct Move {
	int miSNo;													// ???? - ?? 1?
	int miENo;													// ???? - ?? 1?
} Move;

// ????
static Move sz1Move[D_DAY_MAX + 5];								// ????
static int siMCnt;												// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fGetDay(
	int piSNo					// <I> ???? 1?
	, int piENo					// <I> ???? 1?
)
{
	int i;

	// ????
	int liWay = piENo - piSNo;

	// ??
	for (i = 1; i <= siMCnt; i++) {

		// ??????
		if (piSNo < sz1Move[i].miSNo || sz1Move[i].miENo < piSNo) {
			continue;
		}

		// ??
		if (liWay > 0) {
			piSNo = sz1Move[i].miENo;

			// ??????
			if (piSNo >= piENo) {
				return i;
			}
		}
		else {
			piSNo = sz1Move[i].miSNo;

			// ??????
			if (piSNo <= piENo) {
				return i;
			}
		}
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

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ????????? - ??
	int liWork, liPCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &liWork, &siMCnt, &liPCnt);

	// ???? - ??
	for (i = 1; i <= siMCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Move[i].miSNo, &sz1Move[i].miENo);
	}

	// ?? - ??
	for (i = 0; i < liPCnt; i++) {
		int liSNo, liENo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liSNo, &liENo);

		// ?????
		int liDay = fGetDay(liSNo, liENo);

		// ?????
		sprintf(lc1Out, "%d\n", liDay);

		// ????
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

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
./Main.c:92:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:101:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:112:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^