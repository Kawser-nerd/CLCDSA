#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_LV_MAX		10										// ?????

// ????? - ?????
typedef struct Lv {
	int miCnt;													// ???
	int miBonus;												// ????
} Lv;

// ????
static FILE *szpFpI;											// ??
static Lv sz1Lv[D_LV_MAX + 5];									// ???
static int siLCnt;												// ????
static int siGoal;												// ???
static int siMin;												// ?????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ????? - ??
int
fUpMin(
	int piScr					// <I> ?????
	, int *pipCnt				// <I> ?????
)
{
	int i;

	// ?????
	int li1Cnt[D_LV_MAX + 5];
	memcpy(li1Cnt, pipCnt, sizeof(li1Cnt));

	// ???????
	int liLNo = siLCnt;
	while (piScr < siGoal) {
		if (li1Cnt[liLNo] < sz1Lv[liLNo].miCnt) {		// ?????
			piScr += liLNo;
			li1Cnt[liLNo]++;

			if (li1Cnt[liLNo] == sz1Lv[liLNo].miCnt) {		// ????
				piScr += sz1Lv[liLNo].miBonus;
			}
		}
		else {											// ?????
			liLNo--;
		}
	}

	// ?????
	int liSum = 0;
	for (i = 1; i <= siLCnt; i++) {
		liSum += li1Cnt[i];
	}

	// ????? - ??
	if (siMin > liSum) {
		siMin = liSum;
	}

	return 0;
}

// ???????? - ??
int
fMakeBonusPtn(
	int piLNo					// <I> ??? 1?
	, int piScr					// <I> ?????
	, int *pipCnt				// <I> ?????
)
{
	// ??????
	if (piLNo > siLCnt) {
		fUpMin(piScr, pipCnt);								// ????? - ??
		return 0;
	}

	// ????????
	fMakeBonusPtn(piLNo + 1, piScr, pipCnt);			// ???

	// ????????
	piScr += sz1Lv[piLNo].miBonus + piLNo * sz1Lv[piLNo].miCnt;
	pipCnt[piLNo] += sz1Lv[piLNo].miCnt;
	fMakeBonusPtn(piLNo + 1, piScr, pipCnt);			// ???
	pipCnt[piLNo] -= sz1Lv[piLNo].miCnt;

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

	// ??? - ???
	siMin = INT_MAX;											// ?????

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

	// ???????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siLCnt, &siGoal);
	siGoal /= 100;

	// ??? - ??
	for (i = 1; i <= siLCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Lv[i].miCnt, &sz1Lv[i].miBonus);
		sz1Lv[i].miBonus /= 100;
	}
	
	// ???????? - ??
	int li1Cnt[D_LV_MAX + 5];
	memset(li1Cnt, 0, sizeof(li1Cnt));
	fMakeBonusPtn(1, 0, li1Cnt);

	// ?? - ???
	sprintf(lc1Out, "%d\n", siMin);

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
./Main.c:123:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:129:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^