#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_WAY_CNT		2										// ??
#define D_WAY_AB		0										// ?? - A->B
#define D_WAY_BA		1										// ?? - B->A
#define D_TIME_MAX		100000									// ?????

// ????
static int si2Time[D_WAY_CNT][D_TIME_MAX];						// ??
static int si1TCnt[D_WAY_CNT];									// ???
static int si1Move[D_WAY_CNT];									// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fGetCnt(
)
{
	// ???
	int liWNo = D_WAY_AB;
	int liTime = 0;
	int liMCnt = 0;
	int li1TNo[D_WAY_CNT];
	memset(li1TNo, 0, sizeof(li1TNo));

	// ????
	while (1) {

		// ????
		while (1) {
			if (li1TNo[liWNo] >= si1TCnt[liWNo]) {
				return liMCnt / 2;
			}

			// ????????
			if (liTime <= si2Time[liWNo][li1TNo[liWNo]]) {
				break;
			}

			// ??
			li1TNo[liWNo]++;
		}

		// ??
		liMCnt++;
		liTime = si2Time[liWNo][li1TNo[liWNo]] + si1Move[liWNo];

		// ????
		if (liWNo == D_WAY_AB) {
			liWNo = D_WAY_BA;
		}
		else {
			liWNo = D_WAY_AB;
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

	// ??? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &si1TCnt[D_WAY_AB], &si1TCnt[D_WAY_BA]);

	// ???? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &si1Move[D_WAY_AB], &si1Move[D_WAY_BA]);

	// ?? - A->B - ??
	for (i = 0; i < si1TCnt[D_WAY_AB]; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &si2Time[D_WAY_AB][i]);
#else
		fscanf(stdin, "%d", &si2Time[D_WAY_AB][i]);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ?? - B->A - ??
	for (i = 0; i < si1TCnt[D_WAY_BA]; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &si2Time[D_WAY_BA][i]);
#else
		fscanf(stdin, "%d", &si2Time[D_WAY_BA][i]);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ?????
	int liCnt = fGetCnt();

	// ?????
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:93:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:101:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:110:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &si2Time[D_WAY_AB][i]);
   ^
./Main.c:116:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:124:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &si2Time[D_WAY_BA][i]);
   ^
./Main.c:130:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf),...