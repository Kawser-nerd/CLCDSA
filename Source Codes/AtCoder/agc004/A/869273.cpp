#include<iostream>
#include<algorithm>


int main() {
	size_t a[3];
	std::cin >> a[0] >> a[1] >> a[2];
	std::sort(std::begin(a), std::end(a));
	bool f = std::count_if(std::begin(a), std::end(a), [](auto x) {
		return  x % 2 == 0;
	});
	if (f) {
		std::cout << "0\n";
	}
	else {
		std::cout<<a[0] * a[1] << "\n";
		
	}
	//std::cout << a[0] << a[2] << "\n";

	return 0;
}