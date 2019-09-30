#include <cstdio>
#include <vector>
using namespace std;

const int MAX_STEPS = (1<<10) * 10;

int main(void) {
	int testCount;
	scanf("%d", &testCount);
	for (int testNo = 1; testNo <= testCount; ++testNo) {
		int N;
		scanf("%d", &N);
		vector<int> l(N - 1);
		vector<int> r(N - 1);
		for (int i = 0; i < N-1; ++i) {
			scanf("%d%d", &l[i], &r[i]);
			l[i] -= 1;
			r[i] -= 1;
		}
		vector<bool> cnt(N - 1);
		int result = 0;
		for (int cur = 0; cur != N-1 && result <= MAX_STEPS; ++result) {
			cnt[cur] = !cnt[cur];
			if (cnt[cur]) {
				cur = l[cur];
			} else 
				cur = r[cur];
		}
		printf("Case #%d: ", testNo);
		if (result > MAX_STEPS)
			printf("Infinity\n");
		else
			printf("%d\n", result);
	}
	return 0;
}
