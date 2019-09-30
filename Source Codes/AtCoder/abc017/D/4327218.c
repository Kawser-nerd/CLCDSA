#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
#define D_ON			1										// ????? - ON
#define D_OFF			0										// ????? - OFF
#define D_MOD			(long long)1000000007					// ??(10?9?+7)
#define D_SIZE_MAX		100005									// ??????

// ????
static FILE *szpFpI;											// ??
static int siCnt;												// ??
static int si1Val[D_SIZE_MAX];									// ??[????????]
static int si1Eat[D_SIZE_MAX];									// ?????[????????]
static int si1One[D_SIZE_MAX];									// ???????[????????]
static long long sl1Ttl[D_SIZE_MAX];							// ???????[????????]
static long long sl1Sum[D_SIZE_MAX];							// ???????[????????]

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
	int i, liWork;
	char lc1Buf[1024], lc1Out[1024];

	// ??? - ???
	memset(si1Eat, D_OFF, sizeof(si1Eat));						// ?????
	memset(si1One, 0, sizeof(si1One));							// ???????
	memset(sl1Ttl, 0, sizeof(sl1Ttl));							// ???????
	memset(sl1Sum, 0, sizeof(sl1Sum));							// ???????

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

	// ?? - ??
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siCnt, &liWork);

	// ?? - ??
	for (i = 1; i <= siCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d", &si1Val[i]);
	}

	// ??????? - ???
	int liSNo = 1;
	int liENo = 1;
	while (1) {

		// ????????????????
		if (liENo <= siCnt && si1Eat[si1Val[liENo]] == D_OFF) {
			si1Eat[si1Val[liENo]] = D_ON;
			liENo++;
		}
		else if (liSNo <= siCnt) {
			si1One[liSNo] = liENo - liSNo;
			si1Eat[si1Val[liSNo]] = D_OFF;
			liSNo++;
		}
		else {
			break;
		}
	}

	// ??????? - ???
	sl1Sum[0] = 1;

	// ??????? - ?????
	for (i = 1; i <= siCnt; i++) {

		// ???? - ????
		sl1Ttl[i] += sl1Sum[i - 1];
		sl1Ttl[i] %= D_MOD;

		// ???? - ????
		int liNo = i + si1One[i];
		sl1Ttl[liNo] -= sl1Sum[i - 1];
		sl1Ttl[liNo] %= D_MOD;

		// ?? - ???
		sl1Ttl[i] += sl1Ttl[i - 1];
		if (sl1Ttl[i] < 0) {
			sl1Ttl[i] += D_MOD;
		}
		else {
			sl1Ttl[i] %= D_MOD;
		}

		// ??????? - ???
		sl1Sum[i] = sl1Ttl[i];
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", sl1Sum[siCnt]);

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
./Main.c:57:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:62:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
   ^