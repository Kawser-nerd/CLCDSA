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

int32_t X,a,b;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> X>>a>>b;
	X -= a;
	out << X % b << endl;

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
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N;

int32_t dft_table[20][262144];
int32_t* dft(int32_t* arr, size_t size, int depth = 0)
{
	if (size == 1) {
		return arr;
	}

	auto f0 = dft_table[depth + 1];
	auto f1 = dft_table[depth + 1]+size/2;
	for (size_t i = 0; i < size/2; i++)
	{
		f0[i] = arr[2 * i + 0];
		f1[i] = arr[2 * i + 1];
	}

	dft(f0, size / 2);
	dft(f1, size / 2);

	
}
std::vector<int32_t> convolution(std::vector<int32_t>& a, std::vector<int32_t>& b)
{
	size_t s = a.size() + b.size() + 1;
	{size_t tmp = 1; for (; tmp < s; tmp <<= 1) {}
	s = tmp; }

	auto copy = [&s](const std::vector<int32_t>& arr) {
		size_t i = 0;
		for (; i < arr.size(); i++)
		{
			dft_table[0][i] = arr[i];
		}
		for (; i < s; i++)
		{
			dft_table[0][i] = 0;
		}
	};
	copy(a);
	auto a_ = dft(dft_table[0], s);
	copy(b);
	auto b_ = dft(dft_table[0], s);
	auto& ff = a_;
	for (size_t i = 0; i < s; i++)
	{
		ff[i] *= b_[i];
	}
	return inverse_dft(ff);
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;

	return 0;
}
#endif