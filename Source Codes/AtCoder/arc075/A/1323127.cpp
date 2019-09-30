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

auto& in = std::cin;
auto& out = std::cout;

int32_t N;
int32_t s[100];
int32_t dp[100][10001];

template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}

int32_t func(int i, int now)
{
	if (i >= N) {
		return (now % 10) ? now : 0;
	}
	auto& memo = dp[i][now];
	if (memo!=-1) { return memo; }
	return memo=std::max(func(i + 1, now), func(i + 1, now + s[i]));
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	fill_all(dp, -1);
	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> s[i];
	}
	out << func(0, 0) << endl;;

	return 0;
}
#endif


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

auto& in = std::cin;
auto& out = std::cout;

int32_t N,Q;
std::vector<int32_t> parent[100000];
std::vector<int32_t> child[100000];
int32_t V[100000];
void add(int32_t i, int32_t d, int32_t v)
{
	V[i] += v;
	if (d > 0) {
		for (auto& c : child[i]) {
			add(c, d - 1, v);
		}
	}
}
int64_t sum(int32_t i, int32_t d)
{
	int64_t res = V[i];
	if (d > 0) {
		for (auto& c : child[i]) {
			res += sum(c, d - 1);
		}
	}
	return res;
}
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>Q;
	if ((int64_t)(N*Q)>1000000000) {
		return 0;
	}
	for (int32_t i = 0; i < N; ++i)
	{
		int p, v;
		in >> p >> V[i];
		if (p != -1) { parent[i].push_back(p); child[p].push_back(i); }
	}
	for (int32_t loop = 0; loop < Q; ++loop)
	{
		int type;
		in >> type;
		if (type == 1) {
			int p, d, v;
			in >> p >> d >> v;
			add(p, d, v);
		}
		else if (type == 2) {
			int p, d;
			in >> p >> d;
#ifdef _DEBUG
			out << "OUTPUT:";
#endif
			out << sum(p, d) << endl;
		}
		else if (type == 3) {
			int p;
			in >> p >> V[N];
			if (p != -1) { parent[N].push_back(p); child[p].push_back(N); }
			++N;
		}
	}

	return 0;
}
#endif


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

auto& in = std::cin;
auto& out = std::cout;

int32_t ask(const std::string& s) {
#ifdef _DEBUG
#endif
	int32_t t;
	out << "? " << s << std::endl;
	in >> t;
	return t;
}

constexpr int32_t N = 200;//???
std::vector<int32_t> graph[N];//?
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	int32_t t; in >> t;
	std::string s(N,'0');
	int32_t count = 0;
	for (int32_t i = 0; i < N; ++i)
	{
		s[i] = '1';
		for (int32_t j = i+1; j < N; ++j)
		{
			s[j] = '1';

			t = ask(s);
			if (t == 1) {
				graph[i].push_back(j);
				++count;
				if (count >= N-1) {
					goto res_out;
				}
			}

			s[j] = '0';
		}
		s[i] = '0';
	}
res_out:
	out << '!';
	for (int32_t i = 0; i < N; ++i)
	{
		for (auto& j : graph[i]) {
			out << " (" << i << ',' << j << ')';
		}
	}

	return 0;
}
#endif
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

auto& in = std::cin;
auto& out = std::cout;

int32_t N;

constexpr int32_t MAX_N = 300000;//???
constexpr int32_t MAX_LOGN = 30;//log2???
std::unordered_map<int32_t, double> graph[MAX_N];//?
double get(int32_t v, int32_t p) {
	auto& memo = graph[v][p];
	if (memo >= 0 && p != -1) {
		return memo;
	}
	int32_t count = 0;
	double sum = 0;
	for (auto& c : graph[v]) {
		if (c.first != p && c.first != -1) {
			++count;
			sum += get(c.first, v) + 1;
		}
	}
	if (count == 0) {
		return memo = 0;
	}
	return memo = sum / count;
}
bool CASE_HACK_MODE = true;
int32_t center1 = -1;
int32_t center2 = -1;
void input_tree()
{
	in >> N;
	for (int32_t i = 0; i < N - 1; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a][b] = -1;
		graph[b][a] = -1;
		if (center1 == -1) { center1 = a; center2 = b; }
		else {
			if (a == center1 || a == center2) {
				center1 = a;
			}
			else if (b == center1 || b == center2) {
				center1 = b;
			}
			else {
				CASE_HACK_MODE = false;
			}

			center2 = -1;
		}
	}
}


int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	out << std::fixed << std::setprecision(9);
	input_tree();
	if (!CASE_HACK_MODE)
	{
		for (int32_t i = 0; i < N; ++i)
		{
			out << get(i, -1) << endl;
		}

		return 0;
	}

	for (int32_t i = 0; i < N; ++i)
	{
		out << ((i == center1) ? 1.0 : 2.0) << endl;
	}
}
#endif