#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

string s;

int lst[1005];

void solve(){
	string t;
	for(int i=0; i<s.size(); i++){
		string u;
		u.push_back(s[i]);
		t = max(u + t, t + u);
	}
	cout << t;
}

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		cin >> s;
		printf("Case #%d: ", i);
		solve();
		puts("");
	}
}