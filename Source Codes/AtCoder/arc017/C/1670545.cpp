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
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
map<set<long long>, bool> gekogeko;
int main() {
#define int long long
	long long n, x;
	cin >> n >> x;
	vector<int> wow;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		wow.push_back(tmp);
	}
	if (n == 1) {
		if (wow[0] == x) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
		return 0;
	}
	map<int, int> left_cnt[2];
	map<int, int> right_cnt[2];
	left_cnt[0][0]++;
	for (int i = 0;i < n;++i) {
		if (n / 2 > i) {
			for (auto q = left_cnt[i%2].begin();q != left_cnt[i%2].end();++q) {
				left_cnt[(i + 1) % 2][q ->first] += q->second;
				left_cnt[(i + 1) % 2][q->first + wow[i]] += q->second;
				q->second = 0;
			}
		}
		else {
			if (n / 2 == i) {
				right_cnt[i%2][0]++;
			}
			for (auto q = right_cnt[i % 2].begin();q != right_cnt[i % 2].end();++q) {
				right_cnt[(i + 1) % 2][q->first] += q->second;
				right_cnt[(i + 1) % 2][q->first + wow[i]] += q->second;
				q->second = 0;
			}
		}
	}
	long long ans = 0;
	for (auto i = left_cnt[(n/2)%2].begin();i != left_cnt[(n/2)%2].end();++i) {
		long long want = x - i->first;
		ans += i->second*right_cnt[n%2][want];
	}
	cout << ans << endl;
	return 0;
}