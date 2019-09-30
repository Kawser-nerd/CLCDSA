#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		30										// ?????
#define D_AREA_MAX		(D_SIZE_MAX * D_SIZE_MAX)				// ?????
#define D_MOD			(long long)1000000007					// ??(10?9?+7)

// ????
static FILE *szpFpI;											// ??
static int si1Prm[D_AREA_MAX];									// ?????
static int siPCnt;												// ??????
static int siD;													// ????
static int siL;													// ????
static long long sl3Ptn[D_AREA_MAX][D_SIZE_MAX][D_SIZE_MAX];	// ?????????[?????][?][??]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????????
int
fMakePrm(
	int piMax					// <I> ???
)
{
	int i, j;

	// ???
	siPCnt = 0;

	// ??????
	for (i = 2; i <= piMax; i++) {

		// ??????????????
		for (j = 0; j < siPCnt; j++) {
			if (i % si1Prm[j] == 0) {		// ???
				break;
			}
		}
		if (j < siPCnt) {
			continue;
		}

		// ??
		si1Prm[siPCnt] = i;
		siPCnt++;
	}

	return 0;
}

// ?? - ?? - ????
int
fGetFactOne(
	int piVal					// <I> ?
	, int *pipCnt				// <I> ?????
)
{
	int i;

	// ?????
	for (i = 0; i < siPCnt; i++) {
		while (piVal % si1Prm[i] == 0) {
			piVal /= si1Prm[i];
			pipCnt[si1Prm[i]]++;

			if (piVal < 2) {
				return 0;
			}
		}
	}

	return 0;
}

// ?? - ??
int
fGetFact(
	int piVal					// <I> ?
	, int *pipCnt				// <I> ?????
)
{
	int i;

	// ???
	memset(pipCnt, 0, sizeof(int) * D_AREA_MAX);

	// ???
	for (i = 2; i <= piVal; i++) {
		fGetFactOne(i, pipCnt);
	}

	return 0;
}

// ????????? - ??
long long
fGetPtn(
	int piS						// <I> ?????
	, int piX					// <I> ?
	, int piY					// <I> ??
)
{
	int i, j;

	// ???
	if (sl3Ptn[piS][piX][piY] >= 0) {
		return sl3Ptn[piS][piX][piY];
	}

	// ?????
	int li1XY[D_AREA_MAX], li1D[D_AREA_MAX];
	int li1L[D_AREA_MAX], li1S[D_AREA_MAX];
	fGetFact(siD + siL + piS, li1XY);							// ???
	fGetFact(siD, li1D);										// ????
	fGetFact(siL, li1L);										// ????
	fGetFact(piS, li1S);										// ?????

	// ??
	long long llPtn = 1;
	for (i = 0; i < siPCnt; i++) {
		int liPrm = si1Prm[i];

		// ??
		li1XY[liPrm] -= li1D[liPrm] + li1L[liPrm] + li1S[liPrm];

		// ??
		for (j = 0; j < li1XY[liPrm]; j++) {
			llPtn *= (long long)liPrm;
			llPtn %= D_MOD;
		}
	}

	// ?????? - ??
	for (int liDx = 0; ; liDx++) {
		if (piS < piY * liDx) {
			break;
		}

		for (int liDy = 0; ; liDy++) {
			if (liDx == 0 && liDy == 0) {
				continue;
			}

			// ??????
			int liS = piS - piY * liDx - piX * liDy + liDx * liDy;
			if (liS < 0) {
				break;
			}

			// ?????? - ??
			llPtn -= fGetPtn(liS, piX - liDx, piY - liDy) * (long long)(liDx + 1) * (long long)(liDy + 1);
			while (llPtn < 0) {
				llPtn += D_MOD;
			}
		}
	}

	// ????????? - ???
	sl3Ptn[piS][piX][piY] = llPtn;

	return sl3Ptn[piS][piX][piY];
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(sl3Ptn, -1, sizeof(sl3Ptn));							// ?????????

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

	// ????????
	fMakePrm(D_AREA_MAX);

	// ????? - ??
	int liR, liC;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liR, &liC);

	// ?? - ??
	int liX, liY;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liY, &liX);

	// ???????????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siD, &siL);
	int liS = liX * liY - siD - siL;

	// ????????? - ??
	long long llPtn = fGetPtn(liS, liX, liY);

	// ??? - ??
	llPtn *= (long long)(liR - liY + 1);
	llPtn %= D_MOD;

	// ??? - ??
	llPtn *= (long long)(liC - liX + 1);
	llPtn %= D_MOD;

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llPtn);

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
./Main.c:199:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:204:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:208:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^