#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

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

	// ??????
	char lc2From[3][1024];
	strcpy(lc2From[0], "Left");
	strcpy(lc2From[1], "Right");
	strcpy(lc2From[2], "AtCoder");

	// ??????
	char lc2To[3][1024];
	strcpy(lc2To[0], " <");
	strcpy(lc2To[1], " >");
	strcpy(lc2To[2], " A");

	// ??? - ??
	char lc1Str[1024];
	fgets(lc1Str, sizeof(lc1Str), szpFpI);

	// ??? - ??
	lc1Buf[0] = '\0';
	char *lcpNow = lc1Str;
	while (1) {

		// ??????
		int liNo = -1;
		char *lcpFrom = lc1Str + sizeof(lc1Str);
		for (i = 0; i < 3; i++) {
			char *lcpWork = strstr(lcpNow, lc2From[i]);
			if (lcpWork != NULL) {
				if (lcpFrom > lcpWork) {
					lcpFrom = lcpWork;
					liNo = i;
				}
			}
		}
		if (liNo < 0) {
			break;
		}

		// ????? - ??
		strcat(lc1Buf, lc2To[liNo]);

		// ????
		lcpNow = lcpFrom + 1;
	}

	// ?? - ???
	sprintf(lc1Out, "%s\n", &lc1Buf[1]);

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

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
./Main.c:51:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Str, sizeof(lc1Str), szpFpI);
  ^