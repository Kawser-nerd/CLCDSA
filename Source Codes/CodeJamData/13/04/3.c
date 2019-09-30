#define _GNU_SOURCE
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// BM = BitMask
enum { MAX_CHESTS = 20 };
enum { MAX_BM = 1 << MAX_CHESTS };
enum { MAX_KEYS = 41 };

int N, K;

bool solvable[MAX_BM];
int keys_in_chests[MAX_CHESTS][MAX_KEYS];
int start_keys[MAX_KEYS];
int key_to_chest[MAX_CHESTS];

void count_keys(int *key_count, int bm)
{
	for (int i = 0; i < K; ++i)
		key_count[start_keys[i]] += 1;
	for (int i = 0; i < N; ++i) {
		if (bm & (1<<i)) {
			key_count[key_to_chest[i]] -= 1;
			for (int j = 0; keys_in_chests[i][j] != 0; ++j)
				key_count[keys_in_chests[i][j]] += 1;
		}
	}
}

int main(void)
{
	setlinebuf(stdout);
	int cases;
	scanf("%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		scanf("%d %d", &K, &N);
		for (int i = 0; i < K; ++i)
			scanf("%d", &start_keys[i]);
		for (int i = 0; i < N; ++i) {
			int k;
			scanf("%d %d", &key_to_chest[i], &k);
			for (int j = 0; j < k; ++j)
				scanf("%d", &keys_in_chests[i][j]);
			keys_in_chests[i][k] = 0;
		}

		int BM = 1 << N;
		memset(solvable, false, sizeof solvable);
		solvable[BM-1] = true;
		for (int bm = BM-1; bm >= 0; --bm) {
			int key_count[MAX_KEYS] = {};
			count_keys(key_count, bm);
			for (int i = 0; i < N; ++i) {
				if (key_count[0] < 0)
					goto mask_unsolvable;
			}
			for (int i = 0; !solvable[bm] && i < N; ++i) {
				if (key_count[key_to_chest[i]] <= 0)
					continue;
				int nbm = bm | (1 << i);
				solvable[bm] = solvable[nbm];
			}
			continue;
mask_unsolvable:
			solvable[bm] = false;
		}
		printf("Case #%d:", T);
		if (!solvable[0]) {
			puts(" IMPOSSIBLE");
			continue;
		}

		int bm = 0;
		while (bm < BM-1) {
			assert(solvable[bm]);
			int key_count[MAX_KEYS] = {};
			count_keys(key_count, bm);
			for (int i = 0; i < N; ++i) {
				if (key_count[key_to_chest[i]] <= 0)
					continue;
				int nbm = bm | (1 << i);
				if (nbm == bm)
					continue;
				if (solvable[nbm]) {
					printf(" %d", i+1);
					bm = nbm;
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}
