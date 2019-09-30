#include <iostream>

int main() {
	long long int n, m;
	std::cin >> n >> m;
	if (n == 1) {
		if (m == 1) std::cout << 1 << std::endl;
		else std::cout << m - 2 << std::endl;
	}
	else {
		if (m == 1) std::cout << n - 2 << std::endl;
		else std::cout << (n - 2) * (m - 2) << std::endl;
	}
}