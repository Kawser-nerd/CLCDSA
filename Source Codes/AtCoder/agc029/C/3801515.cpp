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

int32_t N;
int32_t A[200010];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;// N = 200000;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> A[i];
		//A[i] = N - i;
	}
	{
		bool ok = true;
		for (int32_t i = 1; i < N; ++i)
		{
			if (A[i - 1] < A[i]) {

			}
			else {
				ok = false;
				break;
			}
		}
		if (ok) {
			out << 1 << endl;
			return 0;
		}
	}
	//{
	//	bool ok = true;
	//	std::unordered_set<int32_t> map;
	//	for (int32_t i = 0; i < N; ++i)
	//	{

	//		if (map.count(A[i])) {
	//			ok = false;
	//			break;
	//		}
	//		map.insert(A[i]);
	//	}
	//	if (ok) {
	//		out << 2 << endl;
	//		return 0;
	//	}
	//}

	//for (int32_t i = 0; i < N; ++i)
	//{
	//	A[i] = std::min(40, A[i]);
	//}


	using BS_INT = int32_t;
	BS_INT ok_range = N, ng_range = 1;
	while (std::abs(ok_range - ng_range) > 1) {
		BS_INT mid = (ok_range + ng_range) / 2;
		bool is_ok = true;

		//?????
		{
			//std::vector<int> now(A[0], 0);
			std::map<int, int> table;
			table[A[0]] = 0;
			for (int32_t i = 1; i < N; ++i)
			{
				if (table.rbegin()->first < A[i])
				{
					table[A[i]] = 0;
					continue;
				}
				if (table.rbegin()->first > A[i]) {
					table.erase(table.upper_bound(A[i]), table.end());
				}
				//add
				bool ok = false;
				for (int j = A[i]; j >= 1; j--)
				{
					if (table[j] == mid - 1) {
						table[j] = 0;
						continue;
					}
					ok = true;
					++table[j];
					break;
				}
				if (ok) {
					continue;
				}

				is_ok = false;
				break;
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