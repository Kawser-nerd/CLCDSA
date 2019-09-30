#pragma comment(linker, "/STACK:1000000000")
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define sz(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;++i)
#define mp make_pair
#define pb push_back
typedef pair<int, int> pii;
//////////////////////

int const N = 1e5 + 41;
int const BASE = (1 << 19);
int const M = 17;
int const INF = 1e9 + 41;

int n, f[N], s[N];
int par[N][M], tin[N], tout[N], cnt, se[N], h[N];
int ver[N];
vector<int> e[N];
vector<int> st;
int dc[N];
int ea[N], eb[N];

int getTo(int id, int v){
	return (f[id] == v ? s[id] : f[id]);
}

int dfs0(int u, int p){
	dc[u] = 1;
	st.pb(u);
	rep(i, 0, sz(e[u])){
		int to = getTo(e[u][i], u);
		if(to == p) continue;
		dc[u] += dfs0(to, u);
	}
	int n = sz(st) - 1;
	rep(i, 0, M){
		par[u][i] = -1;
		if((1<<i) <= n){
			par[u][i] = st[n - (1<<i)];
		}
	}
	st.pop_back();
	return dc[u];
}

void dfs1(int u, int p, int s){
	tin[u] = cnt;
	ver[cnt] = u;
	se[u] = s;
	ea[cnt] = p;
	eb[cnt] = u;
	++cnt;
	h[u] = -1;
	rep(i, 0, sz(e[u])){
		int to = getTo(e[u][i], u);
		if(to == p) continue;
		if(dc[to] * 2 >= dc[u]) h[u] = to;
	}
	if(h[u] != -1){
		dfs1(h[u], u, s);
	}
	rep(i, 0, sz(e[u])){
		int to = getTo(e[u][i], u);
		if(to == p || to == h[u]) continue;
		dfs1(to, u, to);
	}

	tout[u] = cnt-1;	
}

bool isA(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int getLca(int a, int b){
	if(isA(a, b)) return a;
	if(isA(b, a)) return b;
	for(int i=M-1;i>=0;--i){
		if(par[a][i] == -1 || isA(par[a][i], b)) continue;
		a = par[a][i];
	}
	return par[a][0];
}

pii te[BASE];
int adde[BASE];

void push(int v){
	adde[v * 2 + 1] += adde[v];
	adde[v * 2 + 2] += adde[v];
	te[v].first += adde[v];
	adde[v] = 0;
}

void refreshMin(int v, int v1, int v2){
	bool f = false;
	if(te[v1].first + adde[v1] < te[v2].first + adde[v2]){
		f = true;
	}else if(te[v1].first + adde[v1] == te[v2].first + adde[v2]){
		if(te[v1].second < te[v2].second){
			f = true;
		}
	}
	if(f){
		te[v].first = te[v1].first + adde[v1];
		te[v].second = te[v1].second;
	}else{
		te[v].first = te[v2].first + adde[v2];
		te[v].second = te[v2].second;
	}
}

void upd(int v, int tl, int tr, int l, int r, int val){
	if(tl > r || tr < l) return;
	if(l <= tl && tr <= r){
		adde[v] += val;
		return;
	}
	push(v);
	int tm = (tl+tr)/2;
	upd(v*2+1, tl, tm, l, r, val);
	upd(v*2+2, tm+1, tr, l, r, val);
	refreshMin(v, v*2+1, v*2+2);
}

void updLine(int v, int lca, int val){
	while(v != lca){
		int nxt = se[v];
		if(isA(nxt, lca)) nxt = lca;
		if(nxt == lca){
			upd(0, 0, n-1, tin[nxt] + 1, tin[v], val);
			v = nxt;
		}else{
			upd(0, 0, n-1, tin[nxt], tin[v], val);
			v = par[nxt][0];
		}
	}
}

void updWay(int a, int b, int val){
	int lca = getLca(a, b);
	updLine(a, lca, val);
	updLine(b, lca, val);
}

int sf[N], ss[N];

struct Q{
	int from, to, val;
	Q(){};
	Q(int from, int to, int val) : from(from), to(to), val(val) {};
	bool operator<(const Q &a) const{
		if(val == a.val){
			if(from == a.from){
				return to < a.to;
			}else return from < a.from;
		}else return val < a.val;
	};
};

set<Q> t[BASE / 2];
vector<int> fe[N];
Q EMP = Q(-1, -1, INF);

int posInTree[N];

void build(int v, int tl, int tr){
	if(tl != tr){
		int tm = (tl+tr)/2;
		build(v*2+1, tl, tm);
		build(v*2+2, tm+1, tr);
	}else{
		posInTree[ver[tl]] = v;
	}
	rep(i, tl, tr+1){
		int curV = ver[i];
		rep(j, 0, sz(fe[curV])){
			int to = sf[fe[curV][j]];
			if(to == curV) to = ss[fe[curV][j]];
			t[v].insert(Q(curV, to, tin[to]));
		}
	}
}

void getLower(int v, int tl, int tr, int l, int r, Q &val, Q &ret){
	if(tl > r || tr < l) return;
	if(l <= tl && tr <= r){
		auto it = t[v].lower_bound(val);
		if(it == t[v].end()) return;
		ret = min(ret, (*it));
		return;
	}
	int tm = (tl+tr)/2;
	getLower(v*2+1, tl, tm, l, r, val, ret);
	getLower(v*2+2, tm+1, tr, l, r, val, ret);
}

void clear(int v, Q val){
	while(true){
		t[v].erase(val);
		if(v == 0) break;
		v = (v-1) / 2;
	}
}

void buildE(int v, int tl, int tr){
	if(tl == tr){
		if(tl == 0){
			te[v] = mp(INF, 0);
		}else{
			te[v] = mp(0, tl);
		}
	}else{
		int tm = (tl+tr)/2;
		buildE(v*2+1, tl, tm);
		buildE(v*2+2, tm+1, tr);
		te[v] = min(te[v*2+1], te[v*2+2]);
	}
}

void solve(){
	
	n = 1e5;
	cin >> n;
	rep(i, 0, n-1){
		
		f[i] = i + 1;
		s[i] = f[i] + 1;
		cin >> f[i] >> s[i];
		--f[i];--s[i];
		e[f[i]].pb(i);
		e[s[i]].pb(i);
	}
	rep(i, 0, n-1){
		
		sf[i] = 1;
		ss[i] = i + 2;
		cin >> sf[i] >> ss[i];
		--sf[i];
		--ss[i];
		fe[sf[i]].pb(i);
		fe[ss[i]].pb(i);
	}

	dfs0(0, -1);
	dfs1(0, -1, 0);
	
	build(0, 0, n-1);
	buildE(0, 0, n-1);
	
	rep(i, 0, n-1){
		updWay(sf[i], ss[i], 1);
	}
	
	bool ok = true;
	Q curMin;
	Q val = Q(-1, -1, INF);
	rep(i, 0, n-1){
		
		pii curMinEdge = mp(te[0].first + adde[0], te[0].second);
	
		if(curMinEdge.first != 1){
			ok = false;
			break;
		}else{
			
			int a = ea[curMinEdge.second];
			int b = eb[curMinEdge.second];
			
			curMin = EMP;
			val.val = tin[b];
			getLower(0, 0, n-1, 0, tin[b] - 1, val, curMin);

			getLower(0, 0, n-1, tin[b] + dc[b], n-1, val, curMin);
			
			updWay(curMin.from, curMin.to, -1);
			clear(posInTree[curMin.from], curMin);
			clear(posInTree[curMin.to], Q(curMin.to, curMin.from, tin[curMin.from]));
			updWay(a, b, INF);
		}
	}
	
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	//cout << SUM << endl;
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}