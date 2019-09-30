#include <stdio.h>

int main(void)
{
	int t, n, m, a[100], b[100], i;
	scanf("%d%d", &t, &n);
	for (i=0; i<n; i++)
		scanf("%d", a+i);
	scanf("%d", &m);
	for (i=0; i<m; i++)
		scanf("%d", b+i);

	if (n < m) {
		printf("no\n");
		return 0;
	}
	else {
		int count=0;
		for (i=0; i<m; i++) {
			while (1) {
				if (b[i]-a[count] >= 0 && count < n) {
					if (b[i]-a[count++] <= t) {
						break;
					}
				}
				else {
					printf("no\n");
					return 0;
				}
			}
		}
		printf("yes\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &t, &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a+i);
   ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &m);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", b+i);
   ^