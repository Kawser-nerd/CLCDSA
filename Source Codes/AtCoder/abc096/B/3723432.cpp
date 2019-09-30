#include<iostream>
#include<algorithm>
#include<cmath>


int main() {
	int a, b, c,i;
	std::cin >> a >> b >> c >> i;

	auto m = std::max({ a,b,c });
	auto sum = a + b + c - m;

	sum += static_cast<int>(std::pow(2, i)*m);
	std::cout << sum << "\n";
	return 0;
}