#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int C;
	cin >> C;
	for (int c = 1; c <= C; ++c) {
		int N;
		cin >> N;
		vector<ll> input;
		for (int n = 0; n < N; ++n) {
			ll value;
			cin >> value;
			input.push_back(value);
		}

		sort(input.begin(), input.end());
		const ll minValue = input.front();
		const ll maxValue = input.back();

		for (vector<ll>::iterator it = input.begin(), itEnd = input.end(); it != itEnd; ++it) {
			*it -= minValue;
		}

		ll T = input.back();
		for (vector<ll>::iterator it = input.begin(), itEnd = input.end(); it != itEnd; ++it) {
			T = gcd(T, *it);
		}

		const ll y = (maxValue + T - 1) / T * T - maxValue;
		cout << "Case #" << c << ": " << y << endl;
	}
}
