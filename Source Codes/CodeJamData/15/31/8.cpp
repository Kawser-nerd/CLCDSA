#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 22;

int a[N];
int n, m, w;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d %d", &n, &m, &w);
		int answer = 0;
		for (int i = w; i <= m; i += w) {
			answer++;
		}
		answer *= (n - 1);
		for (int i = w; i <= m; i += w) {
			if (i + w > m) {
				int length = m - i + w;
				if (length > w) {
					answer += w + 1;
				} else {
					answer += w;
				}
				break;
			} else {
				answer ++;
			}
		}
		static int testCount = 0;
		printf("Case #%d: %d\n", ++testCount, answer);
	}
	return 0;
}