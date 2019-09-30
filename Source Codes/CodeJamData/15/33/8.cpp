#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111;

int c, n, v;
int cash[N];

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d %d", &c, &n, &v);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cash[i]);
		}
		sort(cash + 1, cash + n + 1);
		cash[n + 1] = (1 << 30);
		long long last = 0;
		int answer = 0;
		for (int i = 1; last < v && i <= n + 1; i++) {
			if (last + 1 >= cash[i]) {
				last += 1LL * cash[i] * c;
			} else {
				long long tmp = last + 1;
				last += tmp * c;
				answer++;
				i--;
			}
		}
		static int testCount = 0;
		printf("Case #%d: %d\n", ++testCount, answer);
	}
	return 0;
}