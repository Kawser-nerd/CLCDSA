#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T, C, N, L;
long long t;
long long dist[1000005];
long long left[1000005];
int main() {
	int i, j, Case = 1;
	scanf("%d", &T);
	while (T --) {
		scanf("%d%I64d%d%d", &L, &t, &N, &C);
		for (i = 0; i < C; i ++) {
			scanf("%I64d", &dist[i]);
			for (j = i; j < N; j += C)
				dist[j] = dist[i];
		}
		long long ans = 0;
		for (i = 0; i < N; i ++)
			if (t >= 2 * dist[i]) {
				t -= 2 * dist[i];
				ans += 2 * dist[i];
			}
			else
				break;
		printf("Case #%d: ", Case ++);
		if (i >= N) {
			printf("%I64d\n", ans);
			continue;
		}
		dist[i] -= t / 2;
		ans += t;
		for (j = 0; i < N; i ++)
			left[j ++] = dist[i];
		sort(left, left + j);
		for (i = j - 1; i >= 0 && i >= j - L; i --)
			ans += left[i];
		for (; i >= 0; i --)
			ans += 2 * left[i];
		printf("%I64d\n", ans);
	}
	return 0;
}
