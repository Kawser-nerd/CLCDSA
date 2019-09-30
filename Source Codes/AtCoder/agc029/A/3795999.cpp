#include<iostream>
#include<string>

using ull = unsigned long long;

int main() {
	std::string s;
	std::cin >> s;

	ull op_count{}, b_count{};

	for (const auto&e : s) {
		if (e == 'B')
			b_count += 1;
		else
			op_count += b_count;

	}
	std::cout << op_count << "\n";

	return 0;
}