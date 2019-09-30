#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100001];
	int i;
	int k, g;
	int cnt[26] = {};
	int len, ans;
	
	scanf("%s", str);
	len = strlen(str);
	
	for (i = 0; i < len; i++)
		cnt[str[i] - 'a']++;
	
	k = g = 0;
	for (i = 0; i < 26; i++) {
		g += cnt[i] / 2;
		k += cnt[i] % 2;
	}
	
	if (k == 0) ans = len;
	else ans = g / k * 2 + 1;
	
	printf("%d\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^