#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_DAY_KIND		6										// ??????

// ????
static FILE *szpFpI;											// ??
static int si1MaxMin[D_DAY_KIND];								// ?? - ???? - ??
static int si1MaxMax[D_DAY_KIND];								// ?? - ???? - ??
static int si1MinMin[D_DAY_KIND];								// ?? - ???? - ??
static int si1MinMax[D_DAY_KIND];								// ?? - ???? - ??
static int si1DCnt[D_DAY_KIND];									// ??

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
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1DCnt, 0, sizeof(si1DCnt));						// ??

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

	// ?? - ???
	for (i = 0; i < D_DAY_KIND; i++) {
		si1MaxMin[i] = INT_MIN;
		si1MaxMax[i] = INT_MAX;
		si1MinMin[i] = INT_MIN;
		si1MinMax[i] = INT_MAX;
	}

	// ?? - ???
	si1MaxMin[0] = 350;

	// ?? - ???
	si1MaxMin[1] = 300;
	si1MaxMax[1] = 350;

	// ?? - ??
	si1MaxMin[2] = 250;
	si1MaxMax[2] = 300;

	// ?? - ???
	si1MinMin[3] = 250;

	// ?? - ??
	si1MinMax[4] = 0;
	si1MaxMin[4] = 0;

	// ?? - ???
	si1MaxMax[5] = 0;

	// ???? - ??
	int liCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liCnt);

	// ??? - ??
	for (i = 0; i < liCnt; i++) {
		int liMax, liMin;
		double ldMax, ldMin;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lf%lf", &ldMax, &ldMin);
		liMax = (int)(ldMax * 10.0);
		liMin = (int)(ldMin * 10.0);

		// ?? - ??
		for (j = 0; j < D_DAY_KIND; j++) {
			if (si1MaxMin[j] <= liMax && liMax < si1MaxMax[j]) {
				if (si1MinMin[j] <= liMin && liMin < si1MinMax[j]) {
					si1DCnt[j]++;
				}
			}
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d", si1DCnt[0]);
	for (i = 1; i < D_DAY_KIND; i++) {
		sprintf(lc1Buf, " %d", si1DCnt[i]);
		strcat(lc1Out, lc1Buf);
	}
	strcat(lc1Out, "\n");

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
./Main.c:79:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:86:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^