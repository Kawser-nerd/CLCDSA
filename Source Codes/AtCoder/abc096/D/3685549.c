#include<stdio.h>

int sosu(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) { return 0; }
	}
	return n;
}
int main() {
	int s[55] = {};
	int m = 0;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= 55555; i++) {
		if (sosu(i) != 0&&i%5==1) {
			s[m] = i;
			if (m == 54) { break; }
			m++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^