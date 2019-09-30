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

std::string STR;;
int sum[20];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> STR;
	std::reverse(all(STR));

	sum[0] = (STR[0] - '0');
	for (size_t i = 1; i < STR.size(); i++)
	{
		sum[i] = sum[i - 1] + (STR[i] - '0');
	}

	std::reverse(all(STR));
	int64_t max = sum[STR.size() - 1];
	int64_t sum2 = 0;
	for (int i = 0; i < STR.size(); i++)
	{
		sum2 += (STR[i] - '0');
		max = std::max<int64_t>(
			max,
			sum2 - 1 + int64_t(STR.size() - 1 - i) * 9
		);
	}

	out << max << endl;

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
#define all(C) std::begin(C), std::end(C)

int32_t H,W;
int32_t h, w;

std::array<std::array<char, 1010>, 1000>  map;

template<typename T, typename U>
std::enable_if_t<std::rank<T>::value == 0> fill_all(T& arr, const U& v) {
	arr = v;
}
template<typename ARR, typename U>
std::enable_if_t<std::rank<ARR>::value != 0> fill_all(ARR& arr, const U& v) {
	for (auto& i : arr) {
		fill_all(i, v);
	}
}
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> H>>W>>w>>h;

	for (auto& ARR : map) { for (auto& i : ARR) { i = '.'; } }

	if (H % 2) {
		for (int32_t i = 0;w>0 && i <= W-2; i+=2)
		{
			map[H - 1][i] = '<';
			map[H - 1][i+1] = '>';
			--w;
		}
	}
	if (W % 2) {
		for (int32_t i = 0; h>0 && i <= H - 2; i += 2)
		{
			map[i][W - 1] = '^';
			map[i + 1][W - 1] = 'v';
			--h;
		}
	}

	for (int hh = 0; hh <= H - 2; hh += 2)
		for (int ww = 0; ww <= W - 2; ww += 2)
		{
			if (h > 0) {
				map[hh][ww] = '^';
				map[hh + 1][ww] = 'v';
				--h;
				if (h == 0) {
					map[hh][ww + 1] = '.';
					map[hh + 1][ww + 1] = '.';
				}
				else {
					map[hh][ww + 1] = '^';
					map[hh + 1][ww + 1] = 'v';
					--h;
				}
			}
			else if (w > 0) {
				map[hh][ww] = '<';
				map[hh][ww + 1] = '>';
				--w;
				if (w == 0) {
					map[hh + 1][ww] = '.';
					map[hh + 1][ww + 1] = '.';
				}
				else {
					map[hh + 1][ww] = '<';
					map[hh + 1][ww + 1] = '>';
					--w;
				}
			}
			else {
				map[hh][ww] = '.';
				map[hh + 1][ww] = '.';
				map[hh][ww + 1] = '.';
				map[hh + 1][ww + 1] = '.';
			}
		}


	if (h<=0&&w<=0) {
		int32_t squ_count = (H / 2)*(W / 2);
		assert(squ_count > (h + 1) / 2 + (w + 1) / 2);
		out << "YES\n";
		for (int32_t i = 0; i < H; i++)
		{
			map[i][W] = '\0';
			out << &map[i][0]<<'\n';
		}
	}
	else {
		out << "NO\n";
	}

	return 0;
}
#endif