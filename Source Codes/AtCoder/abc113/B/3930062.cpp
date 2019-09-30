#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int i;
	int n, t, a;
	double num, min = 100000, idx;
	
	std::cin >> n >> t >> a;

	for (i = 0; i < n; i++) {
		std::cin >> num;
		num = abs(a - (t - num * 0.006));
		if (min > num) {
			min = num;
			idx = i;
		}
	}
	std::cout << idx+1 << std::endl;

	return 0;
}