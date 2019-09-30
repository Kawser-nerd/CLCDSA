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

bool used[2001];
int32_t N,K,Q;
int32_t A[2000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>K>>Q;
	for (int32_t i = 0; i < N; i++)
	{
		in >> A[i];
	}

	int32_t res = 1000000000 + 1;
	for (int32_t MIN_INDEX = 0; MIN_INDEX < N; MIN_INDEX++)
	{
		auto min = A[MIN_INDEX];



		using BS_INT = int32_t;
		BS_INT ok_range = 1000000000 + 1, ng_range = -1;
		while (std::abs(ok_range - ng_range) > 1) {
			BS_INT mid = (ok_range + ng_range) / 2;
			BS_INT max = min + mid;//[]
			bool is_ok = false;

			//?????
			auto iter_used = 0;
			int useable = 0;
			int unuseable = 0;
			int32_t deleted_useable = 0;
			int32_t count = 0;
			for (int32_t i = 0; i < N; i++)
			{
				if (A[i] < min) { unuseable++; }
				if (min<=A[i]&&A[i] <= max) { useable++; }
				if (i < K-1) { continue; }


				if (unuseable <= 0&& useable>0) {
					++count;
					--useable;
					++deleted_useable;
				}
				else {
					while (iter_used < N) {
						auto a = A[iter_used];
						if (min <= a && a <= max) { 
							if (deleted_useable > 0) { --deleted_useable;++iter_used; continue; }
							--useable;
						}
						if (a < min) {
							--unuseable;
						}
						++iter_used;
						break;
					}
				}
			}

			is_ok = count >= Q;
			if (is_ok) {
				ok_range = mid;
			}
			else {
				ng_range = mid;
			}
		}

		res = std::min(ok_range, res);
	}
	out << res << endl;

	return 0;
}
#endif