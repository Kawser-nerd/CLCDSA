#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define lowbit(a) (a&-a)
typedef long long ll;
const int maxn = 100010; const ll inf = 1LL<<60;
int N,T,E,X[maxn]; ll tree1[4*maxn],tree2[4*maxn],f[maxn];

inline int gi()
{
	char ch; int ret = 0,f = 1;
	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
	if (ch == '-') f = -1,ch = getchar();
	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
	return ret*f;
}

inline void build(int now,int l,int r)
{
	tree1[now] = tree2[now] = inf;
	if (l == r) return; int mid = (l+r) >> 1;
	build(now<<1,l,mid); build(now<<1|1,mid+1,r);
}

inline void modify(ll *tree,int now,int l,int r,int pos,ll key)
{
	if (l == r) { tree[now] = key; return; } int mid = (l+r)>>1;
	if (pos <= mid) modify(tree,now<<1,l,mid,pos,key);
	else modify(tree,now<<1|1,mid+1,r,pos,key);
	tree[now] = min(tree[now<<1],tree[now<<1|1]);
}

inline ll query(ll *tree,int now,int l,int r,int ql,int qr)
{
	if (ql == l&&qr == r) return tree[now]; int mid = (l+r)>>1;
	if (qr <= mid) return query(tree,now<<1,l,mid,ql,qr);
	else if (ql > mid) return query(tree,now<<1|1,mid+1,r,ql,qr);
	else return min(query(tree,now<<1,l,mid,ql,mid),query(tree,now<<1|1,mid+1,r,mid+1,qr));
}

int main()
{
	//freopen("G.in","r",stdin);
	//freopen("G.out","w",stdout);
	N = gi(); E = gi(); T = gi();
	for (int i = 1;i <= N;++i) X[i] = gi(),tree1[i] = tree2[i] = 1LL<<60;
	for (int i = 1;i <= N;++i)
	{
		modify(tree1,1,1,N,i,f[i-1]-2LL*(ll)X[i]-(ll)X[i-1]);
		modify(tree2,1,1,N,i,f[i-1]-(ll)X[i-1]);
		int l = 0,r = i-1,mid; f[i] = inf;
		while (l <= r)
		{
			mid = (l+r)>>1;
			if (T-2LL*(X[i]-X[mid+1]) > 0) r = mid-1;
			else l = mid+1;
		}
		if (r+1) f[i] = query(tree1,1,1,N,1,r+1)+3LL*X[i];
		if (r+2 <= i) f[i] = min(f[i],query(tree2,1,1,N,r+2,i)+(ll)X[i]+(ll)T);
	}
	cout << f[N]+(ll)E-(ll)X[N] << endl;
	return 0;
}