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
	int n, k;
	cin >> n >> k;
	map<int, int> wow;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		wow[tmp]++;
	}
	vector<int> gew;
	for (auto i = wow.begin();i != wow.end();++i) {
		gew.push_back(i->second);
	}
	if (gew.size() > k) {
		int ans = 0;
		sort(gew.begin(), gew.end());
		for (int i = 0;i < gew.size() - k;++i) {
			ans += gew[i];
		}
		cout << ans << endl;
	}
	else cout << 0 << endl;
	return 0;
}