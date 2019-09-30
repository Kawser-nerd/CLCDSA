#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ????
static FILE *szpFpI;											// ??

// ???? - ????
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// ???? : plUp * llRet + plNow - plDel(plDay - llRet) > 0 : llRet > (plDel * plDay - plNow) / (plUp + plDel)
long long
fGetDay(
	long long plDay				// <I> ????
	, long long plUp			// <I> ???
	, long long plDel			// <I> ???
	, long long plNow			// <I> ???
)
{
	// ??
	double ldDay = (double)(plDel * plDay - plNow) / (double)(plUp + plDel);
	if (ldDay < 0) {
		return 0;
	}

	return (plDel * plDay - plNow) / (plUp + plDel) + 1;
}

// ?????
int
fMain(
	int piTNo					// <I> ????? 1?
)
{
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

	// ?????? - ??
	long long llDay, llNow;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%lld", &llDay, &llNow);

	// ?????? - ??
	long long llAMoney, llAUp, llBMoney, llBUp, llCDel;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld%lld%lld%lld%lld", &llAMoney, &llAUp, &llBMoney, &llBUp, &llCDel);

	// ??A????? - ??
	long long llADay = fGetDay(llDay, llAUp, llCDel, llNow);

	// ???????
	long long llMin = LLONG_MAX;
	for (; llADay >= 0; llADay--) {

		// ??B??? - ??
		long long llBDay = fGetDay(llDay - llADay, llBUp, llCDel, llNow + llAUp * llADay);

		// ??
		long long llMoney = llAMoney * llADay + llBMoney * llBDay;
		if (llMin > llMoney) {
			llMin = llMoney;
		}
	}

	// ?? - ???
	sprintf(lc1Out, "%lld\n", llMin);

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
./Main.c:56:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^
./Main.c:61:2: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
  fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
  ^