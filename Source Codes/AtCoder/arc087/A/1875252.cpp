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

int32_t N;
std::map<int32_t, int32_t> A;
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
		int32_t a;
		in >> a;
		A[a]++;
	}
	int32_t res = 0;
	for (auto& i : A) {
		if (i.first <= i.second) {
			res += i.second - i.first;
		}
		else {
			res += i.second;
		}
	}

	out << res << endl;
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
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;

int32_t target_x, target_y;
char S[8100];
std::vector<int32_t> move_x;
std::vector<int32_t> move_y;

std::unordered_map<int32_t,bool> dp[8000];
bool funcx(int32_t i, int32_t now)
{
	if (i == move_x.size()) { return now == target_x; }
	if (dp[i].count(now)) { return dp[i][now]; }
	return dp[i][now]=funcx(i + 1, now + move_x[i]) || funcx(i + 1, now - move_x[i]);
}
bool funcy(int32_t i, int32_t now)
{
	if (i == move_y.size()) { return now == target_y; }
	if (dp[i].count(now)) { return dp[i][now]; }
	return dp[i][now] = funcy(i + 1, now + move_y[i]) || funcy(i + 1, now - move_y[i]);
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> S>> target_x>> target_y;
	{
		auto iter_s = S;
		while (*iter_s == 'F') {
			--target_x;
			++iter_s;
		}
		bool xmode = true;
		while (*iter_s == 'T') {
			++iter_s; xmode = !xmode;
			int32_t count = 0;
			while (*iter_s == 'F') {
				++count;
				++iter_s;
			}
			if (xmode) { move_x.push_back(count); }
			else { move_y.push_back(count); }
		}
	}

	bool x = funcx(0, 0);
	for (auto& i : dp) { i.clear(); }
	if (x&&funcy(0, 0)) {
		out << "Yes\n";
	}
	else {
		out << "No\n";
	}

	return 0;
}
#endif