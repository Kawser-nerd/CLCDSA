#include <stdio.h>
#include <string.h>

int main() {
	int check[] = { 1, 0, 0, 0, 1,
					 0, 0, 0, 1, 0,
					 0, 0, 0, 0, 1,
					 0, 0, 0, 0, 0,
					 1, 0, 0, 0, 0, 0};
	long long int group, cur, ans;
	int i, j;
	char sen[1000005];
	int t, n, len;
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		scanf("%s %d", sen, &n);
		len = strlen(sen);
		group = 1;
		cur = 0;
		ans = 0;
		for(j = 0; j < len; j++) {
			group++;
			if(check[sen[j] - 'a'] == 1) {
				if(cur != 0)
					cur = 0;
			}
			else {
				cur++;
				if(cur == n) {
					group -= n;
					ans += group * (len - j);
					cur--;
					group = n;
				}
			}
			//printf("j : %d group : %lld ans : %lld\n", j, group, ans);
		}
		printf("Case #%d: %lld\n", i + 1, ans);
	}
	return 0;
}
