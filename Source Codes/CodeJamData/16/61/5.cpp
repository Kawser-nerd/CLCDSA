#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

long long a,b;
char r[1100];
int digs[30];
int dc = 0;
int rlen;

map<int, long long> memo[31][2][2];
int adv[41];
int st[41];

void read() {
	scanf("%lld %lld", &a, &b);
	scanf("%s", r);
	rlen = strlen(r);
}

int advance(int a) {
	if (adv[a] != -1) return adv[a];
	int ans;

	if (st[a]) return 0;
	st[a]=1;

	if (a == rlen) return ans=(1<<rlen);
	if ('0' <= r[a] && r[a] <= '9') return ans=(1<<a);
	if (r[a] == ')') return ans=advance(a+1);


	if (r[a]=='|') {
		int s = 0;
		int ep = 0;
		for (int i = a+1; i < rlen; i++) {
			if (r[i]=='(') s++;
			if (r[i]==')') s--;
			if (s == -1) {
				ep = i;
				break;
			}
		}

		return ans=advance(ep+1);
	}

	if (r[a]=='*') {
		int s = 0;
		int ep = 0;
		for (int i = a-2; i >= 0; i--) {
			if (r[i] == '(') s++;
			if (r[i] == ')') s--;
			if (s == 1) {
				ep = i;
				break;
			}
		}

		int tans = advance(a+1) | advance(ep+1);
		return ans=tans;
	}

	if (r[a] == '(') {
		int tans = advance(a+1);

		int s = 0;
		int ep = 0;
		for (int i = a; i < rlen; i++) {
			if (r[i]=='(') s++;
			if (r[i]==')') s--;

			if (s == 0) {
				ep = i;
				break;
			}

			if (s == 1 && r[i] == '|') {
				tans |= advance(i+1);
			}
		}
		
		if (ep+1 < rlen && r[ep+1]=='*') tans |= advance(ep+2);
		return ans=tans;
	}

}

long long rec(int idx, bool eq, int possc, bool z) {
	if (possc & (1<<(rlen))) {
		if (idx == dc) return !z;
		possc ^= (1<<(rlen));
	}
	if (idx >= dc) return 0;

	if (memo[idx][eq][z].find(possc) != memo[idx][eq][z].end()) {
		return memo[idx][eq][z][possc];	
	}

	long long &ans = memo[idx][eq][z][possc];
	ans = 0;
	if (z) ans += rec(idx+1, 0, possc, 1);

	for (int d = 0; d <= 9; d++) {
		if (d == 0 && z) continue;
		if (eq && d > digs[idx]) break;

		int tpc = possc;
		int np = 0;

		while (possc) {
			int curpos = __builtin_ctz(possc&-possc);
			possc -= possc&-possc;

			//assert('0' <= r[curpos] && r[curpos] <= '9');

			if ( r[curpos]-'0' == d) {
				np |= adv[curpos+1];
			}
		}

		//if (d == 1) {
		//	printf("np = %d\n", np);
		//}
		int neq = (eq && d == digs[idx]);
		ans += rec(idx+1, neq, np, 0);
		possc = tpc;
	}

	//printf("%d %d %d %d (%d) -> %lld\n", idx,eq,possc,z,digs[idx],ans);
	return ans;
}

long long f(long long tgt) {
	if (tgt == 0) return 0;

	dc = 0;
	while (tgt) {
		digs[dc++] = tgt%10;
		tgt /= 10;
	}
	reverse(digs, digs+dc);

	for (int i = 0; i <dc; i++) {
		for (int e = 0; e < 2; e++) {
			for (int z = 0; z < 2; z++) {
				memo[i][e][z].clear();
			}
		}
	}

	return rec(0, 1, advance(0), 1);
}

void solve() {
	memset(adv,-1,sizeof(adv));
	for (int i = 0; i < rlen; i++) {
		memset(st,0,sizeof(st));
		adv[i]=advance(i);
	}
	adv[rlen] = (1<<rlen);

	long long ans = 0;
	ans += f(b);
	ans -= f(a-1);
	printf("%lld\n", ans);
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			fprintf(stderr, ">%d<\n", i+1);
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}