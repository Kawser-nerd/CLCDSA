#include<stdio.h>
int main() {
	int max=0, min=1000000,maxnum=0,minnum=0;
	int n;
	int s[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		if (max < s[i])max = s[i];
		if (min > s[i])min = s[i];
	}
	if (max - min >= 2) { printf("No"); return 0; }
	
	for (int i = 0; i < n; i++) {
		if (max == s[i])maxnum++;
		if (min == s[i])minnum++;
	}
	if (max == min && (n - maxnum + 1 <= max && max <= n - maxnum + maxnum / 2 || max + 1 == n)) { printf("Yes"); return 0; }
	else if (max == min ) { printf("No"); return 0; }

	if (n - maxnum + 1 <= max && max <= n - maxnum + maxnum / 2) { printf("Yes"); return 0; }
	else {
		printf("No");
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s[i]);
   ^