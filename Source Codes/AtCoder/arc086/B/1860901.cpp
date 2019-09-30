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
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
#define int long long
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	vector<pair<int, int>> wow;
	for (int i = n - 1;i >= 1;--i) {
		if (a[i] < 0 && a[i - 1] > a[i]) {
			if (a[i - 1] + a[i] <= a[i]) {
				wow.push_back(make_pair(i + 1, i));
				a[i - 1] += a[i];
			}
			else if (a[i - 1] + 2 * a[i] <= a[i]) {
				wow.push_back(make_pair(i + 1, i));
				wow.push_back(make_pair(i + 1, i));
				a[i - 1] += 2 * a[i];
			}
		}
	}
	for (int i = 0;i < n - 1;++i) {
		if (a[i] > a[i + 1]) {
			while (a[i] > a[i + 1]) {
				a[i + 1] += a[i];
				wow.push_back(make_pair(i + 1, i + 2));
			}
		}
	}
	assert(wow.size() <= 2 * n);
	cout << wow.size() << endl;
	for (int i = 0;i < wow.size();++i) {
		cout << wow[i].first << " " << wow[i].second << endl;
	}
	return 0;
}