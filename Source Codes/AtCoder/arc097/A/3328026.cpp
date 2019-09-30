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
int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	set<string> already;
	vector<string> gogo;
	REP(i, s.length()) {
		string hoge;
		for (int q = 0; q < k; ++q) {
			if (i + q >= s.length())break;
			hoge.push_back(s[i + q]);
			if (already.find(hoge) == already.end()) {
				already.insert(hoge);
				gogo.push_back(hoge);
			}
		}
	}
	sort(gogo.begin(), gogo.end());
	cout << gogo[k - 1] << endl;
	return 0;
}