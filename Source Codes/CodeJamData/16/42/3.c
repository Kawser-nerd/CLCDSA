#include <stdio.h>
#include <string.h>

typedef long long ll;

double p[210], pstack[210];
double ans, hubo;
int N, K;

double anscalc(int i, int cnt, double prob) {
	if(i >= K) {
		if (cnt == K/2) return prob;
		else return 0;
	}
	if(i + K/2 - cnt > K)
		return 0;
	if(cnt == K/2){
		return anscalc(i+1, cnt, prob*(1-pstack[i]));
	}
	return anscalc(i+1, cnt, prob*(1-pstack[i])) 
		+ anscalc(i+1, cnt+1, prob*pstack[i]);
}

void select(int i, int cnt) {
	int j;
	if(cnt >= K){
		hubo = anscalc(0, 0, 1);
		if (hubo > ans) ans = hubo;
		return;
	}
	if(i >= N) return;
	select(i+1, cnt);
	pstack[cnt] = p[i];
	select(i+1, cnt+1);
}


int main() {
	int t, T;
	int i, j;
	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		ans = 0;
		for(i = 0; i < N; i++) {
			scanf("%lf", &p[i]);
		}
		select(0, 0);
		printf("Case #%d: ", t);
		printf("%lf", ans);
		printf("\n");
	}
}
