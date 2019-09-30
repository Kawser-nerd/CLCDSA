#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s,t;
	cin >> s >> t;
	
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	cout << (s<t?"Yes":"No") << endl;
	return 0;
}