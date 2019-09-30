#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define MAXM 200000
#define MAXY 200000
#define MAXQ 100000
#define MAXW 200000

int comp(const void *a_, const void *b_) {
	const int *a = a_;
	const int *b = b_;
	if (a[0] > b[0]) { return -1; }
	else if (a[0] < b[0]) { return 1; }
	else{
		if (a[1] > b[1]) { return -1; }
		else if (a[1] < b[1]) { return 1; }
		else {
			if (a[2] > b[2]) { return -1; }
			else if (a[2] < b[2]) { return 1; }
			else { return 0; }
		}
	}
}

typedef struct UnionFind {
	int N;
	int Counter;
	struct UnionFind *Up;
	int Rank;
}UF;

void initUF(UF *uf, int n) {
	uf->N = n;
	uf->Counter = 1;
	uf->Up = NULL;
	uf->Rank = 0;
}

UF* getTop(UF *uf) {
	if (uf->Up == NULL) { return uf; }
	else {
		uf->Up = getTop(uf->Up);
		return uf->Up;
	}
}
void Merge(UF *uf1, UF *uf2)
{
	UF* top1 = getTop(uf1);
	UF* top2 = getTop(uf2);
	if (top1 == top2)
	{
		return;
	}
	
	if (top1->Rank > top2->Rank) {
		top2->Up = top1;
		top1->Counter += top2->Counter;
	}
	else {
		top1->Up = top2;
		top2->Counter += top1->Counter;
		if (top1->Rank == top2->Rank) {
			top2->Rank++;
		}
	}
	
}

int main() {
	int N, M;
	int Q;

	scanf("%d %d", &N, &M);
	int yab[MAXM][3];
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &yab[i][1], &yab[i][2], &yab[i][0]);
		yab[i][1]--;
		yab[i][2]--;
	}
	qsort(yab, M, sizeof(int) * 3, &comp);
	scanf("%d", &Q);
	int wvi[MAXQ][3];
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &wvi[i][1], &wvi[i][0]);
		wvi[i][2] = i;
		wvi[i][1]--;
	}
	qsort(wvi, Q, sizeof(int) * 3, &comp);

	int rindex = 0;
	UF uf[MAXN];
	for (int i = 0; i < N; i++)
	{
		initUF(&uf[i], i);
	}
	int ans[MAXQ];
	for (int pindex = 0; pindex < Q; pindex++)
	{
		int now = wvi[pindex][0];
		while (rindex < M && yab[rindex][0] > now)
		{
			int *r = yab[rindex];
			Merge(&uf[r[1]], &uf[r[2]]);
			rindex++;
		}
		int a = getTop(&uf[wvi[pindex][1]])->Counter;
		ans[wvi[pindex][2]] = a;
	}

	for (int i = 0; i < Q; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:74:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &M);
  ^
./Main.c:78:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &yab[i][1], &yab[i][2], &yab[i][0]);
   ^
./Main.c:83:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:87:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &wvi[i][1], &wvi[i][0]);
   ^