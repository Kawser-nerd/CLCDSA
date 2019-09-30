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
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
vector<int> vertexs[200000];
int bad = 0;
int grid[200000] = {};
int dfs(int now,int back) {
	int a = 0, b = 0;
	for (int i = 0;i < vertexs[now].size();++i) {
		if (vertexs[now][i] != back) {
			int hoge = dfs(vertexs[now][i], now);
			if (hoge == 1) {
				a++;
			}
			else b++;
		}
	}
	if (a >= 2) {
		bad = 1;
		return 0;
	}
	if (a == 1) {
		grid[now] = 2;
		return 2;
	}
	if (a == 0) {
		grid[now] = 1;
		if (now == 1) bad = 1;
		return 1;
	}
}
int main() {
	int n;
	cin >> n;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	dfs(1, -1);
	if (bad == 1) {
		cout << "First" << endl;
	}
	else cout << "Second" << endl;
	return 0;
} ./Main.cpp:62:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.