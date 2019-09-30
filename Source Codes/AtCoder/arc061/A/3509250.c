#include<stdio.h>
long long int ten[11];
long long int two[11];

int keta;
long long int sum(int s) {
	long long int memo=0;
	memo += ten[s - 1] * two[keta - s];
	for (int i = 1; i <= s - 1; i++) {
		memo += ten[s - i - 1] * two[keta - s + i-1];
	}
	return memo;

}
int min(int a, int b) {
	if (a >= b) { return b; }
	else { return a; }
}
int max(int a, int b) {
	if (a <= b) { return b; }
	else { return a; }
}
int main() {
	long long int a;
	long long result=0;
	keta = 0;
	long long int memo=1;
	for (int i = 0; i <= 10; i++) {
		ten[i] = memo;
		memo *= 10;
	}
	memo = 1;
	for (int i = 0; i <= 10; i++) {
		two[i] = memo;
		memo *= 2;
	}
	int i = 1;
	scanf("%lld", &a);
	int s[11] = {};
	while (a != 0) {
		s[i] = a % 10;
		keta++;
		a /= 10;
i++;
	}
	for (int i = 1; i <= keta; i++) {
		result += sum(i)*s[i];
	}
	printf("%lld\n", result);
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &a);
  ^