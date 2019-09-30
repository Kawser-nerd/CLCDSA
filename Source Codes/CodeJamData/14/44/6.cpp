#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MOD = int(1e9) + 7;

int comb[110][110];
int fact[110];

int m, n;

struct Trie {
	Trie*ch[26];
	bool have;

	Trie() {
		memset(ch, 0, sizeof ch);
		have = false;
	}

	Trie*get(int w) {
		if (ch[w] == 0)
			ch[w] = new Trie;
		return ch[w];
	}

	int mx[110], way[110];

	void solve() {

		fill_n(mx, n + 1, -1);
		fill_n(way, n + 1, 0);
		mx[have] = 0;
		way[have] = 1;

		for (int i = 0; i < 26; ++i) {
			if (ch[i]) {
				Trie*c = ch[i];
				c->solve();
				//update
				int nmx[110], nway[110];
				fill_n(nmx, n + 1, -1);
				fill_n(nway, n + 1, 0);

				for (int a = 0; a <= n; ++a)
					if (mx[a] != -1) {
						for (int b = 0; b <= n; ++b) {
							if (c->mx[b] != -1) {
								for (int com = 0; com <= a && com <= b; ++com)
									if (a + b - com <= n) {
										int t = mx[a] + c->mx[b];
										int p = a + b - com;
										if (t >= nmx[p]) {
											int w = 1LL * way[a] * c->way[b]
													% MOD * comb[a][com] % MOD
													* comb[b][com] % MOD
													* fact[com] % MOD;
											if (t > nmx[p]) {
												nmx[p] = t;
												nway[p] = 0;
											}
											if (t == nmx[p]) {
												nway[p] += w;
												if (nway[p] >= MOD)
													nway[p] -= MOD;
											}
										}
									}
							}
						}
					}

				copy_n(nmx, n + 1, mx);
				copy_n(nway, n + 1, way);
			}
		}

		for (int i = 0; i <= n; ++i) {
			if (mx[i] != -1) {
				mx[i] += i;
			}
		}
	}
}*rt;

int main() {

	for (int i = 0; i < 110; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}

	fact[0] = 1;
	for (int i = 1; i < 110; ++i) {
		fact[i] = 1LL * fact[i - 1] * i % MOD;
	}

	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		cerr << nc << endl;
		printf("Case #%d: ", nc);

		cin >> m >> n;
		Trie*rt = new Trie;
		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			Trie*t = rt;
			for (int j = 0; j < s.size(); ++j) {
				t = t->get(s[j] - 'A');
			}
			t->have = true;
		}
		rt->solve();
		int a = rt->mx[n], b = rt->way[n];
		b = 1LL * b * fact[n] % MOD;
		cout << a << " " << b << endl;
	}
}
