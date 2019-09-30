#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_TREE_MAX		100000									// ????????
#define D_TREE_WCNT		2										// ?????
#define D_TREE_LEFT		0										// ???? - ??
#define D_TREE_RIGHT	1										// ???? - ??

// ????? - ???
typedef struct Tree {
	int miVal;													// ?
	int mi1Height[D_TREE_WCNT];									// ????
	struct Tree *mzp1Child[D_TREE_WCNT];						// ?
} Tree;

// ????
static FILE *szpFpI;											// ??
static Tree sz1Tree[D_TREE_MAX];								// ??????
static int siTCnt;												// ???????
static Tree *szpTop;											// ???????

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? - ??
Tree *
fTreeMake(
	int piVal					// <I> ?
)
{
	// ???????
	Tree *lzpTree = &(sz1Tree[siTCnt]);
	siTCnt++;

	// ??????
	memset(lzpTree, 0, sizeof(Tree));		// ???
	lzpTree->miVal = piVal;					// ?

	return lzpTree;
}

// ???? - ????
int
fTreeGetHeight(
	Tree *pzpTree				// <I> ??????
)
{
	// ?????
	if (pzpTree == NULL) {
		return 0;
	}

	if (pzpTree->mi1Height[D_TREE_LEFT] >= pzpTree->mi1Height[D_TREE_RIGHT]) {
		return pzpTree->mi1Height[D_TREE_LEFT] + 1;
	}
	else {
		return pzpTree->mi1Height[D_TREE_RIGHT] + 1;
	}
}

// ???? - ???(???????????????)
int
fTreeRttR(
	Tree **pzppTree				// <I> ????
)
{
	// ????
	Tree *lzpChild = (*pzppTree)->mzp1Child[D_TREE_LEFT];

	// ???
	(*pzppTree)->mzp1Child[D_TREE_LEFT] = lzpChild->mzp1Child[D_TREE_RIGHT];	// ???? = ????
	(*pzppTree)->mi1Height[D_TREE_LEFT] = lzpChild->mi1Height[D_TREE_RIGHT];	// ????(?) = ????(?)
	lzpChild->mzp1Child[D_TREE_RIGHT] = *pzppTree;								// ???? = ?
	lzpChild->mi1Height[D_TREE_RIGHT] = fTreeGetHeight(*pzppTree);				// ????(?) - ????
	*pzppTree = lzpChild;														// ? = ?

	return 0;
}

// ???? - ???(???????????????)
int
fTreeRttL(
	Tree **pzppTree				// <I> ????
)
{
	// ????
	Tree *lzpChild = (*pzppTree)->mzp1Child[D_TREE_RIGHT];

	// ???
	(*pzppTree)->mzp1Child[D_TREE_RIGHT] = lzpChild->mzp1Child[D_TREE_LEFT];	// ???? = ????
	(*pzppTree)->mi1Height[D_TREE_RIGHT] = lzpChild->mi1Height[D_TREE_LEFT];	// ????(?) = ????(?)
	lzpChild->mzp1Child[D_TREE_LEFT] = *pzppTree;								// ???? = ?
	lzpChild->mi1Height[D_TREE_LEFT] = fTreeGetHeight(*pzppTree);				// ????(?) - ????
	*pzppTree = lzpChild;														// ? = ?

	return 0;
}

// ???? - ??????????
// ????[1]??????? [0]???????
int
fTreeComAddDel(
	Tree **pzppNow				// <I> ??????
	, int piWay					// <I> ?????
)
{
	// ?????????????
	int liNew = fTreeGetHeight((*pzppNow)->mzp1Child[piWay]);
	if ((*pzppNow)->mi1Height[piWay] == liNew) {												// ????
		return 0;
	}
	(*pzppNow)->mi1Height[piWay] = liNew;														// ??

	// ?????????????
	if ((*pzppNow)->mi1Height[D_TREE_LEFT] - (*pzppNow)->mi1Height[D_TREE_RIGHT] > 1) {			// ?????
		fTreeRttR(pzppNow);																			// ???
	}
	else if ((*pzppNow)->mi1Height[D_TREE_RIGHT] - (*pzppNow)->mi1Height[D_TREE_LEFT] > 1) {	// ?????
		fTreeRttL(pzppNow);																			// ???
	}

	return 1;
}

// ???? - ??
// ????[1]??????? [0]??????? [-1]????
int
fTreeAdd(
	Tree **pzppNow				// <I> ??????
	, int piVal					// <I> ?
)
{
	int liRet;

	// ??
	if (*pzppNow == NULL) {
		*pzppNow = fTreeMake(piVal);
		return 1;
	}

	// ????????
	if ((*pzppNow)->miVal == piVal) {
		return -1;
	}

	// ?????
	int liWay;
	if (piVal < (*pzppNow)->miVal) {									// ??
		liWay = D_TREE_LEFT;
	}
	else {																// ??
		liWay = D_TREE_RIGHT;
	}

	// ???
	liRet = fTreeAdd(&((*pzppNow)->mzp1Child[liWay]), piVal);
	if (liRet < 1) {													// ??????? or ????
		return liRet;
	}

	// ??????????
	return fTreeComAddDel(pzppNow, liWay);
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
	siTCnt = 0;													// ???????
	szpTop = NULL;												// ???????

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
	int liCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liCnt);

	// ?? - ??
	for (i = 0; i < liCnt; i++) {
		int liVal;
		fscanf(szpFpI, "%d", &liVal);

		// ???????
		while (liVal % 2 == 0) {
			liVal /= 2;
		}

		// ??
		fTreeAdd(&szpTop, liVal);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// ?? - ???
	sprintf(lc1Out, "%d\n", siTCnt);

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
./Main.c:205:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(szpFpI, "%d", &liVal);
   ^
./Main.c:215:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^