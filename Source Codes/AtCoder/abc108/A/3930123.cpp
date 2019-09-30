#include <iostream>
using namespace std;

int main() {
	int k, a, b;

	std::cin >> k;
	a = k / 2;
	b = k - a;

	std::cout << a * b << std::endl;

	return 0;
}