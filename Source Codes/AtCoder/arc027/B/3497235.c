#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_CHAR_CNT		26										// ?????

// ????? - ????
typedef struct Char {
	int miNo;													// ???? 0?
	int miSNo;													// ????????? 0?
	int miNum;													// ??
	int miNotZero;												// 0?????
} Char;

// ????
static FILE *szpFpI;											// ??
static Char sz1Char[D_CHAR_CNT];								// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?? or ?? - ??
int
fGetNo(
	char pcChar					// <I> ??
	, int *pipNum				// <O> ??
	, int *pipCNo				// <O> ????
)
{
	if ('0' <= pcChar && pcChar <= '9') {
		*pipNum = pcChar - '0';
		*pipCNo = -1;
	}
	else {
		*pipNum = -1;

		// ????
		int liCNo = pcChar - 'A';
		while (sz1Char[liCNo].miSNo != liCNo) {
			liCNo = sz1Char[liCNo].miSNo;
		}
		*pipCNo = liCNo;
	}

	return 0;
}

// ?? - ????
int
fSwap(
	int *pipVal1				// <IO> ??
	, int *pipVal2				// <IO> ??
)
{
	int liWork = *pipVal1;
	*pipVal1 = *pipVal2;
	*pipVal2 = liWork;

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

	// ???? - ???
	for (i = 0; i < D_CHAR_CNT; i++) {
		sz1Char[i].miNo = i;
		sz1Char[i].miSNo = i;
		sz1Char[i].miNum = -1;
		sz1Char[i].miNotZero = D_OFF;
	}

	// ??? - ??
	int liCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liCnt);

	// ??? - ??
	char lc1Str1[1024], lc1Str2[1024];
	fgets(lc1Str1, sizeof(lc1Str1), szpFpI);
	fgets(lc1Str2, sizeof(lc1Str2), szpFpI);

	// ???? - ???
	int liNum1, liNum2, liCNo1, liCNo2;
	for (i = 0; i < liCnt; i++) {

		// ?? or ?? - ??
		fGetNo(lc1Str1[i], &liNum1, &liCNo1);
		fGetNo(lc1Str2[i], &liNum2, &liCNo2);

		// ??????
		if (liCNo1 < 0) {
			continue;
		}
		if (liCNo2 < 0) {
			continue;
		}

		// ??
		if (liCNo1 > liCNo2) {
			fSwap(&liCNo1, &liCNo2);
		}

		// ???
		sz1Char[liCNo2].miSNo = liCNo1;
	}

	// ????? - ???
	for (i = 0; i < liCnt; i++) {

		// ?? or ?? - ??
		fGetNo(lc1Str1[i], &liNum1, &liCNo1);
		fGetNo(lc1Str2[i], &liNum2, &liCNo2);

		// ????
		if (liNum1 >= 0 && liNum2 >= 0) {
			continue;
		}

		// ????
		if (liCNo1 >= 0 && liCNo2 >= 0) {
			continue;
		}

		// ?????
		if (liNum1 < 0) {
			liNum1 = liNum2;
		}
		else {
			liCNo1 = liCNo2;
		}

		// ???
		sz1Char[liCNo1].miNum = liNum1;
	}

	// ???? - ???
	fGetNo(lc1Str1[0], &liNum1, &liCNo1);
	fGetNo(lc1Str2[0], &liNum2, &liCNo2);
	if (liCNo1 >= 0) {
		sz1Char[liCNo1].miNotZero = D_ON;
	}
	if (liCNo2 >= 0) {
		sz1Char[liCNo2].miNotZero = D_ON;
	}

	// ????? - ??
	long long llPtn = 1;
	for (i = 0; i < liCnt; i++) {

		// ?? or ?? - ??
		fGetNo(lc1Str1[i], &liNum1, &liCNo1);

		// ??
		if (liNum1 >= 0) {
			continue;
		}
		if (sz1Char[liCNo1].miNum >= 0) {
			continue;
		}

		// ????? - ??
		if (sz1Char[liCNo1].miNotZero == D_ON) {
			llPtn *= 9;
		}
		else {
			llPtn *= 10;
		}

		// ??????
		sz1Char[liCNo1].miNum = 1;
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llPtn);

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
./Main.c:101:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:106:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Str1, sizeof(lc1Str1), szpFpI);
  ^
./Main.c:107:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Str2, sizeof(lc1Str2), szpFpI);
  ^