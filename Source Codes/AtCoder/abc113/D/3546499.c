#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_AMD_MAX		8										// ??????

// ????
static FILE *szpFpI;											// ??
static int siH;													// ??
static int siACnt;												// ????
static int siGoal;												// ????
static int si2Ptn[D_AMD_MAX + 5][D_AMD_MAX + 5];				// ???????[???][???]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???????[???] - ???
int
fSetPtn(
	int piANo					// <I> ??? 1?
	, int *pipXBar				// <I> ?????
)
{
	int i;

	// ??????
	if (piANo == siACnt) {

		// ???????[???] - ???
		for (i = 1; i <= siACnt; i++) {
			if (pipXBar[i - 1] == D_ON) {			// ??
				si2Ptn[i][i - 1]++;
			}
			else if (pipXBar[i] == D_ON) {			// ??
				si2Ptn[i][i + 1]++;
			}
			else {									// ????
				si2Ptn[i][i]++;
			}
		}

		return 0;
	}

	// ????
	if (pipXBar[piANo - 1] == D_OFF) {			// ????
		pipXBar[piANo] = D_ON;						// ???
		fSetPtn(piANo + 1, pipXBar);				// ???
		pipXBar[piANo] = D_OFF;						// ???
	}

	// ????
	fSetPtn(piANo + 1, pipXBar);				// ???

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, k;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si2Ptn, 0, sizeof(si2Ptn));							// ???????[???]

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

	// ???????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siH, &siACnt, &siGoal);

	// ???????[???] - ???
	int li1XBar[D_AMD_MAX + 5];
	memset(li1XBar, D_OFF, sizeof(li1XBar));
	fSetPtn(1, li1XBar);

	// ????? - ???
	long long ll1PtnNow[D_AMD_MAX + 5];
	memset(ll1PtnNow, 0, sizeof(ll1PtnNow));
	ll1PtnNow[1] = 1;

	// ??(??)????
	for (i = 0; i < siH; i++) {
		long long ll1PtnNew[D_AMD_MAX + 5];
		memset(ll1PtnNew, 0, sizeof(ll1PtnNew));

		// ????? - ??
		for (j = 1; j <= siACnt; j++) {
			for (k = 1; k <= siACnt; k++) {
				ll1PtnNew[k] += ll1PtnNow[j] * (long long)si2Ptn[j][k];
				ll1PtnNew[k] %= D_MOD;
			}
		}

		// ????? - ??
		for (j = 1; j <= siACnt; j++) {
			ll1PtnNow[j] = ll1PtnNew[j];
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", ll1PtnNow[siGoal]);

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
./Main.c:92:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^