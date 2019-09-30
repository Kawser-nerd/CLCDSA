#include <iostream>

int main () {
	int input, minimum, count, num, N;
	minimum = 1e+5;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		count = 0;
		std::cin >> num;
		while (num > 0) {
			if (num % 2 == 0) {
				count++;
				num /= 2;
			} else {
				break;
			}
		}
		minimum = std::min(minimum, count);
	}
	std::cout << minimum << std::endl;
	return 0;
}