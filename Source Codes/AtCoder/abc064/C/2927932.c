#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SEP_VAL		400										// ???
#define D_RANK_MAX		8										// ?????

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

	// ????
	int liHCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liHCnt);

	// ????????
	int li1Rank[D_RANK_MAX + 5];
	memset(li1Rank, 0, sizeof(li1Rank));
	for (i = 0; i < liHCnt; i++) {
		int liVal;
#ifdef D_TEST
		fscanf(szpFpT, "%d", &liVal);
#else
		fscanf(stdin, "%d", &liVal);
#endif
		if (liVal < 1) {
			continue;
		}

		int liRNo = liVal / D_SEP_VAL;
		if (liRNo > D_RANK_MAX) {
			liRNo = D_RANK_MAX;
		}
		li1Rank[liRNo]++;
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ???
	int liMin = 0;
	for (i = 0; i < D_RANK_MAX; i++) {
		if (li1Rank[i] > 0) {
			liMin++;
		}
	}

	// ???
	int liMax = liMin + li1Rank[D_RANK_MAX];

	// ???????
	if (liMin == 0) {
		if (li1Rank[D_RANK_MAX] > 0) {
			liMin = 1;
			liMax = li1Rank[D_RANK_MAX];
		}
	}

	// ?????
	sprintf(lc1Out, "%d %d\n", liMin, liMax);

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
./Main.c:41:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:53:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &liVal);
   ^
./Main.c:68:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^