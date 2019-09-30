#include <iostream>
#include <vector>

class Filler {
	std::vector<std::vector<char>> vec;
	char _fill, _space;
public:
	Filler(int fill_count, char fill, char space) :_fill{ fill }, _space{ space }, vec(21, std::vector<char>(100, space)) {
		for (auto i = 0; i < 10 && fill_count != 0; ++i) {
			for (auto j = 0; j < 50 && fill_count != 0; ++j) {
				vec[i * 2 + 1][j * 2] = fill;
				--fill_count;
			}
		}
	}
	const std::vector<std::vector<char>> &to_vector() const {
		return vec;
	}
};
std::ostream &operator<<(std::ostream &os, const Filler &filler) {
	for (const auto &l : filler.to_vector()) {
		for (const auto &c : l) {
			os << c;
		}
		os << '\n';
	}
	return os;
}
int main() {
	int a, b;
	std::cin >> a >> b;
	Filler black(a - 1, '.', '#'), white(b - 1, '#', '.');
	std::cout << 42 << ' ' << 100 << std::endl;
	std::cout << black << white;
}