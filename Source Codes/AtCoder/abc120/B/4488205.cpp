#include<iostream>
#include<vector>
#include<algorithm>
int main() {

	int a, b, k;
	std::cin >> a >> b >> k;

	std::vector<int> v;
	auto mv = std::min(a, b);
	for (int i{1}; i <= mv; ++i) {
		if (a%i == 0 && b%i == 0)
			v.emplace_back(i);
	}


	std::cout << *(v.rbegin() + k-1) << "\n";
	return 0;
}