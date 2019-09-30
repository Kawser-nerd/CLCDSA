#include<stdio.h>
int main() {
	int i,j;
	int n;
	int s[100005];
	int s2[100005];
	int result = 0;
	scanf("%d", &n);
	for (i = 0; i <= 100002; i++) {
		s[i] = 0;
		s2[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d",&s[i]);
	}

	for (i = 0; i < n; i++) {
		if (s[i] <= 100000) {
			s2[s[i]]++;
		}
		else {
			s2[100001]++;
		}
	}

	for (i = 1; i < 100001; i++) {
		if (s2[i] > i) {
			result = result + s2[i]-i;
		}
		else if (s2[i] < i) {
			result = result + s2[i];
		}
	}
	result = result + s2[100001];
	printf("%d",result);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^