#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		2000									// ?????
#define M_PI			3.1415926535897932384626433832795		// ???
#define D_DBL_UP		10000000000.0							// double???

// ????? - ????
typedef struct Vtx {
	int miX, miY;												// ??
} Vtx;

// ????
static Vtx sz1Vtx[D_VTX_MAX];									// ??
static int siVCnt;												// ???
static double sd1Agl[D_VTX_MAX * 2];							// ???????
static int siACnt;												// ????????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????? - double??
int
fSortFnc(
	const void *pzpVal1			// <I> ??
	, const void *pzpVal2		// <I> ??
)
{
	double *ldpVal1 = (double *)pzpVal1;
	double *ldpVal2 = (double *)pzpVal2;

	// double??
	if (*ldpVal1 > *ldpVal2) {
		return(1);
	}
	else if (*ldpVal1 < *ldpVal2) {
		return(-1);
	}

	return 0;
}

// ????
// ????[>=0]???? [-1]??
int
fBSrhP(
	double pdVal				// <I> ?
	, int *pipPNo				// <O> [>=0]?????????? [-1]??
)
{
	// ????
	int liSNo = 0;
	int liENo = siACnt - 1;

	// ??
	while (1) {

		// ????
		int liMNo = (liSNo + liENo) / 2;

		// ??????
		long long llVal1 = (long long)(pdVal * D_DBL_UP + 0.5);
		long long llVal2 = (long long)(sd1Agl[liMNo] * D_DBL_UP + 0.5);
		if (llVal1 == llVal2) {
			*pipPNo = liMNo - 1;
			return liMNo;
		}

		// ?????
		if (pdVal < sd1Agl[liMNo]) {				// ???
			if (liSNo < liMNo) {						// ????
				liENo = liMNo - 1;
			}
			else {										// ????
				*pipPNo = liMNo - 1;
				return -1;
			}
		}
		else {										// ???
			if (liENo > liMNo) {						// ????
				liSNo = liMNo + 1;
			}
			else {										// ????
				*pipPNo = liMNo;
				return -1;
			}
		}
	}

	return -1;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];
	
	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siVCnt);

	// ?? - ??
	for (i = 0; i < siVCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &sz1Vtx[i].miX, &sz1Vtx[i].miY);
	}

	// ???
	long long llRCnt = 0;
	long long llWCnt = 0;

	// ???????
	for (i = 0; i < siVCnt; i++) {

		// ???????
		siACnt = 0;
		for (j = 0; j < siVCnt; j++) {
			if (i == j) {
				continue;
			}

			// ??
			sd1Agl[siACnt] = atan2((double)(sz1Vtx[j].miY - sz1Vtx[i].miY), (double)(sz1Vtx[j].miX - sz1Vtx[i].miX));
			siACnt++;

			// 360??????
			sd1Agl[siACnt] = sd1Agl[siACnt - 1] + M_PI * 2.0;
			siACnt++;
		}

		// ??????? - ???
		qsort(sd1Agl, siACnt, sizeof(double), fSortFnc);

		// ???????
		for (j = 0; j < siVCnt; j++) {
			if (i == j) {
				continue;
			}

			// ?????
			double ldAgl = atan2((double)(sz1Vtx[j].miY - sz1Vtx[i].miY), (double)(sz1Vtx[j].miX - sz1Vtx[i].miX));
			int liPNo;
			int liNo = fBSrhP(ldAgl, &liPNo);

			// ??????+90????
			ldAgl += M_PI / 2.0;
			int liNo2 = fBSrhP(ldAgl, &liPNo);
			if (liNo2 >= 0) {								// ??
				llRCnt++;										// ???
				liNo = liNo2;
			}
			else {											// ??
				liNo = liPNo;
			}

			// +90??+270????
			ldAgl += M_PI;
			liNo2 = fBSrhP(ldAgl, &liPNo);
			llWCnt += (long long)(liPNo - liNo);			// ???
			if (liNo2 >= 0) {								// ??
				llRCnt++;										// ???
				liNo = liNo2;
			}
			else {											// ??
				liNo = liPNo;
			}
		}
	}

	// ???
	llRCnt /= (long long)2;
	llWCnt /= (long long)2;

	// ??????
	long long llSCnt = (long long)siVCnt * (long long)(siVCnt - 1) * (long long)(siVCnt - 2) / (long long)6 - llRCnt - llWCnt;

	// ?????
	sprintf(lc1Out, "%lld %lld %lld\n", llSCnt, llRCnt, llWCnt);

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
} ./Main.c:10:0: warning: "M_PI" redefined
 #define M_PI   3.1415926535897932384626433832795  // ???
 ^
In file included from ./Main.c:2:0:
/usr/include/math.h:372:0: note: this is the location of the previous definition
 # define M_PI  3.14159265358979323846 /* pi */
 ^
./Main.c: In function ‘fMain’:
./Main.c:123:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:132:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^