#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_SIZE_MAX		50										// ?????
#define D_MASS_FREE		'.'										// ?? - ??
#define D_MASS_WALL		'#'										// ?? - ?
#define D_STACK_MAX		(D_SIZE_MAX * D_SIZE_MAX)				// ???????

// ????? - ??????
typedef struct Stack {
	int miX, miY;												// ????
	int miLen;													// ????
} Stack;

// ????
static FILE *szpFpI;											// ??
static char sc2Mass[D_SIZE_MAX][D_SIZE_MAX + 5];				// ??
static int si2Len[D_SIZE_MAX][D_SIZE_MAX + 5];					// ????
static int siRCnt;												// ??
static int siCCnt;												// ??
static Stack sz1Stack[D_STACK_MAX];								// ????
static int siSCnt;												// ?????
static int siSSNo;												// ?????? - ???
static int siSGNo;												// ?????? - ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? - ???
int
fStackSet(
	int piX						// <I> ??X
	, int piY					// <I> ??Y
	, int piLen					// <I> ????
)
{
	// ???
	sz1Stack[siSSNo].miX = piX;
	sz1Stack[siSSNo].miY = piY;
	sz1Stack[siSSNo].miLen = piLen;

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
	Stack *pzpRet				// <O> ???
)
{
	// ?????
	if (siSCnt < 1) {
		return -1;
	}
	siSCnt--;

	// ??
	memcpy(pzpRet, &sz1Stack[siSGNo], sizeof(Stack));

	// ?????? - ??
	if (siSGNo < D_STACK_MAX - 1) {
		siSGNo++;
	}
	else {
		siSGNo = 0;
	}

	return 0;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	siSCnt = 0;													// ?????
	siSSNo = 0;													// ?????? - ???
	siSGNo = 0;													// ?????? - ??

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

	// ????? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siRCnt, &siCCnt);

	// ???? - ??
	int liSx, liSy;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liSx, &liSy);
	liSx--;
	liSy--;

	// ???? - ??
	int liEx, liEy;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liEx, &liEy);
	liEx--;
	liEy--;

	// ?? - ??
	for (i = 0; i < siRCnt; i++) {
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpI);
	}

	// ???? - ???
	fStackSet(liSx, liSy, 0);

	// ???????
	while (1) {

		// ??????
		Stack lzStack;
		liRet = fStackGet(&lzStack);
		if (liRet != 0) {
			break;
		}

		// ??????
		if (sc2Mass[lzStack.miX][lzStack.miY] != D_MASS_FREE) {		// ????
			continue;
		}
		sc2Mass[lzStack.miX][lzStack.miY] = D_MASS_WALL;			// ??

		// ????
		si2Len[lzStack.miX][lzStack.miY] = lzStack.miLen;

		// ???????????
		fStackSet(lzStack.miX + 1, lzStack.miY, lzStack.miLen + 1);
		fStackSet(lzStack.miX - 1, lzStack.miY, lzStack.miLen + 1);
		fStackSet(lzStack.miX, lzStack.miY + 1, lzStack.miLen + 1);
		fStackSet(lzStack.miX, lzStack.miY - 1, lzStack.miLen + 1);
	}

	// ?? - ???
	sprintf(lc1Out, "%d\n", si2Len[liEx][liEy]);

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
./Main.c:116:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:121:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:128:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:135:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpI);
   ^