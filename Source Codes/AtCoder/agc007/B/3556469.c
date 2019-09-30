#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		200000									// ?????

// ????
static FILE *szpFpI;											// ??
static int si1A[D_ARRAY_MAX + 5];								// ??A
static int si1B[D_ARRAY_MAX + 5];								// ??B
static int siACnt;												// ???

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024];

	// ??? - ???
	memset(si1A, 0, sizeof(si1A));								// ??A
	memset(si1B, 0, sizeof(si1B));								// ??B

	// ?? - ???
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpI = fopen(lc1Buf, "r");
#else
	szpFpI = stdin;
#endif

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siACnt);

	// ?? - ??? - ???
	for (i = 1; i <= siACnt; i++) {
		si1A[i] = 1;
		si1B[i] = 1;
	}

	// ?? - ??
	for (i = 0; i < siACnt; i++) {
		int liVal;
		fscanf(szpFpI, "%d", &liVal);

		// ?? - ??? - ??
		si1A[liVal] += i;
		si1B[liVal] += i;

	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?? - ??? - ??
	for (i = 1; i <= siACnt; i++) {
		si1A[i] += si1A[i - 1];
	}
	for (i = siACnt; i >= 1; i--) {
		si1B[i] += si1B[i + 1];
	}

	// ??A - ??
	printf("%d", si1A[1]);
	for (i = 2; i <= siACnt; i++) {
		printf(" %d", si1A[i]);
	}
	printf("\n");

	// ??B - ??
	printf("%d", si1B[1]);
	for (i = 2; i <= siACnt; i++) {
		printf(" %d", si1B[i]);
	}
	printf("\n");

	// ???????????
#ifdef D_TEST
	fclose(szpFpI);
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
./Main.c:39:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:51:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liVal);
   ^
./Main.c:58:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^