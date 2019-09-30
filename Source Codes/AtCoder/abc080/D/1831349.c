//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX_T 200002
#define MAX_N 100000

int main() {
#ifdef DEBUG

#endif
	int N, C;
	int s[MAX_N], t[MAX_N], c[MAX_N];
	int tt[MAX_T] = { 0 };
	scanf("%d %d", &N, &C);
	int i,j;
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &s[i], &t[i], &c[i]);
	}
	int cnt[MAX_T] = { 0 };
	int tmp;
	for (i = 1; i <= C; i++) {
		/*for (j = MAX_T / 2; j < MAX_T; j++)tt[j] = 0;
		for (j = 0; j < N; j++)if (c[j] == i) {
			tt[s[j] + MAX_T / 2]++;
			if (t[j] != MAX_T / 2 - 1)tt[t[j] + MAX_T / 2+1]--;
			if (tt[s[j] + MAX_T / 2+1]<0) {
				tt[s[j] + MAX_T / 2]--;
				tt[s[j] + MAX_T / 2+1]++;
			}
			if (t[j] != MAX_T / 2 - 1) {
				if (tt[t[j] + MAX_T / 2] > 0) {
					tt[t[j] + MAX_T / 2 + 1]++;
					tt[t[j] + MAX_T / 2]--;
				}
			}
		}
		for (j = 0; j < MAX_T/2; j++) {
			tt[j] += tt[j + MAX_T/2];
		}//printf("%d", i);*/
		for (j = 0; j < MAX_T; j++)tt[j] = 0;
		for (j = 0; j < N; j++)if (c[j] == i) {
			tt[s[j]]++;
			if (t[j] != MAX_T - 1)tt[t[j]+1]--;
			if (tt[s[j]+1]<0) {
				tt[s[j]]--;
				tt[s[j]+1]++;
			}
			if (t[j] != MAX_T - 1) {
				if (tt[t[j]] > 0) {
					tt[t[j] + 1]++;
					tt[t[j]]--;
				}
			}
		}
		tmp = 0;
		for (j = 0; j < MAX_T; j++) {
			tmp += tt[j];
			if (tmp > 0)cnt[j]++;
			//printf("%d", cnt[j]);
		}//printf("\n");
	}
	int max=0;
	for (i = 0; i < MAX_T; i++) {
		/*
		printf("%d", tt[i]);
		if (i % 20 == 19)printf("\n");
		//*/
		if (max < cnt[i])max = cnt[i];
	}
	printf("%d\n", max);
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &C);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &s[i], &t[i], &c[i]);
   ^