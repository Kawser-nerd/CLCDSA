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
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N,M;
int32_t A[100000];
std::pair<int, int> oper[100000];


#include <vector>

class union_find
{
private:
	std::vector<int>parent;
	std::vector<int>rank;
public:
	union_find(int siz)
	{
		parent.resize(siz);
		rank.resize(siz);
		for (int i = 0; i < siz; ++i)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	void unite(int x, int y)
	{
		int xr = find(x);
		int yr = find(y);
		if (rank[xr] > rank[yr])
		{
			parent[yr] = xr;
		}
		else if (rank[xr] > rank[yr])
		{
			parent[xr] = yr;
		}
		else if (xr != yr)
		{
			parent[yr] = xr;
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
	bool check(int x, int y)
	{
		return find(x) == find(y);
	}
};

bool used[100000];
std::unordered_set<int> member[100000];
std::unordered_set<int> pos[100000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>M;
	for (int32_t i = 0; i < N; i++)
	{
		in >> A[i]; --A[i];
	}
	union_find uniT(N);
	for (int32_t i = 0; i < M; i++)
	{
		in >> oper[i].first >> oper[i].second; --oper[i].first; --oper[i].second;
		uniT.unite(oper[i].first, oper[i].second);
	}

	for (int32_t i = 0; i < N; i++)
	{
		member[uniT.find(i)].insert(A[i]);
		pos[uniT.find(i)].insert(i);
		//member[uniT.find(oper[i].first)].insert(A[oper[i].first]);
		//pos[uniT.find(oper[i].first)].insert(oper[i].first);
		//member[uniT.find(oper[i].second)].insert(A[oper[i].second]);
		//pos[uniT.find(oper[i].second)].insert(oper[i].second);
	}

	int32_t res = 0;
	for (int32_t i = 0; i < N; i++)
	{
		for (auto& V : member[i]) {
			if (pos[i].count(V) > 0) {
				++res;
			}
		}
	}
	out << res << endl;

	return 0;
}
#endif