#include <iostream>

int main () {
	int A, B, C, X;
	int count = 0;
	std::cin >> A >> B >> C >> X;
	for (int a = 0; a <= A; a++) {
		for (int b = 0; b <= B; b++) {
			for (int c = 0; c <= C; c++) {
				if (a * 500 + b * 100 + c * 50 == X) count++;
			}
		}
	}
	std::cout << count << std::endl;
	return 0;
}