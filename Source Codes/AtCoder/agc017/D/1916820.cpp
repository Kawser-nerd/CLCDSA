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
string ans[2] = { "Alice","Bob" };
int dfs(int now, int back) {
	int ans = 0;
	for (int i = 0;i < vertexs[now].size();++i) {
		if (vertexs[now][i] != back) {
			ans ^= 1+dfs(vertexs[now][i], now);
		}
	}
	return ans;
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
	if (dfs(1, -1) != 0) {
		cout << "Alice" << endl;
	}
	else cout << "Bob" << endl;
	return 0;
}