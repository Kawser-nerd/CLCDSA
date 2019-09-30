#include <stdio.h>
#include <string.h>

int n;
char s[128], t[128];

int main()
{
	int ans;
	int i, j;

	scanf("%d", &n);
	scanf("%s %s", s, t);

	ans = n;

	for (i = 0; i < n; i++) {
		j = 0;

		while (i + j < n && s[i + j] == t[j]) {
			j++;
		}

		if (i + j == n) {
			break;
		}

		ans++;
	}

	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s", s, t);
  ^