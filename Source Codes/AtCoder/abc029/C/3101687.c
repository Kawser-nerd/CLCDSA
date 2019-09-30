#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static int siLen;												// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ??
int
fDsp(
	int piCnt					// <I> ??? 0?
	, char *pcpStr				// <I> ???
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ???????
	if (piCnt == siLen) {

		// ??
		pcpStr[piCnt] = '\0';
		sprintf(lc1Out, "%s\n", pcpStr);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif

		return 0;
	}

	// ????
	for (i = 0; i < 3; i++) {
		pcpStr[piCnt] = 'a' + i;
		fDsp(piCnt + 1, pcpStr);			// ???
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siLen);

	// ??
	fDsp(0, lc1Buf);

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
./Main.c:75:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^