#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int T, cas;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int n, cc = 0, x;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if (x > i + 5)
				cc += 1;
		}
		if (cc > 508)
			printf("Case #%d: BAD\n", cas);
		else
			printf("Case #%d: GOOD\n", cas);
	}
}
