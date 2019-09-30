#include <stdio.h>

#define MAX_DIM			(100)
#define TKAYAK			(10)
#define TDRAG			(100)
#define PMAP_SIZE		(TDRAG + 1)
#define MIN_GAP			(50)
#define MIN_KAYAK_LEVEL	(20)

#define TRUE	(1)
#define FALSE	(0)

int T;
int H, N, M;
int C[MAX_DIM][MAX_DIM];
int F[MAX_DIM][MAX_DIM];

typedef char PMAP[MAX_DIM][MAX_DIM];
PMAP P[PMAP_SIZE];

PMAP* curr;
PMAP* next;
PMAP* nextKayak;
PMAP* nextDrag;

#define NEXT_ACTION_MAP(r,c) (H - F[(r)][(c)] >= MIN_KAYAK_LEVEL ? nextKayak : nextDrag)
#define VISITED(pmap_p,r,c) ((*(pmap_p))[(r)][(c)])
#define MARK_VISITED(pmap_p,r,c) ((*(pmap_p))[(r)][(c)] = TRUE)
#define CANVISIT(r,c,r2,c2) (r2 >= 0 && c2 >= 0 && r2 < N && c2 < M && C[(r2)][(c2)] - H >= MIN_GAP && C[(r2)][(c2)] - F[(r)][(c)] >= MIN_GAP && C[(r2)][(c2)] - F[(r2)][(c2)] >= MIN_GAP && C[(r)][(c)] - F[(r2)][(c2)] >= MIN_GAP)

void nextStep() {
	curr = P + (curr - P + 1) % PMAP_SIZE;
	next = P + (next - P + 1) % PMAP_SIZE;
	nextKayak = P + (nextKayak - P + 1) % PMAP_SIZE;
	nextDrag = P + (nextDrag - P + 1) % PMAP_SIZE;
	T++;
	H--;
}

void floodForInit(int r, int c) {
	if (!VISITED(curr, r, c)) {
		MARK_VISITED(curr, r, c);
		if (CANVISIT(r, c, r+1, c)) floodForInit(r+1, c);
		if (CANVISIT(r, c, r-1, c)) floodForInit(r-1, c);
		if (CANVISIT(r, c, r, c+1)) floodForInit(r, c+1);
		if (CANVISIT(r, c, r, c-1)) floodForInit(r, c-1);
	}
}

int main() {
	int ntc, tc;
	scanf("%d", &ntc);

	int i, j, k;

	for (tc = 1; tc <= ntc; tc++) {
		scanf("%d %d %d", &H, &N, &M);
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++)
				scanf("%d", &C[i][j]);
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++)
				scanf("%d", &F[i][j]);
		}
		memset(P, 0, sizeof(P));
		curr = &P[0];
		next = &P[1];
		nextKayak = &P[TKAYAK];
		nextDrag = &P[TDRAG];

		floodForInit(0, 0);
		T = 0;
		while (!VISITED(curr, N-1, M-1)) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < M; j++) {
					if (VISITED(curr, i, j)) {
						MARK_VISITED(next, i, j);
						PMAP* nextActionMap = NEXT_ACTION_MAP(i, j);
						if (CANVISIT(i, j, i+1, j) && !VISITED(nextActionMap, i+1, j))
							MARK_VISITED(nextActionMap, i+1, j);
						if (CANVISIT(i, j, i-1, j) && !VISITED(nextActionMap, i-1, j))
							MARK_VISITED(nextActionMap, i-1, j);
						if (CANVISIT(i, j, i, j+1) && !VISITED(nextActionMap, i, j+1))
							MARK_VISITED(nextActionMap, i, j+1);
						if (CANVISIT(i, j, i, j-1) && !VISITED(nextActionMap, i, j-1))
							MARK_VISITED(nextActionMap, i, j-1);
					}
				}
			}
			nextStep();
		}
		printf("Case #%d: %d.%d\n", tc, T/10, T%10);
	}
	
	return 0;
}

