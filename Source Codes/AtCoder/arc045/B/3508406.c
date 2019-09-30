#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_CLASS_MAX		300000									// ?????
#define D_STDT_MAX		100000									// ?????

// ????? - ????
typedef struct Rng {
	int miSNo, miENo;											// ?? 1?
	int miMulti;												// ??????
} Rng;

// ????
static FILE *szpFpI;											// ??
static int siCCnt;												// ???
static Rng sz1Rng[D_STDT_MAX];									// ??
static int siRCnt;												// ???
static int si1CCnt[D_CLASS_MAX + 5];							// ???[??]
static int si1Only[D_CLASS_MAX];								// ???????
static int siOCnt;												// ????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ??????? - ?????
// ????[>=0]???? [-1]??
int
fBSrhPN(
	int piVal					// <I> ?
	, int *pipPNo				// <O> [>=0]?????????? [-1]??
	, int *pipNNo				// <O> [>=0]?????????? [siOCnt]??
)
{
	// ????
	int liSNo = 0;
	int liENo = siOCnt - 1;

	// ??
	while (1) {

		// ????
		int liMNo = (liSNo + liENo) / 2;

		// ??????
		if (piVal == si1Only[liMNo]) {
			*pipPNo = liMNo - 1;
			*pipNNo = liMNo + 1;
			return liMNo;
		}

		// ?????
		if (piVal < si1Only[liMNo]) {				// ???
			if (liSNo < liMNo) {						// ????
				liENo = liMNo - 1;
			}
			else {										// ????
				*pipPNo = liMNo - 1;
				*pipNNo = liMNo;
				return -1;
			}
		}
		else {										// ???
			if (liENo > liMNo) {						// ????
				liSNo = liMNo + 1;
			}
			else {										// ????
				*pipPNo = liMNo;
				*pipNNo = liMNo + 1;
				return -1;
			}
		}
	}

	return -1;
}

// ???????????
int
fIsMulti(
	int piRNo					// <I> ?? 0?
)
{
	// ????????
	if (siOCnt < 1) {
		return 0;
	}

	// ???? - ??
	int liPNo1, liNNo1;
	int liNo = fBSrhPN(sz1Rng[piRNo].miSNo, &liPNo1, &liNNo1);
	if (liNo >= 0) {												// ??
		return -1;
	}

	// ???? - ??
	int liPNo2, liNNo2;
	liNo = fBSrhPN(sz1Rng[piRNo].miENo, &liPNo2, &liNNo2);
	if (liNo >= 0) {												// ??
		return -1;
	}

	// ??????
	if (liPNo1 != liPNo2) {											// ???
		return -1;
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1CCnt, 0, sizeof(si1CCnt));						// ???[??]
	siOCnt = 0;													// ????????

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

	// ??????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siCCnt, &siRCnt);

	// ?? - ??
	for (i = 0; i < siRCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Rng[i].miSNo, &sz1Rng[i].miENo);

		// ???[??] - ???
		si1CCnt[sz1Rng[i].miSNo]++;
		si1CCnt[sz1Rng[i].miENo + 1]--;
	}

	// ???[??] - ???
	for (i = 1; i <= siCCnt; i++) {
		si1CCnt[i] += si1CCnt[i - 1];

		// ??????? - ??
		if (si1CCnt[i] == 1) {
			si1Only[siOCnt] = i;
			siOCnt++;
		}
	}

	// ?????? - ???
	int liMCnt = 0;
	for (i = 0; i < siRCnt; i++) {
		liRet = fIsMulti(i);
		if (liRet == 0) {
			sz1Rng[i].miMulti = D_ON;
			liMCnt++;
		}
		else {
			sz1Rng[i].miMulti = D_OFF;
		}
	}

	// ??????? - ??
	sprintf(lc1Out, "%d\n", liMCnt);
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ?????? - ??
	for (i = 0; i < siRCnt; i++) {
		if (sz1Rng[i].miMulti == D_ON) {
			sprintf(lc1Out, "%d\n", i + 1);
#ifdef D_TEST
			fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
			if (strcmp(lc1Buf, lc1Out)) {
				siRes = -1;
			}
#else
			printf("%s", lc1Out);
#endif
			}
	}

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
./Main.c:145:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:150:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^