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
long long dp[200000] = {};
int visited[200000] = {};
int main() {
	long long k;
	cin >> k;
	for (int i = 0;i <= k;++i) {
		dp[i] = LONG_INF;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wow;
	wow.push(make_pair(0, 0));
	while (wow.empty() == false) {
		pair<int, int> now = wow.top();
		wow.pop();
		if (visited[now.second] == 0) {
			visited[now.second] = 1;
			if (now.second != 0&&dp[(now.second * 10) % k] > now.first) {
				dp[(now.second * 10)%k] = now.first;
				wow.push(make_pair(now.first,(now.second*10)%k));
			}
			if (dp[(now.second + 1)% k] > now.first+1) {
				dp[(now.second + 1) % k] = now.first + 1;
				wow.push(make_pair(now.first+1, (now.second + 1)%k));
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}