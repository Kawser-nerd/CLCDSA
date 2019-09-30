#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_LEN_MAX		100005									// ??????

// ????
static FILE *szpFpI;											// ??
static char sc1Str[D_LEN_MAX];									// ???
static int siLen;												// ????
static int si1ACnt[D_LEN_MAX];									// ??AC?

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// ??
int
fOut(
	char *pcpLine				// <I> ??
)
{
	char lc1Buf[1024];

#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// ?????
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// ???????? - ??
	int liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siLen, &liQCnt);

	// ??? - ??
	fgets(sc1Str, sizeof(sc1Str), szpFpI);

	// ??AC? - ???
	for (i = 1; i < siLen; i++) {
		if (sc1Str[i - 1] == 'A') {
			if (sc1Str[i] == 'C') {
				si1ACnt[i] = 1;
			}
		}
		si1ACnt[i] += si1ACnt[i - 1];
	}

	// ?? - ??
	for (i = 0; i < liQCnt; i++) {
		int liLNo, liRNo;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liLNo, &liRNo);

		// AC? - ???
		sprintf(lc1Buf, "%d\n", si1ACnt[liRNo - 1] - si1ACnt[liLNo - 1]);

		// AC? - ??
		fOut(lc1Buf);
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

	// ??? - ???
	memset(si1ACnt, 0, sizeof(si1ACnt));						// ??AC?

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
	fOne();
#endif

	return 0;
} ./Main.c: In function ‘fMain’:
./Main.c:55:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:59:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(sc1Str, sizeof(sc1Str), szpFpI);
  ^
./Main.c:74:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^