#if 0
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

int32_t N;



int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	out << ((N % 11!=0)?"yES":"nO") << endl;
	out << ((N % 6 != 0) ? "yES" : "nO") << endl;

	return 0;
}
#endif

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

std::map<std::string, int> STOI;
std::map<int, std::string> ITOS;

std::map<int, std::vector<std::pair<int, long double>>> graph;
std::map<int, std::map<int, long double>> D;

int32_t N;

void func(int start, int now, long double cost = 1) {
	if (D[start].count(now) != 0) {
		return;
	}
	D[start][now] = cost;
	for (auto& i : graph[now]) {
		func(start, i.first, cost*i.second);
	}
}

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
		std::string a, b; long double c;
		in >> a >> c >> b;

		if (STOI.count(a) == 0) {
			auto s = STOI.size();
			STOI[a] = s;
			ITOS[s] = a;
		}
		if (STOI.count(b) == 0) {
			auto s = STOI.size();
			STOI[b] = s;
			ITOS[s] = b;
		}

		graph[STOI[b]].emplace_back(STOI[a],c);
		graph[STOI[a]].emplace_back(STOI[b], 1/c);
	}

	for (auto& s : graph)
	{
		func(s.first, s.first);
	}
	long double max = 0;
	int32_t start, end;
	for (auto& s : D)
	{
		for (auto& v : s.second) {
			if (v.second > max) {
				max = v.second;
				start = s.first;
				end = v.first;
			}
		}
	}

	out << 1 << ITOS[end] << "="
		<< (int32_t)(max+0.001) << ITOS[start] << endl;

	return 0;
}
#endif