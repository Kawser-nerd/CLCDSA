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
int32_t a[100000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> a[i];
	}
	std::sort(a, a + N);

	if (a[0] + 1 < a[N - 1]) {
		std::cout << "No" << endl; return 0;
	}
	if (a[N-2] != a[N - 1]) {
		std::cout << "No" << endl; return 0;
	}
	if (a[0] == N - 1) {
		std::cout << "Yes" << endl; return 0;
	}

	auto iter = std::lower_bound(a, a + N, a[N - 1]);
	auto small_num = iter - a;
	auto big_num = (a + N) - iter;
	//if (a[0] <= (small_num - 1) + big_num / 2) {
	if (a[N-1] <= small_num + big_num / 2 && small_num+1 <= a[N - 1]) {
		std::cout << "Yes" << endl; return 0;
	}
	else{
		std::cout << "No" << endl; return 0;
	}
}
#endif