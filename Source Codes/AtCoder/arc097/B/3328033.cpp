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
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int union_find[200000];
int union_search(int a) {
	if (union_find[a] == a) return a;
	return union_find[a] = union_search(union_find[a]);
}
int union_merge(int a, int b) {
	a = union_search(a);
	b = union_search(b);
	union_find[a] = b;
	return 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		union_find[i] = i;
	}
	REP(i, k) {
		int a, b;
		cin >> a >> b;
		union_merge(a, b);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (union_search(i + 1) == union_search(a[i]))ans++;
	}
	cout << ans << endl;
	return 0;
}