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
	int liY, liM, liD;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d/%d/%d", &liY, &liM, &liD);

	while (1) {

		// ??
		if (liY % (liM * liD) == 0) {
			break;
		}

		// ???
		int liLast;
		switch (liM) {
		case 4:
		case 6:
		case 9:
		case 11:
			liLast = 30;
			break;

		case 2:
			if (liY % 400 == 0) {
				liLast = 29;
			}
			else if (liY % 100 == 0) {
				liLast = 28;
			}
			else if (liY % 4 == 0) {
				liLast = 29;
			}
			else {
				liLast = 28;
			}
			break;

		default:
			liLast = 31;
			break;
		}

		// ???
		if (liD < liLast) {
			liD++;
		}
		else if (liM < 12) {
			liM++;
			liD = 1;
		}
		else {
			liY++;
			liM = 1;
			liD = 1;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%04d/%02d/%02d\n", liY, liM, liD);

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
./Main.c:38:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^