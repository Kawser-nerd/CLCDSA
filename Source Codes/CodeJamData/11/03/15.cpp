#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int CandySplitting(vector <int> candies)
{
	sort(candies.begin(), candies.end());
	int sum = 0;
	for (int i = 0; i < candies.size(); i++) {
		sum ^= candies[i];
	}
	if (sum != 0) {
		return -1;
	}
	return accumulate(candies.begin() + 1, candies.end(), 0);
}


int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		cin >> N;
		vector <int> candies(N);
		for (int i = 0; i < N; i++) {
			cin >> candies[i];
		}
		int ret = CandySplitting(candies);
		cout << "Case #" << caseno << ": ";
		if (ret >= 0) {
			cout << ret;
		} else {
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}
