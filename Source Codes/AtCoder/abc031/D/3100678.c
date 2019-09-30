#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_STR_MAX		27										// ?????
#define D_CMB_MAX		50										// ????????
#define D_NUM_MAX		9										// ?????
#define D_LEN_MIN		1										// ???
#define D_LEN_MAX		3										// ???

// ????? - ?????
typedef struct Str {
	char mc1Str[D_STR_MAX + 5];									// ???
	int miLen;													// ????
} Str;

// ????? - ???????
typedef struct Cmb {
	Str mzNum;													// ??
	Str mzStr;													// ???
} Cmb;

// ????
static Cmb sz1Cmb[D_CMB_MAX];									// ?????
static int siCCnt;												// ??????
static Str sz1Num[D_NUM_MAX];									// ???
static int siNCnt;												// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ????????
int
fSetNStr(
)
{
	int i, j, k;

	// ??????
	for (i = 0; i < siCCnt; i++) {
		Cmb *lzpCmb = &sz1Cmb[i];

		// ?????
		int liSum = 0;
		for (j = 0; j < lzpCmb->mzNum.miLen; j++) {
			int liNo = lzpCmb->mzNum.mc1Str[j] - '1';
			liSum += sz1Num[liNo].miLen;
		}
		if (liSum != lzpCmb->mzStr.miLen) {
			return -1;
		}
	}

	// ????????
	for (i = 0; i < siNCnt; i++) {
		sz1Num[i].mc1Str[0] = '\0';
	}

	// ????????
	for (i = 0; i < siCCnt; i++) {
		Cmb *lzpCmb = &sz1Cmb[i];

		int liFNo = 0;
		for (j = 0; j < lzpCmb->mzNum.miLen; j++) {
			int liNo = lzpCmb->mzNum.mc1Str[j] - '1';

			// ??????
			char lc1Str[D_STR_MAX];
			memset(lc1Str, 0, sizeof(lc1Str));
			for (k = 0; k < sz1Num[liNo].miLen; k++) {
				lc1Str[k] = lzpCmb->mzStr.mc1Str[liFNo];
				liFNo++;
			}

			// ??
			if (sz1Num[liNo].mc1Str[0] != '\0') {
				if (strcmp(sz1Num[liNo].mc1Str, lc1Str)) {
					return -1;
				}
			}

			// ???
			strcpy(sz1Num[liNo].mc1Str, lc1Str);
		}
	}

	return 0;
}

// ??????
int
fSetNum(
	int piNNo					// <I> ?? 0?
)
{
	int i, liRet;

	// ??????
	if (piNNo >= siNCnt) {
		liRet = fSetNStr();
		if (liRet == 0) {
			return 0;
		}
		return -1;
	}

	// ???
	for (i = D_LEN_MIN; i <= D_LEN_MAX; i++) {
		sz1Num[piNNo].miLen = i;
		liRet = fSetNum(piNNo + 1);					// ???
		if (liRet == 0) {
			return 0;
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

	// ?????????? - ??
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siNCnt, &siCCnt);

	// ????? - ??
	for (i = 0; i < siCCnt; i++) {
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%s%s", &sz1Cmb[i].mzNum.mc1Str, &sz1Cmb[i].mzStr.mc1Str);

		// ????
		sz1Cmb[i].mzNum.miLen = strlen(sz1Cmb[i].mzNum.mc1Str);
		sz1Cmb[i].mzStr.miLen = strlen(sz1Cmb[i].mzStr.mc1Str);
	}

	// ??????
	fSetNum(0);

	// ??
	for (i = 0; i < siNCnt; i++) {
		sprintf(lc1Out, "%s\n", sz1Num[i].mc1Str);
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
./Main.c:159:18: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[32]’ [-Wformat=]
   sscanf(lc1Buf, "%s%s", &sz1Cmb[i].mzNum.mc1Str, &sz1Cmb[i].mzStr.mc1Str);
                  ^
./Main.c:159:18: warning: format ‘%s’ expects argument of type ‘char *’, but argument 4 has type ‘char (*)[32]’ [-Wformat=]
./Main.c:148:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:157:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^