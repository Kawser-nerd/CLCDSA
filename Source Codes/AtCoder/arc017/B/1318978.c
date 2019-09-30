#include "stdio.h"
 
int main()
{
	int x, n, k, i = 0, bi = 0, count = 0, ans = 0;
 
	scanf("%d %d", &n, &k);
	for (x = 0; x < n; x++) {
		scanf("%d", &i);
		if (bi < i) {
			count++;
			if (count >= k) {
				ans++;
			}
		}
		else {
			count = 1;
		}
		if (k == 1) {
			bi = 0;
		}
		else {
			bi = i;
		}
	}
	printf("%d\n", ans);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &k);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &i);
   ^