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
int n, k;
pair<int,int> dfs(int now) {
	int maximum_cnt = 1;
	int ans = 0;
	for (int i = 0;i < vertexs[now].size();++i) {
		pair<int, int> wow = dfs(vertexs[now][i]);
		if (now != 1 && wow.second == k) {
			ans++;
		}
		else {
			maximum_cnt = max(maximum_cnt, wow.second + 1);
		}
		ans += wow.first;
	}
	return make_pair(ans, maximum_cnt);
}
int main() {
	cin >> n >> k;
	int ans = 0;
	REP(i, n) {
		int a;
		cin >> a;
		if (i == 0) {
			if (a != 1) ans++;
		}
		else {
			vertexs[a].push_back(i + 1);
		}
	}
	cout << ans + dfs(1).first << endl;
	return 0;
}