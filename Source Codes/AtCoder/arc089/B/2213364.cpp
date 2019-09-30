#include <iostream>
#include <vector>
#include <stack>
#include <string>
class IMos {
	std::vector<std::vector<int>> vec;
	bool is_ready{ false };
public:
	IMos(int height, int width) :vec( height, std::vector<int>(width, 0) ) {}
	void fill(int left, int right, int top, int bottom) {
		if (is_ready) throw "mathod IMos::fill called after IMos::ready called";
		++vec[bottom][left];
		if (top + 1 < vec.size()) --vec[top + 1][left];
		if (right + 1 < vec[0].size()) --vec[bottom][right + 1];
		if (top + 1 < vec.size() && right + 1 < vec[0].size()) ++vec[top + 1][right + 1];
	}
	void ready() {
		for (auto i = 0; i < vec.size(); ++i) {
			for (auto j = 1; j < vec[0].size(); ++j) {
				vec[i][j] += vec[i][j - 1];
			}
		}
		for (auto j = 0; j < vec[0].size(); ++j) {
			for (auto i = 1; i < vec.size(); ++i) {
				vec[i][j] += vec[i - 1][j];
			}
		}
		is_ready = true;
	}
	const std::vector<int> &operator[](int x) const {
		if (!is_ready) throw "method IMos::operator[] called before IMos::ready called";
		return vec[x];
	}
	int height() const { return vec.size(); }
	int width() const { return vec[0].size(); }
};
enum class Color {
	Black, White
};
void fill(int x, int y, Color color, int k, IMos &black, IMos &white) {
	auto mod_x = x % k;
	auto mod_y = y % k;
	auto is_same_color = (x / k + y / k) % 2 == 0;
	if ((color == Color::White && is_same_color) || (color == Color::Black && !is_same_color)) {
		white.fill(0, mod_x, mod_y, 0);
		if (mod_x + 1< k && mod_y + 1< k) white.fill(mod_x + 1, k - 1, k - 1, mod_y + 1);
		if (mod_x + 1< k) black.fill(mod_x + 1, k - 1, mod_y, 0);
		if (mod_y + 1< k) black.fill(0, mod_x, k - 1, mod_y + 1);
	}
	else {
		black.fill(0, mod_x, mod_y, 0);
		if (mod_x + 1< k && mod_y + 1< k) black.fill(mod_x + 1, k - 1, k - 1, mod_y + 1);
		if (mod_x + 1< k) white.fill(mod_x + 1, k - 1, mod_y, 0);
		if (mod_y + 1< k) white.fill(0, mod_x, k - 1, mod_y + 1);
	}
}

int main() {
	int n, k;
	std::cin >> n >> k;
	IMos white(k, k), black(k, k);
	{
		int x, y;
		std::string c;
		for (auto i = 0; i < n; ++i) {
			std::cin >> x >> y >> c;
			if (c == "W") {
				fill(x, y, Color::White, k, black, white);
			}
			else {
				fill(x, y, Color::Black, k, black, white);
			}
		}
	}
	black.ready(); white.ready();
	int max{ 0 };
	for (auto i = 0; i < k; ++i) {
		for (auto j = 0; j < k; ++j) {
			if (black[i][j] > max) max = black[i][j];
			if (white[i][j] > max) max = white[i][j];
		}
	}
	std::cout << max << std::endl;
}