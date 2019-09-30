#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???
	int liCnt = 0;
	int liZero = D_OFF;

	// ?????
	while (1) {

		// ????
		char lcNum;
#ifdef D_TEST
		fscanf(szpFpT, "%c", &lcNum);
#else
		fscanf(stdin, "%c", &lcNum);
#endif
		if (lcNum == '0') {
			liZero = D_ON;
		}

		// ????
		char lcSign = '\0';
#ifdef D_TEST
		fscanf(szpFpT, "%c", &lcSign);
#else
		fscanf(stdin, "%c", &lcSign);
#endif
		if (lcSign == '*') {
			continue;
		}

		// ??????
		if (liZero == D_ON) {
			liZero = D_OFF;
		}
		else {
			liCnt++;
		}

		// ????
		if (lcSign != '+') {
			break;
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", liCnt);

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
./Main.c:47:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%c", &lcNum);
   ^
./Main.c:58:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%c", &lcSign);
   ^