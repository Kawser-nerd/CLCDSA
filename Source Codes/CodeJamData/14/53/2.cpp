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

#define INF 1000000007
#define N 1010
#define M N*N*2
bool e[N]; int a[N], n;
int wl[N],wr[N];
int he[N],ne[M],ad[M],di[M],wi[M];

int t;
void addE(int x, int y, int z, int w) {
	++ t, ne[t] = he[x], he[x] = t, ad[t] = y, di[t] = z, wi[t] = -w;
	++ t, ne[t] = he[y], he[y] = t, ad[t] = x, di[t] = 0, wi[t] = w;
}

int q[N*N*2],pr[N],ed[N],d[N];bool v[N];
bool spfa(int s,int t,int c)
{
	memset(v,0,sizeof v);
	for(int i=0;i<=c;i++)d[i]=INF;
	int l=1,r=1;q[1]=s,v[s]=1,d[s]=0;
	while(l<=r)
	{
		int x=q[l++];v[x]=0;
		for(int p=he[x];p;p=ne[p])if(di[p])
			if(d[x]+wi[p]<d[ad[p]])
			{
				d[ad[p]]=d[x]+wi[p],pr[ad[p]]=x,ed[ad[p]]=p;
				if(!v[ad[p]])v[ad[p]]=1,q[++r]=ad[p];
			}
	}
	return d[t]<=0;
}
PII ff(int s,int t,int c)
{
	int S=0;
	int mf=0;
	while(spfa(s,t,c))
	{
		int nf=INF;
		for(int i=t;i!=s;i=pr[i])nf=min(nf,di[ed[i]]);
		mf+=nf;
		S+=nf*d[t];
		for(int i=t;i!=s;i=pr[i])di[ed[i]]-=nf,di[ed[i]^1]+=nf;
	}
	return mp(mf,-S);
}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			string s; cin >> s >> a[i];
			e[i] = (s[0] == 'E');
		}
		memset(he,0,sizeof he);
		t = 1;
		int ss = n, st = n+1;
		int BS = 0, WE = 0;
		for (int i = 0; i < n; i ++) {
			if (e[i]) {
				wl[i] = i+1;
				bool F = 0;
				if (a[i] == 0) wr[i] = n-1; else {
					wr[i] = n-1;
					for (int j = i+1; j < n; j ++) 
						if (e[i] == e[j] && a[i] == a[j]) {
							F = 1;
							addE(ss,i,1,1); BS ++;
							wr[i] = j-1; break;
						}
				}
				if (!F) addE(ss,i,1,0);
				WE ++;
			} else {
				wr[i] = i-1;
				bool F = 0;
				if (a[i] == 0) wl[i] = 0; else {
					wl[i] = 0;
					for (int j = i-1; j >= 0; j --) {
						if (e[i] == e[j] && a[i] == a[j]) {
							F = 1;
							addE(i,st,1,1); BS ++;
							wl[i] = j+1; break;
						}
					}
				}
				if (!F) addE(i,st,1,0);
			}
		}
		for (int i = 0; i < n; i ++) if (e[i])
			for (int j = wl[i]; j <= wr[i]; j ++)
				if (e[j] != e[i] && (a[j] == a[i] || a[i] == 0 || a[j] == 0) && wl[j] <= i && i <= wr[j]) 
					addE(i,j,1,0);
		PII S = ff(ss,st,st+1);
		printf ("Case #%d: ",__);
		if (S.se != BS) puts ("CRIME TIME");
		else printf ("%d\n",WE-S.fi);
	}
	return 0;
}