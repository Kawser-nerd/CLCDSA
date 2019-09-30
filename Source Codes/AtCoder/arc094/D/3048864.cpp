#include <iostream>
#include <string>
#include <set>
#include <queue>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int mod = 998244353;
	
int countMod3Renzoku(string s) {
	int i, j, k, l, m, m3 = 0;

	rep(i, s.length()) m3 += (s[i] - 'a');
	m3 %= 3;
	
	static int dp[200001][3][3][2] = {0};	//dp[cnt][mod3][lastChar][flag]
	
	rep(i, 3) dp[1][i][i][0] = 1;
	for (i = 1; i < s.length(); i++) {
		rep(j, 3) {
			rep(k, 3) {
				rep(l, 2) {
					rep(m, 3) {
						dp[i + 1][(j + m) % 3][m][l | (k == m)] += dp[i][j][k][l];
						dp[i + 1][(j + m) % 3][m][l | (k == m)] %= mod;
					}
				}
			}
		}
	}
	
	int ret = 0;
	rep(i, 3) { ret += dp[s.length()][m3][i][1]; ret %= mod; }
	return ret;
}

int allSearch(string s) {
	set<string> dict;
	queue<string> que;
	
	que.push(s);
	dict.insert(s);
	
	while (!que.empty()) {
		string t = que.front(); que.pop();
		int i, j;
		rep(i, (int)t.length() - 1) {
			if (t[i] != t[i + 1]) {
				rep(j, 3) if (j + 'a' != t[i] && j + 'a' != t[i + 1]) break;
				char repl = j + 'a';
				string u = t;
				u[i] = repl;
				u[i + 1] = repl;
				if (dict.find(u) == dict.end()) {
					que.push(u);
					dict.insert(u);
				}
			}
		}
	}
	return dict.size();
}

signed main() {
	string s;
	cin >> s;
	
	int i;
	rep(i, s.length() - 1) if (s[i] != s[i + 1]) break;
	
	if (i == s.length() - 1) { cout << 1 << endl; }
	else if (s.length() <= 3) { cout << allSearch(s) << endl; }
	else {
		int res = countMod3Renzoku(s);
		rep(i, s.length() - 1) if (s[i] == s[i + 1]) break;
		if (i == s.length() - 1) res++;
		res %= mod;
		cout << res << endl;
	}
	return 0;
}