#include <stdio.h>
#define MAXN 100100
int solve(int* a, int n) {
	int ans = 0;
	static int cnt[MAXN];
	for(int i = 0; i < n; i++)
		cnt[a[i]]++;
	for(int i = 0; i < MAXN; i++) {
		int s = cnt[i] + cnt[i + 1] + cnt[i + 2];
		if(ans < s) ans = s;
	}
	return ans;
}
int main(void) {
	int n;
	static int a[MAXN];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d\n", solve(a, n));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:18:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
                             ^
./Main.c: In function ‘solve’:
./Main.c:9:23: warning: iteration 100099u invokes undefined behavior [-Waggressive-loop-optimizations]
   int s = cnt[i] + cnt[i + 1] + cnt[i + 2];
                       ^
./Main.c:8:2: note: containing loop
  for(int i = 0; i < MAXN; i++) {
  ^