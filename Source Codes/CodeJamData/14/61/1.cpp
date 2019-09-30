#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define INF 1000000007

string inv(string s) {
	string t;
	for (int i = 0; i < (int) s.length(); i ++)
		if (s[i] == '1') t += '0';
		else t += '1';
	return t;
}

int gg(vector<int> B, int x) {
	int S = 0;
	int n = (int) B.size();
	for (int i = 0; i < n; i ++) {
		if (B[i] != (x^(i&1))) S ++;
	}
	return S/2;
}

int ff(vector<string> A) {
	int S0 = 0, S1 = 0;
	vector<int> B;
	int n = (int) A.size();
	for (int i = 0; i < n; i ++) 
		if (A[0] == A[i]) {
			B.pb(0);
			S0 ++;
		} else 
		if (inv(A[0]) == A[i]) {
			B.pb(1);
			S1 ++;
		} else {
			return INF;
		}
	if (abs(S0-S1)>1) return INF;
	if (S0 == S1) {
		return min(gg(B,1), gg(B,0)); 
		// TWO WAYS
	}
	if (S0 > S1) {
		return gg(B,0);
	}
	if (S1 > S0) {
		return gg(B,1);
	}
}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n;
		vector<string> A;
		cin >> n;
		n *= 2;
		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;
			A.pb(s);
		}
		int S = ff(A);
		vector<string> B(n,string(""));
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < n; j ++) 
				B[j] += A[i][j];
		int T = ff(B);
		int SS = S+T;
		printf ("Case #%d: ",__);
		if (SS >= INF) {
			puts("IMPOSSIBLE");
		} else {
			cout << SS << endl;
		}
	}
	return 0;
}
