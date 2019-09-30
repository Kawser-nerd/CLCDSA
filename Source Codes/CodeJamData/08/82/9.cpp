#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<string>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

const int nMax = 305;
const int INF = 1000000;
const int len = 10000;

int K;
map<string,int> M;
int N;
vector<int> tabK[nMax];
pair<int,int> tabN[nMax];
char S[20];
int n;
pair<int,int> tab[nMax];

int go() {
	int p=0, best=0;
	int res = 0;
	sort(tab, tab+n);
	FOR(i,0,n) if(tab[i].FI>p) {
		if(best<tab[i].FI) return INF;
		res++;
		p = best;
		best = tab[i].SE;
	} else
		best = max(best, tab[i].SE);
	if(p<len) {
		p = best;
		res++;
	}
	if(p<len) return INF;
	return res;
}

void testcase(int tNum) {
	printf("Case #%d: ",tNum);
	M.clear();
	K = 0;
	
	scanf("%d",&N);
	
	FOR(i,0,N) tabK[i].clear();
	
	FOR(i,0,N) {
		int a,b;
		scanf("%s %d %d",S,&a,&b); a--;
		tabN[i] = MP(a,b);
		string s = string(S);
		map<string,int>::iterator it=M.find(s);
		int cur = -1;
		if(it==M.end()) {
			M.insert(MP(s,K));
			cur = K++;
		} else {
			cur = it->SE;
		}
		tabK[cur].PB(i);
	}
	
	int res = INF;
	FOR(a,0,K) {
		n = 0;
		FORE(it,tabK[a]) tab[n++] = tabN[*it];
		res = min(res,go());
	}
	FOR(a,0,K) FOR(b,a+1,K) {
		n = 0;
		FORE(it,tabK[a]) tab[n++] = tabN[*it];
		FORE(it,tabK[b]) tab[n++] = tabN[*it];
		res = min(res,go());
	}
	FOR(a,0,K) FOR(b,a+1,K) FOR(c,b+1,K) {
		n = 0;
		FORE(it,tabK[a]) tab[n++] = tabN[*it];
		FORE(it,tabK[b]) tab[n++] = tabN[*it];
		FORE(it,tabK[c]) tab[n++] = tabN[*it];
		res = min(res,go());
	}
	
	if(res>=INF)
		printf("IMPOSSIBLE\n"); else
		printf("%d\n",res);
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
