#include<iostream>
#include<string>
#include<algorithm>

int main() {
	std::string s;
	unsigned int k;
	std::cin >> s >> k;

	if (s.size() >= k) {
		auto all_one = std::all_of(std::begin(s), std::begin(s) + k, [](auto&c) {return c == '1'; });
		if (all_one) {
			std::cout << 1 << "\n";
			return 0;
		}
	}
		
	auto it = std::find_if(std::begin(s), std::end(s), [](auto&c) {return c != '1'; });
	std::cout << *it << "\n";
	return 0;

}