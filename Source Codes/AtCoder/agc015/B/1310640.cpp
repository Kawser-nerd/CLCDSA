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

char s[1000000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> s;
	size_t N = strlen(s);
	uint64_t count = 0;
	for (size_t i = 0; i < N; i++)
	{
		count += N-1;
		if (s[i] == 'U') {
			count += i;
		}
		else {
			count += (N-1-i);
		}
	}
	std::cout << count << std::endl;

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

auto& in = std::cin;
auto& out = std::cout;

int64_t N,MIN,MAX;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>MIN>>MAX;
	if (N == 1) { std::cout << 0 << std::endl; return 0; }
	if (MAX<MIN) { std::cout << 0 << std::endl; return 0; }
	--N;
	std::cout << ((MAX*N + MIN) - (MIN*N + MAX) + 1) << std::endl;

	return 0;
}
#endif