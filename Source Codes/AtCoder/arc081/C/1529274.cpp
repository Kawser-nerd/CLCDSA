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
pair<int,int> dp[300000] = {};
int now[300000][27] = {};
int cnt[27] = {};
int compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() == b.length() && a < b) {
		return 1;
	}
	return 0;
}
int main() {
	string a;
	cin >> a;
	a += "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0;i < 26;++i) {
		cnt[i] = a.length();
	}
	for (int i = a.length() - 1;i >= 0;--i) {
		for (int q = 0;q < 26;++q) {
			now[i][q] = cnt[q];
		}
		cnt[a[i] - 'a'] = i;
	}
	map<char, int> wow;
	for (int q = a.length() - 1;q >= 0;--q) {
		if (wow[a[q] - 'a'] == false) {
			wow[a[q] - 'a'] = true;
			dp[q] = make_pair(1, -1);
		}
		else {
			dp[q] = make_pair(1000000, 1000);
			for (int j = 0;j < 26;++j) {
				if (dp[q].first > dp[now[q][j]].first + 1) {
					dp[q].first = dp[now[q][j]].first + 1;
					dp[q].second = now[q][j];
				}else if(dp[q].first == dp[now[q][j]].first + 1 &&a[now[q][j]] < a[dp[q].second]){
					dp[q].second = now[q][j];
				}
			}
		}
	}
	map<char, int> ha;
	string s;
	for (int i = 0;i < a.length();++i) {
		if (ha[a[i]] == false) {
			ha[a[i]] = true;
			int nowing = i;
			string pre;
			while (nowing != -1) {
				pre.push_back(a[nowing]);
				nowing = dp[nowing].second;
			}
			if (i == 0 || s.length() > pre.length()) {
				s = pre;
			}
			else if (s.length() == pre.length() && s > pre) {
				s = pre;
			}
		}
	}
	cout << s << endl;
	return 0;
}