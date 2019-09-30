#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int maxn = 200010;
int N,cnt,side[maxn],nxt[maxn],toit[maxn],L[maxn],R[maxn];

inline void add(int a,int b) { nxt[++cnt] = side[a]; side[a] = cnt; toit[cnt] = b; }
inline void ins(int a,int b) { add(a,b); add(b,a); }

inline int gi()
{
	char ch; int ret = 0,f = 1;
	do ch = getchar(); while (!(ch >= '0'&&ch <= '9')&&ch != '-');
	if (ch == '-') f = -1,ch = getchar();
	do ret = ret*10+ch-'0',ch = getchar(); while (ch >= '0'&&ch <= '9');
	return ret*f;
}

inline bool dfs(int now,int fa)
{
	if ((R[now]-L[now])&1) return false;
	if (L[now] > R[now]) return false;
	for (int i = side[now];i;i = nxt[i])
	{
		if (toit[i] == fa) continue;
		L[toit[i]] = max(L[toit[i]],L[now]-1);
		R[toit[i]] = min(R[toit[i]],R[now]+1);
		if (!dfs(toit[i],now)) return false;
		L[now] = max(L[now],L[toit[i]]-1);
		R[now] = min(R[now],R[toit[i]]+1);
		if ((R[now]-L[now])&1) return false;
		if (L[now] > R[now]) return false;
	}
	return true;
}

inline void print(int now,int fa)
{
	L[now] = R[now];
	for (int i = side[now];i;i = nxt[i])
	{
		if (toit[i] == fa) continue;
		L[toit[i]] = max(L[toit[i]],L[now]-1);
		R[toit[i]] = min(R[toit[i]],R[now]+1);
		print(toit[i],now);
	}
}
	

inline bool can() { if (!dfs(1,0)) return false; print(1,0); return true; }

int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	N = gi();
	for (int i = 1;i < N;++i) ins(gi(),gi());
	for (int i = 1;i <= N;++i) L[i] = -(1<<29),R[i] = 1<<29;
	for (int K = gi(),a;K--;) a = gi(),L[a] = R[a] = gi();
	if (can())
	{
		puts("Yes");
		for (int i = 1;i <= N;++i) printf("%d\n",L[i]);
	}
	else puts("No");
	return 0;
}