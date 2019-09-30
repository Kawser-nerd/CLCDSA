#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STEP_MAX		100000									// ???????
#define D_WORD_MAX		100000									// ?????

// ????? - ????
typedef struct Word {
	int miVal;													// ?
	int miSrh;													// ??? 1?
} Word;

// ????
static char sc1Step[D_STEP_MAX + 5];							// ?????
static Word sz1Word[D_WORD_MAX + 5];							// ??
static int siWCnt;												// ???
static int siSNo;												// ??????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
// ???????
int
fCutCrLf(
	char *pcpStr				// <I> ???
)
{
	int i;

	for (i = 0; pcpStr[i] != '\0'; i++) {
		if (pcpStr[i] == '\n') {
			pcpStr[i] = '\0';
			break;
		}
	}

	return i;
}

// ????????
int
fGetSrh(
)
{
	int i;

	// ??????????????????????
	int liSrh = 1;
	int liLPCnt, liLRCnt;
	while (1) {

		// ???????
		if (sz1Word[siSNo].miSrh > 0) {
			liLPCnt = sz1Word[siSNo].miSrh - 1;
			liLRCnt = liSrh - sz1Word[siSNo].miSrh;
			break;
		}

		// ???
		sz1Word[siSNo].miSrh = liSrh;
		liSrh++;

		// ??
		siSNo = sz1Word[siSNo].miVal;
	}

	// ???????????
	int liSLen = fCutCrLf(sc1Step);

	// ????????????
	int liStep;
	if (liSLen < 6) {
		sscanf(sc1Step, "%d", &liStep);
		if (liStep <= liLPCnt) {
			return liStep;
		}
	}

	// ??????????
	liStep = 0;
	for (i = 0; i < liSLen; i++) {
		liStep *= 10;					// ???
		liStep += sc1Step[i] - '0';		// ??
		liStep %= liLRCnt;				// ???????
	}

	// ???????????
	while (liStep <= liLPCnt) {
		liStep += liLRCnt;
	}

	return liStep;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(sz1Word, 0, sizeof(sz1Word));						// ??

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siWCnt, &siSNo);

	// ????? - ??
#ifdef D_TEST
	fgets(sc1Step, sizeof(sc1Step), szpFpT);
#else
	fgets(sc1Step, sizeof(sc1Step), stdin);
#endif

	// ?? - ??
	for (i = 1; i <= siWCnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &sz1Word[i].miVal);
#else
		fscanf(stdin, "%d", &sz1Word[i].miVal);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ????????
	int liSrh = fGetSrh();

	// ???????
	for (i = 1; i <= siWCnt; i++) {
		if (sz1Word[i].miSrh == liSrh) {
			break;
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", sz1Word[i].miVal);

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
./Main.c:129:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:137:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1Step, sizeof(sc1Step), stdin);
  ^
./Main.c:145:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &sz1Word[i].miVal);
   ^
./Main.c:151:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^