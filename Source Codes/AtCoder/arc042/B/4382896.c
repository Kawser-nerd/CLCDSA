#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_VTX_MAX		15										// ?????

// ????? - ????
typedef struct Vtx {
	double mdX, mdY;											// ??
} Vtx;

// ????
static FILE *szpFpI;											// ??
static Vtx sz1Vtx[D_VTX_MAX];									// ??
static int siVCnt;												// ???

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?? - ??
int
fGetPoint(
	double pdSx					// <I> ????X
	, double pdSy				// <I> ????Y
	, double pdEx				// <I> ????X
	, double pdEy				// <I> ????Y
	, double pdPx				// <I> ?X
	, double pdPy				// <I> ?Y
	, double *pdpX				// <O> ??X
	, double *pdpY				// <O> ??Y
)
{
	double ldBx = pdEx - pdSx;
	double ldBy = pdEy - pdSy;
	double ldLen2 = ldBx * ldBx + ldBy * ldBy;

	double ldSx = pdSx - pdPx;
	double ldSy = pdSy - pdPy;
	double ldBase = -(ldSx * ldBx + ldSy * ldBy) / ldLen2;

	*pdpX = pdSx + ldBx * ldBase;
	*pdpY = pdSy + ldBy * ldBase;

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

	// ???? - ??
	double ldSx, ldSy;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lf%lf", &ldSx, &ldSy);

	// ??? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siVCnt);

	// ?? - ??
	for (i = 0; i < siVCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lf%lf", &sz1Vtx[i].mdX, &sz1Vtx[i].mdY);
	}
	sz1Vtx[siVCnt].mdX = sz1Vtx[0].mdX;
	sz1Vtx[siVCnt].mdY = sz1Vtx[0].mdY;

	// ???? - ??
	double ldMin = DBL_MAX;
	for (i = 0; i < siVCnt; i++) {

		// ?? - ??
		double ldVx, ldVy;
		fGetPoint(sz1Vtx[i].mdX, sz1Vtx[i].mdY, sz1Vtx[i + 1].mdX, sz1Vtx[i + 1].mdY, ldSx, ldSy, &ldVx, &ldVy);

		// ??
		double ldX = ldVx - ldSx;
		double ldY = ldVy - ldSy;
		double ldLen = sqrt(ldX * ldX + ldY * ldY);

		// ???? - ??
		if (ldMin > ldLen) {
			ldMin = ldLen;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%.7lf\n", ldMin);

	// ?? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// ??????
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
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
./Main.c:77:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:81:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:86:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^