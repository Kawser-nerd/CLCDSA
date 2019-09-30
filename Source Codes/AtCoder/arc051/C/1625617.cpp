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
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 262144
long long n, a, b;
long long solve(long long now, long long multi) {
	long long ans = now%MAX_MOD;
	long long geko = a%MAX_MOD;
	while (multi != 0) {
		if (multi % 2 == 1) {
			ans *= geko;
			ans %= MAX_MOD;
		}
		geko *= geko;
		geko %= MAX_MOD;
		multi /= 2;
	}
	return ans;
}
int main() {
	cin >> n >> a >> b;
	vector<long long> wow;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		wow.push_back(tmp);
	}
	sort(wow.begin(), wow.end());
	if (a == 1) b = 0;
	while (b != 0) {
		if (wow[0] * a >= wow[n - 1]) {
			vector<pair<long long, long long>> woe;
			for (int i = 0;i < n;++i) {
				long long right = b / n;
				if (i < b%n) {
					woe.push_back(make_pair(i + 1000, solve(wow[i], right + 1)));
				}
				else {
					woe.push_back(make_pair(i, solve(wow[i],right)));
				}
			}
			sort(woe.begin(), woe.end());
			for (int i = 0;i < n;++i) {
				cout << woe[i].second << endl;
			}
			return 0;
		}
		wow[0] *= a;
		b--;
		sort(wow.begin(), wow.end());
	}
	for (int i = 0;i < n;++i) {
		cout << wow[i]%MAX_MOD << endl;
	}
	return 0;
}