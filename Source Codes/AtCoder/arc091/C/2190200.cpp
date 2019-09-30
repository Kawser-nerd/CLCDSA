#include <iostream>
#include <vector>
#include <string>
bool fill_with(std::vector<int> &vec, int start, int a, int b, int upper , int lower) {
	//std::cout << start << "," << a << " => " << upper << "," << b << " => " << lower << std::endl;
	if (a <= 0) return start == vec.size();
	if (vec.size() - start < a) a = vec.size() - start;
	for (auto i = 0; i < a && start < vec.size(); ++i) {
		vec[start++] = upper - a + i + 1;
	}
	if (b <= 0) return start == vec.size();
	if (vec.size() - start < b) b = vec.size() - start;
	for (auto i = 0; i < b && start < vec.size(); ++i) {
		vec[start++] = lower + b - i - 1;
	}
	return fill_with(vec, start, a - 1, b - 1, upper - a, lower + b);
}
int main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if (n < a + b - 1) std::cout << -1 << std::endl;
	else {
		std::vector<int> series(n);
		if (fill_with(series, 0, a, b - 1, n, 1)) {
			for (auto i = 0; i < n - 1; ++i) {
				std::cout << series[i] << ' ';
			}
			std::cout << series[n - 1] << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}
	}
}