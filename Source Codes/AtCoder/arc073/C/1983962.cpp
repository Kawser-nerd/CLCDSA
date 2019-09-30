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
	vector<pair<int, int>> wow;
	vector<int> vertexs;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		vertexs.push_back(a);
		vertexs.push_back(b);
		wow.push_back(make_pair(a, b));
	}
	sort(vertexs.begin(), vertexs.end());
	long long ans = LONG_INF;
	priority_queue<pair<long long, long long>> kouho;
	REP(i, n) {
		kouho.push(make_pair(max(wow[i].first, wow[i].second), min(wow[i].first, wow[i].second)));
	}
	while (true) {
		pair<long long, long long> now = kouho.top();
		kouho.pop();
		if (now.first <= now.second) {
			pair<long long, long long> pee;
			while (kouho.empty() == false) {
				pee = kouho.top();
				kouho.pop();
			}
			ans = (vertexs[2 * n - 1] - vertexs[0]) * (now.first - pee.first);
			break;
		}else{
			kouho.push(make_pair(now.second, now.first));
		}
	}
	long long a = 0, b = LONG_INF, c = 0, d = LONG_INF;
	for (int q = 0;q < n;++q) {
		if (wow[q].first > wow[q].second) swap(wow[q].first, wow[q].second);
		a = max(a, wow[q].first);
		b = min(b, wow[q].first);
		c = max(c, wow[q].second);
		d = min(d, wow[q].second);
	}
	if (n < 16) {
		for (int i = 0;i < (1 << n);++i) {
			long long a = 0, b = LONG_INF, c = 0, d = LONG_INF;
			long long tere = i;
			for (int q = 0;q < n;++q) {
				if (tere % 2 == 1) {
					a = max(a, wow[q].second);
					b = min(b, wow[q].second);
					c = max(c, wow[q].first);
					d = min(d, wow[q].first);
				}
				else {
					a = max(a, wow[q].first);
					b = min(b, wow[q].first);
					c = max(c, wow[q].second);
					d = min(d, wow[q].second);
				}
				tere /= 2;
			}
			ans = min(ans, (d - c)*(b - a));
		}
	}
	cout << min(ans, (d - c)*(b - a)) << endl;
	return 0;
}