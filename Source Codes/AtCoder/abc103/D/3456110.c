#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_WAR_MAX		100000									// ?????
#define D_RNG_START		0										// ?? - ??
#define D_RNG_END		1										// ?? - ??

// ????? - ????
typedef struct War {
	int miWNo;													// ?? 0?
	int miINo;													// ? 1?
	int miRng;													// ??
} War;

// ????
static FILE *szpFpI;											// ??
static War sz1War[D_WAR_MAX * 2];								// ??
static int siWCnt;												// ???
static int si1StartA[D_WAR_MAX + 5];							// ??(??)
static int si1StartO[D_WAR_MAX];								// ??(??)
static int siSCnt;												// ??(??)?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ??? - ????
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	War *lzpVal1 = (War *)pzpVal1;
	War *lzpVal2 = (War *)pzpVal2;

	// ???
	if (lzpVal1->miINo > lzpVal2->miINo) {
		return(1);
	}
	else if (lzpVal1->miINo < lzpVal2->miINo) {
		return(-1);
	}

	// ????
	if (lzpVal1->miRng > lzpVal2->miRng) {
		return(-1);
	}
	else if (lzpVal1->miRng < lzpVal2->miRng) {
		return(1);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	siWCnt = 0;													// ???
	memset(si1StartA, D_OFF, sizeof(si1StartA));				// ??(??)
	siSCnt = 0;													// ??(??)?

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

	// ?????? - ??
	int liICnt, liWCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liICnt, &liWCnt);

	// ?? - ??
	for (i = 0; i < liWCnt; i++) {
		int liINo1, liINo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liINo1, &liINo2);

		// ?? - ???
		sz1War[siWCnt].miWNo = i;
		sz1War[siWCnt].miINo = liINo1;
		sz1War[siWCnt].miRng = D_RNG_START;
		siWCnt++;
		sz1War[siWCnt].miWNo = i;
		sz1War[siWCnt].miINo = liINo2;
		sz1War[siWCnt].miRng = D_RNG_END;
		siWCnt++;
	}

	// ?? - ???
	qsort(sz1War, siWCnt, sizeof(War), fSortFnc);

	// ?? - ??
	int liCnt = 0;
	for (i = 0; i < siWCnt; i++) {
		if (sz1War[i].miRng == D_RNG_START) {			// ??
			si1StartA[sz1War[i].miWNo] = D_ON;
			si1StartO[siSCnt] = sz1War[i].miWNo;
			siSCnt++;
		}
		else {											// ??

			// ???????
			if (si1StartA[sz1War[i].miWNo] != D_ON) {
				continue;
			}

			// ??
			liCnt++;
			for (j = 0; j < siSCnt; j++) {
				si1StartA[si1StartO[j]] = D_OFF;
			}
			siSCnt = 0;
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
./Main.c:98:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^