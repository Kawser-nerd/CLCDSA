#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define V2D(A, T, N, M, V) vector<vector<T> > A(N, vector<T>(M, V))
#define V3D(A, T, N, M, K, V) vector<vector<vector<T> > > A(N, vector<vector<T> >(M, vector<T>(K, V)))

string bt(string &S, string &T) {
	if (T.size() > 30) return "";
	long long x = 0;
	for (int i = 0; i < T.size(); i++) {
		x = x * 2 + T[i] - '0';
	}
	x = x * x;
	string T2 = "";
	while (x) {
		T2 = T2 + (char)((x % 2) + '0');
		x /= 2;
	}
	while (T2.size() < 2 * T.size() - 1) {
		T2 = T2 + '0';
	}
	reverse(T2.begin(), T2.end());
	for (int i = 0; i < T2.size(); i++) {
		int pos = (int)S.size() - (int)T2.size() + i;
		if (pos < 0) return "";
		if (S[pos] == '?') continue;
		if (S[pos] != T2[i]) return "";
	}
	if (T2.size() == S.size()) return T;
	string buf = "1" + T;
	string tmp = bt(S, buf);
	if (tmp != "") return tmp;
	buf = "0" + T;
	tmp = bt(S, buf);
	if (tmp != "") return tmp;
}

void solveTest() {
	string S;
	cin >> S;
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '?') cnt++;
	}
	for (int i = 0; i < (1 << cnt); i++) {
		int num = 0;
		long long res = 0;
		for (int j = 0; j < S.size(); j++) {
			int dig;
			if (S[j] == '?') {
				dig = (i >> num) & 1;
				num++;
			}
			else {
				dig = S[j] - '0';
			}
			res = res * 2 + dig;
		}
		long long cand = (int)(sqrt(res + 0.0) + 0.1);
		if (cand * cand == res) {
			string ans = "";
			while (res) {
				ans += (res % 2) + '0';
				res /= 2;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
			return;
		}
	}
}

int main() {
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; ++it) {
		printf("Case #%d: ", it);
		solveTest();
	}
	return 0;
}
