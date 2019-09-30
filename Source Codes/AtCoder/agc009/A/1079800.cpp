#include <cstdio>
void reader(int *x) {
	char k = getchar_unlocked(); *x = k - '0';
	while (1) {
		k = getchar_unlocked();
		if (k < '0' || k > '9') break;
		*x = ((*x) << 1) + ((*x) << 3) + k - '0';
	}
}
void reader(long long *x) {
	char k = getchar_unlocked(); *x = k - '0';
	while (1) {
		k = getchar_unlocked();
		if (k < '0' || k > '9') break;
		*x = ((*x) << 1) + ((*x) << 3) + k - '0';
	}
}
int n, b[100009]; long long a[100009];
int main() {
	reader(&n);
	for (int i = 0; i < n; i++) {
		reader(&a[i]);
		reader(&b[i]);
	}
	long long ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		long long d = (a[i] + ret) % b[i];
		if (d) ret += b[i] - d;
	}
	printf("%lld\n", ret);
	return 0;
}