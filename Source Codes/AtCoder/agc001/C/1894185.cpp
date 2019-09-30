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
vector<long long> vertexs[3000];
int dfs(int now, int back, int fukasa) {
	int ans = 0;
	fukasa--;
	if (fukasa < 0) ans++;
	for (int i = 0;i < vertexs[now].size();++i) {
		if (vertexs[now][i] != back) {
			ans += dfs(vertexs[now][i], now, fukasa);
		}
	}
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> wow;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		wow.push_back(make_pair(a - 1, b - 1));
		vertexs[a - 1].push_back(b - 1);
		vertexs[b - 1].push_back(a - 1);
	}
	int geko = 3000;
	for (int q = 0;q < n;++q) {
		geko = min(geko, dfs(q, -1, (k + 2) / 2));
	}
	for (int q = 0;q < wow.size();++q) {
		geko = min(geko, dfs(wow[q].first, wow[q].second, (k+1) / 2) + dfs(wow[q].second, wow[q].first, (k+1) / 2));
	}
	cout << geko << endl;
	return 0;
}