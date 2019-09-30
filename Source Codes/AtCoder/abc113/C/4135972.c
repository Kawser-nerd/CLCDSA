#include<stdio.h>

typedef struct {
	int No;//??????
	int P;
	int Y;
	int ans;//?????????????
}CITY;

int Comp1(const void* pElem1, const void* pElem2)
{
	// ?????????????????????
	const CITY* pmem1 = (const CITY*)pElem1;
	const CITY* pmem2 = (const CITY*)pElem2;
	int nDiff;  // ?????
	nDiff = pmem1->P - pmem2->P;
	if (nDiff != 0)
		return nDiff;
	nDiff = pmem1->Y - pmem2->Y;
	if (nDiff != 0)
		return nDiff;
}

int Comp2(const void* pElem1, const void* pElem2)
{
	// ?????????????????????
	const CITY* pmem1 = (const CITY*)pElem1;
	const CITY* pmem2 = (const CITY*)pElem2;
	int nDiff;  // ?????
	nDiff = pmem1->No - pmem2->No;
	if (nDiff != 0)
		return nDiff;
}

//CITY city[10002];//????????

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	CITY city[524288];//????????
	for (int i = 0; i < M; i++)
	{
		city[i].No = i;
		scanf("%d%d", &city[i].P, &city[i].Y);
		//???????????????
		//-1???		:?????(???)
		//0?????	:??
		city[i].ans = -1;
	}

	//????????????
	qsort(city, M, sizeof(CITY), Comp1);

	for (int i = 0; i < M; i++) {
		if (i == 0) {
			city[i].ans = 1;
		}
		else if (i > 0 && city[i].P != city[i - 1].P) {
			city[i].ans = 1;
		}
		else {
			city[i].ans = city[i - 1].ans + 1;
		}
	}

	//?????????????
	qsort(city, M, sizeof(CITY), Comp2);

	//printf("?????\n");
	//for (int i = 0; i < M; i++) {
	//	printf("%d %d %d %d\n", city[i].No, city[i].P, city[i].Y, city[i].ans);
	//}
	for (int i = 0; i < M; i++) {
		printf("%06d%06d\n", city[i].P, city[i].ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
  qsort(city, M, sizeof(CITY), Comp1);
  ^
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &city[i].P, &city[i].Y);
   ^