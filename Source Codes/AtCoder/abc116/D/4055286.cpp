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

int64_t N, K;
std::pair<int64_t, int> A[100000];
std::pair<int64_t, int>* maxt[100000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N >> K;
	for (size_t i = 0; i < N; i++)
	{
		in >> A[i].second >> A[i].first;
	}
	std::sort(A, A + N, std::greater<>{});

	for (auto& i : A)
	{
		if (maxt[i.second] == nullptr) {
			maxt[i.second] = &i;
		}
	}

	int64_t max = 0;
	int64_t res = 0;
	int64_t count = 0;
	std::stack<int64_t> mul;
	size_t i = 0;
	for (; i < K; i++)
	{
		if (&A[i] != maxt[A[i].second]) {
			mul.push(A[i].first);
		}
		else {
			++count;
		}
		res += A[i].first;
	}
	max = res + count * count;

	while (!mul.empty() && i < N)
	{
		if (&A[i] != maxt[A[i].second]) {
			++i;
			continue;
		}

		res -= mul.top(); mul.pop();
		res += A[i].first;
		++count;

		max = std::max(max, res + count * count);
		++i;
	}
	out << max << endl;

	return 0;
}
#endif