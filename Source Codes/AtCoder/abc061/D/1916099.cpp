#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
long long dp[2000] = {};
int main() {
#define int long long
	int n,m;
	cin >> n >> m;
	vector<tuple<int, int, int>> wow;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		wow.push_back(make_tuple(a, b, -c));
	}
	for (int i = 2;i <= n;++i) {
		dp[i] = LONG_INF;
	}
	for (int i = 0;i < n*2;++i) {
		for (int q = 0;q < m;++q) {
			if (dp[get<0>(wow[q])] != LONG_INF&&dp[get<0>(wow[q])] + get<2>(wow[q]) < dp[get<1>(wow[q])]) {
				dp[get<1>(wow[q])] = dp[get<0>(wow[q])] + get<2>(wow[q]);
			}
		}
	}
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			if (dp[get<0>(wow[q])] != LONG_INF&&dp[get<0>(wow[q])] + get<2>(wow[q]) < dp[get<1>(wow[q])]) {
				dp[get<1>(wow[q])] = dp[get<0>(wow[q])] + get<2>(wow[q]);
				if (get<1>(wow[q]) == n) {
					cout << "inf" << endl;
					return 0;
				}
			}
		}
	}
	cout << -dp[n] << endl;
	return 0;
}