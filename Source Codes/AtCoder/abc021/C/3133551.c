#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_TOWN_MAX		100										// ????
#define D_ROAD_MAX		200										// ?????
#define D_STACK_MAX		D_TOWN_MAX								// ???????
#define D_MOD			1000000007								// ??

// ????? - ???
typedef struct Town {
	int miRSNo;													// ?? - ?? 0?
	int miRENo;													// ?? - ?? 0?
	int miRoute;												// ??
	int miSw;													// ??????
} Town;

// ????? - ????
typedef struct Road {
	int miTFNo;													// ? - ? 0?
	int miTTNo;													// ? - ? 0?
} Road;

// ????
static Town sz1Town[D_TOWN_MAX + 5];							// ?
static int siTCnt;												// ??
static int siTFNo;												// ? - ??
static int siTTNo;												// ? - ??
static Road sz1Road[D_ROAD_MAX * 2];							// ??
static int siRCnt;												// ???
static int si1Stack[D_STACK_MAX];								// ????
static int siSCnt;												// ?????
static int siSSNo;												// ?????? - ???
static int siSGNo;												// ?????? - ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?(?)??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Road *lzpVal1 = (Road *)pzpVal1;
	Road *lzpVal2 = (Road *)pzpVal2;

	// ?(?)??
	if (lzpVal1->miTFNo > lzpVal2->miTFNo) {
		return(1);
	}
	else if (lzpVal1->miTFNo < lzpVal2->miTFNo) {
		return(-1);
	}

	return 0;
}

// ???? - ???
int
fStackSet(
	int piVal					// <I> ?
)
{
	// ???
	si1Stack[siSSNo] = piVal;

	// ?????
	siSCnt++;

	// ?????? - ???
	if (siSSNo < D_STACK_MAX - 1) {
		siSSNo++;
	}
	else {
		siSSNo = 0;
	}

	return 0;
}

// ???? - ??
int
fStackGet(
)
{
	// ?????
	if (siSCnt < 1) {
		return -1;
	}
	siSCnt--;

	// ???
	int liRet = si1Stack[siSGNo];

	// ?????? - ??
	if (siSGNo < D_STACK_MAX - 1) {
		siSGNo++;
	}
	else {
		siSGNo = 0;
	}

	return liRet;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	memset(sz1Town, 0, sizeof(sz1Town));						// ?
	siRCnt = 0;													// ???
	siSCnt = 0;													// ?????
	siSSNo = 0;													// ?????? - ???
	siSGNo = 0;													// ?????? - ??

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
	sscanf(lc1Buf, "%d", &siTCnt);

	// ? - ???
	for (i = 1; i <= siTCnt; i++) {
		sz1Town[i].miRSNo = -1;									// ?? - ??
		sz1Town[i].miRENo = -2;									// ?? - ??
	}

	// ?(?????) - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siTFNo, &siTTNo);

	// ??? - ??
	int liRCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &liRCnt);

	// ?? - ??
	for (i = 0; i < liRCnt; i++) {
		int liTNo1, liTNo2;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liTNo1, &liTNo2);

		// ??
		sz1Road[siRCnt].miTFNo = liTNo1;
		sz1Road[siRCnt].miTTNo = liTNo2;
		siRCnt++;
		sz1Road[siRCnt].miTFNo = liTNo2;
		sz1Road[siRCnt].miTTNo = liTNo1;
		siRCnt++;
	}

	// ?? - ???
	qsort(sz1Road, siRCnt, sizeof(Road), fSortFnc);

	// ????????
	for (i = 0; i < siRCnt; i++) {
		int liTNo = sz1Road[i].miTFNo;

		// ?? - ??
		if (sz1Town[liTNo].miRSNo < 0) {
			sz1Town[liTNo].miRSNo = i;
		}

		// ?? - ??
		sz1Town[liTNo].miRENo = i;
	}

	// ????
	sz1Town[siTFNo].miRoute = 1;						// ??
	fStackSet(siTFNo);									// ???? - ???

	// ?????
	while (1) {

		// ?????
		int liSCnt = siSCnt;

		// ??????????
		for (i = 0; i < liSCnt; i++) {
			int liTNo = fStackGet();						// ???? - ??
			sz1Town[liTNo].miSw = D_ON;						// ??????
			fStackSet(liTNo);								// ???? - ???
		}

		// ?????
		for (i = 0; i < liSCnt; i++) {

			// ???? - ??
			int liTFNo = fStackGet();
			Town *lzpTown = &sz1Town[liTFNo];
			lzpTown->miSw = D_ON;								// ??????

			// ???????
			for (j = lzpTown->miRSNo; j <= lzpTown->miRENo; j++) {
				int liTTNo = sz1Road[j].miTTNo;

				// ??????
				if (sz1Town[liTTNo].miSw != D_OFF) {
					continue;
				}

				// ?????
				if (sz1Town[liTTNo].miRoute == 0) {					// ??
					sz1Town[liTTNo].miRoute = lzpTown->miRoute;
					fStackSet(liTTNo);									// ???? - ???
				}
				else {												// ?????
					sz1Town[liTTNo].miRoute += lzpTown->miRoute;
					sz1Town[liTTNo].miRoute %= D_MOD;
				}
			}
		}

		// ??????
		if (sz1Town[siTTNo].miSw == D_ON) {
			break;
		}
	}

	// ?????
	sprintf(lc1Out, "%d\n", sz1Town[siTTNo].miRoute);

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
./Main.c:146:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:160:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:169:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:179:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^