#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ARRAY_MAX		100000									// ?????

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
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ?????
	int liACnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liACnt);

	// ????
	int li1Array[D_ARRAY_MAX + 5];
	for (i = 0; i < liACnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &li1Array[i]);
#else
		fscanf(stdin, "%d", &li1Array[i]);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ????
	li1Array[liACnt] = -1;

	// ??
	long long llSum = 0;
	int liLen = 1;
	for (i = 0; i < liACnt; i++) {
		if (li1Array[i] < li1Array[i + 1]) {	// ????
			liLen++;
		}
		else {									// ????????
			llSum += (long long)liLen * (long long)(liLen + 1) / (long long)2;
			liLen = 1;
		}
	}

	// ?????
	sprintf(lc1Out, "%lld\n", llSum);

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
./Main.c:39:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:49:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &li1Array[i]);
   ^
./Main.c:55:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^