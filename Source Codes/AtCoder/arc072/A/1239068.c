#include <stdio.h>

int n;
int a[100000];

long long int min(long long int a, long long int b) {
	return a < b ? a : b; 
}

long long int count(int sf) {
	int i;
	long long int sum = 0, count = 0;
	
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (!sf) {
			if (sum >= 0) {
				count += sum + 1;
				sum = -1;
			}
		}
		else {
			if (sum <= 0) {
				count += -sum + 1;
				sum = 1;
			}
		}
		sf = !sf;
	}
	return count;
}

int main(void) {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%lld\n", min(count(0), count(1)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^