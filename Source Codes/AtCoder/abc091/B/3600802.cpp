#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M,ans = 0;
	string s, t;
	map<string, int> mp;
	cin >> N;
	REP(i, N) {
		cin >> s;
		mp[s]++;
	}
	cin >> M;
	REP(i, M) {
		cin >> t;
		mp[t]--;
	}

	for(auto x:mp){
		ans = max(ans, x.second);
	}
	cout << ans << endl;
	
	return 0;
}