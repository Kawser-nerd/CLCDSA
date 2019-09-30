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

int64_t gcd(int64_t a, int64_t b)
{
	while (b > 0)
	{
		auto c = b;
		b = a % b;
		a = c;
	}
	return a;
}
int a[100000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);
	

	int n,k;
	in >> n>>k;
	for (int i = 0; i < n; i++)
	{
		in >> a[i];
	}
	int64_t g = a[0];
	for (int i = 0; i < n; i++)
	{
		g = gcd(g, a[i]);
	}
	if (k%g || *std::max_element(a,a+n)< k) {
		out << "IM";
	}
	out << "POSSIBLE" << endl;

	return 0;
}
#endif