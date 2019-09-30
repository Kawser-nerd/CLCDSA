#include<iostream>
#include<vector>
#include<string>

int main() {

	std::string s;
	std::cin >> s;

	std::vector<char> stack_;

	stack_.reserve(s.size());

	auto count = 0;
	for (const auto&e : s) {

		if (stack_.empty()) {
			stack_.push_back(e);
			continue;
		}
			
		if (stack_.back() != e) {
			stack_.pop_back();
			count += 2;
//			continue;
		}
		else {
			stack_.push_back(e);
		}
	}

	std::cout << count << "\n";

	return 0;
}