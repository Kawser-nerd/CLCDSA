#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_DIGIT_MAX		35										// ????

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
	long long llVal;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld", &llVal);

//	llVal = 17;

	// ?????????
	long long ll1RngS[D_DIGIT_MAX];
	long long ll1RngE[D_DIGIT_MAX];
	ll1RngS[0] = 1;
	ll1RngE[0] = 1;
	ll1RngS[1] = -2;
	ll1RngE[1] = -1;
	long long llTwo = 4;
	for (i = 2; i < D_DIGIT_MAX; i++) {
		if (llTwo > 0) {
			ll1RngS[i] = ll1RngE[i - 2] + 1;
			ll1RngE[i] = ll1RngE[i - 2] + llTwo;
		}
		else {
			ll1RngS[i] = ll1RngS[i - 2] + llTwo;
			ll1RngE[i] = ll1RngS[i - 2] - 1;
		}

		llTwo *= -2;									// ??
	}

	// ?????
	int liDNo = 0;
	llTwo = 1;
	if (llVal != 0) {
		for (i = 0; i < D_DIGIT_MAX; i++) {
			if (ll1RngS[i] <= llVal && llVal <= ll1RngE[i]) {
				liDNo = i;
				break;
			}
			else {
				llTwo *= -2;									// ??
			}
		}
	}

	// ??
	int liSNo = 0;
	for (i = liDNo; i >= 0; i--) {
		if (ll1RngS[i] <= llVal && llVal <= ll1RngE[i]) {
			lc1Out[liSNo] = '1';
			llVal -= llTwo;									// ?????
		}
		else {
			lc1Out[liSNo] = '0';
		}

		liSNo++;
		llTwo /= -2;									// ??
	}

	// ??
	lc1Out[liSNo] = '\n';
	lc1Out[liSNo + 1] = '\0';

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
./Main.c:42:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^