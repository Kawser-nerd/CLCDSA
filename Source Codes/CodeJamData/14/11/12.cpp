#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 155;

string s1[MAXN], s2[MAXN];

vector<string> wanted, tmp;;
int n, L, a[MAXN];

inline int trans(int x) {if (x == '0') x = '1'; else x = '0'; return x;}
int main(void) {
	freopen("A-large.in", "r", stdin);
	freopen("out", "w", stdout);
	int kase; cin >>kase; for (int _ = 1; _ <= kase; _++) {
		cin >>n >> L; wanted.clear();
		for (int i = 1; i <= n; i++) cin >>s1[i];
		for (int i = 1; i <= n; i++) cin >>s2[i], wanted.push_back(s2[i]);
		sort(wanted.begin(), wanted.end());
		int Ans = 1000000;
		for (int i = 1; i <= n; i++) {
			int cnt = 0; tmp.clear();
			for (int j = 0; j < L; j++) a[j] = (s1[1][j] != s2[i][j]), cnt += a[j];
			for (int j = 1; j <= n; j++) {
				string st = s1[j];
				for (int k = 0; k < L; k++) if (a[k] == 1) st[k] = trans(st[k]);
				tmp.push_back(st);
			}
			sort(tmp.begin(), tmp.end());
			if (tmp == wanted) Ans = min(Ans, cnt);
		}
		if (Ans != 1000000) printf("Case #%d: %d\n", _, Ans); else printf("Case #%d: NOT POSSIBLE\n", _);
	}
	return 0;
}

