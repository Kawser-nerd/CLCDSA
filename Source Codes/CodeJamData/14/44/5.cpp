#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

#define SZ(v) int((v).size())

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAXM = 2000;
const int MAXN = 200;
const int MAXL = 200;
const int MAXD = 30;
const int MAXT = MAXM * MAXL;

int M, N;

string S[MAXM];
int lcp[MAXM];

ll binom[MAXM][MAXM];
ll fact[MAXM];

int T;
ll trie[MAXT][MAXD];
int sz[MAXT];
int val[MAXT];

ll numWays;
ll maxVal;

ll exp(ll a, ll e) {
	ll res = 1;
	while(e)  {
		if(e % 2) res *= a, res %= MOD;
		e /= 2;
		a *= a, a %= MOD;
	}
	return res;
}

void dfs(int cur = 0) {
	//cerr << cur << ' ' << sz[cur] << ' ' << val[cur] << '\n';
	if(sz[cur] > N) sz[cur] = N;
	maxVal += sz[cur];
	for(int l = 0; l < MAXD; l++) {
		if(trie[cur][l]) dfs(trie[cur][l]);
	}
	ll ways = 0;
	for(int s = sz[cur]; s >= 0; s--) {
		ll v = binom[sz[cur]][s];
		for(int l = 0; l < MAXD; l++) {
			int nxt =  trie[cur][l];
			if(nxt) {
				if(s < sz[nxt]) {
					v = 0; break;
				}
				v *= binom[s][sz[nxt]];
				v %= MOD;
			}
		}
		v *= exp(s, val[cur]);
		v %= MOD;
		if(!v) break;
		if((s % 2) == (sz[cur] % 2)) ways += v;
		else ways -= v;
		if(ways >= MOD) ways -= MOD;
		if(ways < 0) ways += MOD;
	}
	numWays *= ways;
	numWays %= MOD;
}

int main() {
	int Test; cin >> Test;
	for(int t = 1; t <= Test; t++) {
		cin >> M >> N;
		for(int i = 0; i <= M; i++) {
			binom[i][0] = binom[i][i] = 1;
			for(int j = 1; j < i; j++) {
				binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
				if(binom[i][j] >= MOD) binom[i][j] -= MOD;
			}
		}
		for(int i = 0; i < M; i++) cin >> S[i];
		sort(S, S + M);
		T = 1;
		memset(trie, 0, sizeof(trie));
		memset(val, 0, sizeof(val));
		memset(sz, 0, sizeof(sz));
		for(int i = 0; i < M; i++) {
			string s = S[i];
			int cur = 0;
			for(int j = 0; j < SZ(s); j++) {
				sz[cur]++;

				int l = s[j] - 'A';
				if(!trie[cur][l]) {
					trie[cur][l] = T;
					T++;
				}
				cur = trie[cur][l];
			}
			sz[cur]++;
			val[cur]++;
		}
		maxVal = 0;
		numWays = 1;

		dfs();

		cout << "Case #" << t << ": " << maxVal << ' ' << numWays << '\n';
	}
	return 0;
}
