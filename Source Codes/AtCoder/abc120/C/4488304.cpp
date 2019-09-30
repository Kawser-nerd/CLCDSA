#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {

	std::string s;
	std::cin >> s;

	decltype(s.size()) zeros = std::count(s.begin(), s.end(), '0');


	std::cout << 2*std::min(zeros, s.size() - zeros) << "\n";
/*  
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
*/
	return 0;
}