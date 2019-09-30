#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_WORD_MAX		100										// ?????
#define D_WORD_LEN		20										// ?????

// ????? - ????
typedef struct Word {
	char mc1Word[D_WORD_LEN + 5];								// ??
	char mc1Rev[D_WORD_LEN + 5];								// ??(??)
} Word;

// ????
static FILE *szpFpI;											// ??
static Word sz1Word[D_WORD_MAX];								// ??
static int siWCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ??(??)??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Word *lzpVal1 = (Word *)pzpVal1;
	Word *lzpVal2 = (Word *)pzpVal2;

	// ??(??)??
	return strcmp(lzpVal1->mc1Rev, lzpVal2->mc1Rev);
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
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

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siWCnt);

	// ?? - ??
	for (i = 0; i < siWCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%s", sz1Word[i].mc1Word);

		// ??(??)
		int liLen = strlen(sz1Word[i].mc1Word);
		for (j = 0; j < liLen; j++) {
			sz1Word[i].mc1Rev[j] = sz1Word[i].mc1Word[liLen - 1 - j];
		}
		sz1Word[i].mc1Rev[liLen] = '\0';
	}

	// ?? - ???
	qsort(sz1Word, siWCnt, sizeof(Word), fSortFnc);

	// ?? - ??
	for (i = 0; i < siWCnt; i++) {
		sprintf(lc1Out, "%s\n", sz1Word[i].mc1Word);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

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
./Main.c:64:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:69:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^