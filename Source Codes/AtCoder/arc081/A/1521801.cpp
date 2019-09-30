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
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n;
	cin >> n;
	vector<long long> hoge;
	REP(i, n) {
		long long a;
		cin >> a;
		hoge.push_back(a);
	}
	sort(hoge.begin(), hoge.end());
	long long ans = 0;
	for (int i = n - 2;i >= 0;--i) {
		if (hoge[i] == hoge[i + 1]) {
			if (ans == 0) {
				ans = hoge[i];
				i--;
			}else{
				ans *= hoge[i];
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
}