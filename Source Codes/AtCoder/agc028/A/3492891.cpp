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
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
#define int long long
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int hoge = n*m;
	hoge /= gcd(n, m);
	int left = 0;
	int right = 0;
	while (right < m&&left < n) {
		if (s[left] != t[right]) {
			cout << -1 << endl;
			return 0;
		}
		left += n / gcd(n,m);
		right += m / gcd(n,m);
	}
	cout << hoge << endl;
	return 0;
}