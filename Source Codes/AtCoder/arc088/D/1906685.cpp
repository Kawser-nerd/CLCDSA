#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e6+100;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

VI e[N];
int l,r,mid,f[N],n;
inline void dfs(int k) {
	for (int t:e[k]) {
		e[t].erase(find(e[t].begin(),e[t].end(),k));
		dfs(t);
	}
}
inline bool solve(int k) {
	int m=e[k].size(),i,L,R,MID;VI w(m);
	for (i=0;i<m;i++) {
		if (!solve(e[k][i])) return false;
		w[i]=f[e[k][i]]+1;
	}
	if (~m&1) w.pb(0),m++;
	sort(w.begin(),w.end());
	L=0,R=m;
	while (L!=R) {
		MID=(L+R)>>1;
		f[k]=w[MID];
		w.erase(w.begin()+MID);
		for (i=0;i<m/2;i++)
			if (w[i]+w[m-2-i]>mid) break;
		w.insert(w.begin()+MID,f[k]);
		if (i==m/2) R=MID;
		else L=MID+1;
	}
	if (L==m) return false;
	f[k]=w[L];
	return true;
}
int main()
{
	int n=gi(),i,a,b,ans=0,rt;
	for (i=1;i<n;i++) {
		a=gi(),b=gi();
		e[a].pb(b),e[b].pb(a);
	}
	for (i=1;i<=n;i++) ans+=e[i].size()&1,e[i].size()==1?rt=i:0;
	dfs(rt);
	l=1,r=n;
	while (l!=r) {
		mid=(l+r)>>1;
		if (solve(rt)&&f[e[rt][0]]<mid) r=mid;
		else l=mid+1;
	}
	cout<<ans/2<<" "<<l<<endl;
	return 0;
}