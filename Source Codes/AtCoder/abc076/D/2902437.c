#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SCT_MAX		100										// ?????

// ????? - ????
typedef struct Sct {
	int miSec;													// ?
	int miSpd;													// ????
} Sct;

// ????
static Sct sz1Sct[D_SCT_MAX + 5];								// ????
static int siSCnt;												// ?????
static int siSpd;												// ????
static double sdLen;											// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????
int
fAddLen(
	double pdSpd				// <I> ???
	, int piAdd					// <I> ???
	, double pdSec				// <I> ?
)
{
	// ??
	sdLen += pdSpd * pdSec + 0.5 * (double)piAdd * pdSec * pdSec;

	return 0;
}

// ????????
int
fAddOne(
	int piSNo					// <I> ???? 0?
)
{
	int i;

	// ???????????
	int liSpdEnd = sz1Sct[piSNo].miSpd;						// ???

	// ??????????? - ??(?????????)
	int liSecPast = 0;										// ???
	for (i = piSNo + 1; i <= siSCnt; i++) {
		int liVal = sz1Sct[i].miSpd + liSecPast;				// ?????????
		if (liSpdEnd > liVal) {
			liSpdEnd = liVal;
		}
		liSecPast += sz1Sct[i].miSec;							// ???
	}

	// ????
	int liSecLast = sz1Sct[piSNo].miSec;

	// ??????????????????
	int liSecUse = 0;										// ??????????????????
	int liSpdUD = siSpd;									// ????????????
	if (siSpd > liSpdEnd) {									// ?????
		liSecUse = siSpd - liSpdEnd;							// ??????????????????
		fAddLen((double)siSpd, -1, (double)liSecUse);			// ????
	}
	else if (siSpd < liSpdEnd) {							// ?????
		liSecUse = liSpdEnd - siSpd;							// ??????????????????
		if (liSecUse > liSecLast) {								// ????
			liSecUse = liSecLast;									// ???
			liSpdEnd = siSpd + liSecUse;							// ???????
		}
		else {													// ???
			liSpdUD = siSpd + liSecUse;								// ????????????
		}
		fAddLen((double)siSpd, 1, (double)liSecUse);			// ????
	}

	// ???? - ??
	siSpd = liSpdEnd;

	// ????
	liSecLast -= liSecUse;
	if (liSecLast < 1) {									// ??
		return 0;
	}

	// ???????
	int liSecUD = (sz1Sct[piSNo].miSpd - liSpdUD) * 2;		// ???????
	if (liSecUD > 0) {										// ??

		// ?????????
		if (liSecUD > liSecLast) {
			liSecUD = liSecLast;
		}

		// ????
		double ldSec = (double)liSecUD / 2;					// ??
		fAddLen((double)liSpdUD, 1, ldSec);					// ????

		// ????
		double ldSpd = (double)liSpdUD + ldSec;				// ??
		fAddLen(ldSpd, -1, ldSec);							// ????
	}

	// ????
	liSecLast -= liSecUD;
	if (liSecLast < 1) {									// ??
		return 0;
	}

	// ??????
	fAddLen(sz1Sct[piSNo].miSpd, 0, (double)liSecLast);		// ????

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siSpd = 0;													// ????
	sdLen = 0.0;												// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ???????
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siSCnt);

	// ???
	for (i = 0; i < siSCnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &sz1Sct[i].miSec);
#else
		fscanf(stdin, "%d", &sz1Sct[i].miSec);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ??????
	for (i = 0; i < siSCnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &sz1Sct[i].miSpd);
#else
		fscanf(stdin, "%d", &sz1Sct[i].miSpd);
#endif
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// ?????
	sz1Sct[siSCnt].miSec = 0;
	sz1Sct[siSCnt].miSpd = 0;

	// ????????
	for (i = 0; i < siSCnt; i++) {
		fAddOne(i);
	}

	// ?????
	sprintf(lc1Out, "%.15lf\n", sdLen);

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
./Main.c:151:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:160:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &sz1Sct[i].miSec);
   ^
./Main.c:166:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:174:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%d", &sz1Sct[i].miSpd);
   ^
./Main.c:180:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^