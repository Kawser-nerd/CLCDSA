#include <float.h>
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

// ??? - ??
long long
fGetNext(
	long long plNow				// <I> ???
	, long long plPos			// <I> ??
	, int *pipCnt				// <IO> ???
)
{
	// ????????
	long long llValT = plNow / plPos;
	long long llValU = llValT / 10;
	llValT %= 10;
	long long llValD = plNow % plPos;

	// ????????
	switch (llValT) {
	case 0:
		pipCnt[0]++;
		return (llValU * 10 + 3) * plPos + llValD;

	case 3:
		pipCnt[0]--;
		pipCnt[1]++;
		return (llValU * 10 + 5) * plPos + llValD;

	case 5:
		pipCnt[1]--;
		pipCnt[2]++;
		return (llValU * 10 + 7) * plPos + llValD;

	case 7:
		pipCnt[2]--;
		pipCnt[0]++;
		return fGetNext((llValU * 10 + 3) * plPos + llValD, plPos * 10, pipCnt);
	}

	return -1;
}

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

	// ?? - ??
	long long llLimit;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld", &llLimit);

	// ?? - ??
	int liCnt = 0;
	long long llNow = 0;
	int li1Cnt[3];
	memset(li1Cnt, 0, sizeof(li1Cnt));
	while (1) {

		// ??? - ??
		llNow = fGetNext(llNow, 1, li1Cnt);
		if (llNow > llLimit) {
			break;
		}

		// ??????
		for (i = 0; i < 3; i++) {
			if (li1Cnt[i] < 1) {
				break;
			}
		}
		if (i == 3) {
			liCnt++;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:79:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^