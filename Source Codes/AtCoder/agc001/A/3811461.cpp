#include<iostream>
#include<vector>
#include<algorithm>

using ui = unsigned int;

int main() {
	ui n;
	std::cin >> n;

	std::vector<int> v( 2*n );

	for (auto&e : v)
		std::cin >> e;

	std::sort(std::begin(v), std::end(v));
	
	/*
	for (auto&e : v)
		std::cout << e <<" ";
	std::cout << "\n";
	*/

	int sum_{};
	for (ui i{ 0 }; i < 2*n; ++++i)// {
//		std::cout << v[i] << "\n";
		sum_ += v[i];
//	}

	std::cout << sum_ << "\n";

	return 0;
}