#include <cstdio>
#include <bitset>

using namespace std;

const int MAXN = 2001, MAXV = 2001 * 1001;

int n, arr[MAXN];
bitset<MAXV> dp;

int main() {
	scanf("%d", &n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		s += arr[i];
	}
	int maxv = s / 2 + 1;
	dp.set(0);
	for(int i = 0; i < n; i++)
	    dp |= dp << arr[i];
	for (int i = maxv-1; i >= 0; i--) {
		if (dp[i]) {
			printf("%d\n", s - i);
			return 0;
		}
	}
}