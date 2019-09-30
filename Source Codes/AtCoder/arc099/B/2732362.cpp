#define  _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	long long k;
	cin >> k;
	priority_queue<pair<long double,long long>, vector<pair<long double,long long>>, greater<pair<long double,long long>>> hoge;
	for (int i = 0; i < 15; ++i) {
		for (int q = 1; q <= 1000; ++q) {
			string s = to_string(q);
			for (int j = 0; j < i; ++j) {
				s += "9";
			}
			long long geko = stoll(s);
			long double valuing = stold(s);
			long double bunsi = 0;
			for (int q = 0; q < s.length(); ++q) {
				bunsi += s[q] - '0';
			}
			hoge.push(make_pair(valuing / bunsi,geko));
		}
	}
	long long cnt = 0;
	while (hoge.empty() == false) {
		long long pepe = hoge.top().second;
		hoge.pop();
		if (cnt < pepe) {
			cnt = pepe;
			cout << cnt << endl;
			k--;
			if (k == 0) {
				return 0;
			}
		}
	}
	return 0;
}