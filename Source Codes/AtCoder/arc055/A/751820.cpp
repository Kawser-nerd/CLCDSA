#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
using namespace std;
#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)

int main()
{
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	//std::pow<uintmax_t>(10, N) + 7;

	cout << '1';
	for (size_t i = 0; i < N-1; ++i)
	{
		cout << '0';
	}
	cout << '7' << endl;
}