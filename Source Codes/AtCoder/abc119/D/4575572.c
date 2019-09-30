#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_POINT_MAX		100000									// ?????
#define D_LEN_MAX		100000000000							// ????

// ????
static FILE *szpFpI;											// ??
static int siJCnt;												// ???
static int siTCnt;												// ??
static long long sl1JPos[D_POINT_MAX];							// ?????
static long long sl1TPos[D_POINT_MAX];							// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ?????
// ????[>=0]???? [-1]??
int
fBSrhPN(
	long long *plpArray			// <I> ??????
	, int piCnt					// <I> ???????
	, long long plVal			// <I> ?
	, int *pipPNo				// <O> [>=0]?????????? [-1]??
	, int *pipNNo				// <O> [>=0]?????????? [siACnt]??
)
{
	// ????
	int liSNo = 0;
	int liENo = piCnt - 1;

	// ??
	while (1) {

		// ????
		int liMNo = (liSNo + liENo) / 2;

		// ??????
		if (plVal == plpArray[liMNo]) {
			*pipPNo = liMNo;
			*pipNNo = liMNo;
			return 0;
		}

		// ?????
		if (plVal < plpArray[liMNo]) {				// ???
			if (liSNo < liMNo) {						// ????
				liENo = liMNo - 1;
			}
			else {										// ????
				*pipPNo = liMNo - 1;
				*pipNNo = liMNo;
				return 0;
			}
		}
		else {										// ???
			if (liENo > liMNo) {						// ????
				liSNo = liMNo + 1;
			}
			else {										// ????
				*pipPNo = liMNo;
				*pipNNo = liMNo + 1;
				return 0;
			}
		}
	}

	return 0;
}

// ?????
int
fMain(
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ????????? - ??
	int liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siJCnt, &siTCnt, &liQCnt);

	// ?? - ??
	for (i = 0; i < siJCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &sl1JPos[i]);
	}

	// ? - ??
	for (i = 0; i < siTCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &sl1TPos[i]);
	}

	// ? - ??
	for (i = 0; i < liQCnt; i++) {
		long long llPos;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &llPos);

		// ??????? - ?? - ??
		int liLNo, liRNo;
		long long llJLLen, llJRLen;
		fBSrhPN(sl1JPos, siJCnt, llPos, &liLNo, &liRNo);
		if (liLNo < 0) {
			llJLLen = D_LEN_MAX;
		}
		else {
			llJLLen = llPos - sl1JPos[liLNo];
		}
		if (liRNo >= siJCnt) {
			llJRLen = D_LEN_MAX;
		}
		else {
			llJRLen = sl1JPos[liRNo] - llPos;
		}

		// ??????? - ?? - ?
		long long llTLLen, llTRLen;
		fBSrhPN(sl1TPos, siTCnt, llPos, &liLNo, &liRNo);
		if (liLNo < 0) {
			llTLLen = D_LEN_MAX;
		}
		else {
			llTLLen = llPos - sl1TPos[liLNo];
		}
		if (liRNo >= siTCnt) {
			llTRLen = D_LEN_MAX;
		}
		else {
			llTRLen = sl1TPos[liRNo] - llPos;
		}

		// ???
		long long llMin = llJRLen;
		if (llJLLen < llTLLen) {
			llMin = llTLLen;
		}
		else {
			llMin = llJLLen;
		}

		// ???
		long long llLen;
		if (llJRLen < llTRLen) {
			llLen = llTRLen;
		}
		else {
			llLen = llJRLen;
		}
		if (llMin > llLen) {
			llMin = llLen;
		}

		// ???? + ???
		llLen = llJLLen * 2 + llTRLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// ???? + ???
		llLen = llJRLen * 2 + llTLLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// ??? + ????
		llLen = llTLLen * 2 + llJRLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// ??? + ????
		llLen = llTRLen * 2 + llJLLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// ?? - ???
		sprintf(lc1Out, "%lld\n", llMin);

		// ?? - ??
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
	fMain();

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
./Main.c:91:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:96:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:102:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^
./Main.c:109:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^