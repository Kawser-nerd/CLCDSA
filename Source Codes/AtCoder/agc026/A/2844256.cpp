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
int32_t A[101];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	for (size_t i = 0; i < N; i++)
	{
		in >> A[i];
	}
	size_t count = 0;
	for (size_t i = 1; i < N; i++)
	{
		if (A[i - 1] == A[i]) {
			++count;
			A[i] = -1;
		}
	}
	out << count << endl;

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


// ??????Greatest Common Divisor?
uint64_t gcd(uint64_t m, uint64_t n)
{
	// ??????????
	for (;;)
	{
		if (0 == m) { return n; }
		n %= m;
		if (0 == n) { return m; }
		m %= n;
	}
}
// ??????Least Common Multiple?????
uint64_t lcm(uint64_t m, uint64_t n)
{
	if (0 == m) { return n; }
	if (0 == n) { return m; }
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

int32_t Q;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> Q;
	while (Q--)
	{
		int64_t a, b, c, d;
		in >> a >> b >> c >> d;

		if (d < b) {
			out << "No\n";
			continue;
		}
		if (a < b) {
			out << "No\n";
			continue;
		}
		if (c+1 >= b) {
			out << "Yes\n";
			continue;
		}
		a = a - (a / b)*b;
		if (d%b == 0) {
			if (a <= c) {
				out << "Yes\n";
			}
			else {
				out << "No\n";
			}
			continue;
		}

		auto diff = d % b;
		auto diff2 = gcd(b, diff);
		auto err = b-1 - c;//(b,c)
		if (err >= diff2) {
			out << "No\n";
			continue;
		}
		//(c,b)?%diff2 == a?????
		if ((c+ 1) % diff2 <= (b - 1) % diff2) {
			if ((c + 1) % diff2 <= a % diff2 && a%diff2 <= (b - 1) % diff2) {
				out << "No\n";
				continue;
			}
		}
		else {
			if ((b - 1) % diff2 <= a % diff2 || a%diff2 <= (c + 1) % diff2) {
				out << "No\n";
				continue;
			}
		}

		out << "Yes\n";

	}

	return 0;
}
#endif