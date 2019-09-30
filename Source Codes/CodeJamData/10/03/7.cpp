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

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int R, k, N;
		cin >> R >> k >> N;
		vector<int> gs;
		for (int n = 0; n < N; ++n) {
			int g;
			cin >> g;
			gs.push_back(g);
		}

		vector<int> nexts;
		vector<int> moneys;
		for (int start = 0; start < N; ++start) {
			int money = 0;
			int next = 0;
			for (; next < N; ++next) {
				if (money + gs[(start + next) % N] > k) {
					break;
				}
				money += gs[(start + next) % N];
			}
			nexts.push_back(next);
			moneys.push_back(money);
		}

		ll sum = 0;
		int current = 0;
		for (int r = 0; r < R; ++r) {
			sum += moneys[current];
			current += nexts[current];
			current %= N;
		}

		cout << "Case #" << t << ": " << sum << endl;
	}
}
