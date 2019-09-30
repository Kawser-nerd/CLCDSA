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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define f(n) for(int i=0;i<n;++i)
#define REP(i,n) for(long long i = 0;i < n;++i)
pair<long long,long long> seg[700000][2] = {};
const long long hogehoge = 262144;
pair<long long,long long> seg_find(long long left, long long right, long long w_l, long long w_r, long long now, long long a) {
	if (w_r <= left || right <= w_l) return make_pair(LONG_INF,0);
	if (w_l <= left&&right <= w_r) return seg[now][a];
	pair<long long, long long> ac = seg_find(left, (left + right) / 2, w_l, w_r, now * 2, a);
	pair<long long, long long> ad = seg_find((left + right) / 2, right, w_l, w_r, now * 2 + 1, a);
	if (ac.first > ad.first) {
		return ad;
	}
	else {
		return ac;
	}
}
long long seg_set(long long n,long long a) {
	seg[n][a] = min(seg[2*n][a],seg[2*n+1][a]);
	if (n != 1) seg_set(n / 2, a);
	return 0;
}
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		seg[i + hogehoge][0] = make_pair(LONG_INF,i);
		seg[i + hogehoge][1] = make_pair(LONG_INF,i);
		seg[i + hogehoge][i % 2].first = a;
		seg_set((i + hogehoge) / 2, 0);
		seg_set((i + hogehoge) / 2, 1);
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> nya;
	nya.push(make_tuple(0, 0, n));
	while (nya.empty() == false) {
		tuple<int, int, int> now = nya.top();nya.pop();
			pair<int, int> wow = seg_find(0, hogehoge, get<1>(now), get<2>(now), 1, get<1>(now) % 2);
			pair<int, int> hoge = seg_find(0, hogehoge, wow.second + 1, get<2>(now),1,(wow.second + 1) % 2);
			cout << wow.first << " ";
			cout << hoge.first << " ";
			if (get<1>(now) != wow.second) {
				nya.push(make_tuple(seg_find(0, hogehoge, get<1>(now), wow.second, 1, get<1>(now) % 2).first, get<1>(now), wow.second));
			}
			if (wow.second + 1 != hoge.second) {
				nya.push(make_tuple(seg_find(0, hogehoge, wow.second + 1, hoge.second, 1, (wow.second + 1) % 2).first, wow.second + 1, hoge.second));
			}
			if (hoge.second + 1 != get<2>(now)) {
				nya.push(make_tuple(seg_find(0, hogehoge, hoge.second + 1, get<2>(now), 1, (hoge.second + 1) % 2).first, hoge.second + 1, get<2>(now)));
			}
	}
	cout << "\n";
	return 0;
}