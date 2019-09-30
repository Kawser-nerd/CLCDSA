#include <iostream>

long long int f(long long int n, long long int k, long long int b) {
	if (k >= b) return 0;
	auto q = n / b;
	auto r = n % b;
	if (k == 0) return q * b + r;
	if (k <= r) return q * (b - k) + (r - k + 1);
	else return q * (b - k);
}
int main() {
	long long int n, k;
	std::cin >> n >> k;
	long long int res{ 0 };
	for (auto b = k + 1; b <= n; ++b) {
		res += f(n, k, b);
	}
	std::cout << res << std::endl;
}