#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>

int sum[1001];
int now[1001];
int mn[1001];
int mx[1001];
void update_now(int i, int v) {
	now[i] += v;
	if (mn[i] > now[i]) mn[i] = now[i];
	if (mx[i] < now[i]) mx[i] = now[i];
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		int N, K;
		scanf("%d %d", &N, &K);
		memset(now, 0, sizeof(now));
		memset(mn, 0, sizeof(mn));
		memset(mx, 0, sizeof(mx));
		for (int i = 0; i < N - K + 1; i++) {
			scanf("%d", &sum[i]);
			if (i > 0) {
				int dif = sum[i] - sum[i - 1];
				update_now((i - 1) % K, dif);
			}
		}
		int sol = 0;
		int zval = 0;
		for (int i = 0; i < K; i++) {
			int dif = mx[i] - mn[i];
			if (sol < dif) sol = dif;
			zval -= mn[i];
		}
		int mv = 0;
		for (int i = 0; i < K; i++) {
			int dif = mx[i] - mn[i];
			mv += sol - dif;
		}

		int md = ((sum[0] - zval) % K + K) % K;

		if (md > mv) {
			sol++;
		}

		printf("Case #%d: %d\n", cs, sol);
	}

	return 0;
}