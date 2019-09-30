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
char str[100010];
int32_t countA_bace_[100010];
int32_t countA_to_[100010];
auto countA_bace = countA_bace_+5;
auto countA_to = countA_to_+5;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> str;
	countA_bace[0] = (str[0]=='A'?1:0);
	auto c_iter = countA_bace + 1;
	for (auto iter = str+1; *iter != '\0'; ++iter) {
		*c_iter = c_iter[-1] + (*iter == 'A' ? 1 : 0);
		++c_iter;
	}
	*c_iter = c_iter[-1];
	in >> str;
	countA_to[0] = (str[0] == 'A' ? 1 : 0);
	c_iter = countA_to + 1;
	for (auto iter = str + 1; *iter != '\0'; ++iter) {
		*c_iter = c_iter[-1] + (*iter == 'A' ? 1 : 0);
		++c_iter;
	}
	*c_iter = c_iter[-1];

	int32_t Q;
	in >> Q;
	for (int32_t i = 0; i < Q; ++i)
	{
		int a, b;
		in >> a >> b; --a;
		int32_t bace_a = countA_bace[b-1] - countA_bace[a-1];
		int32_t bace_b = (b-a) - bace_a;
		in >> a >> b; --a;
		int32_t to_a = countA_to[b-1] - countA_to[a-1];
		int32_t to_b = (b - a) - to_a;

		int32_t need_a = to_a - bace_a;
		int32_t need_b = to_b - bace_b;
		need_a %= 3; need_b %= 3;
		need_a += 9; need_b += 9;
		need_a %= 3; need_b %= 3;
		if (need_a == need_b) {
			out << "YES" << endl;
		}
		else {
			out << "NO" << endl;
		}
	}

	return 0;
}
#endif