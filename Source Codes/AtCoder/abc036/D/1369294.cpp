#include<string>
#include<vector>
#include<iomanip>
#ifndef _WIN32
#include<iostream>
#endif
#include<algorithm>
using namespace std;
#define FOR(i,bg,ed) for(int i =(bg); i< (ed);i++)
#define REP(i,n) FOR(i,0,n) 

struct cww{
	cww(){
		ios::sync_with_stdio(false);
		cin.tie(0);
	}
}star;
typedef long long LL;
const int mod = 1e9 + 7;
int a[112345];
int b[112345];
typedef vector<int> V;
typedef vector<V> VV;
VV g;
LL on[112345];
LL of[112345];
void dfs(int v,int p){
	on[v] = 1;
	of[v] = 1;
	for (auto &e : g[v]){
		int u = v^a[e] ^ b[e];
		if (u == p)continue;
		dfs(u, v);
		(on[v] *= of[u]) %= mod;
		(of[v] *= of[u]+on[u]) %= mod;
	}
	//cout << v << " " << on[v] << " " << of[v] << endl;
}
int main(){
	int N;
	cin >> N;
	g.assign(N, V());
	REP(i, N-1){
		cin >> a[i] >> b[i];
		g[--a[i]].push_back(i);
		g[--b[i]].push_back(i);
	}
	dfs(0,0);
	cout << (on[0] + of[0]) % mod << endl;

}