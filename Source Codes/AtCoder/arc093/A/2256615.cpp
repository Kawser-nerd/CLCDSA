#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n + 2, 0);
	for (auto i = 1; i <= n; ++i) {
		std::cin >> vec[i];
	}
	int sum{ 0 };
	for (int i = 1; i < vec.size(); ++i) {
		sum += std::abs(vec[i] - vec[i - 1]);
	}
	for (auto i = 1; i <= n; ++i) {
		std::cout << sum - std::abs(vec[i] - vec[i - 1]) - std::abs(vec[i] - vec[i + 1]) + std::abs(vec[i - 1] - vec[i + 1]) << '\n';
	}
}