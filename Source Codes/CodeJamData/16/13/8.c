// Google Code Jam 2016 Round 1A
// Problem C.BFFs

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long LL;

int used[16];
int perm[16];
int f[16];
int ans;

void check(int n) {
	int len, i;
	for (len = n; len >= 2; --len) {
		if (f[perm[0]] == perm[1] || f[perm[0]] == perm[len - 1]) {
			if (f[perm[len - 1]] == perm[0] || f[perm[len - 1]] == perm[len - 2]) {
				for (i = 1; i < len - 1; ++i) {
					if (f[perm[i]] != perm[i - 1] && f[perm[i]] != perm[i + 1]) {
						break;
					}
				}
				if (i >= len - 1) {
					ans = ans < len ? len : ans;
					break;
				}
			}
		}
	}
}

void next_permutation(int pos, int n) {
	int i;
	if (pos == n) {
		check(n);
		return;
	}
	for (i = 0; i < n; ++i) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = 1;
			next_permutation(pos + 1, n);
			used[i] = 0;
		}
	}
}

int main(int argc, char *argv[]) {
	int T, t, n, i;
	char buff[1024];
	fgets(buff, 1024, stdin);
	T = atoi(buff);
	for (t = 1; t <= T; ++t) {
		ans = 0;
		fgets(buff, 1024, stdin);
		n = atoi(buff);
		fgets(buff, 1024, stdin);
		const char *p = buff;
		for (i = 0; i < n; ++i) {
			perm[i] = i;
			f[i] = atoi(p) - 1;
			while (isdigit(*p)) {
				++p;
			}
			++p;
		}
		next_permutation(0, n);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
