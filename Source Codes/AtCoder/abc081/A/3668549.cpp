#include <iostream>

int main() {
	int a;
	int ans = 0;
	std::cin >> a;
	for (int i = 0; i < 3; i++) {
		ans += a % 10;
		a /= 10;
	}
	std::cout << ans << std::endl;
	return 0;
}