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
		ll N, K;
		cin >> N >> K;
		string answer;
		const ll mask = ((1 << N) - 1);
		if ((K & mask) == mask) {
			answer = "ON";
		} else {
			answer = "OFF";
		}
		printf("Case #%d: %s\n", t, answer.c_str());
	}
}
