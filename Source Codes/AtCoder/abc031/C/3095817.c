#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		50										// ?????

// ????
static int si1Array[D_ARRAY_MAX];								// ??
static int siACnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????
int
fGetPoint(
	int piNo1					// <I> ?? 0?
	, int piNo2					// <I> ?? 0?
	, int piAdd					// <I> ???? 0 or 1
)
{
	int i;

	// ??
	int liSNo, liENo;
	if (piNo1 < piNo2) {
		liSNo = piNo1;
		liENo = piNo2;
	}
	else {
		liSNo = piNo2;
		liENo = piNo1;
	}

	// ????
	liSNo += piAdd;

	// ????
	int liSum = 0;
	for (i = liSNo; i <= liENo; i += 2) {
		liSum += si1Array[i];
	}

	return liSum;
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
	sscanf(lc1Buf, "%d", &siACnt);

	// ?? - ??
	for (i = 0; i < siACnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &si1Array[i]);
#else
		fscanf(stdin, "%d", &si1Array[i]);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ??????
	int liTMax = INT_MIN;
	int liTNo;
	for (liTNo = 0; liTNo < siACnt; liTNo++) {

		// ??????
		int liAMax = INT_MIN;
		int liANo;
		for (i = 0; i < siACnt; i++) {
			if (i == liTNo) {
				continue;
			}

			// ??????
			int liVal = fGetPoint(i, liTNo, 1);
			if (liAMax < liVal) {
				liAMax = liVal;
				liANo = i;
			}
		}

		// ??????
		int liVal = fGetPoint(liTNo, liANo, 0);
		if (liTMax < liVal) {
			liTMax = liVal;
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", liTMax);

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
./Main.c:76:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:85:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &si1Array[i]);
   ^
./Main.c:91:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^