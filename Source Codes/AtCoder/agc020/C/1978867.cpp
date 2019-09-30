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
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int dp[2000001] = {};
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	dp[0] = 1;
	for (int i = 0;i < n;++i) {
		int a;
scanf("%d",&a);
		sum += a;
		for (int q = min(2000000 - a,2000*i);q >= 0;--q) {
			dp[q + a] |= dp[q];
		}
	}
	for (int i = sum / 2;i >= 0;--i) {
		if (dp[i]) {
			cout << max(i, sum - i) << endl;
			return 0;
		}
	}
}