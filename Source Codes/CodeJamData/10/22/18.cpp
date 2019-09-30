#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int x[100], v[100];
bool u[100], u2[100];
int a[100];

int main() {
	int T; scanf("%d", &T);
	for (int tt = 0; tt < T; ++tt) {
		int n, k, b, t;
		int result = 0;
		scanf("%d %d %d %d", &n, &k, &b, &t);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
			u[i] = false;
			u2[i] = false;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		
		for (int i = n - 1; i >= 0; --i) {
			if ((b - x[i]) <= t * v[i]) {
				u[i] = true;
				u2[i] = (i == n - 1) || u2[i + 1];
				if (u2[i]) --k;
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (u[i] && !u2[i]) {
				a[i] = 0;
				for (int j = i + 1; j < n; ++j) {
					if (!u[j]) ++a[i];
				}
			} else {
				a[i] = 10000;
			}
		}
		sort(a, a + n);
		for (int i = 0; (i < n) && (a[i] != 10000) && (k > 0); ++i, --k) {
			result += a[i];
		}
		
		printf("Case #%d: ", tt + 1);
		
		if (k > 0) printf("IMPOSSIBLE\n");
		else printf("%d\n", result);
	}
	return 0;
}
