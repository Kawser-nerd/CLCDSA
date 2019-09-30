#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>
#include<algorithm>

using sll = signed long long;
using bs = std::bitset<16>;

auto f(sll a)->sll {
	if (a < 0)
		return 0;

	auto m4 = a % 4;

	auto ans = a - m4;
	for (sll i{ ans + 1 }; i <= a; ++i)
		ans ^= i;
	return ans;
}

int main() {

	sll A, B;
	std::cin >> A >> B;

	std::cout << ( f(B)^f(A-1) ) << "\n";

	return 0;
}