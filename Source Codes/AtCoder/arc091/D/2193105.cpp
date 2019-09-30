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
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
long long calc(long long a, long long b) {
	if (a % b == 0) return a / b;
	long long hoge = a / b;
	long long geko = max(1LL, (a - hoge * b) / (hoge+1));
	return calc(a - (a / b + 1) * geko, b);
} 
int main() {
	int n;
	cin >> n;
	long long hoge = 0;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		hoge ^= calc(a, b);
	}
	if (hoge != 0) {
		cout << "Takahashi" << endl;
	}
	else {
		cout << "Aoki" << endl;
	}
	return 0;
}