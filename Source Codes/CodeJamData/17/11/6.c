#include <stdio.h>
#include <string.h>

int main() {
	int t, r, c;
	char a[30][30], *s;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%d %d\n", &r, &c);
		for (int j = 0; j < r; ++j) {
			gets(s = a[j]);
			for (int k = 0; k < c - 1; ++k) {
				if (s[k] != '?' && s[k + 1] == '?') s[k + 1] = s[k];
			}
			for (int k = c - 1; k > 0; --k) {
				if (s[k] != '?' && s[k - 1] == '?') s[k - 1] = s[k];
			}
		}
		for (int j = 0; j < r - 1; ++j) {
			if (a[j][0] != '?' && a[j + 1][0] == '?') strcpy(a[j + 1], a[j]);
		}
		for (int j = r - 1; j > 0; --j) {
			if (a[j][0] != '?' && a[j - 1][0] == '?') strcpy(a[j - 1], a[j]);
		}
		printf("Case #%d:\n", i);
		for (int j = 0; j < r; ++j) printf("%s\n", a[j]);
	}
}
