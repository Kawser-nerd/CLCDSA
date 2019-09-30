#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		40										// ?????

// ????
static FILE *szpFpI;											// ??
static int si1LCnt[D_SIZE_MAX + 5];								// ??(?)[???]
static int si1RCnt[D_SIZE_MAX + 5];								// ??(?)[???]

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

	// ??? - ???
	memset(si1LCnt, 0, sizeof(si1LCnt));						// ??(?)[???]
	memset(si1RCnt, 0, sizeof(si1RCnt));						// ??(?)[???]

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
	int liLCnt, liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liLCnt, &liRCnt);

	// ??(?)[???] - ??
	for (i = 0; i < liLCnt; i++) {
		int liSize;
		fscanf(szpFpI, "%d", &liSize);
		si1LCnt[liSize]++;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??(?)[???] - ??
	for (i = 0; i < liRCnt; i++) {
		int liSize;
		fscanf(szpFpI, "%d", &liSize);
		si1RCnt[liSize]++;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?????
	int liPCnt = 0;
	for (i = 0; i <= D_SIZE_MAX; i++) {
		if (si1LCnt[i] < si1RCnt[i]) {
			liPCnt += si1LCnt[i];
		}
		else {
			liPCnt += si1RCnt[i];
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", liPCnt);

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
./Main.c:48:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:54:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liSize);
   ^
./Main.c:57:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:62:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liSize);
   ^
./Main.c:65:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^