#include <stdio.h>
#include <string.h>

char s[200005], t[200005];
int g[2][30];
int len;

int main()
{
	int f = 1;

	scanf("%s", s);
	scanf("%s", t);
	
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (g[0][s[i] - 'a'] == 0) {
			g[0][s[i] - 'a'] = t[i];
		} else if (g[0][s[i] - 'a'] != t[i]) {
			f = 0;
		}

		if (g[1][t[i] - 'a'] == 0) {
			g[1][t[i] - 'a'] = s[i];
		} else if (g[1][t[i] - 'a'] != s[i]) {
			f = 0;
		}
	}

	puts((f ? "Yes" : "No"));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", t);
  ^