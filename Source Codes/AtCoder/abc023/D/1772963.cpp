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

auto& in = std::cin;
auto& out = std::cout;

int32_t N;
int64_t H[100000];
int64_t S[100000];
int32_t V[100000];

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

	in >> N;
	for (int32_t i = 0; i < N; i++)
	{
		in >> H[i] >> S[i];
	}


	using BS_INT = int64_t;
	BS_INT ok_range = 1000000000100000000, ng_range = -1;
	while (std::abs(ok_range - ng_range) > 1) {
		BS_INT mid = (ok_range + ng_range) / 2;
		bool is_ok = false;
		is_ok = true;
		//mid???????

		//?????
		fill_all(V, 0);
		for (int32_t i = 0; i < N; i++)
		{
			auto pass = (mid - H[i]) / S[i];
			if ((mid - H[i]) < 0) { is_ok = false; break; }
			V[std::min<int64_t>(pass, N - 1)]++;
		}
		int32_t tmp = 0;
		for (int32_t i = 0; i < N; i++)
		{
			tmp += V[i];
			if (tmp > i + 1) {
				is_ok = false;
			}
		}

		if (is_ok) {
			ok_range = mid;
		}
		else {
			ng_range = mid;
		}
	}
	out << ok_range << endl;

	return 0;
}
#endif