#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_ARRAY_MAX		100000									// ?????

// ????
static int si1Array[D_ARRAY_MAX];								// ??
static int siACnt;												// ???
static long long slMax;											// ???
static int siLen;												// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????? - ???
int
fSetLen(
)
{

	// ???
	long long llM = 1;					// ?
	int liSNo = -1;						// ????
	int liENo = -1;						// ????

	// ??
	while (1) {

		// ??
		while (1) {

			// ??????
			if (liENo >= siACnt - 1) {
				return 0;
			}

			// ??
			liENo++;
			llM *= (long long)si1Array[liENo];

			// ?????
			if (llM > slMax) {
				break;
			}

			// ??????
			int liLen = liENo - liSNo;
			if (siLen < liLen) {
				siLen = liLen;
			}
		}

		// ??
		while (llM > slMax) {
			liSNo++;
			llM /= (long long)si1Array[liSNo];
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

	// ??????
	siLen = 0;													// ??????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%lld", &siACnt, &slMax);

	// ??????? - ??
	int liZero = D_OFF;
	for (i = 0; i < siACnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d", &si1Array[i]);

		// ????
		if (si1Array[i] == 0) {
			liZero = D_ON;
		}
	}

	// ????
	if (liZero == D_ON) {				// ??
		siLen = siACnt;
	}
	else {								// ??
		if (slMax > 0) {					// ?????
			fSetLen();							// ??
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", siLen);

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
./Main.c:98:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:108:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^