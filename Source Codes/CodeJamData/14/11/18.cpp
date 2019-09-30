#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 200;
long long a[N], b[N], c[N], d[N];

long long f(int l) {
	static char s[100];
	long long ret = 0;
	scanf("%s", s);
	for (int i = 0; i < l; i++)
		ret = (ret << 1) + (s[i] - '0');
	return ret;
}

int main() {
	int T, cas;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int n, l;
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; i++)
			a[i] = f(l);
		for (int i = 0; i < n; i++)
			b[i] = f(l);
		int solve = false, ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				c[j] = a[j] ^ a[0];
			for (int j = 0; j < n; j++)
				d[j] = b[j] ^ b[i];
			sort(c, c + n);
			sort(d, d + n);
			int flag = true;
			for (int j = 0; j < n; j++)
				if (c[j] != d[j])
					flag = false;
			if (!flag) continue;
			int cur = 0;
			long long dif = a[0] ^ b[i];
			for (int j = 0; j < l; j++)
				if (1 & (dif >> j)) cur++;
			if (!solve || cur < ans) {
				solve = true;
				ans = cur;
			}
		}
		if (!solve)
			printf("Case #%d: NOT POSSIBLE\n", cas);
		else
			printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}