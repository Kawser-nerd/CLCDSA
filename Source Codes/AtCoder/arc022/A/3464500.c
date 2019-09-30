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

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ??
	int liSw = 0;
	for (i = 0; lc1Buf[i] != '\0'; i++) {
		switch (liSw) {
		case 0:
			if (lc1Buf[i] == 'I' || lc1Buf[i] == 'i') {
				liSw++;
			}
			break;

		case 1:
			if (lc1Buf[i] == 'C' || lc1Buf[i] == 'c') {
				liSw++;
			}
			break;

		case 2:
			if (lc1Buf[i] == 'T' || lc1Buf[i] == 't') {
				liSw++;
			}
			break;
		}
	}

	// ?? - ???
	if (liSw == 3) {
		sprintf(lc1Out, "YES\n");
	}
	else {
		sprintf(lc1Out, "NO\n");
	}

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