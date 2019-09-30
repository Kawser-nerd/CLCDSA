#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

using P = pair<LL, LL>;

template <class T>
struct my_greater : std::greater<T>
{
	static constexpr T defval = std::numeric_limits<T>::min();
};

struct my_greater_P : std::greater<P>
{
	static constexpr P defval = P(std::numeric_limits<LL>::min(), std::numeric_limits<LL>::min());
};

static constexpr P defval = P(std::numeric_limits<LL>::min(), std::numeric_limits<LL>::min());


//Base class for Segment Trees
template <class T>
class segtree_base
{
protected:
	size_t width;
	vector<T> vec;
	T def;
	virtual T query_raw(int l_, int r_, int a_, int b_, int k_) = 0;
public:
	segtree_base(size_t size_, const T& def_ = T()) : def(def_)
	{
		width = 1;
		while (width < size_)width *= 2;
		vec.resize(width * 2 - 1, def);
	}
	//Ask a query in ranges [left,right)
	T query(int left, int right)
	{
		return query_raw(left, right, 0, width, 0);
	}
	//Get the number of child nodes
	size_t treeWidth()
	{
		return width;
	}
	virtual ~segtree_base() {}
};

//Range Minimum Tree
template <class T, class Comp>
class rmq_tree : public segtree_base<T>
{
public:
	rmq_tree(size_t size_) : segtree_base<T>(size_, defval)
	{}

	//Do [] <= base
	void init(const vector<T>&base)
	{
		for (int i = 0; i < min(this->width, base.size()); i++) this->vec[i + this->width - 1] = base[i];
		for (int i = this->width - 2; i >= 0; i--) this->vec[i] = std::min(this->vec[i * 2 + 1], this->vec[i * 2 + 2], Comp());
	}

	//Make [index] <= val;
	void update(int index, T val)
	{
		auto &vec = this->vec;
		index += (this->width - 1);
		vec[index] = val;
		while (index > 0)
		{
			index = (index - 1) / 2;
			vec[index] = std::min(vec[index * 2 + 1], vec[index * 2 + 2], Comp());
		}
	}
private:
	T query_raw(int l_, int r_, int a_, int b_, int k_)override
	{
		const auto &vec = this->vec;
		if (l_ <= a_ && b_ <= r_)
		{
			return vec[k_];
		}
		if (b_ <= l_ || r_ <= a_)
		{
			return this->def;
		}
		int m = (a_ + b_) / 2;
		return std::min(
			query_raw(l_, r_, a_, m, k_ + k_ + 1),
			query_raw(l_, r_, m, b_, k_ + k_ + 2), Comp());
	}
};




template<typename T>
class imos2d
{
private:
	std::vector<std::vector<T>>buf;
	const int lim1, lim2;
	bool convert;
	inline bool valid(int x, int y, bool wide)
	{
		return (0 <= x && 0 <= y && x < lim1 + (wide ? 1 : 0) && y < lim2 + (wide ? 1 : 0));
	}
	T rawsum(int i1, int i2)
	{
		assert(valid(i1, i2, true));
		return buf[i1][i2];
	}
public:
	//????????????
	imos2d(size_t width, size_t height) :
		lim1(width), lim2(height),
		convert(false)
	{
		buf.resize(width + 1, std::vector<T>(height + 1));
	}
	//???????????(splat?????)
	void mark(int first, int second, T value)
	{
		assert(!convert);
		assert(valid(first, second, false));
		buf[first + 1][second + 1] += value;
	}
	//????????????????(mark?????)
	T sumquery(int firstcor, int secondcor, int firstlen, int secondlen)
	{
		assert(convert);
		int px = firstcor, py = secondcor;
		int qx = px + firstlen, qy = py + secondlen;
		assert(valid(px, py, false) && valid(qx, qy, true));
		return rawsum(px, py) + rawsum(qx, qy) - rawsum(px, qy) - rawsum(qx, py);
	}
	//????????(mark?????)
	void splat(int firstcor, int secondcor, int firstlen, int secondlen, T value)
	{
		assert(!convert);
		int px = firstcor, py = secondcor;
		int qx = px + firstlen, qy = py + secondlen;
		assert(valid(px, py, false) && valid(qx, qy, true));
		buf[px][py] += value;
		buf[qx][qy] += value;
		buf[px][qy] -= value;
		buf[qx][py] -= value;
	}
	//????????????(splat?????)
	T depth(int first, int second)
	{
		assert(convert);
		assert(valid(first, second, false));
		return buf[first][second];
	}
	//????
	void imos()
	{
		convert = true;
		for (int i = 0; i < lim1; ++i)
		{
			for (int j = 0; j <= lim2; ++j)
			{
				buf[i + 1][j] += buf[i][j];
			}
		}
		for (int i = 0; i <= lim1; ++i)
		{
			for (int j = 0; j < lim2; ++j)
			{
				buf[i][j + 1] += buf[i][j];
			}
		}
	}
};

vector<rmq_tree<P, my_greater_P>>vec;

LL B[5678][234];

//k???????????[i,j)??????
void bury(imos2d<LL>&imos, int k, int i, int j)
{
	if (i == j)return;
	auto ret = vec[0].query(i, j);
	LL val = ret.first;
	int index = ret.second;
	int lef = i;
	int upp = index;
	int wid = index - i + 1;
	int hei = j - index;
	imos.splat(lef, upp, wid, hei, val);
	bury(imos, k, i, index);
	bury(imos, k, index + 1, j);
}


int main(void)
{
	LL N, M;
	vector<LL>dist(1, 0);
	cin >> N >> M;
	for (int i = 1; i < N; ++i)
	{
		LL a;
		cin >> a;
		dist.push_back(dist.back() + a);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> B[i][j];
		}
	}
	imos2d<LL>base(N, N);
	for (int j = 0; j < M; ++j)
	{
		vec.push_back(rmq_tree<P, my_greater_P>(N));
		auto& seg = vec.back();
		vector<P>cash;
		for (int i = 0; i < N; ++i)cash.push_back({ B[i][j],i });
		seg.init(cash);
		bury(base, j, 0, N);
		vec.pop_back();
	}

	base.imos();

	LL ans = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int l = 0; l <= r; ++l)
		{
			LL minus = dist[r] - dist[l];
			LL cue = base.depth(l, r);
			cue -= minus;
			ans = max(ans, cue);
		}
	}

	cout << ans << endl;
	return 0;
}