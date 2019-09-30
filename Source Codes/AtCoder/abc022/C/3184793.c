#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		300										// ?????
#define D_LEN_MAX		(100000 * D_VTX_MAX)					// ????

// ????? - ????
typedef struct Road {
	int miTNo;													// ? 0?
	int miLen;													// ??
} Road;

// ????
static FILE *szpFpI;											// ??
static int si2Len[D_VTX_MAX][D_VTX_MAX];						// ????
static int siTCnt;												// ??
static Road sz1Road[D_VTX_MAX];									// ????
static int siRCnt;												// ?????

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
	int i, j, k;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siRCnt = 0;													// ?????

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

	// ?????? - ??
	int liRCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siTCnt, &liRCnt);

	// ???? - ???
	for (i = 0; i < siTCnt - 1; i++) {
		for (j = 0; j < siTCnt - 1; j++) {
			if (i == j) {
				si2Len[i][j] = 0;
			}
			else {
				si2Len[i][j] = D_LEN_MAX;
			}
		}
	}

	// ?? - ??
	for (i = 0; i < liRCnt; i++) {
		int liTNo1, liTNo2, liLen;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d%d", &liTNo1, &liTNo2, &liLen);
		liTNo1 -= 2;
		liTNo2 -= 2;

		if (liTNo1 < 0) {						// ????
			sz1Road[siRCnt].miTNo = liTNo2;
			sz1Road[siRCnt].miLen = liLen;
			siRCnt++;
		}
		else if (liTNo2 < 0) {					// ????
			sz1Road[siRCnt].miTNo = liTNo1;
			sz1Road[siRCnt].miLen = liLen;
			siRCnt++;
		}
		else {									// ??????
			si2Len[liTNo1][liTNo2] = liLen;
			si2Len[liTNo2][liTNo1] = liLen;
		}
	}

	// ???? - ?? - ?????????
	for (i = 0; i < siTCnt - 1; i++) {
		for (j = 0; j < siTCnt - 1; j++) {
			for (k = 0; k < siTCnt - 1; k++) {
				int liLen = si2Len[j][i] + si2Len[i][k];
				if (si2Len[j][k] > liLen) {
					si2Len[j][k] = liLen;
				}
			}
		}
	}

	// ????? - ??
	int liMin = INT_MAX;
	for (i = 0; i < siRCnt - 1; i++) {
		for (j = i + 1; j < siRCnt; j++) {
			int liTNo1 = sz1Road[i].miTNo;
			int liTNo2 = sz1Road[j].miTNo;
			if (si2Len[liTNo1][liTNo2] == D_LEN_MAX) {
				continue;
			}

			// ??
			int liLen = sz1Road[i].miLen + sz1Road[j].miLen + si2Len[liTNo1][liTNo2];
			if (liMin > liLen) {
				liMin = liLen;
			}
		}
	}
	if (liMin == INT_MAX) {
		liMin = -1;
	}

	// ?????
	sprintf(lc1Out, "%d\n", liMin);

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
./Main.c:56:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:74:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^