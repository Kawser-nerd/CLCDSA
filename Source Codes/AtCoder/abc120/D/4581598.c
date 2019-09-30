#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ISLAND_MAX	100000									// ????
#define D_BRIDGE_MAX	100000									// ????

// ????? - ???
typedef struct Ild {
	int miDNo;													// ???? 0?
	int miCnt;													// ?????????
} Ild;

// ????? - ???
typedef struct Brd {
	int miINo1;													// ?? 0?
	int miINo2;													// ?? 0?
	long long mlInc;											// ???
} Brd;

// ????
static FILE *szpFpI;											// ??
static Ild sz1Ild[D_ISLAND_MAX];								// ?
static int siICnt;												// ??
static Brd sz1Brd[D_BRIDGE_MAX];								// ?
static int siBCnt;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ???? - ??
int
fGetDNo(
	int piINo				// <I> ? 0?
)
{
	// ??????
	if (piINo == sz1Ild[piINo].miDNo) {
		return piINo;
	}

	// ???
	sz1Ild[piINo].miDNo = fGetDNo(sz1Ild[piINo].miDNo);

	return sz1Ild[piINo].miDNo;
}

// ?????
int
fMain(
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siICnt, &siBCnt);

	// ? - ???
	for (i = 0; i < siICnt; i++) {
		sz1Ild[i].miDNo = i;
		sz1Ild[i].miCnt = 1;
	}

	// ? - ??
	for (i = 0; i < siBCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Brd[i].miINo1, &sz1Brd[i].miINo2);
		sz1Brd[i].miINo1--;
		sz1Brd[i].miINo2--;
	}

	// ??? - ???
	long long llInc = (long long)siICnt * (long long)(siICnt - 1) / 2;

	// ??? - ???
	for (i = siBCnt - 1; i >= 0; i--) {
		sz1Brd[i].mlInc = llInc;

		// ???? - ??
		int liDNo1 = fGetDNo(sz1Brd[i].miINo1);
		int liDNo2 = fGetDNo(sz1Brd[i].miINo2);
		if (liDNo1 == liDNo2) {						// ??
			continue;
		}

		// ??? - ??
		llInc -= (long long)sz1Ild[liDNo1].miCnt * (long long)sz1Ild[liDNo2].miCnt;

		// ???????
		sz1Ild[liDNo1].miCnt += sz1Ild[liDNo2].miCnt;
		sz1Ild[liDNo2].miDNo = liDNo1;
	}

	// ??? - ??
	for (i = 0; i < siBCnt; i++) {
		sprintf(lc1Out, "%lld\n", sz1Brd[i].mlInc);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

	return 0;
}

// ????
int
fOne(
)
{
	int liRet;
	char lc1Buf[1024];

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// ?????
	liRet = fMain();

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// ???????
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne(0);
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:66:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:77:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^