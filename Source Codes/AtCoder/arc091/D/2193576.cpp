#include <iostream>
int nim_num(int x, int k) {
	if (x < k) return 0;
	if (x % k == 0) return x / k;
	return nim_num(x - x / k - 1, k);
}
int main() {
	int n;
	std::cin >> n;
	int res{ 0 };
	{
		int a, k;
		for (auto i = 0; i < n; ++i) {
			std::cin >> a >> k;
			res ^= nim_num(a, k);
		}
	}
	std::cout << (res != 0 ? "Takahashi" : "Aoki") << std::endl;
}