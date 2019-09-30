#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N;

namespace vec2d
{
	const double EPS = 1e-10;
	// ?????????????
	inline double add(double a, double b) {
		if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0.0;
		return a + b;
	}
	inline int32_t add(int32_t a, int32_t b) {
		return a + b;
	}
	// ??????????
	template<typename T>
	struct Pos {
		T x, y;
		Pos() {}
		Pos(const T& x, const T& y) : x(x), y(y) {}

		Pos& operator + () { return *this; }
		const Pos& operator + ()const { return *this; }
		Pos operator - ()const { return Pos(-x,-y); }

		Pos operator + (const Pos& p)const { return Pos(add(x, p.x), add(y, p.y)); }
		Pos operator - (const Pos& p)const { return Pos(add(x, -p.x), add(y, -p.y)); }
		Pos operator * (const T& d)const { return Pos(x * d, y * d); }
		Pos& operator += (const Pos& p) { x = add(x, p.x); y = add(y, p.y); return *this; }
		Pos& operator -= (const Pos& p) { x = add(x, -p.x); y = add(y, -p.y); return *this; }
		Pos& operator *= (const T& d) { x *= d; y *= d; return *this; }

		//??????
		T abs2()const { return x*x+y*y; }
		// ??
		T dot(Pos p)const { return add(x * p.x, y * p.y); }
		// ??
		T det(Pos p)const { return add(x * p.y, -y * p.x); }
		//??
		Pos normal()const { return Pos(-y, x); }
		//???
		Pos<double> normalization()const { double len = std::sqrt(abs2()); return Pos<double>(x/len, y/len); }
	};
	template<typename T>
	// ??p1-p2???q??????
	bool on_seg(const Pos<T>& p1, const Pos<T>& p2, const Pos<T>& q) {
		return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
	}
	template<typename T>
	// ??p1-p2???q1-q2???
	Pos<T> intersection(const Pos<T>& p1, const Pos<T>& p2, const Pos<T>& q1, const Pos<T>& q2) {
		return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
	}

	template<typename T>
	bool operator<(const Pos<T>& p, const Pos<T>& q) {
		if (p.x != q.x) { return p.x < q.x; }
		return p.y < q.y;
	}
}
namespace convex_hull
{
	using TYPE = double;
	using P = vec2d::Pos<TYPE>;
	// ??????
	//O(n log n)
	//?????????????(???)?
	std::vector<int32_t> convex_hull(std::pair<P,int32_t> ps[], int32_t n) {
		std::sort(ps, ps + n);
		int32_t k = 0; // ??????
		std::vector<int32_t> qs(n*2); // ??????
		// ???????
		for (int i = 0; i < n; i++) {
			while (k >= 2 && (ps[qs[k - 1]].first - ps[qs[k - 2]].first).det(ps[i].first - ps[qs[k - 1]].first) <= 0) k--;
			qs[k++] = i;
		}
		// ???????//?0?n-1??????????
		for (int i = n - 2, t = k; i >= 0; i--) {
			while (k > t && (ps[qs[k - 1]].first - ps[qs[k - 2]].first).det(ps[i].first - ps[qs[k - 1]].first) <= 0) k--;
			qs[k++] = i;
		}
		qs.resize(k - 1);//0??????
		return std::move(qs);
	}
}

std::pair<vec2d::Pos<double>, int32_t> v[100];
double result[100] = {};
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);
	
	in >> N;
	for (int32_t i = 0; i < N; i++)
	{
		in >> v[i].first.x >> v[i].first.y;
		v[i].second = i;
	}
	auto hull = convex_hull::convex_hull(v, N);

	for (int32_t i = 0; i < hull.size(); i++)
	{
		//auto tmp = v[hull[(i + 1)% hull.size()]].first - v[hull[i]].first;
		//double angle = -atan2(tmp.y, tmp.x);
		//tmp = v[hull[(i - 1+ hull.size())% hull.size()]].first - v[hull[i]].first;
		//angle += atan2(tmp.y, tmp.x);
		//angle = std::abs(angle);
		//if (angle > PI) { angle = 2 * PI - angle; }

		//double centerangle = 2*PI - angle;
		//result[v[hull[i]].second] = centerangle / (2 * PI);

		auto v1 = v[hull[(i + 1)% hull.size()]].first - v[hull[i]].first;
		auto v2 = v[hull[(i - 1 + hull.size()) % hull.size()]].first - v[hull[i]].first;
		double angle = atan2(v1.det(v2), v1.dot(v2));
		angle = std::abs(angle);
		if (angle > PI) { angle = 2 * PI - angle; }

		double centerangle = PI - angle;
		result[v[hull[i]].second] = centerangle / (2 * PI);
	}

	for (size_t i = 0; i < N; i++)
	{
		out
			<< std::fixed << std::setprecision(9)
			<< result[i] << endl;
	}

	return 0;
}
#endif