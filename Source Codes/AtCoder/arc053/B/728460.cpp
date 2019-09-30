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
#include <set>
#include <vector>
#include <chrono>
#include <random>
#include <forward_list>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	char S[100010];
	cin >> S;
	auto s_len = strlen(S);

	std::sort(S,S+ s_len);

	size_t single = 1, double_ = 0;
	for (size_t i = 1; i < s_len; ++i)
	{
		if (S[i - 1] == S[i]) {
			--single;
			++double_;
			S[i] = '\0';
		}
		else {
			++single;
		}
	}

	if (single == 0) {
		cout << double_ * 2 << endl;
	}
	else {
		cout << (double_ / single) * 2 + 1 << endl;
	}

	return 0;
}