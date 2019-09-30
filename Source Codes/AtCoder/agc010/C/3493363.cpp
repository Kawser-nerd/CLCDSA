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
vector<int> vertexs[200000];
long long timing[200000] = {};
int bad = 0;
long long solve(int now, int back) {
	if (vertexs[now].size() == 1&&back != -1) return timing[now];
	vector<long long> gogo;
	REP(i, vertexs[now].size()) {
		if (vertexs[now][i] != back) {
			long long geko = solve(vertexs[now][i], now);
			gogo.push_back(geko);
			if (geko < 0) bad = 1;
		}
	}
	long long required_loop = 0;
	REP(i, gogo.size()) {
		required_loop += gogo[i];
	}
	required_loop -= timing[now];
	if (required_loop < 0) bad = 1;
	long long backe = 0;
	sort(gogo.begin(), gogo.end());
	REP(i, gogo.size()-1) {
		backe += gogo[i];
	}
	if (required_loop > backe) bad = 1;
	if (bad == 1) {
		return 11000000000000000LL;
	}
	else {
		return timing[now] - required_loop;
	}
}
int main() {
#define int long long
	int n;
	cin >> n;
	REP(i, n) {
		cin >> timing[i];
	}
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	REP(i, n) {
		if (vertexs[i].size() == 1) {
			if (solve(i, -1) == timing[i]&&bad == 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			return 0;
		}
	}
}