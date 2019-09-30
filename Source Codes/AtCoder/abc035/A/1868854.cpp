#include<iostream>

int main(void) {
	int W = 0, H = 0;
	std::cin >> W >> H;
	if (W * 3 == H * 4) {
		std::cout << "4:3" << std::endl;
	}
	else if (W * 9 == H * 16) {
		std::cout << "16:9" << std::endl;
	}

	return 0;
}