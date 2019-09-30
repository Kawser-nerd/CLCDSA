// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <string.h>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;

char poly[1000];

const int MOD = 10009;

struct term {
	int cnt[26];
}t;

int wcnt[20][26];
int sol[5];
int cnt[26];
int k, n;
int perm[6];
vector<term> p;

int eval() {
	int res = 0;
	for (int i=0; i<(int)p.size(); ++i) {
		int v = 1;
		for (int j=0; j<26; ++j) {
			if (p[i].cnt[j] == 0)
				continue;
			for (int k=0; k<p[i].cnt[j]; ++k)
				v = (v * cnt[j]) % MOD;
		}
		res = (res + v) % MOD;
	}
	return res;
}

void backtrack(int cur, int c, int div, bool was_zero) {
	if (c > 0 && !was_zero) {
		sol[c-1] += eval() * (perm[c] / div);
		sol[c-1] %= MOD;
	}
	if (cur == n)
		return;
	int save_cnt[26];
	memcpy(save_cnt, cnt, sizeof(int) * 26);
	for (int x=0; x<=k-c; ++x) {
		backtrack(cur + 1, c + x, div * perm[x], x == 0);
		for (int i=0; i<26; ++i)
			cnt[i] += wcnt[cur][i];
	}
	memcpy(cnt, save_cnt, sizeof(int) * 26);
}

int main() {
	int tc;
	scanf("%d", &tc);
	perm[0] = 1;
	for (int i=1; i<=5; ++i)
		perm[i] = perm[i-1] * i;
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d:", scen);
		scanf("%s", poly);
		memset(t.cnt, 0, sizeof(int) * 26);
		p.clear();
		for (int i=0; poly[i]; ++i) {
			if (poly[i] == '+') {
				p.push_back(t);
				memset(t.cnt, 0, sizeof(int) * 26);
			}
			else
				t.cnt[poly[i]-'a']++;
		}
		p.push_back(t);
		scanf("%d %d", &k, &n);
		char word[1000];
		for (int i=0; i<n; ++i) {
			scanf("%s", word);
			memset(wcnt[i], 0, 26 * sizeof(int));
			for (int j=0; word[j]; ++j)
				wcnt[i][word[j]-'a']++;
		}
		memset(sol, 0, sizeof(int) * k);
		backtrack(0, 0, 1, true);
		for (int i=0; i<k; ++i)
			printf(" %d", sol[i]);
		puts("");
	}
	return 0;
}
