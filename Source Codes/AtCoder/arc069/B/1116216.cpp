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

constexpr int N_Harf = 100'000;
constexpr int N_MAX = N_Harf *2;
class union_find
{
private:
	std::array<int, N_MAX>parent;
	std::array<int, N_MAX>rank;
public:
	union_find()
	{
		//parent.resize(siz);
		//rank.resize(siz);
		for (int i = 0; i < N_MAX; ++i)
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
}uf;


int32_t N;
char s[1000000];
char res[1000000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>s;
	const char type[2] = { 'S','W' };
	for (int32_t s1 = 0; s1 <= 1; ++s1)for (int32_t s2 = 0; s2 <= 1; ++s2)
	{
		res[0] = s1;
		res[1] = s2;
		for (int32_t i = 2; i < N; ++i)
		{
			if ((s[i - 1] == 'o') == (res[i - 1] == 0)) {
				res[i] = res[i - 2];
			}
			else {
				res[i] = res[i - 2] ^ 1;
			}
		}

		bool ok = true;
		if ((s[N - 1] == 'o') == (res[N - 1] == 0)) {
			if (res[0] != res[N - 2]) { ok = false; }
		}
		else {
			if (res[0] == res[N - 2]) { ok = false; }
		}
		if ((s[0] == 'o') == (res[0] == 0)) {
			if (res[1] != res[N - 1]) { ok = false; }
		}
		else {
			if (res[1] == res[N - 1]) { ok = false; }
		}

		if (ok) {
			for (int32_t i = 0; i < N; ++i)
			{
				std::cout << type[res[i]];
			}
			std::cout << std::endl; return 0;
		}
	}
	std::cout << -1 << std::endl;

	return 0;
}
#endif