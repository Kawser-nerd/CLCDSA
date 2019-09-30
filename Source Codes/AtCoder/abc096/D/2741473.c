#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ???? - ????
#ifdef D_TEST
	static FILE *szpFpT;
#endif

// ????
int
fChk(
	int piVal					// <I> ?
)
{
	int i, liRet;

	// ???
	double ldLimit = sqrt((double)piVal);
	int liLimit = (int)ldLimit;

	// ??????????
	for (i = 2; i <= liLimit; i++) {
		liRet = piVal % i;
		if (liRet == 0) {
			return -1;
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
	int i, liRet;
	char lc1Buf[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
#endif

	// ?????
	int liCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liCnt);

	// ?? - 5n+1 AND ??
	int liOut = 0;
	for (i = 11; ; i+=5) {

		// ??????
		liRet = fChk(i);
		if (liRet != 0) {
			continue;
		}

		// ??
		if (liOut > 0) {
			printf(" ");
		}
		printf("%d", i);
		liOut++;

		// ??????
		if (liOut == liCnt) {
			printf("\n");
			break;
		}
	}

	// ???????????
#ifdef D_TEST
	fclose(szpFpT);
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
./Main.c:56:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^