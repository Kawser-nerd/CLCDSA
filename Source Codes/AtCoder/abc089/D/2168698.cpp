#include <iostream>
#include <vector>
struct Point {
	int x{ 0 }, y{ 0 };
	Point() {}
	Point(int a, int b) :x{ a }, y{ b } {}
	int manhattan(Point other) const {
		return std::abs(x - other.x) + std::abs(y - other.y);
	}
};
template<typename T>
class TwoD_vec {
	std::vector<std::vector<T>> vec;
public:
	TwoD_vec(int h, int w) :vec( h, std::vector<T>(w) ) {};
	int height() const {
		return vec.size();
	}
	int width() const {
		return vec.begin()->size();
	}
	T &operator[](Point p) {
		return vec[p.x][p.y];
	}
	const T&operator[](Point p) const {
		return vec[p.x][p.y];
	}
};
class Point_to_num {
	TwoD_vec<int> vec;
	Point_to_num(int h, int w) :vec( h, w ) {}
public:
	static Point_to_num read(int h, int w, std::istream &is) {
		auto res = Point_to_num(h, w);
		for (auto i = 0; i < h; ++i) {
			for (auto j = 0; j < w; ++j) {
				std::cin >> res[Point{ i, j }];
			}
		}
		return res;
	}
	int &operator[](Point p) {
		return vec[p];
	}
	const int operator[](Point p) const {
		return vec[p];
	}
	int height() const {
		return vec.height();
	}
	int width() const {
		return vec.width();
	}
};
class Num_to_Point {
	std::vector<Point> vec;
public:
	Num_to_Point(int h, int w) :vec( h * w + 1 ) {}
	void accumlate(const Point_to_num &pn) {
		for (auto i = 0; i < pn.height(); ++i)
			for (auto j = 0; j < pn.width(); ++j)
				vec[pn[{i, j}]] = (Point(i, j));
	}
	const Point &operator[](int a) const {
		return vec[a];
	}
};

int main() {
	int h, w, d;
	std::cin >> h >> w >> d;
	auto points = Point_to_num::read(h, w, std::cin);
	auto num_to_point = Num_to_Point(h, w);
	num_to_point.accumlate(points);
	std::vector<int> distances(h * w + 1, 0);
	for (int i = distances.size() - d - 1; i >= 0; --i) {
		distances[i] = num_to_point[i].manhattan(num_to_point[i + d]) + distances[i + d];
	}
	int q, l, r;
	std::cin >> q;
	for (auto i = 0; i < q; ++i) {
		std::cin >> l >> r;
		std::cout << distances[l] - distances[r] << std::endl;
	}
}