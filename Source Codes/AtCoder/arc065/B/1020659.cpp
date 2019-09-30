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

#define in std::cin
#define out std::cout


#include <vector>

class union_find
{
private:
	std::array<int, 200000>parent;
	//std::array<std::vector<int>, 200000>set;
	std::array<int, 200000>rank;
public:
	union_find()
	{}
	union_find(int siz)
	{
		init(siz);
	}
	void init(int siz)
	{
		rank.fill(0);
		for (int i = 0; i < siz; ++i)
		{
			parent[i] = i;
			//set[i].push_back(i);
		}
	}
	void unite(int x, int y)
	{
		int xr = find(x);
		int yr = find(y);
		if (rank[xr] > rank[yr])
		{
			parent[yr] = xr;
			//set[xr].insert(set[xr].end(), set[yr].begin(), set[yr].end());
			//set[yr].clear();
		}
		else if (rank[xr] > rank[yr])
		{
			parent[xr] = yr;
			//set[yr].insert(set[yr].end(), set[xr].begin(), set[xr].end());
			//set[xr].clear();
		}
		else if (xr != yr)
		{
			parent[yr] = xr;
			//set[xr].insert(set[xr].end(), set[yr].begin(), set[yr].end());
			//set[yr].clear();
			++rank[xr];
		}
	}
	int find(int x)
	{
		if (parent[x] == x)
		{
			return x;
		}
		else
		{
			return parent[x] = find(parent[x]);
		}
	}
	bool is_same(int x, int y)
	{
		return find(x) == find(y);
	}
	//int size(int x) {
	//	return set[find(x)].size();
	//}
	//void sort() {
	//	for (auto& i : set)
	//	{
	//		std::sort(i.begin(), i.end());
	//	}
	//}
	//auto& get_set(int x) {
	//	return set[find(x)];
	//}
};



int32_t N;
union_find load, train, both;
class increment_iterator
	: public std::iterator<std::output_iterator_tag, int> {
	int* x_;
	int temp;
public:
	increment_iterator(int& x) : x_(&x) {}

	increment_iterator& operator++()
	{
		++*x_;
		return *this;
	}

	increment_iterator operator++(int)
	{
		int tmp = *x_;
		++*x_;
		return increment_iterator(tmp);
	}

	int& operator*()
	{
		return temp;
	}
	int size() { return *x_; }
};
std::unordered_map<uint64_t,int32_t> CASH;
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	load.init(N);
	train.init(N);
	//both.init(N);
	int32_t K, L;
	in >> K>>L;
	for (int i = 0; i < K; ++i)
	{
		int p, q;
		in >> p >> q; --p;--q;
		load.unite(p, q);
	}
	//load.sort();
	for (int i = 0; i < L; ++i)
	{
		int p, q;
		in >> p >> q; --p;--q;
		train.unite(p, q);
	}
	//train.sort();
	//for (int i = 0; i < N; ++i)
	//{
	//	auto v1 = load.find(i);
	//	auto v2 = train.find(i);
	//	auto& c = CASH[((uint64_t)(v1)<<32)| (uint64_t)(v2)];
	//	if (0 < c){
	//		out << c << endl;
	//	}
	//	else {
	//		int size = 0;
	//		increment_iterator intersection(size);
	//		//std::vector<int> intersection;
	//		auto& set1 = load.get_set(v1);
	//		auto& set2 = train.get_set(v2);
	//		set_intersection(set1.begin(), set1.end()
	//			, set2.begin(), set2.end()
	//		//	, inserter(intersection, intersection.end()));
	//		, intersection);
	//		//out << (c = intersection.size()) << endl;
	//		out << (c = size) << endl;
	//	}
	//}

	for (int i = 0; i < N; ++i)
	{
		auto v1 = load.find(i);
		auto v2 = train.find(i);
		auto& c = CASH[((uint64_t)(v1)<<32)| (uint64_t)(v2)];
		++c;
	}
	for (int i = 0; i < N; ++i)
	{
		auto v1 = load.find(i);
		auto v2 = train.find(i);
		auto& c = CASH[((uint64_t)(v1)<<32)| (uint64_t)(v2)];
		out << c << endl;
	}

	return 0;
}
#endif