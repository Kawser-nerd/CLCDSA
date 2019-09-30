#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_HEAP_MAX		10000									// ??????
#define D_NO_CNT		10										// ?????
#define D_MAGIC_MAX		1000									// ????

// ????? - ????
typedef struct Magic {
	int miFNo;													// ?? - ???
	int miTNo;													// ?? - ???
	int miVal;													// ????
} Magic;

// ????
static Magic sz1Heap[D_HEAP_MAX];								// ???
static int siHCnt;												// ????
static int si2Magic[D_NO_CNT][D_NO_CNT];						// ????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ??? - ????????
// ????[>=0]:?????????? [-1]:????
int
fHeapChk(
	int piPNo					// <I> ?????? 0?
)
{
	// ???
	int liMNo = piPNo;

	// ??????
	int liCNo = piPNo * 2 + 1;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].miVal > sz1Heap[liCNo].miVal) {
			liMNo = liCNo;
		}
	}

	// ??????
	liCNo = piPNo * 2 + 2;
	if (liCNo < siHCnt) {
		if (sz1Heap[liMNo].miVal > sz1Heap[liCNo].miVal) {
			liMNo = liCNo;
		}
	}

	// ??????????????
	if (piPNo == liMNo) {
		return -1;
	}

	// ????
	Magic lzWork;
	memcpy(&lzWork, &sz1Heap[liMNo], sizeof(Magic));
	memcpy(&sz1Heap[liMNo], &sz1Heap[piPNo], sizeof(Magic));
	memcpy(&sz1Heap[piPNo], &lzWork, sizeof(Magic));

	return liMNo;
}

// ??? - ?????
int
fHeapEnqueue(
	int piFNo					// <I> ?? - ???
	, int piTNo					// <I> ?? - ???
	, int piVal					// <I> ????
)
{
	int liRet;

	// ?????
	sz1Heap[siHCnt].miFNo = piFNo;		// ?? - ???
	sz1Heap[siHCnt].miTNo = piTNo;		// ?? - ???
	sz1Heap[siHCnt].miVal = piVal;		// ????
	siHCnt++;

	// ????????
	int liNo = siHCnt - 1;
	while (1) {

		// ??????
		liNo = (liNo - 1) / 2;

		// ????????
		liRet = fHeapChk(liNo);
		if (liRet < 0) {
			break;
		}
	}

	return 0;
}

// ??? - ?????
int
fHeapDequeue(
	Magic *pzpRet				// <O> ?????
)
{
	// ????
	if (siHCnt < 1) {
		return -1;
	}

	// ??
	memcpy(pzpRet, &sz1Heap[0], sizeof(Magic));
	siHCnt--;

	// ????
	if (siHCnt < 1) {
		return 0;
	}

	// ??????
	memcpy(&sz1Heap[0], &sz1Heap[siHCnt], sizeof(Magic));

	// ????????
	int liNo = 0;
	while (liNo >= 0) {
		liNo = fHeapChk(liNo);
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, j, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??????
	siHCnt = 0;													// ????

	// ???????????
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// ??????
	int liH, liW;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liH, &liW);

	// ??????????????
	for (i = 0; i < D_NO_CNT; i++) {
		for (j = 0; j < D_NO_CNT; j++) {
#ifdef D_TEST
			fscanf(szpFpT, "%d", &si2Magic[i][j]);
#else
			fscanf(stdin, "%d", &si2Magic[i][j]);
#endif

			// ???????
			if (i != j) {
				fHeapEnqueue(i, j, si2Magic[i][j]);
			}
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ???? - ??
	while (1) {

		// ?????
		Magic lzMagic;
		liRet = fHeapDequeue(&lzMagic);
		if (liRet != 0) {
			break;
		}

		// ??????
		if (si2Magic[lzMagic.miFNo][lzMagic.miTNo] < lzMagic.miVal) {
			continue;
		}
		si2Magic[lzMagic.miFNo][lzMagic.miTNo] = lzMagic.miVal;				// ??

		// ??????????????
		for (i = 0; i < D_NO_CNT; i++) {
			if (lzMagic.miFNo == i) {
				continue;
			}
			if (lzMagic.miTNo == i) {
				continue;
			}

			// ??????
			int liVal = lzMagic.miVal + si2Magic[lzMagic.miTNo][i];
			if (liVal >= D_MAGIC_MAX) {
				continue;
			}

			// ???????
			fHeapEnqueue(lzMagic.miFNo, i, liVal);
		}
	}

	// ?????????????
	int liSum = 0;
	for (i = 0; i < liH; i++) {
		for (j = 0; j < liW; j++) {
			int liNo;
#ifdef D_TEST
			fscanf(szpFpT, "%d", &liNo);
#else
			fscanf(stdin, "%d", &liNo);
#endif

			// ?????
			if (liNo < 0 || liNo == 1) {
				continue;
			}
			liSum += si2Magic[liNo][1];
		}
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	}

	// ?????
	sprintf(lc1Out, "%d\n", liSum);

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
./Main.c:162:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), stdin);
  ^
./Main.c:172:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &si2Magic[i][j]);
    ^
./Main.c:183:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^
./Main.c:231:4: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
    fscanf(stdin, "%d", &liNo);
    ^
./Main.c:243:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), stdin);
   ^