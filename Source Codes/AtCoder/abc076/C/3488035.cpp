#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int func(long long n) {
	if (n < 10)return 1;
	return func(n/10)+1;
}
string S, T;
int sLen, tLen;
bool match(int k) {
	REP(i, tLen) {
		if (T[i] != S[i + k] && S[i + k] != '?')return false;
	}
	return true;
}
string construct(int k){
	string ans = S;
	REP(i, tLen) {
		ans[k + i] = T[i];
	}
	replace(ans.begin(), ans.end(), '?', 'a');
	return ans;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> S >> T;
	sLen = S.length();
	tLen = T.length();
	string ans;

	int k = 0;
	for (k = sLen - tLen; k >= 0;k--) {
		if (match(k))break;
	}

	if(k>=0)cout << construct(k) << endl;
	else cout << "UNRESTORABLE" << endl;
	return 0;
}