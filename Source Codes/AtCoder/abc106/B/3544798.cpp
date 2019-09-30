#include<iostream>

int main() {
	int n;
	std::cin >> n;

	int c = 0;
	c += 105 <= n ? 1 : 0;
	c += 135 <= n ? 1 : 0;
	c += 165 <= n ? 1 : 0;
	c += 189 <= n ? 1 : 0;
	c += 195 <= n ? 1 : 0;
	std::cout << c << "\n";
	return 0;
}