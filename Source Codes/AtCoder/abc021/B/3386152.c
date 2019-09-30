#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
	int n, i, j, k, ans, s1, s2;
	int p[100];
	p[0] = -1;
	scanf("%d", &n);
	scanf("%d %d", &s1, &s2);
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d", &ans);
		for (j = 0; j+1 <= i; j++) {
			if (p[j] == ans || p[j]==s1 || p[j]==s2) {
				printf("NO\n");
				return 0;
			}
		}
		p[i] = ans;
	}
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &s1, &s2);
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &ans);
   ^