#include <cstdio>
#include <assert.h>

int R, N, M, K;
int vecs[9][4] = {{0,0,0,0},
                 {0,0,0,0},
                 {1,0,0,0},
                 {0,1,0,0},
                 {2,0,0,0},
                 {0,0,1,0},
                 {1,1,0,0},
                 {0,0,0,1},
                 {3,0,0,0}};
int numPoss[13][37][13][13][13];
int curnums[12];

long long outputs[8000][12];
long long outputsi[8000][12];
long long outputsj[8000][12];
long long outputsk[8000][12];
long long outputsl[8000][12];
long double bestProb[8000];
int bestNums[8000][12];

void compute(int fcount) {
	for (int i = 0; i < N; i++) {
		printf("%d ", curnums[i]);
	}
	printf(": %d\n", numPoss[N][2][0][0][0]);
	for (int trial = 0; trial < R; trial++) {
		long double prob = 1.0 / (long double) fcount;
		for (int sample = 0; sample < K; sample++) {
			int i = outputsi[trial][sample];
			int j = outputsj[trial][sample];
			int k = outputsk[trial][sample];
			int l = outputsl[trial][sample];
			int numPossibleProducts = numPoss[N][i][j][k][l];
			prob *= (long double) numPossibleProducts;
		}
		if (prob > bestProb[trial]) {
			//printf("Hi, trial = %d\n",trial);
			bestProb[trial] = prob;
			for (int i = 0; i < N; i++) {
				bestNums[trial][i] = curnums[i];
				//printf("%d\n", curnums[i]);
			}
		}
	}
}

void recurse(int sz, int lowestAllowed, int curcount, int fcount) {
	if (sz == N) {
		compute(fcount);
		return;
	}

	for (int num = lowestAllowed; num <= M; num++) {
		int i1 = vecs[num][0];
		int j1 = vecs[num][1];
		int k1 = vecs[num][2];
		int l1 = vecs[num][3];
		for (int i = 0; i <= 36; i++) {
			for (int j = 0; j <= 12; j++) {
				for (int k = 0; k <= 12; k++) {
					for (int l = 0; l <= 12; l++) {
						numPoss[sz+1][i][j][k][l] = (numPoss[sz][i][j][k][l] + (i >= i1 && j >= j1 && k >= k1 && l >= l1 ? numPoss[sz][i-i1][j-j1][k-k1][l-l1] : 0));
					}
				}
			}
		}
		curnums[sz] = num;
		int newcount = lowestAllowed == num ? curcount+1 : 1;
		recurse(sz+1, num, newcount, fcount * newcount);
	}
}

int main() {
	int ncases;
	scanf("%d", &ncases);
	scanf("%d", &R);
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &K);
	for (int trial = 0; trial < R; trial++) {
		for (int sample = 0; sample < K; sample++) {
			scanf("%lld", &outputs[trial][sample]);
			outputsi[trial][sample] = 0;
			outputsj[trial][sample] = 0;
			outputsk[trial][sample] = 0;
			outputsl[trial][sample] = 0;
			long long prod = outputs[trial][sample];
			while (prod % 2 == 0) { outputsi[trial][sample]++; prod /= 2; }
			while (prod % 3 == 0) { outputsj[trial][sample]++; prod /= 3; }
			while (prod % 5 == 0) { outputsk[trial][sample]++; prod /= 5; }
			while (prod % 7 == 0) { outputsl[trial][sample]++; prod /= 7; }
		}
		bestProb[trial] = -1.0;
	}

	for (int i = 0; i < 36; i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 12; k++) {
				for (int l = 0; l < 12; l++) {
					numPoss[0][i][j][k][l] = 0;
				}
			}
		}
	}
	numPoss[0][0][0][0][0] = 1;

	recurse(0, 2, 1, 1);

	printf("Case #1:\n");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < N; j++) {
			assert(2 <= bestNums[i][j]);
			assert(bestNums[j][i] <= M);
			printf("%d", bestNums[i][j]);
		}
		printf("\n");
	}
}
