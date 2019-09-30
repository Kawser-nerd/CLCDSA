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

#define P 2371
#define Q 1000000007

#define N 10010

typedef vector<int>::iterator vit;
typedef pair<PII,int> PI3;

int n;
vector<int> A[N];
string c[N];
map<PII,PII> h;
int fa[N];

#define NN 1000010
int p[NN];

void ff(int x) {
	vector<PII> a;
	for (vit i = A[x].begin(); i != A[x].end(); i ++) 
		if (*i != fa[x]) {
			fa[*i] = x;
			ff(*i);
			a.pb(h[mp(*i,x)]);
		}
	if (fa[x] == -1) return;
	sort(a.begin(),a.end());
	int S = 0;
	int len = 0;
	S = (ll)S*P%Q;
	S = (S+(int)c[x][0])%Q;
	len ++;
	S = (ll)S*P%Q;
	S = (S+(int)('('))%Q;
	len ++;
	for (int i = 0; i < (int) a.size(); i ++) {
		S = (ll)S*p[a[i].se]%Q;
		S = (S+a[i].fi)%Q;
		len += a[i].se;
	}
	S = (ll)S*P%Q;
	S = (S+(int)(')'))%Q;
	len ++;
	h[mp(x,fa[x])] = mp(S,len);
}

int g[N];
set<int> B[N];

bool gg(int x, int y) {
	int ne = *B[x].begin();
	if (ne == y) ne = *B[x].rbegin();
	if (g[ne] == 1) {
		if (*B[ne].begin() == x) return 1;
	} else
	if (g[ne] == 2) {
		if (B[ne].find(x) != B[ne].end()) return gg(ne,x);
	}
	return 0;
}

void hh(int x) {
	vector<PI3> a;
	vector<PII> prf;
	vector<PII> suf;
	for (vit i = A[x].begin(); i != A[x].end(); i ++)
		a.pb(mp(h[mp(*i,x)],*i));
	
	sort(a.begin(),a.end());
	int n = (int) a.size();
	
	map<int,int> rev;
	for (int i = 0; i < n; i ++) 
		rev[a[i].se] = i;
	
	prf.resize(n+1);
	suf.resize(n+1);
	
	prf[0] = mp(0,0);
	for (int i = 0; i < n; i ++) {
		int len = a[i].fi.se;
		int S = (ll)prf[i].fi*p[len]%Q;
		S = (S+a[i].fi.fi)%Q;
		prf[i+1] = mp(S, prf[i].se+len);
	}
	
	suf[n] = mp(0,0);
	for (int i = n-1; i >= 0; i --) {
		int len = a[i].fi.se;
		int S = (ll)a[i].fi.fi*p[suf[i+1].se]%Q;
		S = (S+suf[i+1].fi)%Q;
		suf[i] = mp(S, len+suf[i+1].se);
	}
	
	for (vit i = A[x].begin(); i != A[x].end(); i ++)
		if (*i != fa[x]) {
			int po = rev[*i];
			
			int Sl = prf[po].fi;
			int lenl = prf[po].se;
			int Sr = suf[po+1].fi;
			int lenr = suf[po+1].se;
			
			int S = (ll)Sl*p[lenr]%Q;
			S = (S+Sr)%Q;
			
			int len = lenl+lenr;
			S = (ll)S*P%Q;
			S = (S+(int)(')'))%Q;
			len ++;
			
			S = (S+(ll)(int)('(')*p[len]%Q)%Q;
			len ++;
			
			S = (S+(ll)(int)(c[x][0])*p[len]%Q)%Q;
			len ++;
			
			h[mp(x,*i)] = mp(S,len);
		}
	
	for (vit i = A[x].begin(); i != A[x].end(); i ++)
		if (*i != fa[x]) hh(*i);
}

int main()
{
	p[0] = 1;
	for (int i = 1; i < NN; i ++)
		p[i] = (ll)p[i-1]*P%Q;
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++)
			cin >> c[i];
		h.clear();
		for (int i = 0; i < n; i ++) {
			A[i].clear();
			B[i].clear();
		}
		for (int i = 1; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			x --, y --;
			A[x].pb(y);
			A[y].pb(x);
		}
		fa[0] = -1;
		ff(0);
		
		hh(0);
		
		memset(g,0,sizeof g);
		bool F = 0;
		
		for (int i = 0; i < n; i ++) {
			vector<PI3> a;
			for (vit j = A[i].begin(); j != A[i].end(); j ++)
				a.pb(mp(h[mp(*j,i)],*j));
			sort(a.begin(),a.end());
			int L = (int) a.size();
			int j = 0;
			vector<int> b;
			while (j < L) {
				if (j < L-1 && a[j].fi == a[j+1].fi) {
					j += 2; continue;
				}
				g[i] ++;
				b.pb(a[j].se);
				j ++;
			}
			if (g[i] == 0) {
				F = 1; break;
			}
			if (g[i] < 3) {
				for (vit j = b.begin(); j != b.end(); j ++) {
					B[i].insert(*j);
				}
			}
		}
		
		if (!F) {
		
		/*
		for (vit j = A[2].begin(); j != A[2].end(); j ++)
			cout << 2 << " " << *j << " " << h[mp(*j,2)].fi << " " << h[mp(*j,2)].se << endl;

		for (vit j = A[6].begin(); j != A[6].end(); j ++)
			cout << 6 << " " << *j << " " << h[mp(*j,6)].fi << " " << h[mp(*j,6)].se << endl;
		*/
		
		for (int i = 0; i < n; i ++) {
			for (vit j = A[i].begin(); j != A[i].end(); j ++) {
				/*
				if (i == 2 && *j == 6) {
					cout << i << " " << *j << endl;
					cout << h[mp(*j,i)].fi << " " << h[mp(*j,i)].se << " " << h[mp(i,*j)].fi << " " << h[mp(i,*j)].se << endl;
				}
				*/
				if (h[mp(*j,i)] == h[mp(i,*j)]) F = 1;
			}
		}
				
		}
		
		if (!F) {
		
		for (int i = 0; i < n; i ++) 
			if (g[i] == 1)
				if (gg(i,-1)) {
					F = 1; break;
				}
		
		}
		
		printf("Case #%d: %s\n",__, F?"SYMMETRIC":"NOT SYMMETRIC");
	}
	return 0;
}
