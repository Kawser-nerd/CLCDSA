/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long LL;
const int V = 100100;
const int En = 4000 * 1000;
const int U = 10000;
const int oo = 1000000000;
struct Edge{int num,ne,c;}e[En];
int d[V],p[V],pre[V],low[V];
int gap[V],cur[V];
int N,K,st,ed;
void add(int x,int y,int c)
{
	e[K].num=y;e[K].c=c;
	e[K].ne=p[x];p[x]=K++;
	e[K].num=x;e[K].c=0;
	e[K].ne=p[y];p[y]=K++;
}
int sap()
{
	int ret=0;
	bool fail;
	for(int i=0;i<=N;i++)
	{
		low[i]=gap[i]=d[i]=0;
		cur[i]=p[i];
	}
	low[st]=oo;gap[0]=N;int u=st;
	while(d[st]<N)
	{
		fail=true;
		for(int i=cur[u];i!=-1;i=e[i].ne)
		{
			int v=e[i].num;cur[u]=i;
			if(e[i].c&&d[u]==d[v]+1)
			{
				pre[v]=i;
				low[v]=min(low[u],e[i].c);u=v;
				if(u==ed)
				{
					do
					{
						e[pre[u]].c-=low[ed];
						e[pre[u]^1].c+=low[ed];
						u=e[pre[u]^1].num;
					}while(u!=st);
					ret+=low[ed];
				}
				fail=false;break;
			}
		}
		if(fail)
		{
			gap[d[u]]--;
			if(!gap[d[u]])return ret;
			d[u]=N;
			for(int i=p[u];i!=-1;i=e[i].ne)
			if(e[i].c)d[u]=min(d[u],d[e[i].num]+1);
			gap[d[u]]++;cur[u]=p[u];
			if(u!=st)u=e[pre[u]^1].num;
		}
	}
	return ret;
}
int _, n;
vector <string> split(string s)
{
	s += ' ';
	vector <string> ret;
	ret.clear();
	string t = "";
	for(int i = 0; i < s.length(); ++i)
	{
		if(s[i] == ' ')
		{
			ret.push_back(t);
			t = "";
		}
		else t += s[i];
	}
	return ret;
}
char s[V];
map <string, int> mp;
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d", &n);
		gets(s);
		mp.clear();
		int m = 0;
		memset(p, -1, sizeof(p)); K = 0;
		for(int i = 0; i < n; ++i)
		{
			gets(s);
			string SS = s;
			vector <string> tmp = split(SS);
			for(int j = 0; j < tmp.size(); ++j)
			{
				if(mp.find(tmp[j]) == mp.end())
				{
					mp[tmp[j]] = m++;
				}
				int id = mp[tmp[j]];
				add(i, id * 2 + 2 * n, oo);
				add(id * 2 + 1 + 2 * n, i + n, oo);
			}
		}
		N = 2 * n + 2 * m + 2;
		st = N - 2;
		ed = N - 1;
		for(int i = 0; i < n; ++i)
		{
			add(i, i + n, oo);
			add(st, i, U);
			add(i + n, ed, U);
			if(i == 0) add(st, i, oo);
			if(i == 1) add(i + n, ed, oo);
		}
		for(int i = 0; i < m; ++i) add(2 * n + 2 * i, 2 * n + 2 * i + 1, 1);
		int ret = sap() - n * U;
		printf("Case #%d: %d\n", ca, ret);
	}
	return 0;
}
