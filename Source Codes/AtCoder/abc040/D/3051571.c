#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_CITY_MAX		100000									// ?????
#define D_ROAD_MAX		200000									// ?????
#define D_HUMAN_MAX		100000									// ?????

// ????? - ????
typedef struct City {
	int miPNo;													// ??? 1?
	int miFCnt;													// ???(??????) 1?
} City;

// ????? - ????
typedef struct Road {
	int miCNo1;													// ???? 1?
	int miCNo2;													// ???? 1?
	int miYear;													// ???
} Road;

// ????? - ????
typedef struct Human {
	int miHNo;													// ???? 0?
	int miCNo;													// ???? 1?
	int miYear;													// ?????
	int miCCnt;													// ???????
} Human;

// ????
static City sz1City[D_CITY_MAX + 5];							// ??
static int siCCnt;												// ???
static Road sz1Road[D_ROAD_MAX + 5];							// ??
static int siRCnt;												// ???
static Human sz1Human[D_HUMAN_MAX];								// ??
static int siHCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - ?? - ???
int
fRoadSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Road *lzpVal1 = (Road *)pzpVal1;
	Road *lzpVal2 = (Road *)pzpVal2;

	// ???
	if (lzpVal1->miYear > lzpVal2->miYear) {
		return(-1);
	}
	else if (lzpVal1->miYear < lzpVal2->miYear) {
		return(1);
	}

	return 0;
}

// ????? - ?? - ???
int
fHumanSortFncY(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Human *lzpVal1 = (Human *)pzpVal1;
	Human *lzpVal2 = (Human *)pzpVal2;

	// ???
	if (lzpVal1->miYear > lzpVal2->miYear) {
		return(-1);
	}
	else if (lzpVal1->miYear < lzpVal2->miYear) {
		return(1);
	}

	return 0;
}

// ????? - ?? - ??????
int
fHumanSortFncN(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	Human *lzpVal1 = (Human *)pzpVal1;
	Human *lzpVal2 = (Human *)pzpVal2;

	// ??????
	if (lzpVal1->miHNo > lzpVal2->miHNo) {
		return(1);
	}
	else if (lzpVal1->miHNo < lzpVal2->miHNo) {
		return(-1);
	}

	return 0;
}

// ?? - ?????
int
fCityGetPNo(
	int piCNo					// <I> ???? 1?
)
{
	// ?????????
	if (sz1City[piCNo].miPNo == piCNo) {
		return piCNo;
	}

	// ?????
	sz1City[piCNo].miPNo = fCityGetPNo(sz1City[piCNo].miPNo);

	return sz1City[piCNo].miPNo;
}

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

	// ??????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siCCnt, &siRCnt);

	// ?? - ???
	for (i = 1; i <= siCCnt; i++) {
		sz1City[i].miPNo = i;									// ???
		sz1City[i].miFCnt = 1;									// ???(??)
	}

	// ?? - ??
	for (i = 0; i < siRCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d%d", &sz1Road[i].miCNo1, &sz1Road[i].miCNo2, &sz1Road[i].miYear);
	}

	// ????
	sz1Road[siRCnt].miYear = -1;
	siRCnt++;

	// ?? - ???
	qsort(sz1Road, siRCnt, sizeof(Road), fRoadSortFnc);

	// ??? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siHCnt);

	// ?? - ??
	for (i = 0; i < siHCnt; i++) {
		sz1Human[i].miHNo = i;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Human[i].miCNo, &sz1Human[i].miYear);
	}

	// ?? - ???
	qsort(sz1Human, siHCnt, sizeof(Human), fHumanSortFncY);

	// ?? - ??????????
	int liRNo = 0;
	for (i = 0; i < siHCnt; i++) {

		// ????
		while (sz1Road[liRNo].miYear > sz1Human[i].miYear) {

			// ???
			int liPNo1 = fCityGetPNo(sz1Road[liRNo].miCNo1);
			int liPNo2 = fCityGetPNo(sz1Road[liRNo].miCNo2);

			// ?????????
			if (liPNo1 != liPNo2) {
				sz1City[liPNo1].miFCnt += sz1City[liPNo2].miFCnt;		// ?????
				sz1City[liPNo2].miPNo = liPNo1;							// ?????
			}

			// ??
			liRNo++;
		}

		// ???
		int liPNo = fCityGetPNo(sz1Human[i].miCNo);

		// ???????
		sz1Human[i].miCCnt = sz1City[liPNo].miFCnt;
	}

	// ?? - ???
	qsort(sz1Human, siHCnt, sizeof(Human), fHumanSortFncN);

	// ????
	for (i = 0; i < siHCnt; i++) {
		sprintf(lc1Out, "%d\n", sz1Human[i].miCCnt);
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
		}

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
./Main.c:150:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:165:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:181:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:191:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^