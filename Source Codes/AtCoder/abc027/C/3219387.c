#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

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

	// ??? - ??
	long long llLimit;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld", &llLimit);

	// ???? - ??
	int liOCnt = 0;
	long long llNow = 2;
	for ( ; ; liOCnt++) {
		if (llNow > llLimit) {
			break;
		}
		else {
			llNow *= 2;
		}
	}

	// ??
	llNow = 1;
	for (i = 1; ; i++) {
		if (liOCnt % 2 == 1) {			// ?????
			if (i % 2 == 1) {				// Takahashi
				llNow *= 2;
			}
			else {							// Aoki
				llNow = llNow * 2 + 1;
			}
		}
		else {							// ?????
			if (i % 2 == 1) {				// Takahashi
				llNow = llNow * 2 + 1;
			}
			else {							// Aoki
				llNow *= 2;
			}
		}
		if (llNow > llLimit) {
			break;
		}
	}

	// ?? - ???
	if (i % 2 == 1) {
		sprintf(lc1Out, "Aoki\n");
	}
	else {
		sprintf(lc1Out, "Takahashi\n");
	}

	// ?? - ??
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
./Main.c:39:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^