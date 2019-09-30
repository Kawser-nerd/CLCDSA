#define  _CRT_SECURE_NO_WARNiINGS
#include <stdio.h>
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <cassert>
#include <set>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define cycle_per_sec 2806192512
int bad[1000000] = {};
int main() {
#define int long long
	int n, k, query;
	cin >> n >> k >> query;
	vector<int> a;
	vector<pair<int, int>> hoge;
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
		hoge.push_back(make_pair(b, i));
	}
	sort(hoge.begin(), hoge.end());
	long long ans = 0;
	vector<int> nyaw;
	for (int i = 0; i < n; ++i) {
		vector<int> going;
		for (int q = 0; q < n; ++q) {
			if (bad[q] == 1) {
				if (nyaw.size() >= k) {
					sort(nyaw.begin(), nyaw.end());
					for (int j = 0; j < nyaw.size() - k + 1; ++j) {
						going.push_back(nyaw[j]);
					}
				}
				if (nyaw.size() != 0) {
					nyaw.clear();
				}
			}
			else {
				nyaw.push_back(a[q]);
			}
		}
		if (nyaw.size() >= k) {
			sort(nyaw.begin(), nyaw.end());
			for (int j = 0; j < nyaw.size() - k + 1; ++j) {
				going.push_back(nyaw[j]);
			}
		}
		if (nyaw.size() != 0) nyaw.clear();
		sort(going.begin(), going.end());
		if (going.size() < query) break;
		long long pre_ans = going[query - 1] - hoge[i].first;
		if (i == 0) ans = pre_ans;
		ans = min(pre_ans, ans);
		bad[hoge[i].second] = 1;
	}
	cout << ans << endl;
	return 0;
}