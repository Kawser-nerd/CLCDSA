#include <iostream>

using namespace std;

int main() {
	int n, a, b;

	std::cin >> n;
	if (n == 1) {
		std::cout << "Hello World" << std::endl;
	}
	else {
		std::cin >> a;
		std::cin >> b;
		std::cout << a + b << std::endl;
	}
	
	return 0;
}