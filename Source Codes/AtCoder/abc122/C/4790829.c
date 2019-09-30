#include<stdio.h>

int main() {
	
	int i;
	int q;
	
	int n;
	char s[100001];
	int a[100000],b[100000];
	
	int cnt[100001] = { 0 };
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	
	
	for (i = 0; i < q; i++)scanf("%d%d", &a[i], &b[i]);
	
	for (i = 1; i < n; i++) {

		if (s[i - 1] == 'A' && s[i] == 'C') {
			cnt[i]++;
			
		}cnt[i] = cnt[i] + cnt[i - 1];
	}
	
	

	for (i = 0; i < q; i++)printf("%d\n",cnt[b[i]-1]-cnt[a[i]-1]);
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &q);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:17:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < q; i++)scanf("%d%d", &a[i], &b[i]);
                         ^