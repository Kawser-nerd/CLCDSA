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

#define in std::cin
#define out std::cout

int kind, station;

const int MAX_STATION = 300000+1;
// ????????????????
int n;
int BIT[MAX_STATION + 1];
void init(int n_param) {
	n = 1;
	while (n < n_param) {
		n <<= 1;
	}
}
void add(int index, int value)
{
	++index;
	while (index <= n) {
		BIT[index] += value;
		index += (index & -index);
	}
}
int sum(int index)
{
	int value = 0;
	++index;
	while (index > 0) {
		value += BIT[index];
		index -= (index & -index);
	}
	return value;
}


int kind_in[MAX_STATION];
std::vector<int> kind_out[MAX_STATION +1];
std::vector<int> tr_on[MAX_STATION +1];
int count[MAX_STATION +1];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> kind>>station;
	init(station);


	//????
	for (int i = 0; i < kind; ++i)
	{
		int l, r;
		in >> l >> r;
		++kind_in[l];
		kind_out[r].push_back(l);
	}
	//????
	for (int i = 1; i <= station; ++i)
	{
		for (int p = i; p <= station; p += i)
		{
			tr_on[p].push_back(i);
		}
	}

	for (int i = 1; i <= station; ++i)
	{
#ifdef _DEBUG
		std::cout << "--------------------" << '\n';
		std::cout << kind_in[i] << '\n';
		for (auto p : tr_on[i]) { std::cout << p << ' '; }std::cout << '\n';
		for (auto p : kind_out[i]) { std::cout << p << ' '; }std::cout << '\n';
		std::cout << "--------------------" << '\n';
#endif
		add(i-1, kind_in[i]);
#ifdef _DEBUG
		std::cout << "--------------------" << '\n';
		for (int p = 1; p <= station; ++p) { std::cout << sum(p-1) << ' '; }std::cout << '\n';
		std::cout << "--------------------" << '\n';
#endif
		for (auto p : tr_on[i]) {
			if (i - p > 0) { count[p] -= sum(i - p - 1); }
			count[p] += sum(i-1);
		}
		for (auto p : kind_out[i]) {
			add(p-1, -1);
		}
	}

	for (int p = 1; p <= station; ++p)
	{
		std::cout << count[p] << std::endl;
	}

	return 0;
}
#endif