#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, a[123];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	std::cout << a[n-1] - a[0];
}